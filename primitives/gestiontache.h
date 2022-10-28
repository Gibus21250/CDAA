#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include "tache.h"
#include <list>

class GestionTache
{
private:
    std::list<Tache> lTache;

public:
    GestionTache();
    void ajoutTache(const Tache in);
    bool supprimerTache(const Tache& in);
    unsigned getNombreTache() const;

    friend std::ostream& operator<<(std::ostream& out, const GestionTache& c);
};

#endif // GESTIONTACHE_H
