#ifndef PACKETWINDOW_H
#define PACKETWINDOW_H

#include <QDialog>

namespace Ui {
class PacketWindow;
}

class PacketWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PacketWindow(QWidget *parent = 0);
    ~PacketWindow();

private:
    Ui::PacketWindow *ui;
};

#endif // PACKETWINDOW_H
