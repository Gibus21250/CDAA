#include <QMouseEvent>
#include <QLineEdit>
#include <QFileDialog>
#include <QTextBlock>

#include "fichecontact.h"
#include "interactionwidget.h"
#include "ui_ficheContact.h"
#include "doubleclickqlabel.h"

FicheContact::FicheContact(QWidget *parent, Contact* p_contact, const MainSQLManager* manager)
    : QDialog{parent}, ui(new Ui::FicheContact()), m_p_contact(p_contact), manager(manager), modeEdition(false), quiEstEdite(-1)
{
    ui->setupUi(this);

    QWidget::setWindowTitle(QString::fromStdString("Fiche contact: " + p_contact->getNom() + " " + p_contact->getPrenom()));

    QObject::connect(ui->check_apres, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));
    QObject::connect(ui->check_avant, SIGNAL(toggled(bool)), this, SLOT(onFiltreDateActive(bool)));

    QObject::connect(ui->de_avant, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));
    QObject::connect(ui->de_apres, SIGNAL(dateChanged(QDate)), this, SLOT(onDateEditChange()));

    ui->de_apres->setDate(QDateTime::currentDateTime().date());
    ui->de_avant->setDate(QDateTime::currentDateTime().date());

    /**
     * Explications:
     * Nous avons 6 pointeurs de notre QLabel custom
     * 0: nom, 1: prenom, 2: tel, 3: mail, 4: entreprise, 5: photo
     * et en parallèle nous avons 5 QLineEdit
     * 0: nom, 1: prenom, 2: tel, 3: mail, 4: entreprise
     * Celui de la photo sera géré par la QDialogFile (pour aller chercher une nouvelle photo)
     *
     * Chaque QlineEdit est dans un premier temps caché, il sera visible uniquement quand le label aura
     * reçu un double click, dans lequel cas on entrera en mode edition de cet attribut
     * du contact
     **/
    for(int i = 0; i < 6; i++)
    {
        m_dcl[i] = new DoubleClickQLabel(this, i);

        m_le[i] = new QLineEdit(this);
        m_le[i]->setVisible(false);

        QObject::connect(m_dcl[i], SIGNAL(doubleClicked(char)), this, SLOT(modEditionInformation(char)));
    }

    m_dcl[0]->setText(QString::fromStdString(m_p_contact->getNom()));
    m_dcl[1]->setText(QString::fromStdString(m_p_contact->getPrenom()));
    m_dcl[2]->setText(QString::fromStdString(m_p_contact->getTelephone()));
    m_dcl[3]->setText(QString::fromStdString(m_p_contact->getMail()));
    m_dcl[4]->setText(QString::fromStdString(m_p_contact->getEntreprise()));

    m_dcl[0]->setMaximumWidth(200);
    m_dcl[1]->setMaximumWidth(200);
    m_dcl[2]->setMaximumWidth(200);
    m_dcl[3]->setMaximumWidth(200);
    m_dcl[4]->setMaximumWidth(200);

    QFont font = QFont();
    font.setPointSize(10);

    m_dcl[0]->setFont(font);
    m_dcl[1]->setFont(font);
    m_dcl[2]->setFont(font);
    m_dcl[3]->setFont(font);
    m_dcl[4]->setFont(font);

    m_le[0]->setMaximumWidth(200);
    m_le[1]->setMaximumWidth(200);
    m_le[2]->setMaximumWidth(200);
    m_le[3]->setMaximumWidth(200);

    m_le[0]->setFont(font);
    m_le[1]->setFont(font);
    m_le[2]->setFont(font);
    m_le[3]->setFont(font);

    QString uriImage;
    if(m_p_contact->getPhoto().empty()) uriImage = ":/profileImg/no-image";
    else uriImage = QString::fromStdString(m_p_contact->getPhoto());

    QPixmap pix(uriImage);

    m_dcl[5]->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
    m_dcl[5]->setFixedHeight(100);
    m_dcl[5]->setFixedWidth(100);

    //Ajout de l'image à gauche du layout
    ui->layout_infosPrincipales->insertWidget(0, m_dcl[5]);

    //Ajout nom et prenom
    ui->layout_nom_prenom->addWidget(m_dcl[0]);
    ui->layout_nom_prenom->addWidget(m_le[0]);

    ui->layout_nom_prenom->addWidget(m_le[1]);
    ui->layout_nom_prenom->addWidget(m_dcl[1]);

    //Ajout mail et tel
    ui->layout_mail_tel->addWidget(m_dcl[3]);
    ui->layout_mail_tel->addWidget(m_le[3]);
    ui->layout_mail_tel->addWidget(m_dcl[2]);
    ui->layout_mail_tel->addWidget(m_le[2]);

    //Ajout de l'entreprise
    ui->layout_infos->addWidget(m_dcl[4]);
    ui->layout_infos->addWidget(m_le[4]);
    ui->layout_infos->setAlignment(m_dcl[4], Qt::AlignCenter);
    ui->layout_infos->setAlignment(m_le[4], Qt::AlignCenter);


    // ---- Fin ajout ---- //

    dcte = new DoubleClickTextEditor(this);
    dcte->setReadOnly(true);
    dcte->setEnabled(false);

    ui->de_interaction->setEnabled(false);

    ui->layout_taches->insertWidget(1, dcte);

    QObject::connect(dcte, SIGNAL(doubleClique()), this, SLOT(doubleCliqueTextEditor()));

    QObject::connect(ui->b_ajout_interaction, SIGNAL(clicked()), this, SLOT(ajouterInteraction()));
    QObject::connect(ui->b_supp_interaction, SIGNAL(clicked()), this, SLOT(supprimerInteraction()));

    QObject::connect(ui->lw_interactions, SIGNAL(currentRowChanged(int)), this, SLOT(interactionChange()));

    for(unsigned i = 0; i < m_p_contact->getNombreInteraction(); i++)
    {
        InteractionWidget* iw = new InteractionWidget(this, &(m_p_contact->interactions().getElement(i)));
        auto item = new QListWidgetItem();

        item->setSizeHint(iw->sizeHint());

        ui->lw_interactions->addItem(item);
        ui->lw_interactions->setItemWidget(item, iw);
    }
}

