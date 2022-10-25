#include "dateSimple.h"

#include <iostream>
#include <vector>
#include <sstream>

DateSimple::DateSimple()
{
    time = date::floor<date::days>(system_clock::now());
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

std::string& DateSimple::getDateStrFormat() const
{
    auto ymd = date::year_month_day{time};
    auto test = new std::string("");
    return *test; //std::string(ymd.day()) + "/" + ymd.month() + "/" + ymd.year();
}
