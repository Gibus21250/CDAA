#include "gestiontache.h"

GestionTache::GestionTache()
{

}

void GestionTache::ajoutTache(const Tache tache)
{
    lTache.push_back(tache);
}

bool GestionTache::supprimerTache(const Tache &tache)
{
    bool done = false;
    for(auto it = lTache.begin(); it != lTache.end() && !done; ++it){
        if(*it == tache){
            lTache.erase(it);
            done = true;    //Pour terminer la boucle
        }
    }
    return done;
}

unsigned GestionTache::getNombreTache() const
{
    return lTache.size();
}

std::ostream& operator<<(std::ostream& out, const GestionTache& c)
{
    if(c.getNombreTache() != 0)
    {
        for(auto tache : c.lTache)
        {
            out << tache << std::endl;
        }
    }
    return out;
}
