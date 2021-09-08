/********************************************************************************
** Form generated from reading UI file 'previewimagedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWIMAGEDLG_H
#define UI_PREVIEWIMAGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_PreviewImageDlg
{
public:
    QLabel *wpLblImage;
    QLabel *wpLblIndex;
    QToolButton *wpTbtnLastImage;
    QToolButton *wpTbtnNextImage;

    void setupUi(QDialog *PreviewImageDlg)
    {
        if (PreviewImageDlg->objectName().isEmpty())
            PreviewImageDlg->setObjectName(QString::fromUtf8("PreviewImageDlg"));
        PreviewImageDlg->resize(600, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreviewImageDlg->sizePolicy().hasHeightForWidth());
        PreviewImageDlg->setSizePolicy(sizePolicy);
        PreviewImageDlg->setMinimumSize(QSize(300, 250));
        wpLblImage = new QLabel(PreviewImageDlg);
        wpLblImage->setObjectName(QString::fromUtf8("wpLblImage"));
        wpLblImage->setGeometry(QRect(10, 10, 800, 550));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wpLblImage->sizePolicy().hasHeightForWidth());
        wpLblImage->setSizePolicy(sizePolicy1);
        wpLblImage->setMinimumSize(QSize(800, 550));
        wpLblIndex = new QLabel(PreviewImageDlg);
        wpLblIndex->setObjectName(QString::fromUtf8("wpLblIndex"));
        wpLblIndex->setGeometry(QRect(320, 490, 54, 21));
        wpTbtnLastImage = new QToolButton(PreviewImageDlg);
        wpTbtnLastImage->setObjectName(QString::fromUtf8("wpTbtnLastImage"));
        wpTbtnLastImage->setGeometry(QRect(230, 490, 37, 18));
        wpTbtnNextImage = new QToolButton(PreviewImageDlg);
        wpTbtnNextImage->setObjectName(QString::fromUtf8("wpTbtnNextImage"));
        wpTbtnNextImage->setGeometry(QRect(410, 490, 37, 18));

        retranslateUi(PreviewImageDlg);

        QMetaObject::connectSlotsByName(PreviewImageDlg);
    } // setupUi

    void retranslateUi(QDialog *PreviewImageDlg)
    {
        PreviewImageDlg->setWindowTitle(QCoreApplication::translate("PreviewImageDlg", "Dialog", nullptr));
        wpLblImage->setText(QString());
        wpLblIndex->setText(QCoreApplication::translate("PreviewImageDlg", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        wpTbtnLastImage->setText(QCoreApplication::translate("PreviewImageDlg", "\342\227\200", nullptr));
        wpTbtnNextImage->setText(QCoreApplication::translate("PreviewImageDlg", "\342\226\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewImageDlg: public Ui_PreviewImageDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWIMAGEDLG_H
