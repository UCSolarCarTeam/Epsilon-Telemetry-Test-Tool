#pragma once

#include <QObject>

class AuxBmsData;
class AuxBmsTab;

class AuxBmsReporting : public QObject
{
    Q_OBJECT

public:
    AuxBmsReporting(AuxBmsTab& auxBmsTab);
    void setData(AuxBmsData& auxBmsData);

private:
    AuxBmsTab& auxBmsTab_;
};
