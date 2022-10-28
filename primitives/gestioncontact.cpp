#include "gestioncontact.h"
#include <iterator>
#include <iostream>

GestionContact::GestionContact()
{
    listContact = std::list<Contact>();
}
void GestionContact::ajoutContact(const Contact& in)
{
    this->listContact.push_back(in);
}

bool GestionContact::supprimerContact(const Contact& in)
{
    bool done = false;
    for(auto it = listContact.begin(); it != listContact.end(); ++it){
        if(*it == in){
            listContact.erase(it);
            done = true;
            it = listContact.end();
        }
    }
    return done;
}
