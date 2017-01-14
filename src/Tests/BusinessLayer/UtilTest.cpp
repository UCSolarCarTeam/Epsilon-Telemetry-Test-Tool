#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include "Util.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

class UtilTest: public ::testing::Test {
};

TEST_F(UtilTest, writeBoolsIntoArrayTest)
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

TEST_F(UtilTest, writeFloatIntoArrayTest)
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
TEST_F(UtilTest, writeShortIntoArrayTest)
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
TEST_F(UtilTest, writeUShortIntoArrayTest)
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
TEST_F(UtilTest, writeUIntIntoArrayTest)
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

