#include "Manager.h"
#include <iostream>
#include <memory>
#include <algorithm>

int Manager::get_employees_number() const
{
    return employees_number;
}

void Manager::assign_employee(const int id)
{
    employees.push_back(id);
    employees_number++;
}

void Manager::dismiss_last_employee()
{
    if(employees_number > 0)
    {
        employees.pop_back();
        employees_number--;
    }
    else
    {
        std::cout << "Unable to dismiss employee - employees collection is empty" << std::endl;
    }
}

void Manager::dismiss_employee_by_id(const int id)
{
    if(employees_number > 0)
    {
        employees.erase(std::remove(employees.begin(), employees.end(), id), employees.end());
        employees_number--;
    }
    else
    {
        std::cout << "Unable to dismiss employee - employees collection is empty" << std::endl;
    }
}

void Manager::print() const
{
    Employee::print();
    if(employees_number > 0)
    {
        std::cout << "Employees under Manager:" << std::endl;
        /*for(auto i : employees)
        {
            std::cout << i << std::endl;
        }*/
    }
}

std::vector<int> Manager::get_employees() const
{
    return employees;
}