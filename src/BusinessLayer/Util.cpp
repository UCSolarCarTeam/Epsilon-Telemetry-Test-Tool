#include <Util.h>
#include <CrcCalculator.h>

namespace Util
{
    union DataUnion
    {
        float floatData;
        short shortData[2];
        unsigned short uShortData[2];
        char charData[4];
        unsigned int uIntData;
    };

}

unsigned int Util::frameData(const unsigned char* dataToEncode, unsigned long length, unsigned char* frameData)
{
    unsigned int lengthOfFramedData = stuffData(dataToEncode, length, frameData);
    frameData[lengthOfFramedData++] = TERMINATING_BYTE;
    return lengthOfFramedData;
}

#define FINISH_BLOCK(X) \
{\
   *code_ptr = (X); \
   code_ptr = encodedData++; \
   code = 0x01; \
}


/*
 * This method can only encode arbitrary data (parameter dataToEncode) if it's length is smaller or equal to 254.
 * Before a recent change (see comment in the implementation of the method) the longest possible message was even
 * shorter (limit at 253 bytes) than the maximal possible message length supported by the COBS encoding which is 254.
 * If unexpected problems occur, a fall back to the old 253 bytes limited version is recommended to ensure proper function!
 */
unsigned int Util::stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData)
{
    unsigned int lengthOfEncodedData = length + 1;
    const unsigned char* end = dataToEncode + length;
    unsigned char* code_ptr = encodedData++;
    unsigned char code = 0x01;

    while (dataToEncode < end)
    {
        if (*dataToEncode == 0)
        {
            FINISH_BLOCK(code);
        }
        else
        {
            *encodedData++ = *dataToEncode;
            code++;

            if (code == 0xFF)
            {
                FINISH_BLOCK(code);
                //lengthOfEncodedData++;	// TODO probably artifact. If executed prevents correct encoding of message with length of 254 bytes
            }
        }

        dataToEncode++;
    }

    FINISH_BLOCK(code);
    return lengthOfEncodedData;
}
#undef FINISH_BLOCK

void Util::addChecksum(unsigned char* data, unsigned int length)
{
    unsigned short crc16 = CrcCalculator::calculateCrc16(data, length);
    data[length] = static_cast<unsigned char>(0xFF & crc16);
    data[length + 1] = static_cast<unsigned char>(0xFF & (crc16 >> 8));
}


void Util::writeFloatIntoArray(unsigned char* data, int index, const float& value)
{
    DataUnion dataUnion;
    dataUnion.floatData = value;
    data[index++] = dataUnion.charData[0];
    data[index++] = dataUnion.charData[1];
    data[index++] = dataUnion.charData[2];
    data[index] = dataUnion.charData[3];
}

void Util::writeUIntIntoArray(unsigned char* data, int index, const unsigned int& value)
{
    DataUnion dataUnion;
    dataUnion.uIntData = value;
    data[index++] = dataUnion.charData[0];
    data[index++] = dataUnion.charData[1];
    data[index++] = dataUnion.charData[2];
    data[index] = dataUnion.charData[3];
}


void Util::writeShortIntoArray(unsigned char* data, int index, const short& value)
{
    DataUnion dataUnion;
    dataUnion.shortData[0] = value;
    data[index++] = dataUnion.charData[0];
    data[index] = dataUnion.charData[1];
}

void Util::writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value)
{
    DataUnion dataUnion;
    dataUnion.uShortData[0] = value;
    data[index++] = dataUnion.charData[0];
    data[index] = dataUnion.charData[1];
}

void Util::writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues)
{
    index -= 1;

    for (int i = 0; i < numValues; i++)
    {
        if ((i % 8) == 0)
        {
            index++;
            data[index] = 0;
        }

        if (values[i])
        {
            data[index] += 1 << (i % 8);
        }
    }
}

