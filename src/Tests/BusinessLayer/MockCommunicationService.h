#pragma once

#include "I_CommunicationService.h"

#include "gmock/gmock.h"

class MockCommunicationService : public I_CommunicationService
{

public:
    MOCK_METHOD2(sendSerialData, void(const unsigned char* packet, int packetLength));
    MOCK_METHOD1(sendInternetData, void(const QByteArray& data));

    MOCK_METHOD0(attemptSerialConnection, void());
    MOCK_METHOD0(attemptSerialDisconnection, void());
    MOCK_METHOD0(attemptInternetConnection, void());
    MOCK_METHOD0(attemptInternetDisconnection, void());
};
