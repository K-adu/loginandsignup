
QT       += core gui
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loginandsignup
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        bmi.cpp \
        homepage.cpp \
        main.cpp \
        login.cpp \
        signup.cpp

HEADERS += \
        bmi.h \
        homepage.h \
        login.h \
        signup.h

FORMS += \
        homepage.ui \
        login.ui \
        signup.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
