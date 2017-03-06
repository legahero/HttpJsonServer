#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T11:26:50
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HttpJsonServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httpbase/qhttprequest.cpp \
    httpbase/qhttpresponse.cpp \
    httpbase/qhttpserver.cpp \
    httpbase/http_parser.c \    
    httpbase/threadhandle.cpp \
    httpbase/qasyntcpserver.cpp \
    httpbase/qasynhttpsocket.cpp \
    httpbase/staticfilecontroller.cpp \
    httpbase/httphandler.cpp \
    httpbase/qasyntcpsocket.cpp \
    httpbase/qconnectpool.cpp \
    httpbase/qmultidbmanager.cpp

HEADERS  += mainwindow.h \
    httpbase/http_parser.h \
    httpbase/qhttprequest.h \
    httpbase/qhttpresponse.h \
    httpbase/threadhandle.h \
    httpbase/qasyntcpserver.h \
    httpbase/qasynhttpsocket.h \
    httpbase/qhttpserver.h \
    httpbase/staticfilecontroller.h \
    httpbase/httphandler.h \
    httpbase/qasyntcpsocket.h \
    httpbase/qhttpserverfwd.h \
    httpbase/qconnectpool.h \
    httpbase/qmultidbmanager.h

FORMS    += mainwindow.ui

unix:include($$PWD/eventdispatcher_libev/eventdispatcher_libev.pri)
