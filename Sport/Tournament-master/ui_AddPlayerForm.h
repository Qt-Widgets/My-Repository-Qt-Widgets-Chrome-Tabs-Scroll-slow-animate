/********************************************************************************
** Form generated from reading UI file 'AddPlayerForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERFORM_H
#define UI_ADDPLAYERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AddPlayerWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddPlayerForm
{
public:
    QVBoxLayout *verticalLayout;
    AddPlayerWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *plusPushButton;
    QPushButton *minusPushButton_2;
    QPushButton *randomPushButton_3;
    QPushButton *generatePushButton_4;

    void setupUi(QWidget *AddPlayerForm)
    {
        if (AddPlayerForm->objectName().isEmpty())
            AddPlayerForm->setObjectName(QString::fromUtf8("AddPlayerForm"));
        AddPlayerForm->resize(687, 537);
        verticalLayout = new QVBoxLayout(AddPlayerForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new AddPlayerWidget(AddPlayerForm);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(AddPlayerForm);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plusPushButton = new QPushButton(widget_2);
        plusPushButton->setObjectName(QString::fromUtf8("plusPushButton"));

        horizontalLayout->addWidget(plusPushButton);

        minusPushButton_2 = new QPushButton(widget_2);
        minusPushButton_2->setObjectName(QString::fromUtf8("minusPushButton_2"));

        horizontalLayout->addWidget(minusPushButton_2);

        randomPushButton_3 = new QPushButton(widget_2);
        randomPushButton_3->setObjectName(QString::fromUtf8("randomPushButton_3"));

        horizontalLayout->addWidget(randomPushButton_3);

        generatePushButton_4 = new QPushButton(widget_2);
        generatePushButton_4->setObjectName(QString::fromUtf8("generatePushButton_4"));

        horizontalLayout->addWidget(generatePushButton_4);


        verticalLayout->addWidget(widget_2);


        retranslateUi(AddPlayerForm);

        QMetaObject::connectSlotsByName(AddPlayerForm);
    } // setupUi

    void retranslateUi(QWidget *AddPlayerForm)
    {
        AddPlayerForm->setWindowTitle(QCoreApplication::translate("AddPlayerForm", "Form", nullptr));
        plusPushButton->setText(QCoreApplication::translate("AddPlayerForm", "+", nullptr));
        minusPushButton_2->setText(QCoreApplication::translate("AddPlayerForm", "-", nullptr));
        randomPushButton_3->setText(QCoreApplication::translate("AddPlayerForm", "Random", nullptr));
        generatePushButton_4->setText(QCoreApplication::translate("AddPlayerForm", "Generate Tournament", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayerForm: public Ui_AddPlayerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERFORM_H
