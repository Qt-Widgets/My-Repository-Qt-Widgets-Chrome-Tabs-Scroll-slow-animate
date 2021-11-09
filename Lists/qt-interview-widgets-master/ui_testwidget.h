/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QString::fromUtf8("TestWidget"));
        TestWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(TestWidget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(TestWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(TestWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(TestWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QCoreApplication::translate("TestWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("TestWidget", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("TestWidget", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
