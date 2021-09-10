#include "task.h"
#include "ui_task.h"
#include <QFont>

Task::Task(const QString & name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    this->setName(name);
    connect(ui->checkBox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->checkBox->setText(name);
}

QString Task::getName() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted()
{
    return ui->checkBox->isChecked();
}

void Task::on_Edit_pushButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Edit Task", "Task Name", QLineEdit::Normal, this->getName(), &ok);
    if(ok && !name.isEmpty())
    {
        setName(name);
    }
}

void Task::on_Remove_pushButton_2_clicked()
{
    emit removeTask(this);

}

void Task::checked(bool checked)
{
    QFont font(ui->checkBox->font());
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}
