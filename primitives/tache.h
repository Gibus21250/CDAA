#ifndef TACHE_H
#define TACHE_H
#include <string>

#include "dateSimple.h"

class Tache
{
private:
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
    Tache(const Tache&);

    /**
     * @brief Constructeur de Tache avec contenu
     * @param contenu
     */
    Tache(const std::string& contenu);

    /**
     * @brief Constructeur avec contenu et instance de date
     * @param contenu
     * @param date
     */
    Tache(const std::string& contenu, const DateSimple& date);

    /**
     * @brief Constructeur avec contenu et date sous forme de string
     * @param contenu
     * @param dateStr
     */
    Tache(const std::string& contenu, const std::string& dateStr);

    //Tache(std::string&& contenu);

    ~Tache();

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
     * @param valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    /**
     * @brief getDate
     * @return la date de la tache
     */
    DateSimple getDate() const;

    /**
     * @brief setDate
     * @param valeur de la date à modifier
     */
    void setDate(const DateSimple &value);

    /**
     * @brief setDate
     * @param valeur de la date à modifier
     */
    void setDate(const std::string &value);

    friend std::ostream& operator<<(std::ostream& out, const Tache& tache);

    bool operator==(const Tache& t);
};

#endif // TACHE_H
