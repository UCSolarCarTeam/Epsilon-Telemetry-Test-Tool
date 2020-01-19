#pragma once

#include <QObject>

class MpptData : public QObject
{
    Q_OBJECT

public:
    MpptData();
    virtual ~MpptData();

    bool alive() const;
    double arrayVoltage() const;
    double arrayCurrent() const;
    double batteryVoltage() const;
    unsigned short temperature() const;

    void setAlive(const bool& alive);
    void setArrayVoltage(const double& arrayVoltage);
    void setArrayCurrent(const double& arrayCurrent);
    void setBatteryVoltage(const double& batteryVoltage);
    void setTemperature(const unsigned short& temperature);

private:
    unsigned char mpptNumber_;
    bool alive_;
    double arrayVoltage_;
    double arrayCurrent_;
    double batteryVoltage_;
    unsigned short temperature_;
};
