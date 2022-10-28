#include <iterator>
#include "gestioninteraction.h"
#include <iostream>

GestionInteraction::GestionInteraction()
{
    listInteraction = std::list<Interaction>();
}

void GestionInteraction::ajoutInteraction(const Interaction& in)
{
    this->listInteraction.push_back(in);
}

bool GestionInteraction::supprimerInteraction(const Interaction& in)
{
    bool done = false;
    for(auto it = listInteraction.begin(); it != listInteraction.end(); ++it){
        if(*it == in){
            listInteraction.erase(it);
            done = true;
            it = listInteraction.end();
        }
    }
    return done;
}

std::pair<Interaction, bool> GestionInteraction::getInteraction(const std::string contenu)
{

    for(auto it = listInteraction.begin(); it != listInteraction.end(); ++it){
        if(it->getContenu() == contenu){
            return std::make_pair(*it, true);
        }
    }
    return std::make_pair(Interaction(), false);
}

std::pair<Interaction, bool> GestionInteraction::getInteraction(const int nb)
{
    if(nb < listInteraction.size()){
        auto element = listInteraction.begin();
        std::advance(element, nb);
        //std::cout << "Trouve l'interaction no " << nb << " " << *element << std::endl;
        return std::make_pair(*element, true);
    }
    return std::make_pair(Interaction(), false);
}
