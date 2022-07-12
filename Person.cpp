#include "Person.h"

void Person::set_name(std::string name)
{
    if(name.length() > 31 || name.length() == 0)
    {
        throw std::out_of_range("Invalid name length");
    }
    else
    {
        this->name = name;
    }
}

void Person::set_surname(std::string surname)
{
    if(surname.length() > 31 || surname.length() == 0)
    {
        throw std::out_of_range("Invalid surname length");
    }
    else
    {
        this->surname = surname;
    }
}

void Person::set_birth_date(Date & birth_date)
{
    this->birth_date = birth_date;
}

void Person::set_pesel(std::string pesel)
{
    if(pesel.length() != 11)
    {
        throw std::out_of_range("Invalid PESEL length");
    }
    else
    {
        this->pesel = pesel;
    }
}

void Person::set_gender(std::string gender)
{
    if(gender.length() > 31 || gender.length() == 0)
    {
        throw std::out_of_range("Invalid gender length");
    }
    else
    {
        this->gender = gender;
    }
}

void Person::print() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Birth date: ";
    birth_date.print_date();
    std::cout << "PESEL: " << pesel << std::endl;
    std::cout << "Gender: " << gender << std::endl;
}