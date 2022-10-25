#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include "date/date.h"

using laDate = std::chrono::time_point<std::chrono::system_clock, date::days>;


class Interaction
{
public:
    Interaction();
    Interaction(const laDate date, const std::string str);
    ~Interaction();

    laDate date;
    std::string contenu;

    /**
     * @brief getDate
     * @return la date à laquelle se déroule la/les interactions
     */
    laDate getDate() const;
    void setDate(const laDate &value);

    /**
     * @brief getContenu
     * @return le contenu de l'interaction
     */
    std::string getContenu() const;
    void setContenu(const std::string &value);
};

#endif // INTERACTION_H
