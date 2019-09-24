#-------------------------------------------------
#
# Project created by QtCreator 2019-05-30T15:58:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DLL QWT_DLL
RC_FILE = res.rc
TARGET = FTP
TEMPLATE = app
INCLUDEPATH += D:\Qt5.6.1\5.6\mingw49_32\include\qwt
CONFIG(debug, debug|release) {
    LIBS += -lQt5Ftpd
    LIBS += -L"D:\Qt5.6.1\5.6\mingw49_32\lib" -lqwtd
} else {
    LIBS += -lQt5Ftp
    LIBS += -L"D:\Qt5.6.1\5.6\mingw49_32\lib" -lqwt
}


SOURCES += main.cpp\
        widget.cpp \
    kb.cpp \
    mainwindow.cpp \
    ftp.cpp \
    show.cpp \
    data.cpp \
    ip.cpp \
    translate.cpp \
    zoomer.cpp \
    up.cpp \
    main_window.cpp

HEADERS  += widget.h \
    kb.h \
    mainwindow.h \
    ftp.h \
    show.h \
    data.h \
    ip.h \
    translate.h \
    zoomer.h \
    up.h \
    main_window.h

FORMS    += widget.ui \
    kb.ui \
    mainwindow.ui \
    ftp.ui \
    show.ui \
    ip.ui \
    translate.ui \
    up.ui \
    main_window.ui

RESOURCES += \
    res.qrc
