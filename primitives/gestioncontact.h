#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include "contact.h"
#include <list>

class GestionContact : public Gestionnaire<Contact>
{

public:
    GestionContact();

    bool supprimerParId(const unsigned IdC);
};

#endif // GESTIONCONTACT_H
