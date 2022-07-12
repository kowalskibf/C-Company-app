#include "Employee.h"

void Employee::print() const
{
    std::cout << "Id: " << employee_id << std::endl;
    std::cout << "Type: " << type << std::endl;
    Person::print();
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Date employeed: ";
    date_employeed.print_date();
    std::cout << std::endl;
}

void Employee::set_id(const int id)
{
    this->employee_id = id;
}

void Employee::set_salary(const unsigned int salary)
{
    this->salary = salary;
}

void Employee::set_date_employeed(Date const & date_employeed)
{
    this->date_employeed = date_employeed;
}

bool Employee::operator<(const Employee & e2) const
{
    return (employee_id < e2.employee_id);
}

bool Employee::operator>(const Employee & e2) const
{
    return (employee_id > e2.employee_id);
}

bool Employee::operator>=(const Employee & e2) const
{
    return not operator<(e2);
}

bool Employee::operator<=(const Employee & e2) const
{
    return not operator>(e2);
}

bool Employee::operator==(const Employee & e2) const
{
    return (employee_id == e2.employee_id);
}

bool Employee::operator!=(const Employee & e2) const
{
    return not operator==(e2);
}

std::vector<int> Employee::get_employees() const
{
    std::vector<int> v = {};
    return v;
}

void Employee::assign_employee(const int id)
{
    
}

void Employee::dismiss_employee_by_id(const int id)
{

}

int Employee::get_employees_number() const
{
    return 0;
}