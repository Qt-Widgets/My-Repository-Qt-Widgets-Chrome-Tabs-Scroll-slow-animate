/********************************************************************************
** Form generated from reading UI file 'showfiledlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWFILEDLG_H
#define UI_SHOWFILEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ShowFileDlg
{
public:
    QLabel *shLblTitle;
    QLabel *shLblDatePlace;
    QPushButton *shBtnSeeImage;
    QPushButton *shBtnEdit;
    QPushButton *shBtnDelete;
    QPushButton *shBtnReturn;
    QTextEdit *shTetText;

    void setupUi(QDialog *ShowFileDlg)
    {
        if (ShowFileDlg->objectName().isEmpty())
            ShowFileDlg->setObjectName(QString::fromUtf8("ShowFileDlg"));
        ShowFileDlg->resize(600, 500);
        shLblTitle = new QLabel(ShowFileDlg);
        shLblTitle->setObjectName(QString::fromUtf8("shLblTitle"));
        shLblTitle->setGeometry(QRect(160, 10, 251, 21));
        shLblDatePlace = new QLabel(ShowFileDlg);
        shLblDatePlace->setObjectName(QString::fromUtf8("shLblDatePlace"));
        shLblDatePlace->setGeometry(QRect(200, 50, 54, 20));
        shBtnSeeImage = new QPushButton(ShowFileDlg);
        shBtnSeeImage->setObjectName(QString::fromUtf8("shBtnSeeImage"));
        shBtnSeeImage->setGeometry(QRect(330, 50, 75, 23));
        shBtnEdit = new QPushButton(ShowFileDlg);
        shBtnEdit->setObjectName(QString::fromUtf8("shBtnEdit"));
        shBtnEdit->setGeometry(QRect(20, 430, 75, 23));
        shBtnDelete = new QPushButton(ShowFileDlg);
        shBtnDelete->setObjectName(QString::fromUtf8("shBtnDelete"));
        shBtnDelete->setGeometry(QRect(110, 430, 75, 23));
        shBtnReturn = new QPushButton(ShowFileDlg);
        shBtnReturn->setObjectName(QString::fromUtf8("shBtnReturn"));
        shBtnReturn->setGeometry(QRect(500, 430, 75, 23));
        shTetText = new QTextEdit(ShowFileDlg);
        shTetText->setObjectName(QString::fromUtf8("shTetText"));
        shTetText->setGeometry(QRect(20, 80, 561, 341));

        retranslateUi(ShowFileDlg);
        QObject::connect(shBtnReturn, SIGNAL(clicked()), ShowFileDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(ShowFileDlg);
    } // setupUi

    void retranslateUi(QDialog *ShowFileDlg)
    {
        ShowFileDlg->setWindowTitle(QCoreApplication::translate("ShowFileDlg", "Dialog", nullptr));
        shLblTitle->setText(QCoreApplication::translate("ShowFileDlg", "TextLabel", nullptr));
        shLblDatePlace->setText(QCoreApplication::translate("ShowFileDlg", "TextLabel", nullptr));
        shBtnSeeImage->setText(QCoreApplication::translate("ShowFileDlg", "\346\237\245\347\234\213\347\233\270\345\206\214", nullptr));
        shBtnEdit->setText(QCoreApplication::translate("ShowFileDlg", "\347\274\226\350\276\221", nullptr));
        shBtnDelete->setText(QCoreApplication::translate("ShowFileDlg", "\345\210\240\351\231\244", nullptr));
        shBtnReturn->setText(QCoreApplication::translate("ShowFileDlg", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowFileDlg: public Ui_ShowFileDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFILEDLG_H
