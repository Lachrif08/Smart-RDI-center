QT       += core gui sql charts network multimediawidgets
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    dialog.cpp \
    dumessengerserver.cpp \
    dumessengersocket.cpp \
    employe.cpp \
    equipements.cpp \
    help.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connection.h \
    dialog.h \
    dumessengerserver.h \
    dumessengersocket.h \
    employe.h \
    equipements.h \
    help.h \
    mainwindow.h

FORMS += \
    Chatboxconnectiondialog.ui \
    dialog.ui \
    help.ui \
    mainwindow.ui

OTHER_FILES += \
    TT-Wellingtons-Trial-Medium.otf

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_ICONS += icon.ico
