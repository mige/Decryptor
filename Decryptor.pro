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
    substitutionwithkey.cpp \
    vigenereciphertab.cpp

HEADERS  += mainwindow.h \
    frequencychart.h \
    cipher.h \
    caesarciphertab.h \
    affineciphertab.h \
    substitutionwithkey.h \
    vigenereciphertab.h

FORMS    += mainwindow.ui \
    caesarciphertab.ui \
    affineciphertab.ui \
    substitutionwithkey.ui \
    vigenereciphertab.ui

OTHER_FILES += \
    README
