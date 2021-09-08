/********************************************************************************
** Form generated from reading UI file 'SettingsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFORM_H
#define UI_SETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsForm
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *colorsTab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *bg1lineEdit;
    QPushButton *bg1pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *bg2lineEdit;
    QPushButton *bg2pushButton_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *bg3lineEdit;
    QPushButton *bg3pushButton_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *bg4lineEdit;
    QPushButton *bg4pushButton_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *bg5lineEdit;
    QPushButton *bg5pushButton_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *bg6lineEdit;
    QPushButton *bg6pushButton_6;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *rbglineEdit;
    QPushButton *rbgpushButton_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *rbclineEdit;
    QPushButton *rbcpushButton_8;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *rlclineEdit;
    QPushButton *rlcpushButton_9;
    QWidget *resetTab;
    QVBoxLayout *verticalLayout_3;
    QPushButton *resetColorsPushButton;

    void setupUi(QWidget *SettingsForm)
    {
        if (SettingsForm->objectName().isEmpty())
            SettingsForm->setObjectName(QString::fromUtf8("SettingsForm"));
        SettingsForm->resize(363, 566);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsForm->sizePolicy().hasHeightForWidth());
        SettingsForm->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SettingsForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(SettingsForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        colorsTab = new QWidget();
        colorsTab->setObjectName(QString::fromUtf8("colorsTab"));
        verticalLayout_2 = new QVBoxLayout(colorsTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(colorsTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        bg1lineEdit = new QLineEdit(widget);
        bg1lineEdit->setObjectName(QString::fromUtf8("bg1lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bg1lineEdit->sizePolicy().hasHeightForWidth());
        bg1lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(bg1lineEdit);

        bg1pushButton = new QPushButton(widget);
        bg1pushButton->setObjectName(QString::fromUtf8("bg1pushButton"));
        sizePolicy1.setHeightForWidth(bg1pushButton->sizePolicy().hasHeightForWidth());
        bg1pushButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/rgb.svg"), QSize(), QIcon::Normal, QIcon::Off);
        bg1pushButton->setIcon(icon);

        horizontalLayout->addWidget(bg1pushButton);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(colorsTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        bg2lineEdit = new QLineEdit(widget_2);
        bg2lineEdit->setObjectName(QString::fromUtf8("bg2lineEdit"));
        sizePolicy1.setHeightForWidth(bg2lineEdit->sizePolicy().hasHeightForWidth());
        bg2lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(bg2lineEdit);

        bg2pushButton_2 = new QPushButton(widget_2);
        bg2pushButton_2->setObjectName(QString::fromUtf8("bg2pushButton_2"));
        sizePolicy1.setHeightForWidth(bg2pushButton_2->sizePolicy().hasHeightForWidth());
        bg2pushButton_2->setSizePolicy(sizePolicy1);
        bg2pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(bg2pushButton_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(colorsTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        bg3lineEdit = new QLineEdit(widget_3);
        bg3lineEdit->setObjectName(QString::fromUtf8("bg3lineEdit"));
        sizePolicy1.setHeightForWidth(bg3lineEdit->sizePolicy().hasHeightForWidth());
        bg3lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(bg3lineEdit);

        bg3pushButton_3 = new QPushButton(widget_3);
        bg3pushButton_3->setObjectName(QString::fromUtf8("bg3pushButton_3"));
        sizePolicy1.setHeightForWidth(bg3pushButton_3->sizePolicy().hasHeightForWidth());
        bg3pushButton_3->setSizePolicy(sizePolicy1);
        bg3pushButton_3->setIcon(icon);

        horizontalLayout_3->addWidget(bg3pushButton_3);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(colorsTab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        bg4lineEdit = new QLineEdit(widget_4);
        bg4lineEdit->setObjectName(QString::fromUtf8("bg4lineEdit"));
        sizePolicy1.setHeightForWidth(bg4lineEdit->sizePolicy().hasHeightForWidth());
        bg4lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(bg4lineEdit);

        bg4pushButton_4 = new QPushButton(widget_4);
        bg4pushButton_4->setObjectName(QString::fromUtf8("bg4pushButton_4"));
        sizePolicy1.setHeightForWidth(bg4pushButton_4->sizePolicy().hasHeightForWidth());
        bg4pushButton_4->setSizePolicy(sizePolicy1);
        bg4pushButton_4->setIcon(icon);

        horizontalLayout_4->addWidget(bg4pushButton_4);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(colorsTab);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        bg5lineEdit = new QLineEdit(widget_5);
        bg5lineEdit->setObjectName(QString::fromUtf8("bg5lineEdit"));
        sizePolicy1.setHeightForWidth(bg5lineEdit->sizePolicy().hasHeightForWidth());
        bg5lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(bg5lineEdit);

        bg5pushButton_5 = new QPushButton(widget_5);
        bg5pushButton_5->setObjectName(QString::fromUtf8("bg5pushButton_5"));
        sizePolicy1.setHeightForWidth(bg5pushButton_5->sizePolicy().hasHeightForWidth());
        bg5pushButton_5->setSizePolicy(sizePolicy1);
        bg5pushButton_5->setIcon(icon);

        horizontalLayout_5->addWidget(bg5pushButton_5);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(colorsTab);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        bg6lineEdit = new QLineEdit(widget_6);
        bg6lineEdit->setObjectName(QString::fromUtf8("bg6lineEdit"));
        sizePolicy1.setHeightForWidth(bg6lineEdit->sizePolicy().hasHeightForWidth());
        bg6lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(bg6lineEdit);

        bg6pushButton_6 = new QPushButton(widget_6);
        bg6pushButton_6->setObjectName(QString::fromUtf8("bg6pushButton_6"));
        sizePolicy1.setHeightForWidth(bg6pushButton_6->sizePolicy().hasHeightForWidth());
        bg6pushButton_6->setSizePolicy(sizePolicy1);
        bg6pushButton_6->setIcon(icon);

        horizontalLayout_6->addWidget(bg6pushButton_6);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(colorsTab);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        rbglineEdit = new QLineEdit(widget_7);
        rbglineEdit->setObjectName(QString::fromUtf8("rbglineEdit"));
        sizePolicy1.setHeightForWidth(rbglineEdit->sizePolicy().hasHeightForWidth());
        rbglineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(rbglineEdit);

        rbgpushButton_7 = new QPushButton(widget_7);
        rbgpushButton_7->setObjectName(QString::fromUtf8("rbgpushButton_7"));
        sizePolicy1.setHeightForWidth(rbgpushButton_7->sizePolicy().hasHeightForWidth());
        rbgpushButton_7->setSizePolicy(sizePolicy1);
        rbgpushButton_7->setIcon(icon);

        horizontalLayout_7->addWidget(rbgpushButton_7);


        verticalLayout_2->addWidget(widget_7);

        widget_8 = new QWidget(colorsTab);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(widget_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        rbclineEdit = new QLineEdit(widget_8);
        rbclineEdit->setObjectName(QString::fromUtf8("rbclineEdit"));
        sizePolicy1.setHeightForWidth(rbclineEdit->sizePolicy().hasHeightForWidth());
        rbclineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(rbclineEdit);

        rbcpushButton_8 = new QPushButton(widget_8);
        rbcpushButton_8->setObjectName(QString::fromUtf8("rbcpushButton_8"));
        sizePolicy1.setHeightForWidth(rbcpushButton_8->sizePolicy().hasHeightForWidth());
        rbcpushButton_8->setSizePolicy(sizePolicy1);
        rbcpushButton_8->setIcon(icon);

        horizontalLayout_8->addWidget(rbcpushButton_8);


        verticalLayout_2->addWidget(widget_8);

        widget_9 = new QWidget(colorsTab);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(widget_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        rlclineEdit = new QLineEdit(widget_9);
        rlclineEdit->setObjectName(QString::fromUtf8("rlclineEdit"));
        sizePolicy1.setHeightForWidth(rlclineEdit->sizePolicy().hasHeightForWidth());
        rlclineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(rlclineEdit);

        rlcpushButton_9 = new QPushButton(widget_9);
        rlcpushButton_9->setObjectName(QString::fromUtf8("rlcpushButton_9"));
        sizePolicy1.setHeightForWidth(rlcpushButton_9->sizePolicy().hasHeightForWidth());
        rlcpushButton_9->setSizePolicy(sizePolicy1);
        rlcpushButton_9->setIcon(icon);

        horizontalLayout_9->addWidget(rlcpushButton_9);


        verticalLayout_2->addWidget(widget_9);

        tabWidget->addTab(colorsTab, QString());
        resetTab = new QWidget();
        resetTab->setObjectName(QString::fromUtf8("resetTab"));
        verticalLayout_3 = new QVBoxLayout(resetTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        resetColorsPushButton = new QPushButton(resetTab);
        resetColorsPushButton->setObjectName(QString::fromUtf8("resetColorsPushButton"));

        verticalLayout_3->addWidget(resetColorsPushButton);

        tabWidget->addTab(resetTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(SettingsForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsForm);
    } // setupUi

    void retranslateUi(QWidget *SettingsForm)
    {
        SettingsForm->setWindowTitle(QCoreApplication::translate("SettingsForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("SettingsForm", "Background Color 1", nullptr));
        bg1lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg1lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg1pushButton->setText(QString());
        label_3->setText(QCoreApplication::translate("SettingsForm", "Background Color 2", nullptr));
        bg2lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg2lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg2pushButton_2->setText(QString());
        label_4->setText(QCoreApplication::translate("SettingsForm", "Background Color 3", nullptr));
        bg3lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg3lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg3pushButton_3->setText(QString());
        label_5->setText(QCoreApplication::translate("SettingsForm", "Backround Color 4", nullptr));
        bg4lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg4lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg4pushButton_4->setText(QString());
        label_6->setText(QCoreApplication::translate("SettingsForm", "Backround Color 5", nullptr));
        bg5lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg5lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg5pushButton_5->setText(QString());
        label_7->setText(QCoreApplication::translate("SettingsForm", "Backround Color 6", nullptr));
        bg6lineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        bg6lineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        bg6pushButton_6->setText(QString());
        label_8->setText(QCoreApplication::translate("SettingsForm", "Rounds Background Color", nullptr));
        rbglineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        rbglineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        rbgpushButton_7->setText(QString());
        label_9->setText(QCoreApplication::translate("SettingsForm", "Rounds Border Color", nullptr));
        rbclineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        rbclineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        rbcpushButton_8->setText(QString());
        label_10->setText(QCoreApplication::translate("SettingsForm", "Rounds Line Color", nullptr));
        rlclineEdit->setInputMask(QCoreApplication::translate("SettingsForm", "HHHHHH", nullptr));
        rlclineEdit->setPlaceholderText(QCoreApplication::translate("SettingsForm", "#", nullptr));
        rlcpushButton_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(colorsTab), QCoreApplication::translate("SettingsForm", "Colors", nullptr));
        resetColorsPushButton->setText(QCoreApplication::translate("SettingsForm", "Reset Colors", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(resetTab), QCoreApplication::translate("SettingsForm", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsForm: public Ui_SettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFORM_H
