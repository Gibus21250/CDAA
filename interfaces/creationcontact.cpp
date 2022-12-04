#include <QFileDialog>

#include "creationcontact.h"

#include "ui_creationContact.h"

CreationContact::CreationContact(QWidget *parent)
    : QDialog{parent}, ui(new Ui::CreationContact())
{
    ui->setupUi(this);
    setWindowTitle("Création d'un contact");

    QPixmap pix(":/profileImg/no-image");
    ui->image->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
    //Connection du bouton créer au slot terminer creation
    QObject::connect(ui->b_creer, SIGNAL(clicked()), this, SLOT(terminerCreation()));
    QObject::connect(ui->b_importerImage, SIGNAL(clicked()), this, SLOT(ouvrirDialogFichier()));
}

void CreationContact::ouvrirDialogFichier()
{
    QString dir = QFileDialog::getOpenFileName(this, tr("Image de profil"), QDir::currentPath());
    if(!dir.isEmpty())
    {
        //On charge le fichier que l'utilisateur nous a donné
        QPixmap pix(dir);
        //Si il a eu un echec (fichier non conforme, etc)
        if(pix.isNull())
        {
            pix = QPixmap(":/profileImg/no-image");
            uri = "";
            //On charge l'image par défaut
        }
        else uri = dir;
        ui->image->setPixmap(pix.scaled(75, 75, Qt::KeepAspectRatio));
    }
}

void CreationContact::terminerCreation()
{
    QString infoEchec;
    if(ui->le_nom->text().isEmpty())
    {
        infoEchec.append(" nom");
    }
    if(ui->le_prenom->text().isEmpty())
    {
        infoEchec.append(" prenom");
    }
    if(ui->le_mail->text().isEmpty())
    {
        infoEchec.append(" mail");
    }

    if(infoEchec.isEmpty())
    {
        contact.setPrenom(ui->le_prenom->text().toStdString());
        contact.setNom(ui->le_nom->text().toStdString());

        contact.setTelephone(ui->le_tel->text().toStdString());
        contact.setMail(ui->le_mail->text().toStdString());

        contact.setEntreprise(ui->le_entreprise->text().toStdString());
        contact.setUriPhoto(uri.toStdString());

        contact.setUriPhoto(uri.toStdString());

        //Emission du signal en ayant le contact en argument
        emit creerContact(contact);

        this->close();
    }
    else
    {
        ui->l_infoText->setText("Vous devez renseigner:" + infoEchec);
        ui->l_infoText->setStyleSheet("QLabel { background-color : #FFD580; }");
    }



}

