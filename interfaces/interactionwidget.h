#ifndef INTERACTIONWIDGET_H
#define INTERACTIONWIDGET_H

#include <QWidget>
#include "primitives/interaction.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class InteractionWidget;
}
QT_END_NAMESPACE

/**
 * @brief Classe gérant l'affichage d'une Interaction
 */
class InteractionWidget : public QWidget
{
    Q_OBJECT

private:
    ///Pointeur vers l'ui InteractionWidget
    Ui::InteractionWidget* ui;
    ///Pointeur vers l'interaction à associer
    Interaction* m_p_interaction;

public:
    /**
     * @brief Constructeur
     * @param parent Pointeur vers la fenêtre parent
     * @param p_int Pointeur vers l'Interaction à associer
     */
    explicit InteractionWidget(QWidget *parent = nullptr, Interaction* p_int = nullptr);
    ~InteractionWidget();

    /**
     * @brief Renvoie le pointeur de l'Interaction associé au widget
     * @return Le pointeur de l'interaction
     */
    Interaction *p_interaction() const;

    /**
     * @brief Change la valeur du pointeur de l'Interaction
     * @param newP_interaction Nouvelle valeur du pointeur
     */
    void setP_interaction(Interaction *newP_interaction);

    /**
     * @brief Actualise les informations affichés sur le widget
     */
    void actualiserInfoWidget();

signals:

};

#endif // INTERACTIONWIDGET_H
