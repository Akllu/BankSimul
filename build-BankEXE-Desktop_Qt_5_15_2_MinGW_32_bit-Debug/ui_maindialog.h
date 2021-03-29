/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *balanceButton;
    QLabel *headerLabel;
    QPushButton *transactionButton;
    QPushButton *withdrawButton;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer;
    QPushButton *transferButton;
    QLabel *infoLabel;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
        MainDialog->resize(550, 350);
        verticalLayout = new QVBoxLayout(MainDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        balanceButton = new QPushButton(MainDialog);
        balanceButton->setObjectName(QString::fromUtf8("balanceButton"));

        gridLayout->addWidget(balanceButton, 3, 2, 1, 1);

        headerLabel = new QLabel(MainDialog);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        headerLabel->setFont(font);
        headerLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(headerLabel, 0, 1, 1, 1);

        transactionButton = new QPushButton(MainDialog);
        transactionButton->setObjectName(QString::fromUtf8("transactionButton"));

        gridLayout->addWidget(transactionButton, 5, 2, 1, 1);

        withdrawButton = new QPushButton(MainDialog);
        withdrawButton->setObjectName(QString::fromUtf8("withdrawButton"));

        gridLayout->addWidget(withdrawButton, 2, 2, 1, 1);

        logoutButton = new QPushButton(MainDialog);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        gridLayout->addWidget(logoutButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        transferButton = new QPushButton(MainDialog);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));

        gridLayout->addWidget(transferButton, 3, 0, 1, 1);

        infoLabel = new QLabel(MainDialog);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(infoLabel, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QCoreApplication::translate("MainDialog", "Dialog", nullptr));
        balanceButton->setText(QCoreApplication::translate("MainDialog", "Saldo", nullptr));
        headerLabel->setText(QCoreApplication::translate("MainDialog", "Valitse:", nullptr));
        transactionButton->setText(QCoreApplication::translate("MainDialog", "Selaa tilitapahtumia", nullptr));
        withdrawButton->setText(QCoreApplication::translate("MainDialog", "Nosta rahaa", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainDialog", "Kirjaudu ulos", nullptr));
        transferButton->setText(QCoreApplication::translate("MainDialog", "Tilisiirto/Uusi maksu", nullptr));
        infoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