void FicheContact::interactionChange()
{
    dcte->clear();

    if(ui->lw_interactions->currentRow() != -1)
    {
        dcte->setEnabled(true);
        actualiserContenuTextEdit();
    }
    else
    {
        dcte->setEnabled(false);
    }

}

void FicheContact::modEditionInformation(char type)
{
    if(type == 5)
    {
        QString dir = QFileDialog::getOpenFileName(this, tr("Image de profil"), QDir::currentPath());

        if(!dir.isEmpty())
        {
            //On charge le fichier que l'utilisateur nous a donné
            QPixmap pix(dir);
            //Si succes, on change l'image coté IHM et dans l'instance Joueur
            if(!pix.isNull())
            {
                m_dcl[5]->setPixmap(pix.scaled(75, 75, Qt::KeepAspectRatio));
                m_p_contact->setPhoto(dir.toStdString());
            }
        }
    }
    else
    {
        m_dcl[(int)type]->setVisible(false);
        m_le[(int)type]->setText(m_dcl[(int)type]->text());
        m_le[(int)type]->setVisible(true);
        changerEtatPourEdition(false);
        modeEdition = true;
        quiEstEdite = type;

        ui->l_info->setText("Appuyez sur la touche Entrer pour valider, Echap pour annuler");
    }

}

void FicheContact::changerEtatPourEdition(bool mode)
{
    ui->b_ajout_interaction->setEnabled(mode);
    ui->b_supp_interaction->setEnabled(mode);

    for(int i = 0; i < 6; i++)
    {
        m_dcl[i]->setEnabled(mode);
    }

    dcte->setEnabled(mode);
    ui->lw_interactions->setEnabled(mode);
}

