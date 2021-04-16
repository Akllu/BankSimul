QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    homewindow.cpp \
    main.cpp \
    mainmenu.cpp

HEADERS += \
    homewindow.h \
    mainmenu.h \

FORMS += \
    homewindow.ui \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

win32: LIBS += -L$$PWD/../../SerialPortDLL/build-SerialPortDLL-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lSerialPortDLL

INCLUDEPATH += $$PWD/../../SerialPortDLL/SerialPortDLL
DEPENDPATH += $$PWD/../../SerialPortDLL/SerialPortDLL

win32: LIBS += -L$$PWD/../../PINCodeDLL/build-DLLPinCode-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lDLLPinCode

INCLUDEPATH += $$PWD/../../PINCodeDLL/DLLPinCode
DEPENDPATH += $$PWD/../../PINCodeDLL/DLLPinCode
