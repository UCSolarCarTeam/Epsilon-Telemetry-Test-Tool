#ifndef VIEW_H
#define VIEW_H

#include <QObject>
class TelemetryReporting;
class CommunicationServer;
class QSerialPort;
class Window;
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;

class View : public QObject
{
    Q_OBJECT
public:
    View(QSerialPort& serialPort, TelemetryReporting& telemetryReporting);

private:
    void connectSlots();

private slots:
    void attemptConnection();
    void differentModeSelected();
    void sendKeyDriverControl();
    void sendDriverControlDetails();
    void sendFaults();
    void sendBatteryData();
    void sendCmuData();
    void sendMpptData();
    void sendAll();


private:
    QSerialPort& serialPort_;
    TelemetryReporting& telemetryReporting_;
    Window* window_;

};

#endif // VIEW_H
