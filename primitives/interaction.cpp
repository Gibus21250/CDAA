#include "interaction.h"

Interaction::Interaction()
{
    Interaction("");
}

Interaction::Interaction(const std::string& desc)
{
    contenu = desc;
    date = DateSimple();
    lTache = std::list<Tache>();
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

std::list<Tache> Interaction::getLTache() const
{
    return lTache;
}

void Interaction::setLTache(const std::list<Tache> &value)
{
    lTache = value;
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

std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.getContenu() << " " << i.getDate().getDateStrFormat();
    if(i.getLTache().size() != 0)
    {
        for(auto tache = i.getLTache().begin(); tache != i.getLTache().end();)
        {
            out << std::endl << *tache;
        }
    }
    out << std::endl;
    return out;
}

bool Interaction::operator==(const Interaction& in){
    return in.contenu.compare(contenu) == 0;
}

