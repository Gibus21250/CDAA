#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include "date/date.h"


class Interaction
{
public:
    Interaction();
    std::chrono::time_point<std::chrono::system_clock, date::days> date;
    std::string contenu;
};

#endif // INTERACTION_H
