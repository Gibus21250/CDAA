#ifndef CREATIONCONTACT_H
#define CREATIONCONTACT_H

#include <QDialog>

#include "primitives/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class CreationContact;
}
QT_END_NAMESPACE

class CreationContact : public QDialog
{
    Q_OBJECT

private:
    //pointeur du l'ui CreationContact
    Ui::CreationContact* ui;
    //Instance d'un contact
    Contact contact;
    //Uri de la photo de profil du contact
    QString uri;

public:
    explicit CreationContact(QWidget *parent = nullptr);

signals:
    /**
     * @brief Signal émit lors de la confirmation de la création du contact
     * @param c le contact crée
     */
    void creerContact(Contact& c);

private slots:
    /**
     * @brief Slot recepteur du clique du bouton créer
     */
    void terminerCreation();
    /**
     * @brief Slot recepteur du clique du bouton importer image de profile
     */
    void ouvrirDialogFichier();
    /**
     * @brief Slot recepteur du clique du bouton annuler
     * Annule la créaton du contact
     */
    void annulerCreation();
};

#endif // CREATIONCONTACT_H
