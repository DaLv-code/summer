#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(0,0,681,342);
    w.show();
    return a.exec();
}
