#ifndef TACHE_H
#define TACHE_H
#include <string>

#include "dateSimple.h"

/**
 * @brief Classe gérant une Tache
 */
class Tache
{
private:
    ///ID de la Tache
    unsigned m_IdT;
    ///Contenu de
    std::string m_contenu;
    DateSimple m_date;
    bool m_hasDate;

public:
    /**
     * @brief Constructeur par défaut sans contenu, dans date
     */
    Tache();

    /**
     * @brief Constructeur par copy
     */
    Tache(const unsigned id, const Tache& tache);

    /**
     * @brief Constructeur de Tache avec contenu
     * @param id Id de la Tache
     * @param contenu Contenu de la Tache
     */
    Tache(const unsigned id, const std::string& contenu);

    /**
     * @brief Constructeur avec contenu et instance de date
     * @param id Id de la Tache
     * @param contenu Contenu de la Tache
     * @param date associée à la Tache
     */
    Tache(const unsigned id, const std::string& contenu, const DateSimple& date);

    /**
     * @brief Constructeur avec contenu et date sous forme de string
     * @param id ID de la Tache
     * @param contenu Contenu de la Tache
     * @param dateStr associée à la Tache sous forme de string
     */
    Tache(const unsigned id, const std::string& contenu, const std::string& dateStr);

    void printValue();

    /**
     * @brief isDate
     * @return un boolean pour savoir si la tache est datée
     */
    bool isDatee() const;

    /**
     * @brief getContenu
     * @return le contenu de la tache
     */
    std::string getContenu() const;

    /**
     * @brief setContenu
     * @param value valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    /**
     * @brief getDate
     * @return la date de la tache
     */
    DateSimple getDate() const;

    /**
     * @brief setDate
     * @param value valeur de la date à modifier
     */
    void setDate(const DateSimple &value);

    /**
     * @brief setDate
     * @param value valeur de la date à modifier
     */
    void setDate(const std::string &value);

    friend std::ostream& operator<<(std::ostream& out, const Tache& tache);

    bool operator==(const Tache& t) const;

    const unsigned &IdT() const;
    void setIdT(const unsigned &newIdT);
};

#endif // TACHE_H
