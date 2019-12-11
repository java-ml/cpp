#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T02:01:02
#
#-------------------------------------------------

QT       += core gui
QT += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        mywin.cpp \
        utils.cpp

HEADERS += \
        mainwindow.h \
        mywin.h \
        utils.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    file.qrc
INCLUDEPATH += H:\opencv\include
win32: LIBS += -LH:\opencv\x64\mingw\lib \
-lopencv_core410 \
-lopencv_imgproc410 \
-llibopencv_imgcodecs410 \
-llibopencv_stitching410 \
-lopencv_highgui410 \
-lopencv_ml410 \
-lopencv_video410 \
-llibopencv_videoio410 \
-lopencv_features2d410 \
-lopencv_calib3d410 \
-lopencv_objdetect410 \
-llibopencv_dnn410 \
-llibopencv_flann410 \
-llibopencv_gapi410 \
-llibopencv_photo410 \
-lopencv_flann410


