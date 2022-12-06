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
    Ui::InteractionWidget* ui;
    Interaction* m_p_interaction;

public:
    explicit InteractionWidget(QWidget *parent = nullptr, Interaction* p_int = nullptr);
    ~InteractionWidget();

signals:

};

#endif // INTERACTIONWIDGET_H
