#include "SettingsDialog.h"

#include <SettingsForm.h>
#include <QDialogButtonBox>
#include <QVBoxLayout>

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent)
{
    SettingsForm *sw = new SettingsForm(this);
    QVBoxLayout *l = new QVBoxLayout();
    QDialogButtonBox *bb = new QDialogButtonBox(this);
    bb->addButton("OK", QDialogButtonBox::AcceptRole);
    bb->addButton("Abbrechen", QDialogButtonBox::RejectRole);
    connect(bb, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(bb, &QDialogButtonBox::rejected, this, &SettingsDialog::close);

    l->addWidget(sw);
    l->addWidget(bb);
    setLayout(l);
}
