#include "tache.h"

#include <iostream>

Tache::Tache() : m_contenu(""), m_date(), m_hasDate(false)
{
    std::cout << "[TACHE] Constructor default called" << std::endl;
    printValue();
}

Tache::Tache(const Tache& tache)
    : m_contenu(tache.m_contenu), m_date(tache.m_date), m_hasDate(tache.m_hasDate)
{
    std::cout << "[TACHE] Constructor copy called" << std::endl;
}

Tache::Tache(const std::string& contenu_)
    : m_contenu(contenu_), m_date(), m_hasDate(false)
{
    std::cout << "[TACHE] Constructor string& called" << std::endl;
    printValue();
}

Tache::Tache(const std::string& contenu_, const DateSimple& date_)
    : m_contenu(contenu_), m_date(date_), m_hasDate(true)
{
    std::cout << "[TACHE] Constructor string&, date& called" << std::endl;
    printValue();
}

Tache::Tache(const std::string& contenu_, const std::string& datestr)
    : m_contenu(contenu_), m_date(DateSimple(datestr)), m_hasDate(true)
{
    std::cout << "[TACHE] Constructor string&, string& called" << std::endl;
    printValue();
}

/*Tache::Tache(std::string&& contenu)
{
    std::cout << "Move constructor string&& called" << std::endl;
    m_contenu.clear();
    m_contenu.append(contenu);
}
*/

Tache::~Tache()
{
    std::cout << "[TACHE] détruite" << std::endl;
}

void Tache::printValue()
{
    std::cout << m_contenu << " " << m_date.getDateStrFormat() << " " << m_hasDate << std::endl;
}

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

bool Tache::operator==(const Tache& t)
{
    return m_contenu.compare(t.getContenu()) == 0 && m_date == t.getDate();
}
