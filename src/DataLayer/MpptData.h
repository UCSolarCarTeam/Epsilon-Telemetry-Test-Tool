#pragma once

#include <QObject>

class MpptData : public QObject
{
    Q_OBJECT

public:
    MpptData();
    virtual ~MpptData();

    unsigned char mpptNumber() const;
    bool alive(int mpptNumber) const;
    unsigned short arrayVoltage(int mpptNumber) const;
    unsigned short arrayCurrent(int mpptNumber) const;
    unsigned short batteryVoltage(int mpptNumber) const;
    unsigned short temperature(int mpptNumber) const;

    void setMpptNumber(const unsigned char& mpptNumber);
    void setAlive(const bool& alive);
    void setArrayVoltage(const unsigned short& arrayVoltage);
    void setArrayCurrent(const unsigned short& arrayCurrent);
    void setBatteryVoltage(const unsigned short& batteryVoltage);
    void setTemperature(const unsigned short& temperature);

private:
    unsigned char mpptNumber_;
    bool alive_ [3];
    unsigned short arrayVoltage_ [3];
    unsigned short arrayCurrent_ [3];
    unsigned short batteryVoltage_ [3];
    unsigned short temperature_ [3];
};
