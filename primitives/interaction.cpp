#include "interaction.h"

const GestionTache &Interaction::taches() const
{
    return m_taches;
}

void Interaction::setTaches(const GestionTache &newTaches)
{
    m_taches = newTaches;
}

Interaction::Interaction() : Interaction("") {}

Interaction::Interaction(const std::string& desc)
    : m_contenu(desc), m_date(DateSimple()) {}

Interaction::Interaction(const std::string& desc, const DateSimple& date_)
    : m_contenu(desc), m_date(date_) {}

Interaction::Interaction(const std::string& desc, const std::string& dateStr)
    : m_contenu(desc), m_date(DateSimple(dateStr)) {}

const DateSimple &Interaction::getDate() const
{
    return m_date;
}

const std::string& Interaction::getContenu() const
{
    return m_contenu;
}

void Interaction::setContenu(const std::string &value)
{
    m_contenu = value;
}

void Interaction::setDate(const DateSimple &value)
{
    m_date = value;
}

unsigned Interaction::getNombreTache() const
{
    return m_taches.getNombreElements();
}

void Interaction::ajouterTache(const Tache &tache)
{
    m_taches.ajouterElement(tache);
}

void Interaction::ajouterTache(const std::string& contenu, std::string& dateStr)
{
    m_taches.ajouterElement(Tache(contenu, dateStr));
}

void Interaction::ajouterTache(const std::string& contenu, DateSimple& date)
{
    m_taches.ajouterElement(Tache(contenu, date));
}


std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.getContenu() << " " << i.getDate().getDateStrFormat();
    if(i.getNombreTache() != 0)
        out << std::endl << i.m_taches;
    return out;
}

bool Interaction::operator==(const Interaction& in) const {
    return in.m_contenu.compare(m_contenu) == 0 && this->m_taches == in.m_taches;
}

