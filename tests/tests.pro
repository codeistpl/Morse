include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_morse.h

SOURCES += \
        main.cpp

LIBS += -L$$OUT_PWD/../morse/ -lmorse
