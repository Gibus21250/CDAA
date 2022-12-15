#include "accueil.h"

#include "ui_Accueil.h"

#include "contactwidget.h"
#include "creationcontact.h"
#include "fichecontact.h"
#include "bdd/mainsqlmanager.h"
#include "windowrecherche.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

Accueil::Accueil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Accueil()), je(&gt)
{
    QDir cacheDir("cache");
    if(cacheDir.exists())
    {
        QFile cacheBdd("cache/bdd.data");
        if(cacheBdd.exists())
        {
            cacheBdd.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&cacheBdd);
            if(!in.atEnd()) BDDLocation = in.readLine();
        }
        else
        {
            cacheBdd.open(QIODevice::WriteOnly);
        }
        cacheBdd.close();
    }
    else
    {
        if(cacheDir.mkpath("."))
        {
            QFile cacheBdd("cache/bdd.data");
            cacheBdd.open(QIODevice::WriteOnly);
        }
    }

    //BDDLocation = "E:\\Cloud\\GitHub\\CDAA\\CDAA\\gestion.sqlite";

    if(!BDDLocation.isEmpty())
    {
        manager.connectTo(this->BDDLocation.toStdString());
        manager.chargerBaseDeDonnee(&gt);
    }


    ui->setupUi(this);


    //On initialise les dates des QDateEdit par la date d'aujourd'hui
    ui->de_CApres->setDate(QDateTime::currentDateTime().date());
    ui->de_CAvant->setDate(QDateTime::currentDateTime().date());
    ui->de_MApres->setDate(QDateTime::currentDateTime().date());
    ui->de_MAvant->setDate(QDateTime::currentDateTime().date());

    nbVisible = gt.getNombreElements();

    l_nbContact = new QLabel("Nombre total de contact: " + QString::number(nbVisible));
    l_nbContactActuel = new QLabel("  |  Nombre actuel de contact visible: " + QString::number(nbVisible));
    ui->statusBar->addPermanentWidget(l_nbContact);
    ui->statusBar->addPermanentWidget(l_nbContactActuel);


    QObject::connect(ui->b_Supprimer, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    QObject::connect(ui->b_Ajouter, SIGNAL(clicked()), this, SLOT(ouvrirCreationContact()));
    QObject::connect(ui->lw_Contact, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirInfoContact(QListWidgetItem*)));

    //Connexion des checkbox de filtre
    QObject::connect(ui->check_Prenom, SIGNAL(toggled(bool)), this, SLOT(onFiltreActive(bool)));
    QObject::connect(ui->check_nom, SIGNAL(toggled(bool)), this, SLOT(onFiltreActive(bool)));
    QObject::connect(ui->check_entreprise, SIGNAL(toggled(bool)), this, SLOT(onFiltreActive(bool)));

    //Connexion des lineEdit associé aux checkbox
    QObject::connect(ui->le_nom, SIGNAL(textChanged(QString)), this, SLOT(onValueTEChanged()));
    QObject::connect(ui->le_prenom, SIGNAL(textChanged(QString)), this, SLOT(onValueTEChanged()));
    QObject::connect(ui->le_entreprise, SIGNAL(textChanged(QString)), this, SLOT(onValueTEChanged()));


    //Connexion aux checkBox associé aux date de filtre
    QObject::connect(ui->check_CApres, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));
    QObject::connect(ui->check_CAvant, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));
    QObject::connect(ui->check_MApres, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));
    QObject::connect(ui->check_MAvant, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));

    //Connexion des dateEdit, lorsqu'ils sont modifié on récupère leur signaux
    QObject::connect(ui->de_CApres, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));
    QObject::connect(ui->de_CAvant, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));
    QObject::connect(ui->de_MApres, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));
    QObject::connect(ui->de_MAvant, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));


    QWidget::setWindowTitle("Gestionnaire de Contact");
    setMinimumWidth(650);
    setMinimumHeight(700);

    resetList();
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::resetList()
{
    ui->lw_Contact->clear();

    for(unsigned i = 0; i < gt.getNombreElements(); i++)
    {
        ContactWidget* cw = new ContactWidget(this, &(gt.getElement(i)));

        auto item = new QListWidgetItem();

        item->setSizeHint(cw->sizeHint());

        ui->lw_Contact->addItem(item);
        ui->lw_Contact->setItemWidget(item, cw);

    }

    l_nbContact->setText("Nombre total de contact: " + QString::number(gt.getNombreElements()));
    actualiserStatusBar();
}

