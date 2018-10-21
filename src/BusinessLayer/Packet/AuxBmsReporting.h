#pragma once

#include <QObject>

class AuxBmsData;
class AuxBmsTab;

class AuxBmsReporting : public QObject
{
    Q_OBJECT

public:
    AuxBmsReporting(AuxBmsData& auxBmsPacket0,
                    AuxBmsData& auxBmsPacket1,
                    AuxBmsTab& auxBmsTab);
    void setData(int packetNum);

private:
    AuxBmsData& auxBmsPacket0_;
    AuxBmsData& auxBmsPacket1_;
    AuxBmsTab& auxBmsTab_;
};
