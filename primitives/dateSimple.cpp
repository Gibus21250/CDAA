#include "dateSimple.h"

#include <iostream>
#include <vector>
#include <sstream>

DateSimple::DateSimple()
{
    if(date::is_am(std::chrono::hours()))
    {
        time = date::floor<date::days>(system_clock::now());
    }
    else
    {
        time = date::ceil<date::days>(system_clock::now());
    }
}

DateSimple::DateSimple(const std::string str)
{
    std::stringstream ss(str);
    std::string tmp;
    unsigned date[3];

    short i = 0;
    while(std::getline(ss, tmp, '/'))
    {
        date[i] = stoi(tmp);
        i++;
    }
    time = date::year(date[2])/date::month(date[1])/date::day(date[0]);
}

int DateSimple::getDifferenceDays(const DateSimple& d1, const DateSimple& d2)
{
    auto timeRestant = d2.time - d1.time;
    return timeRestant.count();
}

std::string DateSimple::getDateStrFormat() const
{
    auto ymd = date::year_month_day{time};

    std::string
            nbDay = std::to_string(ymd.day().d_),
            nbMois = std::to_string(ymd.month().m_),
            nbAnnee = std::to_string(ymd.year().y_);
    return nbDay + "/" + nbMois + "/" + nbAnnee;
}

    //  --  -- Operators -- -- //

bool DateSimple::operator<(const DateSimple& date) const
{
    return time < date.time;
}

bool DateSimple::operator>(const DateSimple& date) const
{
    return time > date.time;
}

bool DateSimple::operator==(const DateSimple& date) const
{
    return time == date.time;
}

bool DateSimple::operator<=(const DateSimple& date) const
{
    return time <= date.time;
}

bool DateSimple::operator>=(const DateSimple& date) const
{
    return time >= date.time;
}

bool DateSimple::operator!=(const DateSimple& date) const
{
    return time != date.time;
}


