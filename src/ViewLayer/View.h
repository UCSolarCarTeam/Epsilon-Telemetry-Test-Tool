#ifndef VIEW_H
#define VIEW_H

#include <QObject>
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
    View(QSerialPort& serialPort);
    void setConnectionStatus(bool connectionStatus);
    QString getModeSelected();
    QString getCommunicationPort();

private:
    void connectToUi();

signals:
    void attemptConnectionSignal();
    void differentModeSelectedSignal();
    void sendKeyDriverControlSignal();
    void sendDriverControlDetailsSignal();
    void sendFaultsSignal();
    void sendBatteryDataSignal();
    void sendCmuDataSignal();
    void sendMpptDataSignal();
    void sendAllSignal();


private:
    QSerialPort& serialPort_;
    Window* window_;

};

#endif // VIEW_H
