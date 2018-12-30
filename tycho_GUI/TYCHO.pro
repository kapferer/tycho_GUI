#-------------------------------------------------
#
# Project created by QtCreator 2012-04-02T20:39:10
#
#-------------------------------------------------

QT       += gui
QT       += widgets

TARGET = tychoGUI
TEMPLATE = app

RC_FILE = ../tycho_Windows/myapp.rc

SOURCES += main.cpp\
    mainwindow.cpp \
    save_parameterfile.cpp \
    boundary_selector.cpp \
    open_initial_conditions.cpp \
    ic_selector.cpp \
    filetype_selector.cpp \
    load_parameterfile.cpp \
    logic_parameter.cpp \
    local_simulation.cpp \
    help1.cpp \
    reset_gui.cpp \
    run_error.cpp \
    help2.cpp \
    help3.cpp \
    help4.cpp \
    help5.cpp \
    help6.cpp \
    help7.cpp \
    help8.cpp \
    help_local_simulation.cpp \
    about.cpp \
    configure_path.cpp \

HEADERS  += mainwindow.h \
    help1.h \
    local_simulation.h \
    globals.h \
    run_error.h \
    help2.h \
    help3.h \
    help4.h \
    help5.h \
    help6.h \
    help7.h \
    help8.h \
    help_local_simulation.h \
    about.h \
    ui_configure_path.h \
    configure_path.h \
    ui_configure_path.h

FORMS    += \
    help1.ui \
    local_simulation.ui \
    run_error.ui \
    help2.ui \
    help3.ui \
    help4.ui \
    help5.ui \
    help6.ui \
    help7.ui \
    help8.ui \
    help_local_simulation.ui \
    about.ui \
    mainwindow.ui \
    configure_path.ui
