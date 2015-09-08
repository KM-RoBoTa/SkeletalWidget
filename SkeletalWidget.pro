#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T22:45:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SkeletalWidget
TEMPLATE = app
CONFIG += console debug

SOURCES += main.cpp\
    djoint.cpp \
    projections.cpp \
    dskeleton.cpp \
    snakeviz.cpp

HEADERS  += \
    djoint.h \
    projections.h \
    dskeleton.h \
    snakeviz.h

FORMS    += \
    projections.ui \
    snakeviz.ui
