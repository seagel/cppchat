TEMPLATE = app
TARGET = gui
QT += core \
    gui
HEADERS += ChatWindow/ChatWindow.h \
    ChatWindow/MyInputField/MyInputField.h \
    MyQMainWindow/MyQMainWindow.h
SOURCES += main.cpp \
    ChatWindow/ChatWindow.cpp \
    ChatWindow/MyInputField/MyInputField.cpp
FORMS += 
RESOURCES += 
