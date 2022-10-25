#include "tache.h"


Tache::Tache(const std::string& contenu_)
{
    contenu = contenu_;
    hasDate = false;
}

Tache::Tache(const std::string& contenu_, const DateSimple& date_)
{
    contenu = contenu_;
    date = date_;
    hasDate = true;
}

Tache::Tache(const std::string& contenu_, const std::string& datestr)
{
    contenu = contenu_;
    date = DateSimple(datestr);
    hasDate = true;
}

bool Tache::isDated() const
{
    return hasDate;
}

std::ostream& operator<<(std::ostream& out, const Tache& tache)
{
    out << "@todo " << tache.contenu;
    if(tache.isDated())
    {
        out << " @date " << tache.date.getDateStrFormat();
    }
    return out;
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
