#include "creationcontact.h"

#include "ui_creationContact.h"

CreationContact::CreationContact(QWidget *parent)
    : QDialog{parent}, ui(new Ui::CreationContact())
{
    ui->setupUi(this);
    setWindowTitle("Création d'un contact");
    //Connection du bouton créer au slot terminer creation
    QObject::connect(ui->b_creer, SIGNAL(clicked()), this, SLOT(terminerCreation()));
}

void CreationContact::terminerCreation()
{
    contact.setNom(ui->le_nom->text().toStdString());
    contact.setPrenom(ui->le_prenom->text().toStdString());
    contact.setTelephone(ui->le_tel->text().toStdString());
    contact.setMail(ui->le_mail->text().toStdString());
    contact.setEntreprise(ui->le_entreprise->text().toStdString());

    //Emission du signal en ayant le contact en argument
    emit creerContact(contact);

    this->close();
}

