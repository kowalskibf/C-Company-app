#include "Person.h"
#include <vector>

class Employee : public Person
{
protected:
    unsigned int employee_id, salary;
    Date date_employeed;
    std::string type;
public:
    Employee(){}
    Employee(std::string name, std::string surname, std::string pesel,
        std::string gender, unsigned int employee_id, unsigned int salary,
        Date birth_date, Date date_employeed)
        :Person(name, surname, birth_date, pesel, gender)
    {
        this->employee_id = employee_id;
        this->salary = salary;
        this->date_employeed = date_employeed;
        this->type = "Employee";
    }

    void print() const;

    unsigned int get_id() const {return employee_id;}
    unsigned int get_salary() const {return salary;}
    Date get_date_employeed() const {return date_employeed;}
    std::string get_type() const {return type;}

    void set_id(const int id);
    void set_salary(const unsigned int salary);
    void set_date_employeed(Date const & date_employeed);

    bool operator<(const Employee & e2) const;
    bool operator>(const Employee & e2) const;
    bool operator<=(const Employee & e2) const;
    bool operator>=(const Employee & e2) const;
    bool operator==(const Employee & e2) const;
    bool operator!=(const Employee & e2) const;

    virtual std::vector<int> get_employees() const;
    virtual void assign_employee(const int id);
    virtual void dismiss_employee_by_id(const int id);
    virtual int get_employees_number() const;
};