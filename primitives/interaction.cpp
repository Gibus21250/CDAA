#include "interaction.h"

Interaction::Interaction()
{
    Interaction("");
}

Interaction::Interaction(const std::string& desc)
{
    contenu = desc;
    date = DateSimple();
    taches = GestionTache();
}

Interaction::Interaction(const std::string& desc, const DateSimple& date_)
{
    contenu = desc;
    date = date_;
}

Interaction::Interaction(const std::string& desc, const std::string& dateStr)
{
    contenu = desc;
    date = DateSimple(dateStr);
}

std::string Interaction::getContenu() const
{
    return contenu;
}

void Interaction::setContenu(const std::string &value)
{
    contenu = value;
}

DateSimple Interaction::getDate() const
{
    return date;
}

void Interaction::setDate(const DateSimple &value)
{
    date = value;
}

GestionTache Interaction::getTaches() const
{
    return taches;
}

void Interaction::setTaches(const GestionTache &value)
{
    taches = value;
}

unsigned Interaction::getNombreTache() const
{
    return taches.getNombreTache();
}

void Interaction::ajouterTache(const Tache &tache)
{
    taches.ajoutTache(tache);
}

void Interaction::ajouterTache(const std::string contenu, std::string dateStr)
{
    taches.ajoutTache(Tache(contenu, dateStr));
}

void Interaction::ajouterTache(const std::string contenu, DateSimple date)
{
    taches.ajoutTache(Tache(contenu, date));
}


std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.getContenu() << " " << i.getDate().getDateStrFormat();
    if(i.getNombreTache() != 0)
        out << std::endl << i.getTaches();
    return out;
}

bool Interaction::operator==(const Interaction& in){
    return in.contenu.compare(contenu) ==0;
}

