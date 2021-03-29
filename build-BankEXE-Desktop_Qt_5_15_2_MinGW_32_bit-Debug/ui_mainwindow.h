/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QLabel *insertLabel;
    QLabel *pictureLabel;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(380, 169);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        headerLabel->setFont(font);
        headerLabel->setAutoFillBackground(false);
        headerLabel->setFrameShape(QFrame::NoFrame);
        headerLabel->setFrameShadow(QFrame::Plain);
        headerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(headerLabel);

        insertLabel = new QLabel(centralwidget);
        insertLabel->setObjectName(QString::fromUtf8("insertLabel"));
        QFont font1;
        font1.setPointSize(14);
        insertLabel->setFont(font1);
        insertLabel->setFrameShape(QFrame::NoFrame);
        insertLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(insertLabel);

        pictureLabel = new QLabel(centralwidget);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy);
        pictureLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pictureLabel);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        headerLabel->setText(QCoreApplication::translate("MainWindow", "PANKKIAUTOMAATTI", nullptr));
        insertLabel->setText(QCoreApplication::translate("MainWindow", "Aseta kortti lukijaan:", nullptr));
        pictureLabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Luettu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
