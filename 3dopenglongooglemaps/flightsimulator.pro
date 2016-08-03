QT += core gui widgets webkitwidgets opengl
TEMPLATE = app
TARGET = flightsimulator
SOURCES += ngraphicswebview.cpp nmainwindow.cpp airplane.cpp main.cpp utility.cpp
HEADERS += device.h airplane.h nmainwindow.h ngraphicswebview.h utility.h ndebug.h
RESOURCES += resource.qrc
RC_FILE=myapp.rc
CONFIG += console
