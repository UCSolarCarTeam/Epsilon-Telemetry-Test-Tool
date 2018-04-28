#pragma once

#include <QObject>

class AuxBmsData;
class AuxBmsTab;

class AuxBmsReporting : public QObject
{
    Q_OBJECT

public:
    AuxBmsReporting(AuxBmsData& auxBmsData,
                    AuxBmsTab& auxBmsTab);
    void setUiData();

private:
    AuxBmsData& auxBmsData_;
    AuxBmsTab& auxBmsTab_;
};
