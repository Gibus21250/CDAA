#include "tache.h"


Tache::Tache(const std::string& contenu_)
{
    contenu = contenu_;
    date = DateSimple();
}

Tache::Tache(const std::string& contenu_, const DateSimple& date_)
{
    contenu = contenu_;
    date = date_;
}

Tache::Tache(const std::string& contenu_, const std::string& datestr)
{
    contenu = contenu_;
    date = DateSimple(datestr);
}

std::string Tache::getContenu() const
{
    return contenu;
}

void Tache::setContenu(const std::string &value)
{
    contenu = value;
}

DateSimple Tache::getDate() const
{
    return date;
}

void Tache::setDate(const DateSimple &value)
{
    date = value;
}
