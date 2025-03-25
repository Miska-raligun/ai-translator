QT += widgets network

CONFIG += c++17

SOURCES += main.cpp \
           input_hook.cpp \
           mainwindow.cpp \
           openai_translator.cpp \
           mytextedit.cpp \
           model_config_dialog.cpp

HEADERS += mainwindow.h \
           input_hook.h \
           openai_translator.h \
           mytextedit.h \
           model_config_dialog.h

win32: LIBS += -luser32

FORMS += mainwindow.ui \
         model_config_dialog.ui

RESOURCES += \
    resource.qrc

RC_FILE = appicon.rc

