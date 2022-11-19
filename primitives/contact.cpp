#include "contact.h"

Contact::Contact(const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto)
    : m_nom(nom), m_prenom(prenom), m_entreprise(entreprise), m_mail(mail), m_telephone(telephone), m_uriPhoto(uriPhoto) {}

DateSimple Contact::getDate() const
{
    return m_date;
}

void Contact::setDate(const DateSimple &value)
{
    m_date = value;
}

std::string Contact::getUriPhoto() const
{
    return m_uriPhoto;
}

void Contact::setUriPhoto(const std::string &value)
{
    m_uriPhoto = value;
}

std::string Contact::getTelephone() const
{
    return m_telephone;
}

void Contact::setTelephone(const std::string &value)
{
    m_telephone = value;
}

std::string Contact::getMail() const
{
    return m_mail;
}

void Contact::setMail(const std::string &value)
{
    m_mail = value;
}

std::string Contact::getEntreprise() const
{
    return m_entreprise;
}

void Contact::setEntreprise(const std::string &value)
{
    m_entreprise = value;
}

std::string Contact::getPrenom() const
{
    return m_prenom;
}

void Contact::setPrenom(const std::string &value)
{
    m_prenom = value;
}

std::string Contact::getNom() const
{
    return m_nom;
}

void Contact::setNom(const std::string &value)
{
    m_nom = value;
}

bool Contact::operator==(const Contact& in){

    return (
                in.m_nom.compare(m_nom) &&
                in.m_prenom.compare(m_prenom) &&
                in.m_entreprise.compare(m_entreprise) &&
                in.m_mail.compare(m_mail) &&
                in.m_telephone.compare(m_telephone) &&
                in.m_uriPhoto.compare(m_uriPhoto)
           );
    
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

void Contact::ajoutInteraction(const Interaction& in)
{
    m_interactions.ajoutInteraction(in);
}

void Contact::ajoutInteraction(const std::string& contenu, const std::string& dateStr)
{
    DateSimple dt(dateStr);
    ajoutInteraction(contenu, dt);
}

void Contact::supprimerInteraction(const Interaction &in)
{
    m_interactions.supprimerInteraction(in);
}

unsigned Contact::getNombreInteraction() const
{
    return m_interactions.getNombreInteraction();
}

GestionInteraction Contact::getGestionInteraction() const
{
    return m_interactions;
}

void Contact::ajoutInteraction(const std::string& contenu, const DateSimple& date)
{
    Interaction tmp(contenu, date);
    m_interactions.ajoutInteraction(tmp);
}

void Contact::ajoutInteraction(const std::string& contenu)
{
    m_interactions.ajoutInteraction(Interaction(contenu));
}
