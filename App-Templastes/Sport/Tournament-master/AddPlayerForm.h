#ifndef ADDPLAYERFORM_H
#define ADDPLAYERFORM_H

#include <QWidget>

namespace Ui
{
    class AddPlayerForm;
}

class AddPlayerForm : public QWidget
{
    Q_OBJECT

  public:
    explicit AddPlayerForm(QWidget *parent = nullptr);
    ~AddPlayerForm();

    QList< QString > getPlayerList();

  private slots:
    void on_plusPushButton_clicked();

    void on_minusPushButton_2_clicked();

    void on_randomPushButton_3_clicked();

  private:
    Ui::AddPlayerForm *ui;
};

#endif  // ADDPLAYERFORM_H
