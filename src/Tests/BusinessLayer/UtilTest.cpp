#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "Util.h"
#include "TestUtils.h"

using TestUtils::expectCobsCorrect;
using TestUtils::appendChecksum;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

/*
 * Tests if Consistent Overhead Byte Stuffing (COBS) is working as intended
 */
TEST(UtilTest, COBSTest)
{
    unsigned char nullArrayInput[] = {0x00};
    unsigned char nullArrayExpected[] = {0x01, 0x01, 0x00};
    expectCobsCorrect(nullArrayInput, nullArrayExpected, 1);
    unsigned char input1[] = {0x00, 0x00};
    unsigned char expected1[] = {0x01, 0x01, 0x01, 0x00};
    expectCobsCorrect(input1, expected1, 2);
    unsigned char input2[] = {0x11, 0x22, 0x00, 0x33};
    unsigned char expected2[] = {0x03, 0x11, 0x22, 0x02, 0x33, 0x00};
    expectCobsCorrect(input2, expected2, 4);
    unsigned char input3[] = {0x11, 0x22, 0x33, 0x44};
    unsigned char expected3[] = {0x05, 0x11, 0x22, 0x33, 0x44, 0x00};
    expectCobsCorrect(input3, expected3, 4);
    unsigned char input4[] = {0x11, 0x00, 0x00, 0x00};
    unsigned char expected4[] = {0x02, 0x11, 0x01, 0x01, 0x01, 0x00};
    expectCobsCorrect(input4, expected4, 4);
    const unsigned int MAX_COBS_PACKAGE_LENGTH = 254;
    unsigned char inputAlmostMax[MAX_COBS_PACKAGE_LENGTH - 1];
    unsigned char expectedAlmostMax[MAX_COBS_PACKAGE_LENGTH + 1];

    for (unsigned char i = 0; i < MAX_COBS_PACKAGE_LENGTH - 1; ++i)
    {
        inputAlmostMax[i] = i + 1;
        expectedAlmostMax[i + 1] = i + 1;
    }

    expectedAlmostMax[0] = 0xFE;
    expectedAlmostMax[MAX_COBS_PACKAGE_LENGTH] = 0x00;
    expectCobsCorrect(inputAlmostMax, expectedAlmostMax, MAX_COBS_PACKAGE_LENGTH - 1);
    unsigned char inputMax[MAX_COBS_PACKAGE_LENGTH];
    unsigned char expectedMax[MAX_COBS_PACKAGE_LENGTH + 2];

    for (unsigned char i = 0; i < MAX_COBS_PACKAGE_LENGTH; ++i)
    {
        inputMax[i] = i + 1;
        expectedMax[i + 1] = i + 1;
    }

    expectedMax[0] = 0xFF;
    expectedMax[MAX_COBS_PACKAGE_LENGTH + 1] = 0x00;
    expectCobsCorrect(inputMax, expectedMax, MAX_COBS_PACKAGE_LENGTH); // TODO this one fails. can probably be fixed by removing line 452 from TelemetryReporting.cpp
    // TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // TODO WHAT HAPPENS IF THE Distance to the first zero is more than 254 bytes?? (our packages are smaller...)
    // TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

/*
 * This test tests if the checksum is correctly appended. It does not test the checksum calculation itself.
 */
TEST(UtilTest, addChecksumTest)
{
    const unsigned char numberOfTestRuns = 42;

    for (unsigned char i = 0; i < numberOfTestRuns; i++)
    {
        const unsigned int length = i + 16;
        unsigned char dataExpected[length];
        unsigned char dataActual[length];

        for (unsigned char c = 0; c < length; c++)
        {
            dataActual[c] = c + i;
            dataExpected[c] = c + i;
        }

        appendChecksum(dataExpected, length);
        Util::addChecksum(dataActual, length - Util::CHECKSUM_LENGTH);
        ASSERT_THAT(std::vector<unsigned char>(dataActual, dataActual + length),
                    ElementsAreArray(std::vector<unsigned char>(dataExpected, dataExpected + length)));
    }
}

TEST(UtilTest, writeBoolsIntoArrayTest)
{
	bool inSingleTrue[] = {true};
	const std::vector<unsigned char> expctSingleTrue = {0x01};
	bool inSingleFalse[] = {false};
	const std::vector<unsigned char> expctSingleFalse = {0x00};
	bool input4[] = {false, true, false, true};
	const std::vector<unsigned char> expct4 = {0x0A};
	bool input4inv[] = {true, false, true, false};
	const std::vector<unsigned char> expct4inv = {0x05};
	bool input8[] = {false, true, false, true, false, true, false, true};
	const std::vector<unsigned char> expct8 = {0xAA};
	bool input9[] = {false, true, false, true, false, true, false, true, true};
	const std::vector<unsigned char> expct9 = {0xAA, 0x01};
	bool inputsAllTrue[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
	const std::vector<unsigned char> expctAllTrue = {0xFF, 0xFF};
	bool inputsAllFalse[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
	const std::vector<unsigned char> expctAllFalse = {0x00, 0x00};
	const std::vector<std::tuple<bool*, int, std::vector<unsigned char>>> inputs =
	{
			std::make_tuple(inSingleTrue, sizeof(inSingleTrue) / sizeof(bool), expctSingleTrue),
			std::make_tuple(inSingleFalse, sizeof(inSingleFalse) / sizeof(bool), expctSingleFalse),
			std::make_tuple(input4, sizeof(input4) / sizeof(bool), expct4),
			std::make_tuple(input4inv, sizeof(input4inv) / sizeof(bool), expct4inv),
			std::make_tuple(input8, sizeof(input8) / sizeof(bool), expct8),
			std::make_tuple(input9, sizeof(input9) / sizeof(bool), expct9),
			std::make_tuple(inputsAllTrue, sizeof(inputsAllTrue) / sizeof(bool), expctAllTrue),
			std::make_tuple(inputsAllFalse, sizeof(inputsAllFalse) / sizeof(bool), expctAllFalse)
	};

	for (std::vector<std::tuple<bool*, int, std::vector<unsigned char>>>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const bool* input = std::get<0>(*it);
		unsigned int actualLength = std::get<2>(*it).size();
		unsigned char actual[actualLength];
		Util::writeBoolsIntoArray(actual, 0, input, std::get<1>(*it));
		// introduce vector wrapper for actual (workaround to get the matcher handle variable-length arrays)
	    std::vector<unsigned char> actual_wrapper(actual, actual + actualLength);
	    ASSERT_THAT(actual_wrapper, ElementsAreArray(std::get<2>(*it)));
	}
}

TEST(UtilTest, writeFloatIntoArrayTest)
{
	const std::vector<float> inputs = {42.1234, 0, 3512.341, 19921.213, -10.2, -42.32, -7, 12,
			400, -66, -235.324, 8773.823, std::numeric_limits<float>::infinity(),
			std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<float>::epsilon(),
			std::numeric_limits<float>::min(), std::numeric_limits<float>::max()
	};

	for (std::vector<float>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const float input = *it;
		char* p = ( char*)((void*)&input);
		unsigned char actual[sizeof(float)];
		Util::writeFloatIntoArray(actual, 0, input);
		ASSERT_THAT(actual, ElementsAre(*p, *(p + 1), *(p + 2), *(p + 3)));
	}
}

// test may fail if short size is smaller than 16 bit!!
TEST(UtilTest, writeShortIntoArrayTest)
{
	std::vector<short> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
			12416, 3264, 12825, 6, 31210 , 24,
			-42, -3512, -19921, -12, -400, -66, -235, -8773,
			-12416, -3264, -12825, -6, -31210 , -24,
			std::numeric_limits<short>::min() + 1, std::numeric_limits<short>::max() - 1,
			std::numeric_limits<short>::min(), std::numeric_limits<short>::max()
	};
	short pot2 = 1;

	for (int i = 0; i < 16; i++)
	{
		inputs.push_back(pot2 - 1);
		inputs.push_back(pot2);
		pot2 *= 2;
	}

	for (std::vector<short>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const short input = *it;
		char* p = ( char*)((void*)&input);
		unsigned char actual[sizeof(short)];
		Util::writeShortIntoArray(actual, 0, input);
		ASSERT_THAT(actual, ElementsAre(*p, *(p + 1)));
	}
}

// test may fail if short size is smaller than 16 bit!!
TEST(UtilTest, writeUShortIntoArrayTest)
{
	std::vector<unsigned short> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
			12416, 3264, 12825, 6, 51210 , 24,
			std::numeric_limits<unsigned short>::min() + 1, std::numeric_limits<unsigned short>::max() - 1,
			std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max()
	};
	unsigned short pot2 = 1;

	for (int i = 0; i < 16; i++)
	{
		inputs.push_back(pot2 - 1);
		inputs.push_back(pot2);
		pot2 *= 2;
	}

	for (std::vector<unsigned short>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const unsigned short input = *it;
		char* p = ( char*)((void*)&input);
		unsigned char actual[sizeof(unsigned short)];
		Util::writeUShortIntoArray(actual, 0, input);
		ASSERT_THAT(actual, ElementsAre(*p, *(p + 1)));
	}
}

// test may fail if uint size smaller than 32 bit!!
TEST(UtilTest, writeUIntIntoArrayTest)
{
	std::vector<unsigned int> inputs = {42, 3512, 19921, 12, 400, 66, 235, 8773,
			1241632, 64128256, 5121024,
			std::numeric_limits<unsigned int>::min() + 1, std::numeric_limits<unsigned int>::max() - 1,
			std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max()
	};
	unsigned int pot2 = 1;

	for (int i = 0; i < 32; i++)
	{
		inputs.push_back(pot2 - 1);
		inputs.push_back(pot2);
		pot2 *= 2;
	}

	for (std::vector<unsigned int>::const_iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		const unsigned int input = *it;
		char* p = ( char*)((void*)&input);
		unsigned char actual[sizeof(unsigned int)];
		Util::writeUIntIntoArray(actual, 0, input);
		ASSERT_THAT(actual, ElementsAre(*p, *(p + 1), *(p + 2), *(p + 3)));
	}
}

