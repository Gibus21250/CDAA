#include "accueil.h"

#include "ui_Accueil.h"

#include "contactwidget.h"
#include "creationcontact.h"
#include "fichecontact.h"
#include "bdd/mainsqlmanager.h"

#include <QFileDialog>
#include <QErrorMessage>

#include <QDebug>

Accueil::Accueil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Accueil())
{

    BDDLocation = "E:\\Cloud\\GitHub\\CDAA\\CDAA\\gestion.sqlite";

    manager.connectTo(this->BDDLocation);

    ui->setupUi(this);

    manager.chargerBaseDeDonnee(&gt);

    //On initialise les dates des QDateEdit par la date d'aujourd'hui
    ui->de_CApres->setDate(QDateTime::currentDateTime().date());
    ui->de_CAvant->setDate(QDateTime::currentDateTime().date());
    ui->de_MApres->setDate(QDateTime::currentDateTime().date());
    ui->de_MAvant->setDate(QDateTime::currentDateTime().date());


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
            BDDLocation = dir.toStdString();
            gt.effacerToutElements();
            manager.chargerBaseDeDonnee(&gt);
            resetList();
        }
        else
        {
            QErrorMessage qem(this);
            qem.showMessage("Impossible d'ouvrir la base de donnée selectionnée!\nVérifier que le fichier est valide (.sqlite)");
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
}

void Accueil::onValueTEChanged()
{
    if(ui->check_Prenom->isChecked() || ui->check_entreprise->isChecked() || ui->check_nom->isChecked())
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
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
}

void Accueil::onDateEditChange()
{
    if(ui->check_CApres->isChecked() || ui->check_CAvant->isChecked() || ui->check_MApres->isChecked() || ui->check_MAvant)
    {
        reafficherListe();
        filtrerListe();
        filtrerListeParDate();
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


