#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include "interaction.h"

#include <list>

class GestionInteraction
{
private:
    std::list<Interaction> listInteraction;
public:
    GestionInteraction();
    void ajoutInteraction(const Interaction& in);
    bool supprimerInteraction(const Interaction& in);
    std::pair<Interaction, bool> getInteraction(const std::string contenu);
    std::pair<Interaction, bool> getInteraction(const int nb);
};

#endif // GESTIONINTERACTION_H
