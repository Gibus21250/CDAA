#ifndef CONTACT_H
#define CONTACT_H

#include <string>

#include "dateSimple.h"
#include "gestioninteraction.h"

/**
 * @brief La classe primitive d'un Contact
 */
class Contact
{
private:

    std::string nom, prenom, entreprise, mail, telephone, uriPhoto;
    GestionInteraction interactions;
    DateSimple date;

public:

    /**
     * @brief Constructeur standard
     * @param nom Le nom du contact
     * @param prenom Le prenom du contact
     * @param entreprise
     * @param mail
     * @param telephone
     * @param uriPhoto
     */
    Contact(const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto);

    friend std::ostream& operator<<(std::ostream& out, const Contact& c);

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

    /**
     * @brief getMail
     * @return le mail du contact
     */
    std::string getMail() const;
    void setMail(const std::string &value);

    /**
     * @brief getTelephone
     * @return le numero de telephone du contact
     */
    std::string getTelephone() const;
    void setTelephone(const std::string &value);

    /**
     * @brief getUriPhoto
     * @return l'URI de la photo du contact
     */
    std::string getUriPhoto() const;
    void setUriPhoto(const std::string &value);

    /**
     * @brief Recupère la Date de création du contact
     * @return la date de création du contact
     */
    DateSimple getDate() const;
    void setDate(const DateSimple &value);

    bool operator==(const Contact& in);

    //////////////////////////////////////////
    /// Gestion des Intéractions du contact //
    //////////////////////////////////////////

    /**
     * @brief Ajoute une copie de l'interaction à la liste des interaction du Contact
     * @param in
     */
    void ajoutInteraction(const Interaction& in);

    /**
     * @brief Ajoute une interaction à la liste des interaction du contact
     * @param contenu de l'interaction
     * @param date de l'interaction
     */
    void ajoutInteraction(const std::string contenu, const DateSimple date);

    /**
     * @brief Ajoute une interaction à la liste des interaction du contact en prenant la date du jour
     * @param contenu de l'intéraction
     */
    void ajoutInteraction(const std::string contenu);

    /**
     * @brief Ajoute une interaction à la liste des interaction du contact
     * @param contenu
     * @param dateStr
     */
    void ajoutInteraction(const std::string contenu, const std::string dateStr);

    /**
     * @brief Avoir le nombre d'interaction du contact
     */
    unsigned getNombreInteraction() const;

protected:

    GestionInteraction getGestionInteraction() const;


};

#endif // CONTACT_H
