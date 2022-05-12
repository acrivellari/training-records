TEMPLATE = app
CONFIG += qt console
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    backend/src/backendException.cpp \
    backend/src/model.cpp \
        backend/src/training.cpp \
        backend/src/usersauth.cpp \
            backend/src/awsio.cpp \
            backend/src/jsonio.cpp \
    backend/src/controller.cpp \
    frontend/src/view.cpp

HEADERS += \
    backend/backendException.h \
    backend/model.h \
        backend/training.h \
            backend/usersauth.h \
            backend/io.h \
                backend/awsio.h \
                backend/jsonio.h \
    backend/controller.h \
    frontend/view.h

