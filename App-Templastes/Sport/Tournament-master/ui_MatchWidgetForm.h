/********************************************************************************
** Form generated from reading UI file 'MatchWidgetForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHWIDGETFORM_H
#define UI_MATCHWIDGETFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PointsWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MatchWidgetForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    PointsWidget *widget_4;
    QFrame *line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    PointsWidget *widget_6;

    void setupUi(QWidget *MatchWidgetForm)
    {
        if (MatchWidgetForm->objectName().isEmpty())
            MatchWidgetForm->setObjectName(QString::fromUtf8("MatchWidgetForm"));
        MatchWidgetForm->resize(745, 367);
        MatchWidgetForm->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(MatchWidgetForm);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 2, 0, 2);
        widget = new QWidget(MatchWidgetForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_2->addWidget(label);


        horizontalLayout->addWidget(widget_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_4 = new PointsWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);

        line = new QFrame(MatchWidgetForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget_2 = new QWidget(MatchWidgetForm);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 5, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout_2->addWidget(widget_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget_6 = new PointsWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy1.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(widget_6);


        verticalLayout->addWidget(widget_2);


        retranslateUi(MatchWidgetForm);

        QMetaObject::connectSlotsByName(MatchWidgetForm);
    } // setupUi

    void retranslateUi(QWidget *MatchWidgetForm)
    {
        MatchWidgetForm->setWindowTitle(QCoreApplication::translate("MatchWidgetForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("MatchWidgetForm", "---", nullptr));
        label_2->setText(QCoreApplication::translate("MatchWidgetForm", "---", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatchWidgetForm: public Ui_MatchWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHWIDGETFORM_H
