#ifndef MAINSQLMANAGER_H
#define MAINSQLMANAGER_H

#include <QtSql/QSqlDatabase>

#include "primitives/gestioncontact.h"

class MainSQLManager
{

private:

    bool isConnected;
    QSqlDatabase db;

public:

    bool connectTo(const std::string& pathFichier);
    bool verifierSchema() const;

    bool getIsConnected() const;

    void chargerBaseDeDonnee(GestionContact* gt) const;

    /////////////////////////////
    /// Partie des Contacts   ///
    /////////////////////////////

    bool ajouterContact(Contact* contact) const;
    bool supprimerContact(const int IdC) const;
    bool modifierContact(const Contact* contact) const;


    ////////////////////////////////
    /// Partie des Interactions  ///
    ////////////////////////////////

    bool ajouterInteraction(const int IdC, Interaction* inter) const;
    bool supprimerInteraction(const int IdC) const;
    bool modifierInteraction(const Interaction* inter) const;

    ////////////////////////////////
    ///    Partie des Tâches     ///
    ////////////////////////////////

    bool ajouterTache(const int IdI, Tache* tache) const;
    bool supprimerTache(const int IdT) const;
    bool modifierTache(const Tache* tache) const;

    void supprimerToutTache(const int IdI) const;
};

#endif // MAINSQLMANAGER_H
