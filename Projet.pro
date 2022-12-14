TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
RC_ICONS = images/appli.ico

SOURCES += \
        bdd/jsonexporteur.cpp \
        bdd/mainsqlmanager.cpp \
        interfaces/accueil.cpp \
        interfaces/contactwidget.cpp \
        interfaces/creationcontact.cpp \
        interfaces/doubleclickqlabel.cpp \
        interfaces/doubleclicktexteditor.cpp \
        interfaces/fichecontact.cpp \
        interfaces/interactionwidget.cpp \
        interfaces/windowrecherche.cpp \
        interfaces/windowtachecontact.cpp \
        main.cpp \
        primitives/contact.cpp \
        primitives/dateSimple.cpp \
        primitives/gestioncontact.cpp \
        primitives/gestioninteraction.cpp \
        primitives/gestiontache.cpp \
        primitives/interaction.cpp \
        primitives/tache.cpp

HEADERS += \
    bdd/jsonexporteur.h \
    bdd/mainsqlmanager.h \
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
    interfaces/doubleclickqlabel.h \
    interfaces/doubleclicktexteditor.h \
    interfaces/fichecontact.h \
    interfaces/interactionwidget.h \
    interfaces/windowrecherche.h \
    interfaces/windowtachecontact.h \
    primitives/contact.h \
    primitives/dateSimple.h \
    primitives/gestioncontact.h \
    primitives/gestioninteraction.h \
    primitives/gestionnaire.h \
    primitives/gestiontache.h \
    primitives/interaction.h \
    primitives/tache.h

QT += widgets sql

FORMS += \
    interfaces/Accueil.ui \
    interfaces/contactwidget.ui \
    interfaces/creationContact.ui \
    interfaces/ficheContact.ui \
    interfaces/interactionwidget.ui \
    interfaces/windowRecherche.ui \
    interfaces/windowTacheContact.ui

RESOURCES += \
    images.qrc
