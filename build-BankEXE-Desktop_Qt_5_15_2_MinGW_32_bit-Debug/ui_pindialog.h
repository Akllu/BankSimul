/********************************************************************************
** Form generated from reading UI file 'pindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINDIALOG_H
#define UI_PINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PINDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QLineEdit *lineEdit;
    QPushButton *sendButton;

    void setupUi(QDialog *PINDialog)
    {
        if (PINDialog->objectName().isEmpty())
            PINDialog->setObjectName(QString::fromUtf8("PINDialog"));
        PINDialog->resize(405, 257);
        verticalLayout = new QVBoxLayout(PINDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headerLabel = new QLabel(PINDialog);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        headerLabel->setFont(font);
        headerLabel->setFrameShape(QFrame::NoFrame);
        headerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(headerLabel);

        lineEdit = new QLineEdit(PINDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFrame(true);

        verticalLayout->addWidget(lineEdit);

        sendButton = new QPushButton(PINDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        verticalLayout->addWidget(sendButton);


        retranslateUi(PINDialog);

        QMetaObject::connectSlotsByName(PINDialog);
    } // setupUi

    void retranslateUi(QDialog *PINDialog)
    {
        PINDialog->setWindowTitle(QCoreApplication::translate("PINDialog", "Dialog", nullptr));
        headerLabel->setText(QCoreApplication::translate("PINDialog", "Sy\303\266t\303\244 kortin PIN-koodi:", nullptr));
        sendButton->setText(QCoreApplication::translate("PINDialog", "Kirjaudu sis\303\244\303\244n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PINDialog: public Ui_PINDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINDIALOG_H
