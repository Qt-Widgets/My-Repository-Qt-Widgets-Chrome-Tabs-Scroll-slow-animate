#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    int completedCount = 0;
    for(auto t : mTasks)
    {
        if(t->isCompleted())
        {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;

    ui->label->setText(QString("Status: %1 todo / %2 Completed").arg(todoCount).arg(completedCount));
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add Task", "Task Name", QLineEdit::Normal, "Untitled task", &ok);
    if(ok && !name.isEmpty())
    {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removeTask, this, &MainWindow::onRemovedTask);
        connect(task, &Task::statusChanged, this, &MainWindow::onStatusChanged);
        mTasks.append(task);
        ui->verticalLayout->addWidget(task);
        this->update();
    }
}

void MainWindow::onRemovedTask(Task *task)
{
    mTasks.removeOne(task);
    ui->verticalLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    this->update();
}

void MainWindow::onStatusChanged()
{
    this->update();
}
