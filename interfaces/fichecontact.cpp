#include <QMouseEvent>
#include <QLineEdit>
#include <QFileDialog>

#include "fichecontact.h"
#include "interactionwidget.h"
#include "ui_ficheContact.h"
#include "doubleclickqlabel.h"

FicheContact::FicheContact(QWidget *parent, Contact* p_contact)
    : QDialog{parent}, ui(new Ui::FicheContact()), m_p_contact(p_contact), modeEdition(false), quiEstEdite(-1)
{
    ui->setupUi(this);

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

    QString uriImage;
    if(m_p_contact->getUriPhoto().empty()) uriImage = ":/profileImg/no-image";
    else uriImage = QString::fromStdString(m_p_contact->getUriPhoto());

    QPixmap pix(uriImage);

    m_dcl[5]->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));


    //Ajout de l'image à gauche du layout
    ui->layout_infosPrincipales->insertWidget(0, m_dcl[5]);

    //Ajout nom et prenom
    ui->layout_nom_prenom->addWidget(m_dcl[0]);
    ui->layout_nom_prenom->addWidget(m_le[0]);

    ui->layout_nom_prenom->addWidget(m_dcl[1]);
    ui->layout_nom_prenom->addWidget(m_le[1]);

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

    ui->te_information->setReadOnly(true);

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
    ui->te_information->clear();

    InteractionWidget* iw = dynamic_cast<InteractionWidget*>(ui->lw_interactions->itemWidget(ui->lw_interactions->currentItem()));

    ui->te_information->append(QString::fromStdString(iw->p_interaction()->getContenu()));
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

    ui->te_information->append(lineTodo);
}

void FicheContact::modEditionInformation(char type)
{
    std::cout << "Double clique sur " << '0' + type << std::endl;
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
                m_p_contact->setUriPhoto(dir.toStdString());
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

    ui->te_information->setEnabled(mode);
    ui->lw_interactions->setEnabled(mode);

    if(!mode)
    {
        ui->l_info->setText("Appuyez sur la touche Entrer pour valider, Echap pour annuler");
    }
}

void FicheContact::keyPressEvent(QKeyEvent *event)
{
    if(modeEdition)
    {
        if (event->key() == Qt::Key_Return)
        {
            changerEtatPourEdition(true);
            m_le[(int) quiEstEdite]->setVisible(false);
            m_dcl[(int) quiEstEdite]->setVisible(true);

            m_dcl[(int) quiEstEdite]->setText(m_le[(int) quiEstEdite]->text());

            switch (quiEstEdite) {
            case 0:
                m_p_contact->setNom(m_le[(int) quiEstEdite]->text().toStdString());
                break;
            case 1:
                m_p_contact->setPrenom(m_le[(int) quiEstEdite]->text().toStdString());
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
            m_le[(int) quiEstEdite]->setVisible(false);
            m_dcl[(int) quiEstEdite]->setVisible(true);

            quiEstEdite = -1;
            modeEdition = false;
        }
    }
}

FicheContact::~FicheContact()
{
    delete ui;
}
