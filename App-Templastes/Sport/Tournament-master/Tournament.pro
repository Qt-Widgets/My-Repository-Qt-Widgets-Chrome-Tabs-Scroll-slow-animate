QT       += core gui

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
    AddPlayerDialog.cpp \
    AddPlayerForm.cpp \
    AddPlayerWidget.cpp \
    GraphicsView.cpp \
    Match.cpp \
    MatchGraphicsItem.cpp \
    MatchWidget.cpp \
    MatchWidgetForm.cpp \
    Player.cpp \
    PointsWidget.cpp \
    Round.cpp \
    RoundWidget.cpp \
    Settings.cpp \
    SettingsData.cpp \
    SettingsDialog.cpp \
    SettingsForm.cpp \
    Tournament.cpp \
    TournamentGraphicScene.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AddPlayerDialog.h \
    AddPlayerForm.h \
    AddPlayerWidget.h \
    GraphicsView.h \
    MainWindow.h \
    Match.h \
    MatchGraphicsItem.h \
    MatchWidget.h \
    MatchWidgetForm.h \
    Player.h \
    PointsWidget.h \
    Round.h \
    RoundWidget.h \
    Settings.h \
    SettingsData.h \
    SettingsDialog.h \
    SettingsForm.h \
    Tournament.h \
    TournamentGraphicScene.h

FORMS += \
    AddPlayerForm.ui \
    MainWindow.ui \
    MatchWidgetForm.ui \
    SettingsForm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
