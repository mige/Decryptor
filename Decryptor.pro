#-------------------------------------------------
#
# Project created by QtCreator 2012-03-02T13:22:27
#
#-------------------------------------------------

QT       += core gui

TARGET = Decryptor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frequencychart.cpp \
    cipher.cpp \
    caesarciphertab.cpp \
    affineciphertab.cpp \
    substitutionwithkey.cpp

HEADERS  += mainwindow.h \
    frequencychart.h \
    cipher.h \
    caesarciphertab.h \
    affineciphertab.h \
    substitutionwithkey.h

FORMS    += mainwindow.ui \
    caesarciphertab.ui \
    affineciphertab.ui \
    substitutionwithkey.ui

OTHER_FILES += \
    README
