#include "mainwindow1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow1 w;
    w.show();
    return a.exec();
}
