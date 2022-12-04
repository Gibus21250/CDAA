TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
RC_ICONS = app.ico

SOURCES += \
        interfaces/accueil.cpp \
        interfaces/contactwidget.cpp \
        interfaces/creationcontact.cpp \
        main.cpp \
        primitives/contact.cpp \
        primitives/dateSimple.cpp \
        primitives/gestioncontact.cpp \
        primitives/gestioninteraction.cpp \
        primitives/gestiontache.cpp \
        primitives/interaction.cpp \
        interfaces/accueil.cpp \
        primitives/tache.cpp

HEADERS += \
    date/chrono_io.h \
    date/date.h \
    date/ios.h \
    date/islamic.h \
    date/iso_week.h \
    date/julian.h \
    date/ptz.h \
    date/solar_hijri.h \
    date/tz.h \
    date/tz_private.h \
    interfaces/accueil.h \
    interfaces/contactwidget.h \
    interfaces/creationcontact.h \
    primitives/contact.h \
    primitives/dateSimple.h \
    primitives/gestioncontact.h \
    primitives/gestioninteraction.h \
    primitives/gestionnaire.h \
    primitives/gestiontache.h \
    primitives/interaction.h \
    primitives/tache.h

QT += widgets

FORMS += \
    interfaces/Accueil.ui \
    interfaces/contactwidget.ui \
    interfaces/creationContact.ui

RESOURCES += \
    images.qrc
