#include "AddPlayerDialog.h"

#include <QDialogButtonBox>

AddPlayerDialog::AddPlayerDialog(QWidget *parent) : QDialog(parent)
{
    layout = new QVBoxLayout(this);
    form = new AddPlayerForm(this);
    layout->addWidget(form);

    QDialogButtonBox *bb = new QDialogButtonBox(this);
    bb->addButton("OK", QDialogButtonBox::AcceptRole);
    bb->addButton("Abbrechen", QDialogButtonBox::RejectRole);
    connect(bb, &QDialogButtonBox::accepted, this, &AddPlayerDialog::accept);
    connect(bb, &QDialogButtonBox::rejected, this, &AddPlayerDialog::close);

    layout->addWidget(bb);
}

QList< QString > AddPlayerDialog::getPlayerList() { return form->getPlayerList(); }
