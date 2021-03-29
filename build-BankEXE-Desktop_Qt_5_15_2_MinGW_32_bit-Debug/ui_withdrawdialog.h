/********************************************************************************
** Form generated from reading UI file 'withdrawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWDIALOG_H
#define UI_WITHDRAWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_WithdrawDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *button200;
    QPushButton *button60;
    QPushButton *button20;
    QPushButton *button100;
    QPushButton *button500;
    QLabel *headerLabel;
    QPushButton *button40;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonOther;
    QSpacerItem *verticalSpacer_4;
    QPushButton *buttonClose;

    void setupUi(QDialog *WithdrawDialog)
    {
        if (WithdrawDialog->objectName().isEmpty())
            WithdrawDialog->setObjectName(QString::fromUtf8("WithdrawDialog"));
        WithdrawDialog->resize(486, 230);
        gridLayout_2 = new QGridLayout(WithdrawDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 1, 1, 1);

        button200 = new QPushButton(WithdrawDialog);
        button200->setObjectName(QString::fromUtf8("button200"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        button200->setFont(font);

        gridLayout->addWidget(button200, 2, 2, 1, 1);

        button60 = new QPushButton(WithdrawDialog);
        button60->setObjectName(QString::fromUtf8("button60"));
        button60->setFont(font);

        gridLayout->addWidget(button60, 3, 0, 1, 1);

        button20 = new QPushButton(WithdrawDialog);
        button20->setObjectName(QString::fromUtf8("button20"));
        button20->setFont(font);

        gridLayout->addWidget(button20, 1, 0, 1, 1);

        button100 = new QPushButton(WithdrawDialog);
        button100->setObjectName(QString::fromUtf8("button100"));
        button100->setFont(font);

        gridLayout->addWidget(button100, 1, 2, 1, 1);

        button500 = new QPushButton(WithdrawDialog);
        button500->setObjectName(QString::fromUtf8("button500"));
        button500->setFont(font);

        gridLayout->addWidget(button500, 3, 2, 1, 1);

        headerLabel = new QLabel(WithdrawDialog);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        headerLabel->setFont(font1);
        headerLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(headerLabel, 0, 1, 1, 1);

        button40 = new QPushButton(WithdrawDialog);
        button40->setObjectName(QString::fromUtf8("button40"));
        button40->setFont(font);

        gridLayout->addWidget(button40, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        buttonOther = new QPushButton(WithdrawDialog);
        buttonOther->setObjectName(QString::fromUtf8("buttonOther"));
        buttonOther->setFont(font);

        gridLayout->addWidget(buttonOther, 4, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        buttonClose = new QPushButton(WithdrawDialog);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setFont(font);

        gridLayout->addWidget(buttonClose, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WithdrawDialog);

        QMetaObject::connectSlotsByName(WithdrawDialog);
    } // setupUi

    void retranslateUi(QDialog *WithdrawDialog)
    {
        WithdrawDialog->setWindowTitle(QCoreApplication::translate("WithdrawDialog", "Dialog", nullptr));
        button200->setText(QCoreApplication::translate("WithdrawDialog", "200\342\202\254", nullptr));
        button60->setText(QCoreApplication::translate("WithdrawDialog", "60\342\202\254", nullptr));
        button20->setText(QCoreApplication::translate("WithdrawDialog", "20\342\202\254", nullptr));
        button100->setText(QCoreApplication::translate("WithdrawDialog", "100\342\202\254", nullptr));
        button500->setText(QCoreApplication::translate("WithdrawDialog", "500\342\202\254", nullptr));
        headerLabel->setText(QCoreApplication::translate("WithdrawDialog", "Nosta rahaa:", nullptr));
        button40->setText(QCoreApplication::translate("WithdrawDialog", "40\342\202\254", nullptr));
        buttonOther->setText(QCoreApplication::translate("WithdrawDialog", "Muu summa", nullptr));
        buttonClose->setText(QCoreApplication::translate("WithdrawDialog", "Sulje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawDialog: public Ui_WithdrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWDIALOG_H
