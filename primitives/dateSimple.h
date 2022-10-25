#ifndef DATESIMPLE_H
#define DATESIMPLE_H

#include <string>
#include <chrono>

#include "date/date.h"

using namespace std::chrono;

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
     * @brief DateSimple
     * @param time
     */
    DateSimple(time_point<system_clock, date::days> time);

    /**
     * @brief Renvoie sous forme de string standard la date associé à l'instance
     * @return DateSimple sous forme de string standard à à l'aide de la classe date.h modifiée
     */
    std::string getDateStrFormat() const;

    static int getDifferenceDays(const DateSimple& d1, const DateSimple& d2);

    bool operator<(const DateSimple& date) const;
    bool operator==(const DateSimple& date) const;
    bool operator>(const DateSimple& date) const;
    bool operator<=(const DateSimple& date) const;
    bool operator>=(const DateSimple& date) const;
    bool operator!=(const DateSimple& date) const;

};

#endif // DATESIMPLE_H
