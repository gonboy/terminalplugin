DEFINES += TERMINALPLUGIN_LIBRARY


QTW_LIBRARY_PATH = $$(QTERMWIDGET_LIBRARY_PATH)
isEmpty(QTW_LIBRARY_PATH):QTW_LIBRARY_PATH=/usr/local/lib64
LIBS += -L$$QTW_LIBRARY_PATH -lqtermwidget5
INCLUDEPATH += $$(QTERMWIDGET_INCLUDE_PATH)

# TerminalPlugin files

SOURCES += terminalpluginplugin.cpp \
    terminalpane.cpp \
    terminaloptionspage.cpp \
    terminalwidget.cpp

HEADERS += terminalpluginplugin.h \
        terminalplugin_global.h \
    terminalpane.h \
    terminaloptionspage.h \
    terminalwidget.h

# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$(QTC_SOURCE)
isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=/opt/qt-creator

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=/opt/qt-creator-build

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on Mac
# USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

QTC_PLUGIN_NAME = TerminalPlugin
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

include($$QTCREATOR_SOURCES/src/qtcreatorplugin.pri)

FORMS += \
    terminaloptionspage.ui

RESOURCES += \
    terminalplugin.qrc

DISTFILES += \
    README.md

