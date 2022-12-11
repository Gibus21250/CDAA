#include "contact.h"


const GestionInteraction &Contact::interactions() const
{
    return m_interactions;
}

void Contact::setInteractions(const GestionInteraction &newInteractions)
{
    m_interactions = newInteractions;
}

const unsigned &Contact::getIdC() const
{
    return m_IdC;
}

void Contact::setIdC(const unsigned &newIdC)
{
    m_IdC = newIdC;
}

Contact::Contact(const unsigned id, const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto)
    : m_nom(nom), m_prenom(prenom), m_entreprise(entreprise), m_mail(mail), m_telephone(telephone), m_uriPhoto(uriPhoto) {}

Contact::Contact(const Contact &copy)
    : m_nom(copy.getNom()), m_prenom(copy.getPrenom()),
      m_entreprise(copy.getEntreprise()), m_mail(copy.getMail()),
      m_telephone(copy.getTelephone()), m_uriPhoto(copy.getUriPhoto()),
      m_interactions(copy.interactions()) {}

Contact::Contact() : m_IdC(-1) {}

const DateSimple &Contact::dateDerniereModification() const
{
    return m_dateDerniereModification;
}

void Contact::setDateDerniereModification(const DateSimple &newDateDerniereModification)
{
    m_dateDerniereModification = newDateDerniereModification;
}

const DateSimple& Contact::getDateCreation() const
{
    return m_dateCreation;
}

const DateSimple &Contact::getDateModification() const
{
    return m_dateDerniereModification;
}

const std::string& Contact::getUriPhoto() const
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
                in.m_nom.compare(m_nom) == 0 &&
                in.m_prenom.compare(m_prenom) == 0 &&
                in.m_entreprise.compare(m_entreprise) == 0 &&
                in.m_mail.compare(m_mail) == 0&&
                in.m_telephone.compare(m_telephone) == 0 &&
                in.m_uriPhoto.compare(m_uriPhoto) == 0 &&
                in.m_dateCreation == m_dateCreation &&
                in.m_dateDerniereModification == m_dateDerniereModification
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
        out << c.m_interactions;
    return out;
}
        //////////////////////////////////////////
        /// Gestion des Intéractions du contact //
        //////////////////////////////////////////

void Contact::ajoutInteraction(const Interaction& in)
{
    m_interactions.ajouterElement(in);
}

void Contact::supprimerInteraction(const Interaction &in)
{
    m_interactions.supprimerParId(in.IdI());
}

void Contact::supprimerInteraction(const int indice)
{
    m_interactions.supprimerElement(indice);
}

unsigned Contact::getNombreInteraction() const
{
    return m_interactions.getNombreElements();
}
