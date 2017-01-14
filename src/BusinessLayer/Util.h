#ifndef BUSINESSLAYER_UTIL_H_
#define BUSINESSLAYER_UTIL_H_

namespace Util
{
    void writeFloatIntoArray(unsigned char* data, int index, const float& value);
    void writeShortIntoArray(unsigned char* data, int index, const short& value);
    void writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value);
    void writeUIntIntoArray(unsigned char* data, int index, const unsigned int& value);
    void writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues);
}



#endif /* BUSINESSLAYER_UTIL_H_ */
