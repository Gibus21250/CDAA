#include "contactwidget.h"

#include <iostream>
#include <QPixmap>

#include "ui_contactwidget.h"

Contact* ContactWidget::getContact() const
{
    return contact;
}

ContactWidget::ContactWidget(QWidget *parent, Contact* cont)
    : QWidget{parent}, contact(cont), ui(new Ui::ContactWidget())
{
    ui->setupUi(this);
    actualiserAffichage();
}

ContactWidget::~ContactWidget()
{
    delete ui;
}

void ContactWidget::actualiserAffichage()
{
    QString uriImage;
    if(contact->getPhoto().empty()) uriImage = ":/profileImg/no-image";
    else uriImage = QString::fromStdString(contact->getPhoto());

    QPixmap pix(uriImage);
    if(pix.isNull())
    {
        pix = QPixmap(":/profileImg/no-image");
    }
    ui->profileImg->setPixmap(pix.scaled(75, 75, Qt::KeepAspectRatio));

    ui->l_nom->setText(QString::fromStdString(contact->getNom()));
    ui->l_prenom->setText(QString::fromStdString(contact->getPrenom()));

    ui->l_mail->setText(QString::fromStdString(contact->getMail()));
    ui->l_tel->setText(QString::fromStdString(contact->getTelephone()));

    ui->l_entreprise->setText(QString::fromStdString(contact->getEntreprise()));

    ui->l_DateC->setText(QString::fromStdString(contact->getDateCreation().getDateStrFormat()));

    ui->l_DateM->setText(QString::fromStdString(contact->dateDerniereModification().getDateStrFormat()));
}
