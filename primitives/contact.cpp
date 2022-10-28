#include "contact.h"

Contact::Contact(const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto)
{
    this->nom = nom;
    this->prenom = prenom;
    this->entreprise = entreprise;
    this->mail = mail;
    this->telephone = telephone;
    this->uriPhoto = uriPhoto;
    this->interactions = GestionInteraction();
}

DateSimple Contact::getDate() const
{
    return date;
}

void Contact::setDate(const DateSimple &value)
{
    date = value;
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

bool Contact::operator==(const Contact& in){

    if((in.nom.compare(nom) && 
    in.prenom.compare(prenom) && 
    in.entreprise.compare(entreprise) && 
    in.mail.compare(mail) && 
    in.telephone.compare(telephone) && 
    in.uriPhoto.compare(uriPhoto))==0)
    {
        return true;
    }else
    {
        return false;
    }
    
}

std::ostream& operator<<(std::ostream& out, const Contact& c)
{
    out << "Nom: " <<  c.getNom()
               << ", Prénom: " << c.getPrenom()
               << std::endl << "Entreprise: " << c.getEntreprise()
               << ", Mail: " << c.getMail()
               << ", Téléphone: " << c.getTelephone()
               << std::endl << "Uri: " << c.getUriPhoto()
               << std::endl << "Nombre d'interaction(s): " << c.getNombreInteraction() << std::endl;
    if(c.getNombreInteraction() > 0)
        out << c.getGestionInteraction();
    return out;
}
//////////////////////////////////////////
/// Gestion des Intéractions du contact //
//////////////////////////////////////////

void Contact::ajoutInteraction(const Interaction &in)
{
    interactions.ajoutInteraction(in);
}

void Contact::ajoutInteraction(const std::string contenu, const std::string dateStr)
{
    DateSimple dt(dateStr);
    ajoutInteraction(contenu, dt);
}

void Contact::supprimerInteraction(const Interaction &in)
{
    interactions.supprimerInteraction(in);
}

unsigned Contact::getNombreInteraction() const
{
    return interactions.getNombreInteraction();
}

GestionInteraction Contact::getGestionInteraction() const
{
    return interactions;
}

void Contact::ajoutInteraction(const std::string contenu, const DateSimple date)
{
    Interaction tmp(contenu, date);
    interactions.ajoutInteraction(tmp);
}

void Contact::ajoutInteraction(const std::string contenu)
{
    interactions.ajoutInteraction(Interaction(contenu));
}
