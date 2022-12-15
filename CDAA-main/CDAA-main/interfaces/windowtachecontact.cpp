#include "windowtachecontact.h"

#include "ui_windowTacheContact.h"
#include <QDate>

WindowTacheContact::WindowTacheContact(QWidget *parent, std::list<Tache*>* list,
                                       const Contact* who, const QDate* apres, const QDate* avant, const bool filtre)
    : QDialog{parent}, ui(new Ui::WindowTacheContact())
{
    ui->setupUi(this);
    QWidget::setWindowTitle(QString::fromStdString("Liste de tâche"));

    ui->l_infos->setText("Voici la liste des tâches de "
                         + QString::fromStdString(who->getNom())
                         + " "
                         + QString::fromStdString(who->getPrenom()));

    if(filtre)
    {
        //On affiche les tâches avant la date
        if(apres != nullptr && avant == nullptr)
        {
             ui->l_infoDates->setText("Après le " + apres->toString("dd/MM/yyyy"));
        }
        //On affiche les tâches apres la date
        else if(apres == nullptr && avant != nullptr)
        {
            ui->l_infoDates->setText("Avant le " + avant->toString("dd/MM/yyyy"));
        }
        //On affiche les tâches entre deux dates
        else
        {
            ui->l_infoDates->setText("Entre le "
                                     + apres->toString("dd/MM/yyyy")
                                     + " et le "
                                     + avant->toString("dd/MM/yyyy")
                                     + ":");
        }
    }
    //Pas de filtre -> on affiche donc tout
    else
    {
        ui->l_infoDates->setText("");
    }


    for(Tache* pt : *list)
    {
        ui->lw_taches->addItem("@todo " + QString::fromStdString(pt->getContenu()) + " @date " + QString::fromStdString(pt->getDate().getDateStrFormat()));
    }
}

void WindowTacheContact::on_pb_fermer_clicked()
{
    close();
}

