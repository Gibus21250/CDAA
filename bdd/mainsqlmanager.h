#ifndef MAINSQLMANAGER_H
#define MAINSQLMANAGER_H

#include <QtSql/QSqlDatabase>
#include "primitives/contact.h"


class MainSQLManager
{

private:

    bool isConnected;
    QSqlDatabase db;

public:

    bool connectTo(const std::string& pathFichier);
    bool verifierSchema() const;

    bool getIsConnected() const;

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
};

#endif // MAINSQLMANAGER_H
