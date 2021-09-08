#include "mainsite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSite w;
    w.show();

    return a.exec();
}
