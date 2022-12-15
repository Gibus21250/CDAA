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

    ///Id du contact
    unsigned m_IdC;

    std::string m_nom, m_prenom, m_entreprise, m_mail, m_telephone, m_photo;
    ///Instance de GestionInteraction gérant les Interaction associés au Contact
    GestionInteraction m_interactions;
    ///Date de création
    DateSimple m_dateCreation;
    ///Date de dernière modification
    DateSimple m_dateDerniereModification;

public:

    /**
     * @brief Constructeur standard d'un contact
     * @param ID du Contact
     * @param nom Le nom du contact
     * @param prenom Le prenom du contact
     * @param entreprise Le nom de l'entreprise
     * @param mail  Le mail du contact
     * @param telephone Le téléphone du contact
     * @param uriPhoto  L'uri de l'image de profile du contact
     */
    Contact(const unsigned id, const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto);

    /**
     * @brief Constructeur par copie
     */
    Contact(const Contact& copy);

    ///Constructeur pas défaut d'un contact
    Contact();

    ///Renvoie l'ID du Contact
    const unsigned &getIdC() const;

    ///Change la valeur de l'ID du Contact par la valeur en argument
    void setIdC(const unsigned &newIdC);

    /**
     * @brief getNom
     * @return le nom du contact
     */
    std::string getNom() const;

    /**
     * @brief Change le nom de l'instance Contact
     * @param Nouveau nom
     */
    void setNom(const std::string &value);

    /**
     * @brief getPrenom
     * @return le prenom du contact
     */
    std::string getPrenom() const;

    /**
     * @brief Change le prenom de l'instance Contact
     * @param Nouveau prenom
     */
    void setPrenom(const std::string &value);

    /**
     * @brief getEntreprise
     * @return le nom de l'entreprise du contact
     */
    std::string getEntreprise() const;

    /**
     * @brief Change l'entreprise de l'instance Contact
     * @param Nouvelle entreprise
     */
    void setEntreprise(const std::string &value);

    /**
     * @brief getMail
     * @return le mail du contact
     */
    std::string getMail() const;

    /**
     * @brief Change le mail de l'instance Contact
     * @param Nouveau mail
     */
    void setMail(const std::string &value);

    /**
     * @brief getTelephone
     * @return le numero de telephone du contact
     */
    std::string getTelephone() const;

    /**
     * @brief Change le numéro de téléphone de l'instance Contact
     * @param Nouveau numéro de téléphone
     */
    void setTelephone(const std::string &value);

    /**
     * @brief getUriPhoto
     * @return l'URI de la photo du contact
     */
    const std::string& getPhoto() const;

    /**
     * @brief Change le chemin de la photo de l'instance Contact
     * @param Nouveau chemin de photo du Contact
     */
    void setPhoto(const std::string &value);

    /**
     * @brief Recupère la Date de création du contact
     * @return Instance DateSimple de la date de création du contact
     */
    const DateSimple& getDateCreation() const;

    /**
     * @brief Recupère la Date de dernière modification du contact
     * @return Instance DateSimple de la date de dernière modification du contact
     */
    const DateSimple& getDateModification() const;

    ///Compare tous les attributs de deux instances de Contact
    bool operator==(const Contact& in);

    ///Surcharge de l'opérateur << pour transformer l'instance de Contact en flux et l'envoyer dans le flux de sortie
    friend std::ostream& operator<<(std::ostream& out, const Contact& c);

    /**
     * @brief Ajoute une copie de l'interaction à la liste des interaction du Contact
     * @param in
     */
    void ajoutInteraction(const Interaction& in);

    /**
     * @brief Ajoute une interaction à la liste des interaction du contact
     * @param contenu
     * @param dateStr
     */
    void ajoutInteraction(const std::string& contenu, const std::string& dateStr);

    /**
     * @brief Permet de retirer une interaction de la liste des interactions du contact
     * Dans le pire des cas O(N) comparaison d'instance
     * @param Interaction
     */
    void supprimerInteraction(const Interaction& in);

    /**
     * @brief Supprime l'interaction à l'indice précisé O(1)
     * @param indice
     */
    void supprimerInteraction(const int indice);

    /**
     * @return Renvoie le nombre d'interaction du contact
     */
    unsigned getNombreInteraction() const;

    ///Renvoie l'instance de GestionInteraction associé au Contact
    const GestionInteraction &interactions() const;

    ///Change l'instance de GestionInteraction associé au Contact par l'instance en argument
    void setInteractions(const GestionInteraction &newInteractions);


    /**
     * @brief Change l'instance DateSimple associé à la date de création du Contact
     * @param Nouvelle DateSimple
     */
    void setDateCreation(const DateSimple &newDateCreation);

    /**
     * @brief Change l'instance DateSimple associé à la dernière date de modification du Contact
     * @param Nouvelle DateSimple
     */
    void setDateDerniereModification(const DateSimple &newDateDerniereModification);
};

#endif // CONTACT_H
