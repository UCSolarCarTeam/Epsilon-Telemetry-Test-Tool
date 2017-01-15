#ifndef BUSINESSLAYER_UTIL_H_
#define BUSINESSLAYER_UTIL_H_

namespace Util
{
	const unsigned int CHECKSUM_LENGTH = 2;
	const unsigned int FRAMING_LENGTH_INCREASE = 2;
    const unsigned char TERMINATING_BYTE = 0x00;

	unsigned int frameData(const unsigned char* dataToEncode, unsigned long length, unsigned char* frameData);
	unsigned int stuffData(const unsigned char* dataToEncode, unsigned long length, unsigned char* encodedData);
	void addChecksum(unsigned char* data, unsigned int length);

    void writeFloatIntoArray(unsigned char* data, int index, const float& value);
    void writeShortIntoArray(unsigned char* data, int index, const short& value);
    void writeUShortIntoArray(unsigned char* data, int index, const unsigned short& value);
    void writeUIntIntoArray(unsigned char* data, int index, const unsigned int& value);
    void writeBoolsIntoArray(unsigned char* data, int index, const bool values[], int numValues);
}



#endif /* BUSINESSLAYER_UTIL_H_ */
