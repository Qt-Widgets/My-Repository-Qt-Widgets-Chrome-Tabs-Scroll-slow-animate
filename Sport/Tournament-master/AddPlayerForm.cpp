#include "AddPlayerForm.h"
#include "ui_AddPlayerForm.h"

#include <QRandomGenerator>

AddPlayerForm::AddPlayerForm(QWidget *parent) : QWidget(parent), ui(new Ui::AddPlayerForm) { ui->setupUi(this); }

AddPlayerForm::~AddPlayerForm() { delete ui; }

QList< QString > AddPlayerForm::getPlayerList() { return ui->widget->getPlayerNames(); }

void AddPlayerForm::on_plusPushButton_clicked() { ui->widget->addPlayerLineEdit(); }

void AddPlayerForm::on_minusPushButton_2_clicked() { ui->widget->removePlayerLineEdit(); }

void AddPlayerForm::on_randomPushButton_3_clicked()
{
    QRandomGenerator *generator = QRandomGenerator::system();
    int playerCount = generator->bounded(3, 25);

    QList< QString > names;

    for (int i = 1; i <= playerCount; i++)
    {
        QString name = "Player ";
        name += QString::number(i);
        names << name;
    }
    ui->widget->randomise(names);
}
