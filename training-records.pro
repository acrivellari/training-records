QT += widgets
CONFIG += app
TEMPLATE = app

SOURCES += \
    main.cpp \
    backend/src/backendException.cpp \
    backend/src/model.cpp \
        backend/src/training.cpp \
        backend/src/usersauth.cpp \
            backend/src/awsio.cpp \
            backend/src/jsonio.cpp \
    backend/src/controller.cpp \
    frontend/src/dummyView.cpp \
    frontend/src/widgetView.cpp \
        frontend/src/widgetView/wvAuth.cpp \
        frontend/src/widgetView/wvLogin.cpp \
        frontend/src/widgetView/wvSignup.cpp \
        frontend/src/widgetView/wvHomePage.cpp \
        frontend/src/widgetView/Sort.cpp


HEADERS += \
    backend/backendException.h \
    backend/model.h \
        backend/training.h \
            backend/usersauth.h \
            backend/io.h \
                backend/awsio.h \
                backend/jsonio.h \
    backend/controller.h \
    frontend/view.h \
        frontend/dummyView.h \
        frontend/widgetView.h \
            frontend/widgetView/wvAuth.h \
            frontend/widgetView/wvLogin.h \
            frontend/widgetView/wvSignup.h \
            frontend/widgetView/wvHomePage.h \
            frontend/widgetView/Sort.h

