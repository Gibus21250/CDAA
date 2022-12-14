#include "windowrecherche.h"

#include "ui_windowRecherche.h"

#include <QTableWidgetItem>


WindowRecherche::WindowRecherche(QWidget *parent, const GestionContact* p_gt)
    : QDialog{parent}, ui(new Ui::WindowRecherche()), m_p_gt(p_gt)
{
    ui->setupUi(this);
    ui->de_apres->setDate(QDate::currentDate());
    ui->de_avant->setDate(QDate::currentDate());

    QWidget::setWindowTitle("Recherche générale");

    ui->cb_donnee->addItem("Contact");
    ui->cb_donnee->addItem("Interaction");
    ui->cb_donnee->addItem("Tâches");

    ui->tw_donnee->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QObject::connect(ui->check_apres, SIGNAL(toggled(bool)), this, SLOT(reactualiserTable()));
    QObject::connect(ui->check_avant, SIGNAL(toggled(bool)), this, SLOT(reactualiserTable()));

    QObject::connect(ui->de_apres, SIGNAL(dateChanged(QDate)), this, SLOT(reactualiserTable()));
    QObject::connect(ui->de_avant, SIGNAL(dateChanged(QDate)), this, SLOT(reactualiserTable()));

    QObject::connect(ui->cb_donnee, SIGNAL(currentIndexChanged(int)), this, SLOT(reactualiserTable()));

    setupColonne();
    setupDonnee();

}

void WindowRecherche::setupColonne()
{
    ui->tw_donnee->horizontalHeader()->sortIndicatorOrder();
    //Contact selectionné
    if(ui->cb_donnee->currentIndex() == 0)
    {
        ui->tw_donnee->setColumnCount(3);
        //Nom, prénom et date de création
        ui->tw_donnee->setHorizontalHeaderLabels(QStringList() << "Nom" << "Prénom" << "Date de création");

    }
    //Interaction
    else if (ui->cb_donnee->currentIndex() == 1)
    {
        ui->tw_donnee->setColumnCount(2);
        ui->tw_donnee->setHorizontalHeaderLabels(QStringList() << "Contenu" << "Date");
    }
    else
    {
        ui->tw_donnee->setColumnCount(2);
        ui->tw_donnee->setHorizontalHeaderLabels(QStringList() << "Contenu" << "Date");
    }
}

void WindowRecherche::setupDonnee()
{
    //On charge les données de tous les contacts
    if(ui->cb_donnee->currentIndex() == 0)
    {
        ui->tw_donnee->setRowCount(m_p_gt->getNombreElements());
        for(int i = 0; i < m_p_gt->getNombreElements(); i++)
        {
            ui->tw_donnee->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).getNom())));
            ui->tw_donnee->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).getPrenom())));
            ui->tw_donnee->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).getDateCreation().getDateStrFormat())));
        }
    }
    else if(ui->cb_donnee->currentIndex() == 1)
    {
        int row = 0;
        for(int i = 0; i < m_p_gt->getNombreElements(); i++)
        {
            for(int j = 0; j < m_p_gt->getElement(i).getNombreInteraction(); j++)
            {
                row++;
                ui->tw_donnee->setRowCount(row);
                ui->tw_donnee->setItem(row-1, 0, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).interactions().getElement(j).getContenu())));
                ui->tw_donnee->setItem(row-1, 1, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).interactions().getElement(j).getDate().getDateStrFormat())));

            }
        }
    }
    else
    {
        int row = 0;
        //Pour chaque contact
        for(int i = 0; i < m_p_gt->getNombreElements(); i++)
        {
            //Pour chaque interaction du contact
            for(int j = 0; j < m_p_gt->getElement(i).getNombreInteraction(); j++)
            {
                //Pour chaque tache de chaque interaction de chaque contact
                for(int k = 0; k < m_p_gt->getElement(i).interactions().getElement(j).getNombreTache(); k++)
                {
                    row++;
                    ui->tw_donnee->setRowCount(row);
                    ui->tw_donnee->setItem(row-1, 0, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).interactions().getElement(j).taches().getElement(k).getContenu())));
                    ui->tw_donnee->setItem(row-1, 1, new QTableWidgetItem(QString::fromStdString(m_p_gt->getElement(i).interactions().getElement(j).taches().getElement(k).getDate().getDateStrFormat())));
                }
            }
        }
    }
}

void WindowRecherche::filtrerParDate()
{
    const QDate dateFiltreApres = ui->de_apres->date();
    const QDate dateFiltreAvant = ui->de_avant->date();
    for(int i = ui->tw_donnee->rowCount()-1; i >=0; --i)
    {

        QDate dateCellule = QDate::fromString(ui->tw_donnee->item(i, ui->tw_donnee->columnCount()-1)->text(), "dd/MM/yyyy");
        if(!dateCellule.isValid())
        {
            dateCellule = QDate::fromString(ui->tw_donnee->item(i, ui->tw_donnee->columnCount()-1)->text(), "d/MM/yyyy");
        }

        if(!dateCellule.isValid())
        {
            dateCellule = QDate::fromString(ui->tw_donnee->item(i, ui->tw_donnee->columnCount()-1)->text(), "dd/M/yyyy");
        }

        if(!dateCellule.isValid())
        {
            dateCellule = QDate::fromString(ui->tw_donnee->item(i, ui->tw_donnee->columnCount()-1)->text(), "d/M/yyyy");
        }

        if(ui->check_apres->isChecked())
        {

            if(dateCellule < dateFiltreApres)
            {
                ui->tw_donnee->removeRow(i);
            }
        }
        if(ui->check_avant->isChecked())
        {

            if(dateCellule > dateFiltreAvant)
            {
                ui->tw_donnee->removeRow(i);
            }
        }
    }
}

void WindowRecherche::on_check_trier_toggled(bool checked)
{
    ui->tw_donnee->setSortingEnabled(checked);
}

void WindowRecherche::reactualiserTable()
{
    ui->tw_donnee->setSortingEnabled(false);
    ui->tw_donnee->clear();
    setupColonne();
    setupDonnee();
    if(ui->check_apres->isChecked() || ui->check_avant->isChecked())
    {
        filtrerParDate();
    }
    ui->tw_donnee->setSortingEnabled(ui->check_trier->isChecked());
}

