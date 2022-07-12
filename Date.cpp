#include "Date.h"

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
    bool leap_year = (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    bool month_31 = (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12);
    bool month_30 = (m == 4 || m == 6 || m == 9 || m == 11);
    if(y <= 0)
    {
        throw std::out_of_range("Invalid year");
    }
    if(m < 1 || m > 12)
    {
        throw std::out_of_range("Invalid year");
    }
    if(d < 1 || d > 31)
    {
        throw std::out_of_range("Invalid day");
    }
    if(month_30)
    {
        if(d > 30)
        {
            throw std::out_of_range("Invalid day");
        }
    }
    if(m == 2 && ((leap_year && d > 29) || (!leap_year && d > 28)))
    {
        throw std::out_of_range("Invalid day");
    }
    day = d;
    month = m;
    year = y;
}

void Date::set_day(unsigned int d)
{
    if (d > 31 or d < 1)
    {
        throw std::out_of_range("Niepoprawny dzień!");
    }
    else
    {
        day = d;
    }
}

void Date::set_month(unsigned int m)
{
    if (m > 12 or m < 1)
        throw std::out_of_range("Niepoprawny miesiąc!");
    else
    {
        month = m;
    }
}

void Date::set_year(unsigned int y)
{
    year = y;
}

void Date::print_date() const
{
    std::cout << day << "-" << month << "-" << year << std::endl;
}

bool Date::operator<(const Date & d2) const
{
    if(year < d2.get_year()) return true;
    if(year > d2.get_year()) return false;
    if(month < d2.get_month()) return true;
    if(month > d2.get_month()) return false;
    if(day < d2.get_day()) return true;
    return false;
}

bool Date::operator>(const Date & d2) const
{
    if(year > d2.get_year()) return true;
    if(year < d2.get_year()) return false;
    if(month > d2.get_month()) return true;
    if(month < d2.get_month()) return false;
    if(day > d2.get_day()) return true;
    return false;
}

bool Date::operator<=(const Date & d2) const
{
    return not operator>(d2);
}

bool Date::operator>=(const Date & d2) const
{
    return not operator<(d2);
}

bool Date::operator==(const Date & d2) const
{
    return (day == d2.get_day() && month == d2.get_month() && year == d2.get_year());
}

bool Date::operator!=(const Date & d2) const
{
    return not operator==(d2);
}

Date Date::operator=(const Date & d2)
{
    day = d2.get_day();
    month = d2.get_month();
    year = d2.get_year();
    return *this;
}