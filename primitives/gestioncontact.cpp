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

GestionContact& GestionContact::getContactsEntreprise(const std::string &mot)
{

    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getEntreprise().find(mot) == std::string::npos)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionContact& GestionContact::getContactsAvantCreation(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDateModification() > date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionContact& GestionContact::getContactsApresCreation(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDateCreation() < date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionContact& GestionContact::getContactsAvantModif(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDateModification() > date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionContact& GestionContact::getContactsApresModif(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDateModification() < date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}
