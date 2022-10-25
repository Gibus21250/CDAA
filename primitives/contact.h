#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <list>

#include "interaction.h"
#include "dateSimple.h"

/**
 * @brief La classe primitive d'un Contact
 */
class Contact
{
private:

    std::string nom, prenom, entreprise, mail, telephone, uriPhoto;
    std::list<Interaction> listinteractions;
    DateSimple date;

public:

    Contact();
    /**
     * @brief Contact
     * @param nom Le nom du contact
     * @param prenom Le prenom du contact
     */
    Contact(const std::string nom, const std::string prenom);

    /**
     * @brief getNom
     * @return le nom du contact
     */
    std::string getNom() const;
    void setNom(const std::string &value);

    /**
     * @brief getPrenom
     * @return le prenom du contact
     */
    std::string getPrenom() const;
    void setPrenom(const std::string &value);

    /**
     * @brief getEntreprise
     * @return le nom de l'entreprise du contact
     */
    std::string getEntreprise() const;
    void setEntreprise(const std::string &value);

    std::string getMail() const;
    void setMail(const std::string &value);

    std::string getTelephone() const;
    void setTelephone(const std::string &value);

    std::string getUriPhoto() const;
    void setUriPhoto(const std::string &value);

    std::list<Interaction> getListinteractions() const;
    void setListinteractions(const std::list<Interaction> &value);

    DateSimple getDate() const;
    void setDate(const DateSimple &value);
};

#endif // CONTACT_H
