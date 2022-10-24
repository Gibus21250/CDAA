#include "contact.h"

Contact::Contact()
{

}

std::chrono::time_point<std::chrono::system_clock, date::days> Contact::getDate() const
{
    return date;
}

void Contact::setDate(const std::chrono::time_point<std::chrono::system_clock, date::days> &value)
{
    date = value;
}

std::list<Interaction> Contact::getListinteractions() const
{
    return listinteractions;
}

void Contact::setListinteractions(const std::list<Interaction> &value)
{
    listinteractions = value;
}

std::string Contact::getUriPhoto() const
{
    return uriPhoto;
}

void Contact::setUriPhoto(const std::string &value)
{
    uriPhoto = value;
}

std::string Contact::getTelephone() const
{
    return telephone;
}

void Contact::setTelephone(const std::string &value)
{
    telephone = value;
}

std::string Contact::getMail() const
{
    return mail;
}

void Contact::setMail(const std::string &value)
{
    mail = value;
}

std::string Contact::getEntreprise() const
{
    return entreprise;
}

void Contact::setEntreprise(const std::string &value)
{
    entreprise = value;
}

std::string Contact::getPrenom() const
{
    return prenom;
}

void Contact::setPrenom(const std::string &value)
{
    prenom = value;
}

std::string Contact::getNom() const
{
    return nom;
}

void Contact::setNom(const std::string &value)
{
    nom = value;
}