void FicheContact::keyPressEvent(QKeyEvent *event)
{
    if(modeEdition)
    {
        //Si le mode edition est activé les attributs du contact (0 1 2 3 4 ou 5)
        if (event->key() == Qt::Key_Return && quiEstEdite != -1)
        {
            changerEtatPourEdition(true);
            m_le[(int) quiEstEdite]->setVisible(false);
            m_dcl[(int) quiEstEdite]->setVisible(true);

            m_dcl[(int) quiEstEdite]->setText(m_le[(int) quiEstEdite]->text());

            switch (quiEstEdite) {
            case 0:
                m_p_contact->setNom(m_le[(int) quiEstEdite]->text().toStdString());
                QWidget::setWindowTitle(QString::fromStdString("Fiche contact: " + m_p_contact->getNom() + " " + m_p_contact->getPrenom()));
                break;
            case 1:
                m_p_contact->setPrenom(m_le[(int) quiEstEdite]->text().toStdString());
                QWidget::setWindowTitle(QString::fromStdString("Fiche contact: " + m_p_contact->getNom() + " " + m_p_contact->getPrenom()));
                break;
            case 2:
                m_p_contact->setTelephone(m_le[(int) quiEstEdite]->text().toStdString());
                break;
            case 3:
                m_p_contact->setMail(m_le[(int) quiEstEdite]->text().toStdString());
                break;
            case 4:
                m_p_contact->setEntreprise(m_le[(int) quiEstEdite]->text().toStdString());
                break;
            default:
                break;
            }

            quiEstEdite = -1;
            modeEdition = false;

        }
        else if (event->key() == Qt::Key_Escape)
        {
            changerEtatPourEdition(true);
            //On annule l'edition des attributs du contacts
            if(quiEstEdite != -1)
            {
                m_le[(int) quiEstEdite]->setVisible(false);
                m_dcl[(int) quiEstEdite]->setVisible(true);
            }
            //Ici on doit annuler les modifications de l'interaction du contact
            else
            {
                dcte->setReadOnly(true);

                actualiserContenuTextEdit();

                ui->de_interaction->setEnabled(false);

            }
            quiEstEdite = -1;
            modeEdition = false;
        }
        //Ici on cherche à enregistrer les modifications d'une interactions
        else if (event->matches(QKeySequence::Save) && quiEstEdite == -1)
        {

            Interaction I;

            //On récupère la nouvelle date sous intance DateSimple
            QDate d = ui->de_interaction->date();

            DateSimple dateI(d.year(), d.month(), d.day());

            I.setDate(dateI);

            InteractionWidget* iw = dynamic_cast<InteractionWidget*>(ui->lw_interactions->itemWidget(ui->lw_interactions->currentItem()));

            //On oublie pas de copier aussi l'ID de l'interaction!
            I.setIdI(iw->p_interaction()->IdI());

            // --------------PARTIE DECOUPAGE DU TEXT ET RCUPERATION DONNEES----------------- //

            manager->supprimerToutTache(iw->p_interaction()->IdI());

            QTextDocument* qDoc = dcte->document();
            QTextCursor c(qDoc);

            //On récupère la première ligne du textedit, qui est la ligne décrivant l'interaction
            QTextBlock tb = qDoc->findBlockByLineNumber(0);
            QString descInteraction = tb.text();

            I.setContenu(descInteraction.toStdString());

            //On va découper chaque todo et en extraillant la date (si tag @date trouvé)
            QTextDocument::FindFlags fcs = (QTextDocument::FindFlag) 0;

            QRegularExpression reg("^@todo .*$");

            Tache tache;
            std::string ligne, descTache, dateStrTache;

            while(!(c = qDoc->find(reg, c.position(), fcs)).isNull())
            {
                ligne = c.block().text().toStdString();
                descTache = ligne.substr(6, ligne.length());
                auto pos = descTache.find("@date");

                //Si le tag @date a été trouvé, on doit modifier à la fois la desc de la tache et récupérer la date
                if(pos != std::string::npos)
                {
                    dateStrTache = descTache.substr(pos+6, descTache.length());
                    descTache = descTache.substr(0, pos-1);
                }
                if(dateStrTache.empty())
                {
                    //Dans l'énoncé, il est dit de mettre la date d'aujourdhui, si pas de @date trouvé
                    tache = Tache(-1, descTache, DateSimple());
                }
                else
                {
                    tache = Tache(-1, descTache, dateStrTache);
                }
                manager->ajouterTache(iw->p_interaction()->IdI(), &tache);
                I.ajouterTache(tache);
            }



            //On modifie directement dans la mémoire la nouvelle Interaction
            *iw->p_interaction() = I;

            iw->p_interaction()->setIdI(I.IdI());

            manager->modifierInteraction(iw->p_interaction());
            iw->actualiserInfoWidget();

            ui->de_interaction->setEnabled(false);
            dcte->setReadOnly(true);
            actualiserContenuTextEdit();
            quiEstEdite = -1;
            modeEdition = false;

            changerEtatPourEdition(true);

        }
        ui->l_info->setText("Double cliquez sur le contenu pour modifier le contenu de l'interaction");
    }
}

