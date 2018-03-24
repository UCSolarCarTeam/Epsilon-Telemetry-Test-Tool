#pragma once

#include <QObject>

class MpptData;
class MpptTab;

class MpptReporting : public QObject
{
    Q_OBJECT

public:
    MpptReporting(MpptData& mpptData,
                  MpptTab& mpptTab);
    void setMpptData();

private:
    MpptData& mpptData_;
    MpptTab& mpptTab_;
};
