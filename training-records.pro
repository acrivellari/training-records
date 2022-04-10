TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        main.cpp \
        backend/src/model.cpp \
        backend/src/training.cpp \
        backend/src/backendException.cpp \
            backend/src/controller.cpp \
            backend/src/io.cpp \
                frontend/src/view.cpp

HEADERS += \
    backend/model.h \
    backend/training.h \
        backend/controller.h \
        backend/io.h \
            frontend/view.h

