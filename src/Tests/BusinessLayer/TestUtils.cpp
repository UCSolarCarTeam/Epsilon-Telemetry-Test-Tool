#include "TestUtils.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Util.h"
#include "CrcCalculator.h"

using ::testing::Not;
using ::testing::Matches;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

#define COUT_HEX( x ) std::setw(2) << "\\x" << std::hex << (int)( x )

void TestUtils::expectCobsCorrect(unsigned char* input, unsigned char* expected, const unsigned int inputLength)
{
    const unsigned int expectedArrayLength = inputLength + 2;
    unsigned char encodedArray[expectedArrayLength];
    Util::frameData(input, inputLength, encodedArray);

    if(Matches(Not(ElementsAreArray(std::vector<unsigned char>(expected, expected + expectedArrayLength))))(std::vector<unsigned char>(encodedArray, encodedArray + expectedArrayLength)))
    {
    	std::cout << COUT_HEX(encodedArray[inputLength]) << " " << COUT_HEX(encodedArray[inputLength + 1]) << std::endl;
    }

    EXPECT_THAT(std::vector<unsigned char>(encodedArray, encodedArray + expectedArrayLength),
                ElementsAreArray(std::vector<unsigned char>(expected, expected + expectedArrayLength)));
}

void TestUtils::appendChecksum(unsigned char* data, unsigned int lengthPayload)
{
    // this is just here to ensure that every test which uses the method fails, if the length of the check sum changes.
    // In this case this method has to be adapted
    ASSERT_THAT(Util::CHECKSUM_LENGTH, 2);

    const unsigned short checksum = CrcCalculator::calculateCrc16(data, lengthPayload - Util::CHECKSUM_LENGTH);
    const unsigned char lowerByte = (unsigned char) checksum & 0xFF;
    const unsigned char higherByte = (unsigned char) ((checksum & 0xFF00) >> 8);
    data[lengthPayload - Util::CHECKSUM_LENGTH] = lowerByte;
    data[lengthPayload - (Util::CHECKSUM_LENGTH - 1)] = higherByte;
}
