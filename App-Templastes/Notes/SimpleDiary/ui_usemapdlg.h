/********************************************************************************
** Form generated from reading UI file 'usemapdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEMAPDLG_H
#define UI_USEMAPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_UseMapDlg
{
public:

    void setupUi(QDialog *UseMapDlg)
    {
        if (UseMapDlg->objectName().isEmpty())
            UseMapDlg->setObjectName(QString::fromUtf8("UseMapDlg"));
        UseMapDlg->resize(600, 500);

        retranslateUi(UseMapDlg);

        QMetaObject::connectSlotsByName(UseMapDlg);
    } // setupUi

    void retranslateUi(QDialog *UseMapDlg)
    {
        UseMapDlg->setWindowTitle(QCoreApplication::translate("UseMapDlg", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UseMapDlg: public Ui_UseMapDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEMAPDLG_H
