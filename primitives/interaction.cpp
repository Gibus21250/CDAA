#include "interaction.h"

Interaction::Interaction()
{
    Interaction("");
}

Interaction::Interaction(const std::string& desc)
{
    contenu = desc;
    date = DateSimple();
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

std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.contenu << " " << i.date.getDateStrFormat() << std::endl;
    return out;
}

