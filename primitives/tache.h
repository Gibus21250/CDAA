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

    bool isDated() const;

    std::string getContenu() const;
    void setContenu(const std::string &value);

    DateSimple getDate() const;
    void setDate(const DateSimple &value);

    friend std::ostream& operator<<(std::ostream& out, const Tache& tache);
    bool operator==(const Tache& t);
};

#endif // TACHE_H
