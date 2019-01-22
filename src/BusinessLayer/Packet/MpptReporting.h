#pragma once

#include <QObject>

class MpptData;
class MpptTab;

class MpptReporting : public QObject
{
    Q_OBJECT

public:
    MpptReporting(MpptTab& mpptTab);
    void setData(MpptData& mpptData);

private:
    MpptTab& mpptTab_;
};
