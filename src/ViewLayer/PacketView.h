#pragma once

#include <QObject>
#include <QSignalMapper>

class PacketWindow;
class AuxBmsTab;
class BatteryFaultsTab;
class BatteryTab;
class DriverControlsTab;
class MotorTab;
class LightsTab;
class MotorFaultsTab;
class MpptTab;

class PacketView : public QObject
{
    Q_OBJECT
public:
    PacketView(PacketWindow* window);
    AuxBmsTab& getAuxBmsTab();
    BatteryFaultsTab& getBatteryFaultsTab();
    BatteryTab& getBatteryTab();
    DriverControlsTab& getDriverControlsTab();
    LightsTab& getLightsTab();
    MotorTab& getMotor0Tab();
    MotorTab& getMotor1Tab();
    MotorFaultsTab& getMotor0FaultsTab();
    MotorFaultsTab& getMotor1FaultsTab();
    MpptTab& getMpptTab();

signals:
    void setAll(int packetNum);

private:
    PacketWindow* window_;
    QSignalMapper signalMapper;
};
