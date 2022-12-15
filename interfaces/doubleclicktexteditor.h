#ifndef DOUBLECLICKTEXTEDITOR_H
#define DOUBLECLICKTEXTEDITOR_H

#include <QObject>
#include <QTextEdit>

/**
 * @brief Classe dérivée d(un QTextEdit, permettant de gérer le double clique
 */
class DoubleClickTextEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit DoubleClickTextEditor(QWidget *parent = nullptr);

    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     * @param event évènement de la souris
     */
    void mouseDoubleClickEvent(QMouseEvent* e);

signals:
    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     */
    void doubleClique();

};

#endif // DOUBLECLICKTEXTEDITOR_H
