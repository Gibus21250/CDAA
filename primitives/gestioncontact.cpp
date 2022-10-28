#include "gestioncontact.h"
#include <iterator>
#include <iostream>

std::list<Contact> GestionContact::getListContact() const
{
    return listContact;
}

Contact GestionContact::getContact(const int no)
{
    auto it = listContact.begin();
    std::advance(it, no);
    return *it;
}

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
std::ostream& operator<<(std::ostream& out, const GestionContact& c)
{
    for(auto ct : c.getListContact())
    {
        out << ct << std::endl << std::endl ;
    }
    return out;
}
