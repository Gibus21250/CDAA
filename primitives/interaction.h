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

    DateSimple getDate() const;
    void setDate(const DateSimple &value);

    std::string getContenu() const;
    void setContenu(const std::string &value);

    std::list<Tache> getLTache() const;
    void setLTache(const std::list<Tache> &value);

    bool operator==(const Interaction& in);
};

#endif // INTERACTION_H
