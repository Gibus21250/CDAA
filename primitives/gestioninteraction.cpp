#include <iterator>
#include "gestioninteraction.h"
#include <iostream>

GestionInteraction::GestionInteraction() {}

bool GestionInteraction::supprimerParId(const unsigned IdC)
{
    bool finded = false;
    for(auto it = m_list.begin(); it != m_list.end() && !finded; ++it){
        if(it->IdI() == IdC)
        {
            m_list.erase(it);           //On le supprime de la list
            finded = true;              //Pour terminer la boucle
            break;
        }
    }
    return finded;
}
