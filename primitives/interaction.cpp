#include "interaction.h"

Interaction::Interaction() : Interaction("") {}

Interaction::Interaction(const std::string& desc)
    : m_contenu(desc), m_date(DateSimple()) {}

Interaction::Interaction(const std::string& desc, const DateSimple& date_)
    : m_contenu(desc), m_date(date_) {}

Interaction::Interaction(const std::string& desc, const std::string& dateStr)
    : m_contenu(desc), m_date(DateSimple(dateStr)) {}

std::string Interaction::getContenu() const
{
    return m_contenu;
}

void Interaction::setContenu(const std::string &value)
{
    m_contenu = value;
}

DateSimple Interaction::getDate() const
{
    return m_date;
}

void Interaction::setDate(const DateSimple &value)
{
    m_date = value;
}

GestionTache Interaction::getTaches() const
{
    return m_taches;
}

unsigned Interaction::getNombreTache() const
{
    return m_taches.getNombreTache();
}

void Interaction::ajouterTache(const Tache &tache)
{
    m_taches.ajoutTache(tache);
}

void Interaction::ajouterTache(const std::string& contenu, std::string& dateStr)
{
    m_taches.ajoutTache(Tache(contenu, dateStr));
}

void Interaction::ajouterTache(const std::string& contenu, DateSimple& date)
{
    m_taches.ajoutTache(Tache(contenu, date));
}


std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.getContenu() << " " << i.getDate().getDateStrFormat();
    if(i.getNombreTache() != 0)
        out << std::endl << i.getTaches();
    return out;
}

bool Interaction::operator==(const Interaction& in){
    return in.m_contenu.compare(m_contenu) == 0;
}

