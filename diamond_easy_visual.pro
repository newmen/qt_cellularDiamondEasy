# -------------------------------------------------
# Project created by QtCreator 2010-07-09T17:06:30
# -------------------------------------------------
QT += opengl \
    xml
TARGET = diamond_easy_visual
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    lifeviewer.cpp \
    readerxyz.cpp \
    readerwxyz.cpp \
    GLPrimitives.cpp
HEADERS += mainwindow.h \
    lifeviewer.h \
    readerxyz.h \
    common.h \
    readerwxyz.h \
    reader.h
FORMS += mainwindow.ui
LIBS += -lQGLViewer