void FicheContact::ajouterInteraction()
{

    Interaction i(-1, "Remplir contenu");
    manager->ajouterInteraction(m_p_contact->getIdC(), &i);
    m_p_contact->ajoutInteraction(i);

    int nbI = m_p_contact->getNombreInteraction();

    InteractionWidget* iw = new InteractionWidget(this, &(m_p_contact->interactions().getElement(nbI-1)));
    auto item = new QListWidgetItem();

    item->setSizeHint(iw->sizeHint());

    ui->lw_interactions->addItem(item);
    ui->lw_interactions->setItemWidget(item, iw);
}

void FicheContact::actualiserContenuTextEdit()
{
    dcte->clear();

    InteractionWidget* iw = dynamic_cast<InteractionWidget*>(ui->lw_interactions->itemWidget(ui->lw_interactions->currentItem()));

    dcte->insertPlainText(QString::fromStdString(iw->p_interaction()->getContenu()));

    ui->de_interaction->setDate(QDate(iw->p_interaction()->getDate().getAnnee()
                                      , iw->p_interaction()->getDate().getMois(),
                                      iw->p_interaction()->getDate().getJour()));

    QString lineTodo;
    for(int i = 0; i < iw->p_interaction()->getNombreTache(); i++)
    {
        lineTodo.append("@todo ");
        lineTodo.append(iw->p_interaction()->taches().getElement(i).getContenu().c_str());
        if(iw->p_interaction()->taches().getElement(i).isDatee())
        {
            lineTodo.append(" @date ");
            lineTodo.append(iw->p_interaction()->taches().getElement(i).getDate().getDateStrFormat().c_str());
        }
        lineTodo.append('\n');
    }

    dcte->append(lineTodo);
}

void FicheContact::supprimerInteraction()
{
    //On vérifie qu'il y a bien un item de séléctionné
    if(ui->lw_interactions->selectedItems().count() != 0)
    {

        //On récupère le InteractionWidget associé à l'item de la QListWidget
        InteractionWidget* cw = dynamic_cast<InteractionWidget*>(ui->lw_interactions->itemWidget(ui->lw_interactions->currentItem()));

        manager->supprimerInteraction(cw->p_interaction()->IdI());

        //utilisation de supprimerInteraction avec un indice, car supprime interaction par instance
        //Est de une: lourde (compare chaque instance une par une)
        //Mais le plus grave, c'est qu'elle supprime la première instance correspondant, qui n'est donc pas
        //forcément celle selectionné dans l'IHM (car deux instances peuvent être identique, pour autant
        //L'utilisateur les vois comme differente.
        m_p_contact->supprimerInteraction(ui->lw_interactions->currentRow());

        ui->lw_interactions->removeItemWidget(ui->lw_interactions->currentItem());
        delete ui->lw_interactions->currentItem();

    }
}

void FicheContact::doubleCliqueTextEditor()
{
    ui->l_info->setText("Echap pour annuler les modifications | ctrl+s pour enregistrer");
    modeEdition = true;
    changerEtatPourEdition(false);
    dcte->setReadOnly(false);
    dcte->setEnabled(true);
    ui->de_interaction->setEnabled(true);
}

void FicheContact::reafficherListe()
{
    for(int i = 0; i < ui->lw_interactions->count(); ++i)
    {
        ui->lw_interactions->item(i)->setHidden(false);
    }
}

void FicheContact::onFiltreDateActive(bool checked)
{
    if(checked)
    {
        reafficherListe();
        filtrerListeParDate();
    }
    else
    {
        reafficherListe();
    }
}

void FicheContact::filtrerListeParDate()
{

    for(int i = 0; i < ui->lw_interactions->count(); ++i)
    {
        InteractionWidget* cw = dynamic_cast<InteractionWidget*>(
                    ui->lw_interactions->itemWidget(ui->lw_interactions->item(i)));


        if(ui->check_apres->isChecked())
        {
            const QDate sdate = ui->de_apres->date();

            DateSimple date(sdate.year(), sdate.month(), sdate.day());

            if(cw->p_interaction()->getDate() < date)
            {
                ui->lw_interactions->item(i)->setHidden(true);
            }
        }
        if(ui->check_avant->isChecked())
        {

            const QDate sdate = ui->de_avant->date();
            DateSimple date(sdate.year(), sdate.month(), sdate.day());

            if(cw->p_interaction()->getDate() > date)
            {
                ui->lw_interactions->item(i)->setHidden(true);
            }
        }
    }

}

void FicheContact::onDateEditChange()
{
    if(ui->check_apres->isChecked() || ui->check_avant->isChecked())
    {
        reafficherListe();
        filtrerListeParDate();
    }
}

FicheContact::~FicheContact()
{
    delete ui;
}
