TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        main.cpp \
        backend/model.cpp \
        backend/training.cpp

HEADERS += \
    backend/model.h \
    backend/training.h
