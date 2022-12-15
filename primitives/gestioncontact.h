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
};

#endif // GESTIONCONTACT_H