void Accueil::filtrerListe()
{
    for(int i = 0; i < ui->lw_Contact->count(); ++i)
    {
        ContactWidget* cw = dynamic_cast<ContactWidget*>(
                    ui->lw_Contact->itemWidget(ui->lw_Contact->item(i)));
        if(ui->check_nom->isChecked())
        {
            if(cw->getContact()->getNom().find(ui->le_nom->text().toStdString()) == std::string::npos)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }
        if(ui->check_Prenom->isChecked())
        {
            if(cw->getContact()->getPrenom().find(ui->le_prenom->text().toStdString()) == std::string::npos)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }
        if(ui->check_entreprise->isChecked())
        {
            if(cw->getContact()->getEntreprise().find(ui->le_entreprise->text().toStdString()) == std::string::npos)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }
    }
}

void Accueil::reafficherListe()
{
    for(int i = 0; i < ui->lw_Contact->count(); ++i)
    {
        ui->lw_Contact->item(i)->setHidden(false);
    }

        l_nbContactActuel->setText("  |  Nombre actuel de contact visible: " + QString::number(ui->lw_Contact->count()));
}

/**
 * @brief Slot recepteur lors du bouton supprimer
 */
void Accueil::supprimerContact()
{
    //On vérifie qu'il y a bien un item de séléctionné
    if(ui->lw_Contact->selectedItems().count() != 0)
    {
        ContactWidget* cw = dynamic_cast<ContactWidget*>(ui->lw_Contact->itemWidget(ui->lw_Contact->currentItem()));

        if(cw->getContact()->getPhoto() != "")
        {
            QFile::remove(QString::fromStdString(cw->getContact()->getPhoto()));
        }

        manager.supprimerContact(cw->getContact()->getIdC());
        //On supprime le contact de la list de contact
        gt.supprimerElement(ui->lw_Contact->currentRow());

        ui->lw_Contact->removeItemWidget(ui->lw_Contact->currentItem());
        //Dans la doc on nous dit de delete nous même le pointer, pour que le widget soit à jour
        delete ui->lw_Contact->currentItem();
    }

}

void Accueil::ouvrirInfoContact(QListWidgetItem* )
{
    //On récupère le widget selectionné par l'utilisateur
    ContactWidget* cw = dynamic_cast<ContactWidget*>(ui->lw_Contact->itemWidget(ui->lw_Contact->currentItem()));

    FicheContact fc(this, cw->getContact(), &manager);
    fc.exec();

    manager.modifierContact(cw->getContact());
    cw->actualiserAffichage();
    reafficherListe();
    filtrerListe();
    filtrerListeParDate();
}

void Accueil::ouvrirCreationContact()
{
    CreationContact cc(this);
    QObject::connect(&cc, SIGNAL(creerContact(Contact&)), this, SLOT(ajouterContact(Contact&)));
    cc.exec();
    resetList();
}

void Accueil::ajouterContact(Contact& c)
{
    manager.ajouterContact(&c);
    //Important de le mettre après car manager actualise le numéro du contact!
    if(c.getPhoto() != "")
    {
        //On récupère les infos de l'image
        QFileInfo imageSelec(QString::fromStdString(c.getPhoto()));

        if(!QDir("images").exists()) QDir().mkpath("images");
        //On génère un nouveau nom, pour le copier dedans
        QString dirGeneralImage = "images/" + QString::number(c.getIdC()) + "." + imageSelec.suffix();
        if(QFile(dirGeneralImage).exists()) QFile::remove(dirGeneralImage); //On supprime si elle existait déjà

        QFile::copy(imageSelec.absoluteFilePath(), dirGeneralImage);

        c.setPhoto(dirGeneralImage.toStdString());
        //On met a jour sa nouvelle photo
        manager.modifierContact(&c);
    }
    gt.ajouterElement(c);
    resetList();
}

