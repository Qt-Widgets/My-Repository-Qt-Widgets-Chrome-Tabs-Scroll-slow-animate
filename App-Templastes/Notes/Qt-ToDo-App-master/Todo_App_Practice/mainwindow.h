#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "task.h"
#include <QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void update();

private slots:
    void on_pushButton_clicked();
    void onRemovedTask(Task *task);
    void onStatusChanged();

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;
};

#endif // MAINWINDOW_H
