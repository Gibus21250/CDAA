#ifndef DATESIMPLE_H
#define DATESIMPLE_H

#include <string>
#include <chrono>

#include "date/date.h"
#include "date/chrono_io.h"

using namespace std::chrono;

using day_point = time_point<system_clock, date::days>;

/**
 * @brief Une classe permettant l'utilisation plus simple d'objet Date
 */
class DateSimple
{
private:
    time_point<system_clock, date::days> time;

public:
                ////////////////////////
                ///   CONSTRUCTEURS  ///
                ////////////////////////
    /**
     * @brief Initialise une date à la date du jour
     */
    DateSimple();
    /**
     * @brief Initialise une date au jour correspondant à la date strDate
     * @param strDate
     */
    DateSimple(const std::string strDate);
    /**
     * @brief Initialise la DateSimple correspondant au jour, le mois et l'année mis en argument
     * @param y : Année de la date demandée
     * @param m : Mois de l'année demandée
     * @param d : numéro du jour de l'année demandé
     */
    DateSimple(const unsigned y, const unsigned m,  const unsigned d);

    /**
     * @brief Renvoie sous forme de string standard la date associé à l'instance
     * @return DateSimple sous forme de string standard
     */
    std::string& getDateStrFormat() const;

};

#endif // DATESIMPLE_H
