#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include "primitives/dateSimple.h"


class Interaction
{
public:
    Interaction();
    Interaction(const std::string& desc);
    Interaction(const std::string& desc, const DateSimple& date);
    Interaction(const std::string& desc, const std::string& date);

    DateSimple date;
    std::string contenu;
    friend std::ostream& operator<<(std::ostream out, const Interaction& i);

    DateSimple getDate() const;
    void setDate(const DateSimple &value);
    std::string getContenu() const;
    void setContenu(const std::string &value);
};

#endif // INTERACTION_H
