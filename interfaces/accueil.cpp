#include "accueil.h"

#include "ui_Accueil.h"

#include "contactwidget.h"
#include "creationcontact.h"

void Accueil::setGt(GestionContact *newGt)
{
    gt = newGt;
    actualiseList();
}

void Accueil::actualiseList()
{
    for(unsigned i = 0; i < gt->getNombreElements(); i++)
    {
        ContactWidget* cw = new ContactWidget(this, gt->getElement(i));

        auto item = new QListWidgetItem();

        item->setSizeHint(cw->sizeHint());

        ui->lw_Contact->addItem(item);
        ui->lw_Contact->setItemWidget(item, cw);

    }
}

Accueil::Accueil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Accueil())
{
    ui->setupUi(this);

    QObject::connect(ui->b_Supprimer, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    QObject::connect(ui->b_Ajouter, SIGNAL(clicked()), this, SLOT(ouvrirCreationContact()));

    QWidget::setWindowTitle("Gestionnaire de Contact");
    setMinimumWidth(650);
    setMinimumHeight(700);
}

Accueil::~Accueil()
{
    delete ui;
}

/**
 * @brief Slot recepteur lors du bouton supprimer
 * @param checked
 */
void Accueil::supprimerContact()
{
    //On vérifie qu'il y a bien un item de séléctionné
    if(ui->lw_Contact->selectedItems().count() != 0)
    {
        //On récupère le ContactWidget associé à l'item de la QListWidget
        ContactWidget* cw = dynamic_cast<ContactWidget*>(ui->lw_Contact->itemWidget(ui->lw_Contact->currentItem()));
        //On supprime le contact de la list de contact
        gt->supprimerElement(cw->getContact());
        //TODO OPTIMISER
        ui->lw_Contact->clear();
        actualiseList();
    }

}


void Accueil::ouvrirCreationContact()
{
    CreationContact* cc = new CreationContact(this);
    QObject::connect(cc, SIGNAL(creerContact(Contact)), this, SLOT(ajouterContact(Contact)));
    cc->exec();
    //Execution de Accueil mit en attente de la fin d'execution de la fenêtre de création création
    delete cc;
}

void Accueil::ajouterContact(const Contact& c)
{
    gt->ajouterElement(c);
    ui->lw_Contact->clear();
    actualiseList();
}

