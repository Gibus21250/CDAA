TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

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
    date/tz_private.h
