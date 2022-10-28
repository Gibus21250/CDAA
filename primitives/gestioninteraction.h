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
    void addInteraction(const Interaction& in);
    bool removeInteraction(const Interaction& in);
    std::pair<Interaction, bool> getInteraction(const std::string contenu);
    std::pair<Interaction, bool> getInteraction(const int nb);
    const std::list<Interaction> &getListInteraction() const;
};

#endif // GESTIONINTERACTION_H
