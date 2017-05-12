#pragma once

#include <QMainWindow>
#include <QList>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window(QList<QWidget*> widgets);
    virtual ~Window() {};
};
