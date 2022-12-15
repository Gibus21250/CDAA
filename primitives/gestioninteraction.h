#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include "interaction.h"
#include <list>

/**
 * @brief Classe gérant une liste d'Interaction
 */
class GestionInteraction : public Gestionnaire<Interaction>
{

public:
    ///Constructeur par défaut
    GestionInteraction();

    ///Supprime l'instance Interaction associé à l'ID en paramètre
    bool supprimerParId(const unsigned IdI);

};

#endif // GESTIONINTERACTION_H
