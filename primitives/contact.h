#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <list>

#include "interaction.h"
#include "date/date.h"
#include "date/chrono_io.h"

using laDate = std::chrono::time_point<std::chrono::system_clock, date::days>;

/**
 * @brief La classe primitive d'un Contact
 */
class Contact
{
public:

    Contact();
    /**
     * @brief Contact
     * @param nom Le nom du contact
     * @param prenom Le prenom du contact
     */
    Contact(const std::string nom, const std::string prenom, const std::string entreprise,const std::string mail, const std::string telephone, const std::string uriPhoto);

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
     * @brief getListinteractions
     * @return la liste de(s) interaction(s) du contact
     */
    std::list<Interaction> getListinteractions() const;
    void setListinteractions(const std::list<Interaction> &value);

    /**
     * @brief getDate
     * @return la(les) date(s) de(s) interaction(s)
     */
    laDate getDate() const;
    void setDate(const laDate &value);

private:

    std::string nom, prenom, entreprise, mail, telephone, uriPhoto;
    std::list<Interaction> listinteractions;
    laDate date;


};

#endif // CONTACT_H
