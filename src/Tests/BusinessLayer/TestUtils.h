namespace TestUtils
{
    void expectCobsCorrect(unsigned char* input, unsigned char* expected, const unsigned int inputLength);

    void appendChecksum(unsigned char* data, unsigned int lengthPayload);
}
