#include "PacketWindow.h"
#include "ui_PacketWindow.h"

PacketWindow::PacketWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PacketWindow)
{
    ui->setupUi(this);
}

PacketWindow::~PacketWindow()
{
    delete ui;
}
