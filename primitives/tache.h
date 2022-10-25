#ifndef TACHE_H
#define TACHE_H
#include <string>

#include "dateSimple.h"

class Tache
{
private:
    std::string contenu;
    DateSimple date;

public:
    Tache(const std::string& contenu);
    Tache(const std::string& contenu, const DateSimple& date);
    Tache(const std::string& contenu, const std::string& dateStr );

    std::string getContenu() const;
    void setContenu(const std::string &value);

    DateSimple getDate() const;
    void setDate(const DateSimple &value);
};

#endif // TACHE_H
