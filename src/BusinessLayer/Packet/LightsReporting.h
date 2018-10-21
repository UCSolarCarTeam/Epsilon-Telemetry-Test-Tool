#pragma once

#include <QObject>

class LightsData;
class LightsTab;

class LightsReporting : public QObject
{
    Q_OBJECT

public:
    LightsReporting(LightsData& lightsPacket0,
                    LightsData& lightsPacket1,
                    LightsTab& lightsTab);
    void setData(int packetNum);

private:
    LightsData& lightsPacket0_;
    LightsData& lightsPacket1_;
    LightsTab& lightsTab_;
};
