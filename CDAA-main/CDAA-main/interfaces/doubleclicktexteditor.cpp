#include "doubleclicktexteditor.h"

DoubleClickTextEditor::DoubleClickTextEditor(QWidget *parent)
    : QTextEdit{parent}
{

}

void DoubleClickTextEditor::mouseDoubleClickEvent(QMouseEvent* e)
{
    emit doubleClique();
}