void Accueil::on_actionQuitter_triggered()
{
    close();
}

void Accueil::on_actionOuvrirBDD_triggered()
{
    QString dir = QFileDialog::getOpenFileName(this, tr("Fichier BDD"), QDir::currentPath());
    if(!dir.isEmpty())
    {
        manager.connectTo(dir.toStdString());
        if(manager.getIsConnected())
        {
            BDDLocation = dir;

            //On sauvegarde le nouveau dir selectionné
            QFile cache("cache/bdd.data");
            cache.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
            cache.write(dir.toStdString().c_str());
            cache.close();

            gt.effacerToutElements();
            manager.chargerBaseDeDonnee(&gt);
            resetList();
        }
        else
        {
            QMessageBox qem("Base de donnée incorrecte",
                            "Le fichier selectionné est invalide!\nVérifier que le fichier (.sqlite)) ainsi que les schémas des tables correspondent",
                            QMessageBox::NoIcon, QMessageBox::Ok | QMessageBox::Default, QMessageBox::NoButton, QMessageBox::NoButton);
            qem.exec();
        }
    }
}

void Accueil::onFiltreActive(bool checked)
{
    if(checked)
    {
        filtrerListe();
    }
    else
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
    }
    actualiserStatusBar();
}

void Accueil::onValueTEChanged()
{
    if(ui->check_Prenom->isChecked() || ui->check_entreprise->isChecked() || ui->check_nom->isChecked())
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
        actualiserStatusBar();
    }
}

void Accueil::onFiltreDateActive(bool checked)
{
    if(checked)
    {
        filtrerListeParDate();
    }
    else
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
    }
    actualiserStatusBar();
}

void Accueil::onDateEditChange()
{
    if(ui->check_CApres->isChecked() || ui->check_CAvant->isChecked() || ui->check_MApres->isChecked() || ui->check_MAvant)
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
        actualiserStatusBar();
    }
}

void Accueil::filtrerListeParDate()
{
    for(int i = 0; i < ui->lw_Contact->count(); ++i)
    {
        ContactWidget* cw = dynamic_cast<ContactWidget*>(
                    ui->lw_Contact->itemWidget(ui->lw_Contact->item(i)));


        if(ui->check_CApres->isChecked())
        {
            const QDate sdate = ui->de_CApres->date();

            DateSimple date(sdate.year(), sdate.month(), sdate.day());

            if(cw->getContact()->getDateCreation() < date)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }
        if(ui->check_CAvant->isChecked())
        {

            const QDate sdate = ui->de_CAvant->date();
            DateSimple date(sdate.year(), sdate.month(), sdate.day());

            if(cw->getContact()->getDateCreation() > date)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }

        if(ui->check_MApres->isChecked())
        {

            const QDate sdate = ui->de_MApres->date();
            DateSimple date(sdate.year(), sdate.month(), sdate.day());
            if(cw->getContact()->dateDerniereModification() < date)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }
        if(ui->check_MAvant->isChecked())
        {

            const QDate sdate = ui->de_MAvant->date();
            DateSimple date(sdate.year(), sdate.month(), sdate.day());
            if(cw->getContact()->dateDerniereModification() > date)
            {
                ui->lw_Contact->item(i)->setHidden(true);
            }
        }

    }
}

void Accueil::actualiserStatusBar()
{
    nbVisible = gt.getNombreElements();

    for(unsigned i = 0; i < ui->lw_Contact->count(); i++)
    {

        if(ui->lw_Contact->item(i)->isHidden())
        {
            nbVisible--;
        }
    }

    l_nbContactActuel->setText("  |  Nombre actuel de contact visible: " + QString::number(nbVisible));
}

void Accueil::on_actionGenerale_triggered()
{
    WindowRecherche* wr = new WindowRecherche(this, &gt);
    wr->show();
}

void Accueil::on_actionJSON_triggered()
{
    QString dir = QFileDialog::getSaveFileName(this, tr("Dossier de sauvegarde du fichier JSON"), QDir::currentPath());
    std::cout << dir.toStdString() << std::endl;
    je.exporterJSONVers(dir);
}


void Accueil::on_action_actualiser_triggered()
{
    resetList();
}

