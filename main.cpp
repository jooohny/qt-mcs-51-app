#include "mainwindow.h"
#include <QApplication>

#include "MenuStyle.h"

#include "memorywindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new MenuStyle());
    FrontWindow w("MCS-51 IDE");
    QDir::setCurrent(QDir::homePath());
    w.setMinimumHeight(800);
    w.setMinimumWidth(1200);
    w.show();
    return a.exec();
}
