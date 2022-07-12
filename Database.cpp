#include "Database.h"
#include <algorithm>

Database::Database()
{
    max_employees = 0;
}

bool Database::add_employee(std::string type, std::string name, std::string surname, std::string pesel, std::string gender, Date birth_date, Date date_employeed, unsigned int salary)
{
    if(type == "Manager" || type == "manager" || type == "M" || type == "m")
    {
        std::unique_ptr<Employee> ptr = std::make_unique<Manager>(name, surname, pesel, gender, max_employees + 1, salary, birth_date, date_employeed);
        database.push_back(std::move(ptr));
    }
    else
    {
        std::unique_ptr<Employee> ptr = std::make_unique<Employee>(name, surname, pesel, gender, max_employees + 1, salary, birth_date, date_employeed);
        database.push_back(std::move(ptr));
    }
    max_employees++;
    return true;
}

void Database::remove_employee(const int id)
{
    int pos = 0;
    for(auto & i : database)
    {
        if(id != i->get_id())
        {
            pos++;
        }
        else
        {
            break;
        }
    }
    database.erase(database.begin() + pos);
    for(auto & i : database)
    {
        if(i->get_type() == "Manager")
        {
            for(auto j : i->get_employees())
            {
                if(j == id)
                {
                    i->dismiss_employee_by_id(id);
                }
            }
        }
    }

}

bool Database::print_employee(const int id) const
{
    for(auto & i : database)
    {
        if(id == i->get_id())
        {
            std::cout << "Id: " << i->get_id() << std::endl;
            std::string type = i->get_type(); 
            if (type.size() == 0)
                type = "Employee";
            std::cout << "Type: " << type << std::endl;
            std::cout << "Name: " << i->get_name() << std::endl;
            std::cout << "Surname: " << i->get_surname() << std::endl;
            std::cout << "PESEL: " << i->get_pesel() << std::endl;
            std::cout << "Gender: " << i->get_gender() << std::endl;
            std::cout << "Birth date: " << i->get_birth_date().get_day() << "-" << i->get_birth_date().get_month() << "-" << i->get_birth_date().get_year() << std::endl;
            std::cout << "Employeed date: " << i->get_date_employeed().get_day() << "-" << i->get_date_employeed().get_month() << "-" << i->get_date_employeed().get_year() << std::endl;
            std::cout << "Salary: " << i->get_salary() << std::endl;
            return true;
        }
    }
    return false;
}

void Database::print_all_employees() const
{
    for(auto & i : database)
    {
        i->print();
        if(i->get_type() == "Manager")
        {
            if(i->get_employees_number() > 0)
            {
                for(auto j : i->get_employees())
                {
                    for(auto & k : database)
                    {
                        if(k->get_id() == j)
                        {
                            std::cout << k->get_id() << ". " << k->get_type() << " " << k->get_name() << " " << k->get_surname() << " " << k->get_pesel() << std::endl;
                        }
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}

std::vector<std::unique_ptr<Employee>>* Database::get_db_ptr()
{
    return &database;
}

void Database::clear_database()
{
    database.clear();
    max_employees = 0;
}

void Database::assign_employee_by_id(const int man_id, const int emp_id)
{
    bool ok_man = false;
    bool ok_emp = false;
    for(auto & i : database)
    {
        if(i->get_id() == man_id && i->get_type() == "Manager")
        {
            ok_man = true;
            break;
        }
    }
    for(auto & i : database)
    {
        if(i->get_id() == emp_id && i->get_type() == "Employee")
        {
            ok_emp = true;
            break;
        }
    }
    for(auto & i : database)
    {
        if(i->get_type() == "Manager")
        {
            for(auto i : i->get_employees())
            {
                if(i == emp_id)
                {
                    ok_emp = false;
                }
            }
        }
    }
    if(ok_man && ok_emp)
    {
        for(auto & i : database)
        {
            if(i->get_id() == man_id && i->get_type() == "Manager")
            {
                i->assign_employee(emp_id);
            }
        }
    }
}

void Database::dismiss_employee_by_id(const int man_id, const int emp_id)
{
    bool ok_man = false;
    bool ok_emp = false;
    for(auto & i : database)
    {
        if(i->get_id() == man_id && i->get_type() == "Manager")
        {
            ok_man = true;
            break;
        }
    }
    for(auto & i : database)
    {
        if(i->get_id() == emp_id && i->get_type() == "Employee")
        {
            ok_emp = true;
            break;
        }
    }
    if(ok_man && ok_emp)
    {
        for(auto & i : database)
        {
            if(i->get_id() == man_id && i->get_type() == "Manager")
            {
                i->dismiss_employee_by_id(emp_id);
            }
        }
    }
}

int Database::get_employees_number() const
{
    return database.size();
}

int Database::get_max_employees() const
{
    return max_employees;
}

void Database::set_max_employees(const int num)
{
    this->max_employees = num;
}
