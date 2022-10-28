#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include "contact.h"
#include <list>

class GestionContact
{
private:
    /**
     * @brief Les contacts sont stockés dans une liste
     */
    std::list<Contact> listContact;
public:
    GestionContact();
    /**
     * @brief Permet d'ajouter un contact
     * @param Le contact à ajouter
     */
    void ajoutContact(const Contact& in);
    /**
     * @brief Permet de supprimer un contact
     * @param Le contact à supprimer
     * @return un boolean
     */
    bool supprimerContact(const Contact& in);
};

#endif // GESTIONCONTACT_H
