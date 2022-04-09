TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        main.cpp \
        backend/model.cpp \
        backend/training.cpp \
        backend/backendException.cpp \
            backend/controller.cpp \
            backend/io.cpp \
                frontend/view.cpp

HEADERS += \
    backend/model.h \
    backend/training.h \
        backend/controller.h \
        backend/io.h \
            frontend/view.h

