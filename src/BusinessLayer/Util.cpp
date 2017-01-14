
#include <Util.h>

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

