#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include "AddPlayerForm.h"

#include <QVBoxLayout>
#include <QDialog>

class AddPlayerDialog : public QDialog
{
  public:
    AddPlayerDialog(QWidget *parent = Q_NULLPTR);

    QList< QString > getPlayerList();

  private:
    QVBoxLayout *layout = Q_NULLPTR;

    AddPlayerForm *form = Q_NULLPTR;
};

#endif  // ADDPLAYERDIALOG_H
