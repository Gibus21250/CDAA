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
};

#endif // INTERACTION_H
