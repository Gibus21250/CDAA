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

    /**
     * @brief Initialise une date à la date du jour
     */
    DateSimple();

    /**
     * @brief Initialise une date au jour correspondant à la date strDate
     * @param String de la date<br>
     * L'argument peut être de forme jj/MM/aaaa ou aaaa-MM-jj
     */
    DateSimple(const std::string& strDate);

    /**
     * @brief Initialise la DateSimple correspondant au jour, le mois et l'année mis en argument
     * @param y : Année de la date demandée
     * @param m : Mois de l'année demandée
     * @param d : numéro du jour de l'année demandé
     */
    DateSimple(const unsigned y, const unsigned m, const unsigned d);

    /**
     * @brief DateSimple
     * @param time
     */
    DateSimple(time_point<system_clock, date::days> time);

    /**
     * @brief Renvoie sous forme de string standard la date associé à l'instance de forme jj/MM/aaaa
     * @return string correspondant à l'instance DateSimple
     */
    std::string getDateStrFormat() const;

    /**
     * @brief Renvoie sous forme de string standart la date associé à l'instance de forme aaaa-MM-jj
     * @return string correspondant à l'instance DateSimple
     */
    std::string getDateStrFormatBDD() const;

    ///Renvoie le numéro du jour associé à l'instance DateSimple
    int getJour() const;
    ///Renvoie le numéro du mois associé à l'instance DateSimple
    int getMois() const;
    ///Renvoie le numéro de l'année associé à l'instance DateSimple
    int getAnnee() const;

    /**
     * @brief avoir le nombre restant de jour entre les dates d1 et d2
     * @param d1
     * @param d2
     * @return
     */
    static int getDifferenceDays(const DateSimple& d1, const DateSimple& d2);

    bool operator<(const DateSimple& date) const;
    bool operator==(const DateSimple& date) const;
    bool operator>(const DateSimple& date) const;
    bool operator<=(const DateSimple& date) const;
    bool operator>=(const DateSimple& date) const;
    bool operator!=(const DateSimple& date) const;

};

#endif // DATESIMPLE_H
