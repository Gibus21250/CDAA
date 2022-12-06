#include "fichecontact.h"

#include "interactionwidget.h"

#include "ui_ficheContact.h"

FicheContact::FicheContact(QWidget *parent, Contact* p_contact)
    : QDialog{parent}, ui(new Ui::FicheContact()), m_p_contact(p_contact)
{
    ui->setupUi(this);

    ui->te_information->setReadOnly(true);

    QObject::connect(ui->lw_interactions, SIGNAL(currentRowChanged(int)), this, SLOT(interactionChange()));

    QString uriImage;
    if(m_p_contact->getUriPhoto().empty()) uriImage = ":/profileImg/no-image";
    else uriImage = QString::fromStdString(m_p_contact->getUriPhoto());

    QPixmap pix(uriImage);
    ui->photo->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));

    ui->l_nom->setText(QString::fromStdString(m_p_contact->getNom()));
    ui->l_prenom->setText(QString::fromStdString(m_p_contact->getPrenom()));

    ui->l_mail->setText(QString::fromStdString(m_p_contact->getMail()));
    ui->l_tel->setText(QString::fromStdString(m_p_contact->getTelephone()));

    ui->l_entreprise->setText(QString::fromStdString(m_p_contact->getEntreprise()));

    for(unsigned i = 0; i < m_p_contact->getNombreInteraction(); i++)
    {
        InteractionWidget* iw = new InteractionWidget(this, &(m_p_contact->interactions().getElement(i)));
        auto item = new QListWidgetItem();

        item->setSizeHint(iw->sizeHint());

        ui->lw_interactions->addItem(item);
        ui->lw_interactions->setItemWidget(item, iw);
    }
}

void FicheContact::interactionChange()
{
    ui->te_information->clear();

    InteractionWidget* iw = dynamic_cast<InteractionWidget*>(ui->lw_interactions->itemWidget(ui->lw_interactions->currentItem()));

    ui->te_information->append(QString::fromStdString(iw->p_interaction()->getContenu()));
    QString lineTodo;
    for(int i = 0; i < iw->p_interaction()->getNombreTache(); i++)
    {
        lineTodo.append("@todo ");
        lineTodo.append(iw->p_interaction()->taches().getElement(i).getContenu().c_str());
        if(iw->p_interaction()->taches().getElement(i).isDatee())
        {
            lineTodo.append(" @date ");
            lineTodo.append(iw->p_interaction()->taches().getElement(i).getDate().getDateStrFormat().c_str());
        }
        lineTodo.append('\n');
    }

    ui->te_information->append(lineTodo);
}

FicheContact::~FicheContact()
{
    delete ui;
}
