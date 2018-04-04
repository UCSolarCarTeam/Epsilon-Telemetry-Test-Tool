#pragma once

#include <QObject>

class MpptData : public QObject
{
    Q_OBJECT

public:
    MpptData();
    virtual ~MpptData();

    unsigned char mpptNumber() const;
    bool alive() const;
    unsigned short arrayVoltage() const;
    unsigned short arrayCurrent() const;
    unsigned short batteryVoltage() const;
    unsigned short temperature() const;

    void setMpptNumber(const unsigned char& mpptNumber);
    void setAlive(const bool& alive);
    void setArrayVoltage(const unsigned short& arrayVoltage);
    void setArrayCurrent(const unsigned short& arrayCurrent);
    void setBatteryVoltage(const unsigned short& batteryVoltage);
    void setTemperature(const unsigned short& temperature);

private:
    unsigned char mpptNumber_;
    bool alive_;
    unsigned short arrayVoltage_;
    unsigned short arrayCurrent_;
    unsigned short batteryVoltage_;
    unsigned short temperature_;
};
