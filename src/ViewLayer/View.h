#ifndef VIEW_H
#define VIEW_H

#include <QObject>
class QSerialPort;
class Window;
class WindowDesign;
class QPushButton;
class QComboBox;
class QLineEdit;
class QLabel;

class View : public QObject
{
    Q_OBJECT
public:
    View(Window& window);
    void setConnectionStatus(bool connectionStatus);
    QString getCommunicationPort();
    QString getModeSelected();

private:
    void connectToUi();
    void connectTest();

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
    Window& window_;
    WindowDesign* windowDesign_;
};

#endif // VIEW_H
