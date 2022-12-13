#include "accueil.h"

#include "ui_Accueil.h"

#include "contactwidget.h"
#include "creationcontact.h"
#include "fichecontact.h"
#include "bdd/mainsqlmanager.h"

#include <QFileDialog>
#include <QErrorMessage>

#include <QDebug>
void Accueil::actualiseList()
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
        std::cout << *cw->getContact() << std::endl;
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

Accueil::Accueil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Accueil())
{

    BDDLocation = "E:\\Cloud\\GitHub\\CDAA\\CDAA\\gestion.sqlite";

    manager.connectTo(this->BDDLocation);

    ui->setupUi(this);

    manager.chargerBaseDeDonnee(&gt);


    QObject::connect(ui->b_Supprimer, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    QObject::connect(ui->b_Ajouter, SIGNAL(clicked()), this, SLOT(ouvrirCreationContact()));
    QObject::connect(ui->lw_Contact, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirInfoContact(QListWidgetItem*)));

    QWidget::setWindowTitle("Gestionnaire de Contact");
    setMinimumWidth(650);
    setMinimumHeight(700);

    actualiseList();
}

Accueil::~Accueil()
{
    delete ui;
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
    actualiseList();
}


void Accueil::ouvrirCreationContact()
{
    CreationContact cc(this);
    QObject::connect(&cc, SIGNAL(creerContact(Contact&)), this, SLOT(ajouterContact(Contact&)));
    cc.exec();
    actualiseList();
}

void Accueil::ajouterContact(Contact& c)
{
    manager.ajouterContact(&c);
    gt.ajouterElement(c);
    actualiseList();
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
        qDebug() << "dir non null";
        manager.connectTo(dir.toStdString());
        qDebug() << manager.getIsConnected();
        if(manager.getIsConnected())
        {
            BDDLocation = dir.toStdString();
            gt.effacerToutElements();
            manager.chargerBaseDeDonnee(&gt);
            actualiseList();
        }
        else
        {
            QErrorMessage qem(this);
            qem.showMessage("Impossible d'ouvrir la base de donnée selectionnée!\nVérifier que le fichier est valide (.sqlite)");
            qem.exec();
        }
    }
}


void Accueil::on_check_nom_toggled(bool checked)
{
    if(checked)
    {
        filtrerListe();
    }
    else
    {
        actualiseList();
    }
}

void Accueil::on_check_Prenom_toggled(bool checked)
{
    if(checked)
    {
        filtrerListe();
    }
    else
    {
        actualiseList();
    }
}

void Accueil::on_check_entreprise_toggled(bool checked)
{
    if(checked)
    {
        filtrerListe();
    }
    else
    {
        actualiseList();
    }
}

void Accueil::on_le_nom_textChanged(const QString &arg1)
{
    if(ui->check_nom->isChecked())
    {
        actualiseList();
        filtrerListe();
    }
}
