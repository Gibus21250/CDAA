#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include "interaction.h"
#include <list>

class GestionInteraction : public Gestionnaire<Interaction>
{

public:
    GestionInteraction();

    bool supprimerParId(const unsigned IdI);

};

#endif // GESTIONINTERACTION_H
