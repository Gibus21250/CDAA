#include "tache.h"

#include <iostream>

const unsigned &Tache::IdT() const
{
    return m_IdT;
}

void Tache::setIdT(const unsigned &newIdT)
{
    m_IdT = newIdT;
}

Tache::Tache() : m_contenu(""), m_hasDate(false) {}

Tache::Tache(const unsigned id, const Tache& tache)
    : m_IdT(id), m_contenu(tache.m_contenu), m_date(tache.m_date), m_hasDate(tache.m_hasDate) {}

Tache::Tache(const unsigned id, const std::string& contenu_)
    : m_IdT(id), m_contenu(contenu_), m_hasDate(false) {}

Tache::Tache(const unsigned id, const std::string& contenu_, const DateSimple& date_)
    : m_IdT(id), m_contenu(contenu_), m_date(date_), m_hasDate(true) {}

Tache::Tache(const unsigned id, const std::string& contenu_, const std::string& datestr)
    : m_IdT(id), m_contenu(contenu_), m_date(DateSimple(datestr)), m_hasDate(true) {}

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

void Tache::setDate(const std::string &value)
{
    if(value.compare("") != 0)
    {
        m_date = DateSimple(value);
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

bool Tache::operator==(const Tache& t) const
{
    return m_contenu.compare(t.m_contenu) == 0? //Les contenus sont equivalent ? si oui on regarde s'ils sont tous les deux daté, on compare leurs date, sinon on renvois s'ils sont tous les deux date ou non
                (m_hasDate & t.m_hasDate)?
                    m_date == t.m_date : (m_hasDate == t.m_hasDate)
                  : 0;  //Ici les contenu ne sont pas equivalent
}
