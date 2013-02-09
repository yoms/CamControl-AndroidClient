#-------------------------------------------------
#
# Project created by QtCreator 2013-02-09T18:10:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamControlClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    android/version.xml \
    android/res/values-ru/strings.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/values-de/strings.xml \
    android/res/layout/splash.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-es/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-id/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/values-ms/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-ro/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/AndroidManifest.xml

