#include "gestiontache.h"

GestionTache::GestionTache(){}

void GestionTache::ajoutTache(const Tache& tache)
{
    m_lTache.push_back(new Tache(tache)); //Push_back fait un copy de la tache en argument
}

bool GestionTache::supprimerTache(const Tache &tache)
{
    bool finded = false;
    for(auto it = m_lTache.begin(); it != m_lTache.end() && !finded; ++it){
        if(**it == tache){
            delete *it;                 //On détruit l'objet dans le tas
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

std::pair<Tache*, bool> GestionTache::getTache(const unsigned indice) const
{
    if(indice < (int) m_lTache.size())
    {
        auto element = m_lTache.begin();
        std::advance(element, indice);
        return std::make_pair(*element, true);
    }

    return std::make_pair(nullptr, false);
}

GestionTache::~GestionTache()
{
    for(auto& ptr_tache : m_lTache) delete ptr_tache;
    m_lTache.clear();
}

std::ostream& operator<<(std::ostream& out, const GestionTache& c)
{
    if(c.getNombreTache() != 0)
    {
        for(auto& tache : c.m_lTache)
        {
            out << *tache << std::endl;
        }
    }
    return out;
}
