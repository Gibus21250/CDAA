#ifndef INTERACTIONWIDGET_H
#define INTERACTIONWIDGET_H

#include <QWidget>
#include "primitives/interaction.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class InteractionWidget;
}
QT_END_NAMESPACE

class InteractionWidget : public QWidget
{
    Q_OBJECT

private:
    //Pointeur vers l'ui InteractionWidget
    Ui::InteractionWidget* ui;
    //Pointeur vers l'interaction à associer
    Interaction* m_p_interaction;

public:
    /**
     * @brief Constructeur
     * @param parent
     * @param p_int pointeur vers l'interaction à associer
     */
    explicit InteractionWidget(QWidget *parent = nullptr, Interaction* p_int = nullptr);
    ~InteractionWidget();

    /**
     * @brief p_interaction
     * @return
     */
    Interaction *p_interaction() const;

    /**
     * @brief setP_interaction
     * @param newP_interaction
     */
    void setP_interaction(Interaction *newP_interaction);

    void actualiserInfoWidget();

signals:

};

#endif // INTERACTIONWIDGET_H
