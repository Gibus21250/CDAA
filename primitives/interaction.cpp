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

std::ostream& operator<<(std::ostream& out, const Interaction& i)
{
    out << i.contenu << " " << i.date.getDateStrFormat() << std::endl;
    return out;
}

std::string Interaction::getContenu() const
{
    return contenu;
}

void Interaction::setContenu(const std::string &value)
{
    contenu = value;
}

laDate Interaction::getDate() const
{
    return date;
}

void Interaction::setDate(const laDate &value)
{
    date = value;
}
