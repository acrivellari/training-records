TEMPLATE = app
CONFIG += qt console
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
        backend/src/model.cpp \
        backend/src/training.cpp \
        backend/src/backendException.cpp \
            backend/src/controller.cpp \
            backend/src/awsio.cpp \
            backend/src/jsonio.cpp \
                frontend/src/view.cpp

HEADERS += \
    backend/model.h \
    backend/training.h \
    backend/backendException.h \
        backend/controller.h \
        backend/io.h \
        backend/awsio.h \
        backend/jsonio.h \
            frontend/view.h

