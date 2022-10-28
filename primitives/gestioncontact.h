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

    /**
     * @brief Renvoie la liste de contacts
     * @return
     */
    std::list<Contact> getListContact() const;

    /**
     * @brief Renvoie le no contact ajoute à la liste
     * @param no
     * @return
     */
    Contact getContact(const int no);

    friend std::ostream& operator<<(std::ostream& out, const GestionContact& c);

};

#endif // GESTIONCONTACT_H
