/********************************************************************************
** Form generated from reading UI file 'mainsite.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSITE_H
#define UI_MAINSITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MainSite
{
public:
    QLabel *mLblTitle;

    void setupUi(QDialog *MainSite)
    {
        if (MainSite->objectName().isEmpty())
            MainSite->setObjectName(QString::fromUtf8("MainSite"));
        MainSite->resize(600, 500);
        mLblTitle = new QLabel(MainSite);
        mLblTitle->setObjectName(QString::fromUtf8("mLblTitle"));
        mLblTitle->setGeometry(QRect(10, 0, 211, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(22);
        mLblTitle->setFont(font);

        retranslateUi(MainSite);

        QMetaObject::connectSlotsByName(MainSite);
    } // setupUi

    void retranslateUi(QDialog *MainSite)
    {
        MainSite->setWindowTitle(QCoreApplication::translate("MainSite", "MainSite", nullptr));
        mLblTitle->setText(QCoreApplication::translate("MainSite", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#0055ff;\">\346\227\205\346\270\270\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSite: public Ui_MainSite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSITE_H
