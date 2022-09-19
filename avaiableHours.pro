TEMPLATE = app
TARGET = contactlist
QT += quick

HEADERS += \
    fileio.h

SOURCES += \
    fileio.cpp \
    main.cpp

RESOURCES += \
    Tela.qml \
    Form.ui.qml \
    main.qml \
    restaurant_hours.csv

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = $$PWD/designer

