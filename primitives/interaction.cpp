#include "interaction.h"

Interaction::Interaction()
{

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
