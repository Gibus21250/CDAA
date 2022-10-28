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
    void ajoutInteraction(const Interaction in);
    bool supprimerInteraction(const Interaction& in);
    unsigned getNombreInteraction() const;
    std::pair<Interaction, bool> getInteraction(const std::string contenu);
    std::pair<Interaction, bool> getInteraction(const int nb);
    std::list<Interaction> getListInteraction() const;

    friend std::ostream& operator<<(std::ostream& out, const GestionInteraction& c);
};

#endif // GESTIONINTERACTION_H
