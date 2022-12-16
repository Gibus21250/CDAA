#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include "contact.h"
#include <list>

/**
 * @brief Classe gérant une liste de Contact
 */
class GestionContact : public Gestionnaire<Contact>
{

public:
    ///Constructeur par défaut
    GestionContact();

    ///Supprime l'instance Contact associé à l'ID en paramètre
    bool supprimerParId(const unsigned IdC);

    /**
     * @brief Permet de récupérer l'instance de GestionContact avec dedans toutes les Contacts étant dans l'entreprise 'mot'
     * @param mot Le mot à tester
     * @return Un nouveau GestionContact contenant des Contacts satisfaisant la condition
     */
    GestionContact& getContactsEntreprise(const std::string& mot);

    /**
     * @brief Permet de récupérer l'instance de GestionContact avec dedans toutes les Contacts se passant avant la date en agument
     * @param date La date a tester
     * @return Un nouveau GestionContact contenant des Interactions satisfaisant la condition
     */
    GestionContact& getContactsAvantCreation(const DateSimple& date);

    /**
     * @brief Permet de récupérer l'instance de GestionContact avec dedans toutes les Contacts se passant après la date en agument
     * @param date La date a tester
     * @return Un nouveau GestionContact contenant des Contacts satisfaisant la condition
     */
    GestionContact& getContactsApresCreation(const DateSimple& date);

    /**
     * @brief Permet de récupérer l'instance de GestionContact avec dedans toutes les Contacts se passant avant la date en agument
     * @param date La date a tester
     * @return Un nouveau GestionContact contenant des Interactions satisfaisant la condition
     */
    GestionContact& getContactsAvantModif(const DateSimple& date);

    /**
     * @brief Permet de récupérer l'instance de GestionContact avec dedans toutes les Contacts se passant après la date en agument
     * @param date La date a tester
     * @return Un nouveau GestionContact contenant des Contacts satisfaisant la condition
     */
    GestionContact& getContactsApresModif(const DateSimple& date);

};


#endif // GESTIONCONTACT_H
