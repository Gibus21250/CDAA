#include "contactwidget.h"

#include <iostream>
#include <QPixmap>

#include "ui_contactwidget.h"

ContactWidget::ContactWidget(QWidget *parent, const Contact& cont)
    : QWidget{parent}, contact(cont), ui(new Ui::ContactWidget())
{
    ui->setupUi(this);
    QPixmap pix("E:/Cloud/GitHub/CDAA/CDAA/interfaces/no-user-image.gif");
    ui->profileImg->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));

    ui->l_nom->setText(QString::fromStdString(contact.getNom()));
    ui->l_prenom->setText(QString::fromStdString(contact.getPrenom()));

    ui->l_mail->setText(QString::fromStdString(contact.getMail()));
    ui->l_tel->setText(QString::fromStdString(contact.getTelephone()));

    ui->l_entreprise->setText(QString::fromStdString(contact.getEntreprise()));


}

ContactWidget::~ContactWidget()
{
    delete ui;
}
