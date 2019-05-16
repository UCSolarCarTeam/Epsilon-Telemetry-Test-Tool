#include <QTabWidget>
#include <QScopedPointer>
#include "Window.h"

Window::Window(QList<QWidget*> widgets)
{
    setWindowTitle("Telem Test Program");
    setMinimumSize(900, 500);
    setMaximumSize(1920, 1080);
    QTabWidget* mainWidget = new QTabWidget(this);

    foreach (QWidget* widget, widgets)
    {
        mainWidget->addTab(widget, widget->windowTitle());
    }

    setCentralWidget(mainWidget);
    show();
}
