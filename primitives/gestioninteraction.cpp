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

GestionInteraction& GestionInteraction::getInteractionsContenant(const std::string &mot)
{

    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getContenu().find(mot) == std::string::npos)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionInteraction& GestionInteraction::getInteractionsAvant(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDate() > date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}

GestionInteraction& GestionInteraction::getInteractionsApres(const DateSimple &date)
{
    //On parcour toutes les tâches
    for(auto it = m_list.begin(); it != m_list.end(); ++it){
        //Si le contenu de la tache ne contient pas le mot recherché, on le supprime
        if(it->getDate() < date)
        {
            m_list.erase(it);           //On le supprime de la list
        }
    }
    return *this;
}
