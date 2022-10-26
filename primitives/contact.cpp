#include "contact.h"

Contact::Contact(const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto)
{
    this->nom = nom;
    this->prenom = prenom;
    this->entreprise = entreprise;
    this->mail = mail;
    this->telephone = telephone;
    this->uriPhoto = uriPhoto;
    this->interactions = new GestionInteraction();
}

Contact::~Contact()
{
    delete interactions;
}

std::ostream& operator<<(std::ostream& out, const Contact& c)
{
    return out << c.getNom() << " " << c.getPrenom() << " " << c.getEntreprise() << " " << c.getMail() << " " << c.getTelephone() << " " << c.getUriPhoto();
}

DateSimple Contact::getDate() const
{
    return date;
}

void Contact::setDate(const DateSimple &value)
{
    date = value;
}

GestionInteraction& Contact::getGestionInteractions() const
{
    return *interactions;
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
