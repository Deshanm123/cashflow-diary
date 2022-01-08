#include "mainwindow.h"
//#include <dbmanager.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//test
//     DbManager db;
    return a.exec();
}
