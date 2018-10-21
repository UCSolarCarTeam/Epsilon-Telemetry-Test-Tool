#pragma once

#include <QObject>

class MpptData;
class MpptTab;

class MpptReporting : public QObject
{
    Q_OBJECT

public:
    MpptReporting(MpptData& mpptPacket0,
                  MpptData& mpptPacket1,
                  MpptTab& mpptTab);
    void setData(int packetNum);

private:
    MpptData& mpptPacket0_;
    MpptData& mpptPacket1_;
    MpptTab& mpptTab_;
};
