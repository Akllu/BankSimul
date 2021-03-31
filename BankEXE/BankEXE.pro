QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balancedialog.cpp \
    main.cpp \
    maindialog.cpp \
    mainwindow.cpp \
    otherwithdrawdialog.cpp \
    pindialog.cpp \
    withdrawdialog.cpp

HEADERS += \
    balancedialog.h \
    maindialog.h \
    mainwindow.h \
    otherwithdrawdialog.h \
    pindialog.h \
    withdrawdialog.h

FORMS += \
    balancedialog.ui \
    maindialog.ui \
    mainwindow.ui \
    otherwithdrawdialog.ui \
    pindialog.ui \
    withdrawdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
