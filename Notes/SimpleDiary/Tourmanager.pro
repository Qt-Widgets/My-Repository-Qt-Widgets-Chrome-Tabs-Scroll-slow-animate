#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T20:57:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tourmanager
TEMPLATE = app


SOURCES += main.cpp\
        mainsite.cpp \
    addfiledlg.cpp \
    searchdlg.cpp \
    usemapdlg.cpp \
    previewimagedlg.cpp \
    showfiledlg.cpp \
    mybutton.cpp

HEADERS  += mainsite.h \
    addfiledlg.h \
    searchdlg.h \
    usemapdlg.h \
    previewimagedlg.h \
    showfiledlg.h \
    mybutton.h

FORMS    += mainsite.ui \
    addfiledlg.ui \
    searchdlg.ui \
    usemapdlg.ui \
    previewimagedlg.ui \
    showfiledlg.ui

RESOURCES += \
    icon.qrc

RC_FILE += tourmanager.rc
