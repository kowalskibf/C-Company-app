#include <stdexcept>
#include <iostream>

class Date
{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int d = 1, unsigned int m = 1, unsigned int y = 1);
    
    void set_day(unsigned int d);
    void set_month(unsigned int m);
    void set_year(unsigned int y);

    unsigned int get_day() const {return day;}
    unsigned int get_month() const {return month;}
    unsigned int get_year() const {return year;}

    void print_date() const;

    bool operator<(const Date & d2) const;
    bool operator>(const Date & d2) const;
    bool operator<=(const Date & d2) const;
    bool operator>=(const Date & d2) const;
    bool operator==(const Date & d2) const;
    bool operator!=(const Date & d2) const;

    Date operator=(const Date & d2);
};