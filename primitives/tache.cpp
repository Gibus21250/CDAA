#include "tache.h"

Tache::Tache() : Tache("") {}

Tache::Tache(const std::string& contenu_)
    : m_contenu(contenu_), m_hasDate(false) {}

Tache::Tache(const std::string& contenu_, const DateSimple& date_)
    : m_contenu(contenu_), m_date(date_), m_hasDate(true) {}

Tache::Tache(const std::string& contenu_, const std::string& datestr)
    : m_contenu(contenu_), m_date(DateSimple(datestr)), m_hasDate(true) {}

bool Tache::isDatee() const
{
    return m_hasDate;
}

std::string Tache::getContenu() const
{
    return m_contenu;
}

void Tache::setContenu(const std::string &value)
{
    m_contenu = value;
}

DateSimple Tache::getDate() const
{
    return m_date;
}

void Tache::setDate(const DateSimple &value)
{
    if(value.getDateStrFormat().compare("") != 0)
    {
        m_date = value;
        m_hasDate = true;
    }
    else m_hasDate = false;

}

std::ostream& operator<<(std::ostream& out, const Tache& tache)
{
    out << "@todo " << tache.m_contenu;
    if(tache.isDatee())
    {
        out << " @date " << tache.m_date.getDateStrFormat();
    }
    return out;
}

bool Tache::operator==(const Tache& t)
{
    return m_contenu == t.getContenu() && m_date == t.getDate();
}
