#include <iostream>
#include "Date.h"

class Person
{
protected:
    std::string name;
    std::string surname;
    Date birth_date;
    std::string pesel;
    std::string gender;
public:
    Person(){}
    Person(std::string name, std::string surname, Date birth_date, std::string pesel, std::string gender)
    {
        this->name = name;
        this->surname = surname;
        this->birth_date = birth_date;
        this->pesel = pesel;
        this->gender = gender;
    }
    std::string get_name() const {return name;}
    std::string get_surname() const {return surname;}
    Date get_birth_date() const {return birth_date;}
    std::string get_pesel() const {return pesel;}
    std::string get_gender() const {return gender;}
    void set_name(std::string name);
    void set_surname(std::string surname);
    void set_birth_date(Date & birth_date);
    void set_pesel(std::string pesel);
    void set_gender(std::string gender);
    virtual void print() const;
};