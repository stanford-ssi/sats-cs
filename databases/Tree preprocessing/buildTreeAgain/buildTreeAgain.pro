TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/databasenode.cpp \
    src/main.cpp \
    src/generatetree.cpp \

SUBDIRS += \
    buildTreeAgain.pro

HEADERS += \
    src/databasenode.h \
    src/databasenode.h \
    src/generatetree.h \


DISTFILES += \
    res/sample1.csv
