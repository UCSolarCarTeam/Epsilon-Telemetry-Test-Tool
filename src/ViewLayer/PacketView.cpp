#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QRadioButton>
#include <QGroupBox>
#include "PacketView.h"
#include "PacketWindow.h"

#include <QDebug>

namespace
{
    const int BAUDRATE = 9600;
}

PacketView::PacketView(PacketWindow* window)
    : window_(window)
{

}
