#ifndef DOUBLECLICKTEXTEDITOR_H
#define DOUBLECLICKTEXTEDITOR_H

#include <QObject>
#include <QTextEdit>

class DoubleClickTextEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit DoubleClickTextEditor(QWidget *parent = nullptr);

    void mouseDoubleClickEvent(QMouseEvent* e);

signals:

    void doubleClique();

};

#endif // DOUBLECLICKTEXTEDITOR_H
