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
    QString uriImage;
    if(cont->getPhoto().empty()) uriImage = ":/profileImg/no-image";
    else uriImage = QString::fromStdString(cont->getPhoto());

    QPixmap pix(uriImage);
    ui->profileImg->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));

    ui->l_nom->setText(QString::fromStdString(contact->getNom()));
    ui->l_prenom->setText(QString::fromStdString(contact->getPrenom()));

    ui->l_mail->setText(QString::fromStdString(contact->getMail()));
    ui->l_tel->setText(QString::fromStdString(contact->getTelephone()));

    ui->l_entreprise->setText(QString::fromStdString(contact->getEntreprise()));

}

ContactWidget::~ContactWidget()
{
    delete ui;
}
