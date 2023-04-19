QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    main.cpp \
    mainwindow.cpp \
    methodistwindow.cpp \
    studentwindow.cpp \
    teacherwindow.cpp

HEADERS += \
    mainwindow.h \
    methodistwindow.h \
    studentwindow.h \
    teacherwindow.h \
    Client.h


FORMS += \
    mainwindow.ui \
    methodistwindow.ui \
    studentwindow.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
