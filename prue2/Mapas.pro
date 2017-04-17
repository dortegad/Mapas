#-------------------------------------------------
#
# Project created by QtCreator 2015-07-27T17:05:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prue2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#QT_CONFIG -= no-pkg-config
#CONFIG += link_pkgconfig
#PKGCONFIG += opencv

INCLUDEPATH += C:/opencv-3.2.0/build/install/include
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_calib3d320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_core320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_features2d320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_flann320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_highgui320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_imgcodecs320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_imgproc320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_ml320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_objdetect320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_photo320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_shape320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_stitching320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_superres320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_video320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_videoio320d.lib
LIBS += C:/opencv-3.2.0/build/install/x86/vc12/lib/opencv_videostab320d.lib

