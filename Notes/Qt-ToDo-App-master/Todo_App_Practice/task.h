#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QInputDialog>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name, QWidget *parent = 0);
    ~Task();

    void setName(const QString& name);
    QString getName()const;

    bool isCompleted();

signals:
    void removeTask(Task *task);
    void statusChanged(Task* task);

private slots:
    void on_Edit_pushButton_clicked();

    void on_Remove_pushButton_2_clicked();

    void checked(bool checked);

private:
    Ui::Task *ui;
};

#endif // TASK_H
