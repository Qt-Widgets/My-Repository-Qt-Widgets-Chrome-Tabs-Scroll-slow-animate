#include "SettingsForm.h"
#include "ui_SettingsForm.h"

#include "Settings.h"

#include <QColorDialog>

SettingsForm::SettingsForm(QWidget *parent) : QWidget(parent), ui(new Ui::SettingsForm)
{
    ui->setupUi(this);

    sData = Settings::instance()->getSettingsData();

    init();
}

SettingsForm::~SettingsForm()
{
    delete ui;
    delete sData;
}

void SettingsForm::init()
{
    ui->bg1lineEdit->setText(sData->getBackgroundColor1().name());
    ui->bg2lineEdit->setText(sData->getBackgroundColor2().name());
    ui->bg3lineEdit->setText(sData->getBackgroundColor3().name());
    ui->bg4lineEdit->setText(sData->getBackgroundColor4().name());
    ui->bg5lineEdit->setText(sData->getBackgroundColor5().name());
    ui->bg6lineEdit->setText(sData->getBackgroundColor6().name());

    ui->rbglineEdit->setText(sData->getRoundsBackgroundColor().name());
    ui->rbclineEdit->setText(sData->getRoundsBorderColor().name());
    ui->rlclineEdit->setText(sData->getRoundsLineColor().name());

    ui->bg1lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor1().name()));
    ui->bg2lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor2().name()));
    ui->bg3lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor3().name()));
    ui->bg4lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor4().name()));
    ui->bg5lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor5().name()));
    ui->bg6lineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getBackgroundColor6().name()));

    ui->rbglineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getRoundsBackgroundColor().name()));
    ui->rbclineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getRoundsBorderColor().name()));
    ui->rlclineEdit->setStyleSheet(lineEditArgToValidHexColor(sData->getRoundsLineColor().name()));
}

void SettingsForm::on_resetColorsPushButton_clicked()
{
    sData->resetColors();
    init();
}

QString SettingsForm::lineEditArgToValidHexColor(const QString &col) const
{
    QString colName = col;
    while (colName.size() < 6)
        colName += "0";
    QString n_col = "Background-color: " + colName;
    return n_col;
}

QColor SettingsForm::openColorChooserDialog(const QColor &currentColor) const
{
    QColorDialog dia;
    dia.setCurrentColor(currentColor);
    if (dia.exec() == QColorDialog::Accepted)
    {
        return dia.currentColor();
    }

    return QColor("#31c926");  // Random Green
}

void SettingsForm::on_bg1pushButton_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor1());
    ui->bg1lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg1lineEdit->setText(n_Col.name());
    sData->setBackgroundColor1(n_Col);
}

void SettingsForm::on_bg2pushButton_2_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor2());
    ui->bg2lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg2lineEdit->setText(n_Col.name());
    sData->setBackgroundColor2(n_Col);
}

void SettingsForm::on_bg3pushButton_3_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor3());
    ui->bg3lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg3lineEdit->setText(n_Col.name());
    sData->setBackgroundColor3(n_Col);
}

void SettingsForm::on_bg4pushButton_4_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor4());
    ui->bg4lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg4lineEdit->setText(n_Col.name());
    sData->setBackgroundColor4(n_Col);
}

void SettingsForm::on_bg5pushButton_5_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor5());
    ui->bg5lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg5lineEdit->setText(n_Col.name());
    sData->setBackgroundColor5(n_Col);
}

void SettingsForm::on_bg6pushButton_6_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getBackgroundColor6());
    ui->bg6lineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->bg6lineEdit->setText(n_Col.name());
    sData->setBackgroundColor6(n_Col);
}

void SettingsForm::on_rbgpushButton_7_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getRoundsBackgroundColor());
    ui->rbglineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->rbglineEdit->setText(n_Col.name());
    sData->setRoundsBackgroundColor(n_Col);
}

void SettingsForm::on_rbcpushButton_8_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getRoundsBorderColor());
    ui->rbclineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->rbclineEdit->setText(n_Col.name());
    sData->setRoundsBorderColor(n_Col);
}

void SettingsForm::on_rlcpushButton_9_clicked()
{
    QColor n_Col = openColorChooserDialog(sData->getRoundsLineColor());
    ui->rlclineEdit->setStyleSheet("Background-color: " + n_Col.name());
    ui->rlclineEdit->setText(n_Col.name());
    sData->setRoundsLineColor(n_Col);
}

void SettingsForm::on_bg1lineEdit_textChanged(const QString &arg1) { ui->bg1lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_bg2lineEdit_textChanged(const QString &arg1) { ui->bg2lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_bg3lineEdit_textChanged(const QString &arg1) { ui->bg3lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_bg4lineEdit_textChanged(const QString &arg1) { ui->bg4lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_bg5lineEdit_textChanged(const QString &arg1) { ui->bg5lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_bg6lineEdit_textChanged(const QString &arg1) { ui->bg6lineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_rbglineEdit_textChanged(const QString &arg1) { ui->rbglineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_rbclineEdit_textChanged(const QString &arg1) { ui->rbclineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }

void SettingsForm::on_rlclineEdit_textChanged(const QString &arg1) { ui->rlclineEdit->setStyleSheet(lineEditArgToValidHexColor("#" + arg1)); }
