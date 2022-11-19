#include <iterator>
#include "gestioninteraction.h"
#include <iostream>

GestionInteraction::GestionInteraction()
{
    listInteraction = std::list<Interaction>();
}

//TODO VERIFIER LE BON AJOUT A LA LISTE
void GestionInteraction::ajoutInteraction(const Interaction& in)
{
    this->listInteraction.push_back(in);
}

bool GestionInteraction::supprimerInteraction(const Interaction& in)
{
    bool finded = false;
    for(auto it = listInteraction.begin(); it != listInteraction.end() && !finded; ++it){
        if(*it == in)
        {
            listInteraction.erase(it);      //On supprime l'interaction
            finded = true;                  //On affecte
        }
    }
    return finded;      //On renvoie si oui ou non l'interaction a été trouvée et supprimée
}

unsigned GestionInteraction::getNombreInteraction() const
{
    return listInteraction.size();
}

std::pair<Interaction, bool> GestionInteraction::getInteraction(const std::string& contenu) const
{

    for(auto it = listInteraction.begin(); it != listInteraction.end(); ++it)
    {
        if(it->getContenu() == contenu){
            return std::make_pair(*it, true);
        }
    }
    return std::make_pair(Interaction(), false);
}

std::pair<Interaction, bool> GestionInteraction::getInteraction(const int nb) const
{
    if(nb < (int) listInteraction.size()){
        auto element = listInteraction.begin();
        std::advance(element, nb);
        return std::make_pair(*element, true);
    }
    return std::make_pair(Interaction(), false);
}

std::list<Interaction> GestionInteraction::getListInteraction() const
{
    return listInteraction;
}

std::ostream& operator<<(std::ostream& out, const GestionInteraction& c)
{
    if(c.getNombreInteraction() < 1)
    {
        out << "Aucune interaction";
    }
    else
    {
        int cmpt = 1;
        for(auto in : c.getListInteraction())
        {
            out << std::endl << "Interaction No " << cmpt++;
            out << std::endl << in << std::endl;
        }
    }
    return out;
}
