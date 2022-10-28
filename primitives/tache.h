#ifndef TACHE_H
#define TACHE_H
#include <string>

#include "dateSimple.h"

class Tache
{
private:
    std::string contenu;
    DateSimple date;
    bool hasDate;

public:
    Tache(const std::string& contenu);
    Tache(const std::string& contenu, const DateSimple& date);
    Tache(const std::string& contenu, const std::string& dateStr );

    /**
     * @brief isDate
     * @return un boolean pour savoir s'il y a une date
     */
    bool isDate() const;

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

    friend std::ostream& operator<<(std::ostream& out, const Tache& tache);
    bool operator==(const Tache& t);
};

#endif // TACHE_H
