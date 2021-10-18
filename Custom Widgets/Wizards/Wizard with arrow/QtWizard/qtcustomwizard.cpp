#include "qtcustomwizard.h"

QtCustomWizard::QtCustomWizard(QWidget *parent) : QWizard(parent)
{
    setWizardStyle(QWizard::NStyles);
    setOption(QWizard::NoBackButtonOnStartPage);
}
