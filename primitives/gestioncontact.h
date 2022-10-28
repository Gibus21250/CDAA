#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include "contact.h"
#include <list>

class GestionContact
{
private:
    std::list<Contact> listContact;
public:
    GestionContact();
    void ajoutContact(const Contact& in);
    bool supprimerContact(const Contact& in);
};

#endif // GESTIONCONTACT_H
