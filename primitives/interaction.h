#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include "primitives/dateSimple.h"

using laDate = std::chrono::time_point<std::chrono::system_clock, date::days>;


class Interaction
{
public:
    Interaction();
<<<<<<< HEAD
    Interaction(const std::string& desc);
    Interaction(const std::string& desc, const DateSimple& date);
    Interaction(const std::string& desc, const std::string& date);

    DateSimple date;
    std::string contenu;
    friend std::ostream& operator<<(std::ostream out, const Interaction& i);
=======
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
>>>>>>> de128080eccd3c5be6cda10e29c325f5d5406ff1
};

#endif // INTERACTION_H
