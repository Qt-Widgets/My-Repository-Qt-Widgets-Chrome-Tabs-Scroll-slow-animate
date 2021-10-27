#include <QApplication>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication *app = new QApplication(argc, argv);
    MainWindow *window = new MainWindow();
    window->show();
    app->exec();
    return 0;
}
