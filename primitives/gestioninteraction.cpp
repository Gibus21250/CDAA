#include <iterator>
#include "gestioninteraction.h"
#include <iostream>

GestionInteraction::GestionInteraction()
{
    listInteraction = std::list<Interaction>();
}

void GestionInteraction::ajoutInteraction(const Interaction in)
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

unsigned GestionInteraction::getNombreInteraction() const
{
    return listInteraction.size();
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
            out << std::endl << in;
        }
    }
    return out;
}
