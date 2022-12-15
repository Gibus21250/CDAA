#include "gestioncontact.h"

GestionContact::GestionContact() {}

bool GestionContact::supprimerParId(const unsigned IdC)
{
    bool finded = false;
    for(auto it = m_list.begin(); it != m_list.end() && !finded; ++it){
        if(it->getIdC() == IdC)
        {
            m_list.erase(it);           //On le supprime de la list
            finded = true;              //Pour terminer la boucle
            break;
        }
    }
    return finded;
}
