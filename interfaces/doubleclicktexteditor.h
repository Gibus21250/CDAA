#ifndef DOUBLECLICKTEXTEDITOR_H
#define DOUBLECLICKTEXTEDITOR_H

#include <QObject>
#include <QTextEdit>

/**
 * @brief Classe hériant d'un QTextEdit et permet de gérer les doubles cliques
 */
class DoubleClickTextEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit DoubleClickTextEditor(QWidget *parent = nullptr);

    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     * @param e Evènement souris
     */
    void mouseDoubleClickEvent(QMouseEvent* e);

signals:
    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     */
    void doubleClique();

};

#endif // DOUBLECLICKTEXTEDITOR_H
