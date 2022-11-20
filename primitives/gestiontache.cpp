#include "gestiontache.h"

GestionTache::GestionTache(){}

void GestionTache::ajoutTache(const Tache& tache)
{
    //Push_back fait un copy de la tache en argument
    //emplace_back instancie directement dans la list, sans faire une copy superflue de l'instance, comme push_back
    m_lTache.emplace_back(tache);
}

bool GestionTache::supprimerTache(const Tache &tache)
{
    bool finded = false;
    for(auto it = m_lTache.begin(); it != m_lTache.end() && !finded; ++it){
        if(*it == tache)
        {
            m_lTache.erase(it);         //On le supprime de la list
            finded = true;              //Pour terminer la boucle
        }
    }
    return finded;
}

unsigned GestionTache::getNombreTache() const
{
    return m_lTache.size();
}

void GestionTache::effacerTouteTache()
{
    m_lTache.clear();
}

std::pair<Tache, bool> GestionTache::getTache(const unsigned indice) const
{
    if(indice < (int) m_lTache.size())
    {
        auto element = m_lTache.begin();
        std::advance(element, indice);
        return std::make_pair(*element, true);
    }

    return std::make_pair(Tache(), false);
}

bool GestionTache::remplacer(const Tache& tache, const unsigned indice)
{
    if(indice < m_lTache.size())
    {
        //On récupère l'iterator au début de la liste
        auto element = m_lTache.begin();
        //On avance dans l'iterator
        std::advance(element, indice);
        //On supprime l'instance désignée
        m_lTache.erase(element);

        element = m_lTache.begin();
        std::advance(element, indice);
        m_lTache.emplace(element, tache);
        return true;
    }
    return false;
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
