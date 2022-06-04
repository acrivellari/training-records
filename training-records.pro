QT += widgets
CONFIG += app
TEMPLATE = app

SOURCES += \
    main.cpp \
    backend/src/backendException.cpp \
    backend/src/model.cpp \
        backend/src/training.cpp \
        backend/src/usersauth.cpp \
        backend/src/trainingLogic.cpp \
            backend/src/awsio.cpp \
            backend/src/jsonio.cpp \
    backend/src/controller.cpp \
    frontend/src/dummyView.cpp \
    frontend/src/widgetView.cpp \
        frontend/src/widgetView/wvMainLayout.cpp \
        frontend/src/widgetView/wvLogin.cpp

HEADERS += \
    backend/backendException.h \
    backend/model.h \
        backend/training.h \
            backend/trainingLogic.h \
            backend/usersauth.h \
            backend/io.h \
                backend/awsio.h \
                backend/jsonio.h \
    backend/controller.h \
    frontend/view.h \
        frontend/dummyView.h \
        frontend/widgetView.h \
            frontend/widgetView/wvMainLayout.h \
            frontend/widgetView/wvLogin.h

