#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include "SettingsData.h"

#include <QWidget>

namespace Ui
{
    class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT

  public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();

  private slots:
    void on_bg1pushButton_clicked();
    void on_bg1lineEdit_textChanged(const QString &arg1);


    void on_resetColorsPushButton_clicked();

    void on_bg2lineEdit_textChanged(const QString &arg1);

    void on_bg3lineEdit_textChanged(const QString &arg1);

    void on_bg4lineEdit_textChanged(const QString &arg1);

    void on_bg5lineEdit_textChanged(const QString &arg1);

    void on_bg6lineEdit_textChanged(const QString &arg1);

    void on_rbglineEdit_textChanged(const QString &arg1);

    void on_rbclineEdit_textChanged(const QString &arg1);

    void on_rlclineEdit_textChanged(const QString &arg1);

    void on_bg2pushButton_2_clicked();

    void on_bg3pushButton_3_clicked();

    void on_bg4pushButton_4_clicked();

    void on_bg5pushButton_5_clicked();

    void on_bg6pushButton_6_clicked();

    void on_rbgpushButton_7_clicked();

    void on_rbcpushButton_8_clicked();

    void on_rlcpushButton_9_clicked();

  private:
    Ui::SettingsForm *ui;
    SettingsData *sData = Q_NULLPTR;

    void init();

    QString lineEditArgToValidHexColor(const QString &col) const;
    QColor openColorChooserDialog(const QColor &currentColor) const;
};

#endif  // SETTINGSFORM_H
