/********************************************************************************
** Form generated from reading UI file 'wiringform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIRINGFORM_H
#define UI_WIRINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WiringForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *materialComboBox;
    QLabel *label_2;
    QLineEdit *currentEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *calcButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *wireSectionLabel;

    void setupUi(QWidget *WiringForm)
    {
        if (WiringForm->objectName().isEmpty())
            WiringForm->setObjectName(QString::fromUtf8("WiringForm"));
        WiringForm->resize(340, 188);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WiringForm->sizePolicy().hasHeightForWidth());
        WiringForm->setSizePolicy(sizePolicy);
        WiringForm->setMinimumSize(QSize(340, 0));
        verticalLayout = new QVBoxLayout(WiringForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(WiringForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setWordWrap(true);

        verticalLayout->addWidget(label_4);

        line = new QFrame(WiringForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(WiringForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        materialComboBox = new QComboBox(WiringForm);
        materialComboBox->addItem(QString());
        materialComboBox->addItem(QString());
        materialComboBox->setObjectName(QString::fromUtf8("materialComboBox"));

        gridLayout->addWidget(materialComboBox, 0, 1, 1, 1);

        label_2 = new QLabel(WiringForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        currentEdit = new QLineEdit(WiringForm);
        currentEdit->setObjectName(QString::fromUtf8("currentEdit"));

        gridLayout->addWidget(currentEdit, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        calcButton = new QPushButton(WiringForm);
        calcButton->setObjectName(QString::fromUtf8("calcButton"));

        horizontalLayout_4->addWidget(calcButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        label_3 = new QLabel(WiringForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        wireSectionLabel = new QLabel(WiringForm);
        wireSectionLabel->setObjectName(QString::fromUtf8("wireSectionLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wireSectionLabel->sizePolicy().hasHeightForWidth());
        wireSectionLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(wireSectionLabel, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(materialComboBox);
        label_2->setBuddy(currentEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(WiringForm);
        QObject::connect(currentEdit, SIGNAL(returnPressed()), calcButton, SLOT(click()));

        QMetaObject::connectSlotsByName(WiringForm);
    } // setupUi

    void retranslateUi(QWidget *WiringForm)
    {
        WiringForm->setWindowTitle(QApplication::translate("WiringForm", "\320\240\320\260\321\201\321\207\320\265\321\202 \320\277\321\200\320\276\320\262\320\276\320\264\320\272\320\270", nullptr));
        label_4->setText(QApplication::translate("WiringForm", "\320\240\320\260\321\201\321\207\320\265\321\202 \321\201\320\265\321\207\320\265\320\275\320\270\321\217 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260 \320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\262 \321\201 \321\200\320\265\320\267\320\270\320\275\320\276\320\262\320\276\320\271 \320\270\320\267\320\276\320\273\321\217\321\206\320\270\320\265\320\271 \320\264\320\273\321\217 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\264\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \321\202\320\276\320\272\320\260", nullptr));
        label->setText(QApplication::translate("WiringForm", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273:", nullptr));
        materialComboBox->setItemText(0, QApplication::translate("WiringForm", "\320\234\320\265\320\264\321\214", nullptr));
        materialComboBox->setItemText(1, QApplication::translate("WiringForm", "\320\220\320\273\321\216\320\274\320\270\320\275\320\270\320\271", nullptr));

        label_2->setText(QApplication::translate("WiringForm", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \321\202\320\276\320\272 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\270, \320\220:", nullptr));
        calcButton->setText(QApplication::translate("WiringForm", "\320\240\320\260\321\201\321\207\320\265\321\202", nullptr));
        label_3->setText(QApplication::translate("WiringForm", "\320\241\320\265\321\207\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\262\320\276\320\264\320\260, \320\274\320\274\302\262:", nullptr));
        wireSectionLabel->setText(QApplication::translate("WiringForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WiringForm: public Ui_WiringForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIRINGFORM_H
