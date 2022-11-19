#include "gestiontache.h"

GestionTache::GestionTache(){}

void GestionTache::ajoutTache(const Tache& tache)
{
    m_lTache.push_back(tache);
}

bool GestionTache::supprimerTache(const Tache &tache)
{
    bool finded = false;
    for(auto it = m_lTache.begin(); it != m_lTache.end() && !finded; ++it){
        if(*it == tache){
            m_lTache.erase(it);
            finded = true;    //Pour terminer la boucle
        }
    }
    return finded;
}

unsigned GestionTache::getNombreTache() const
{
    return m_lTache.size();
}

std::ostream& operator<<(std::ostream& out, const GestionTache& c)
{
    if(c.getNombreTache() != 0)
    {
        for(auto& tache : c.m_lTache)
        {
            out << tache << std::endl;
        }
    }
    return out;
}
