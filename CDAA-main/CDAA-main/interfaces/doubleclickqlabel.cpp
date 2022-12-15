#include "doubleclickqlabel.h"

#include <iostream>

DoubleClickQLabel::DoubleClickQLabel(QWidget* parent, const char type)
    : QLabel(parent), type(type) {}

DoubleClickQLabel::DoubleClickQLabel(QWidget* parent)
    : QLabel(parent), type(0) {}


void DoubleClickQLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked(type);
}
