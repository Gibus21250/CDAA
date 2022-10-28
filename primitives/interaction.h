#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include <list>

#include "primitives/dateSimple.h"
#include "tache.h"


class Interaction
{
private:

    DateSimple date;
    std::string contenu;
    std::list<Tache> lTache;

public:

    Interaction();
    Interaction(const std::string& desc);
    Interaction(const std::string& desc, const DateSimple& date);
    Interaction(const std::string& desc, const std::string& date);

    friend std::ostream& operator<<(std::ostream& out, const Interaction& i);

    /**
     * @brief getDate
     * @return la date à laquelle se passe l'interaction
     */
    DateSimple getDate() const;

    /**
     * @brief setDate
     * @param la valeur de la date à modifier
     */
    void setDate(const DateSimple &value);

    /**
     * @brief getContenu
     * @return Le contenu de l'interaction
     */
    std::string getContenu() const;

    /**
     * @brief setContenu
     * @param valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    /**
     * @brief getLTache
     * @return
     */
    std::list<Tache> getLTache() const;

    /**
     * @brief setLTache
     * @param value
     */
    void setLTache(const std::list<Tache> &value);

    bool operator==(const Interaction& in);
};

#endif // INTERACTION_H
