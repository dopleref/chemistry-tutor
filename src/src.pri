
QMAKE_CXXFLAGS += -std=c++14

HEADERS += src/mainwindow.h \
    $$PWD/wtheory.h \
    $$PWD/wsolution.h \
    $$PWD/wtask.h \
    $$PWD/appcore.h

SOURCES += src/main.cpp \
            src/mainwindow.cpp \
    $$PWD/wtheory.cpp \
    $$PWD/wsolution.cpp \
    $$PWD/wtask.cpp \
    $$PWD/appcore.cpp

RESOURCES += \
    $$PWD/theory.qrc \
    $$PWD/qml.qrc
