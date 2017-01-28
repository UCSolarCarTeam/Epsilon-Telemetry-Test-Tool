#pragma once

#include "I_CommunicationService.h"

#include "gmock/gmock.h"

class MockCommunicationService : public I_CommunicationService
{

public:
    MOCK_METHOD2(sendData, void(const unsigned char* packet, int packetLength));
};
