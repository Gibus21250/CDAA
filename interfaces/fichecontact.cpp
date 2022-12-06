#include "fichecontact.h"

#include "ui_ficheContact.h"

FicheContact::FicheContact(QWidget *parent, Contact* p_contact)
    : QDialog{parent}, ui(new Ui::FicheContact()), m_p_contact(p_contact)
{
    ui->setupUi(this);

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
        ui->lw_interactions->addItem(QString::fromStdString(m_p_contact->interactions().getElement(i).getContenu()));
    }
}
FicheContact::~FicheContact()
{
    delete ui;
}
