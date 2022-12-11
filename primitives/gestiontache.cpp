#include "gestiontache.h"

GestionTache::GestionTache(){}

bool GestionTache::supprimerParId(const unsigned IdT)
{
    bool finded = false;
    for(auto it = m_list.begin(); it != m_list.end() && !finded; ++it){
        if(it->IdT() == IdT)
        {
            m_list.erase(it);           //On le supprime de la list
            finded = true;              //Pour terminer la boucle
            break;
        }
    }
    return finded;
}


