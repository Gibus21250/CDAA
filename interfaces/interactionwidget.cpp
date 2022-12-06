#include "interactionwidget.h"

#include "ui_interactionwidget.h"

Interaction *InteractionWidget::p_interaction() const
{
    return m_p_interaction;
}

void InteractionWidget::setP_interaction(Interaction *newP_interaction)
{
    m_p_interaction = newP_interaction;
}

InteractionWidget::InteractionWidget(QWidget *parent, Interaction* interaction)
    : QWidget{parent}, ui(new Ui::InteractionWidget()), m_p_interaction(interaction)
{
    ui->setupUi(this);

    ui->l_desc->setText(QString::fromStdString(m_p_interaction->getContenu()));
    ui->l_date->setText(QString::fromStdString(m_p_interaction->getDate().getDateStrFormat()));
    ui->l_nbTaches->setText(QString::number(m_p_interaction->taches().getNombreElements()));

}

InteractionWidget::~InteractionWidget()
{
    delete ui;
}
