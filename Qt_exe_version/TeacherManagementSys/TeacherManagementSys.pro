QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Teacherinfo.cpp \
    addinfo.cpp \
    analyze_result.cpp \
    analyzeresultdisplay.cpp \
    edit.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    rangetext.cpp

HEADERS += \
    Teacherinfo.h \
    addinfo.h \
    analyze_result.h \
    analyzeresultdisplay.h \
    edit.h \
    mainwindow.h \
    menu.h \
    rangetext.h

FORMS += \
    addinfo.ui \
    analyze_result.ui \
    analyzeresultdisplay.ui \
    edit.ui \
    mainwindow.ui \
    menu.ui \
    rangetext.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
