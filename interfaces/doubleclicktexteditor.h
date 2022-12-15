#ifndef DOUBLECLICKTEXTEDITOR_H
#define DOUBLECLICKTEXTEDITOR_H

#include <QObject>
#include <QTextEdit>

class DoubleClickTextEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit DoubleClickTextEditor(QWidget *parent = nullptr);

    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     * @param event
     */
    void mouseDoubleClickEvent(QMouseEvent* e);

signals:
    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     * @param event
     */
    void doubleClique();

};

#endif // DOUBLECLICKTEXTEDITOR_H
