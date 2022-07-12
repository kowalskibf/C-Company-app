#include "FileHandler.h"
#include <fstream>

void FileHandler::save(std::string const path)
{
    std::ofstream file;
    file.open(path);
    for(auto &i : *(database->get_db_ptr()))
    {
        file << i->get_id() << std::endl;
        file << i->get_type() << std::endl;
        file << i->get_name() << std::endl;
        file << i->get_surname() << std::endl;
        file << i->get_pesel() << std::endl;
        file << i->get_gender() << std::endl;
        file << i->get_birth_date().get_day() << "-" << i->get_birth_date().get_month() << "-" << i->get_birth_date().get_year() << std::endl;
        file << i->get_date_employeed().get_day() << "-" << i->get_date_employeed().get_month() << "-" << i->get_date_employeed().get_year() << std::endl;
        file << i->get_salary() << std::endl;
        if(i->get_type() == "Manager")
        {
            file << "{" << std::endl;
            for(auto j : i->get_employees())
            {
                file << j << std::endl;
            }
            file << "}" << std::endl;
        }
    }
    file.close();
}

void FileHandler::load(std::string const path)
{
    database->clear_database();
    std::string line, id, type, name, surname, pesel, gender, birth_date, date_employeed, sal;
    std::ifstream file;
    file.open(path);
    int lines_counter = 0;
    int man_ct = 0;
    std::vector<std::vector<int>> assignments = {};
    while(getline(file, line))
    {
        if(lines_counter == 0)
        {
            id = line;
            while(std::stoi(id) > database->get_max_employees() + 1)
            {
                database->set_max_employees(database->get_max_employees() + 1);
            }
        }
        else if(lines_counter == 1) type = line;
        else if(lines_counter == 2) name = line;
        else if(lines_counter == 3) surname = line;
        else if(lines_counter == 4) pesel = line;
        else if(lines_counter == 5) gender = line;
        else if(lines_counter == 6) birth_date = line;
        else if(lines_counter == 7) date_employeed = line;
        else if(lines_counter == 8) sal = line;
        if(type == "Manager" && lines_counter > 8)
        {
            if(line == "{")
            {
                assignments.push_back(std::vector<int>{database->get_employees_number() + 1});
            }
            else if(line != "}")
            {
                (assignments[man_ct]).push_back(std::stoi(line));
            }
        }
        lines_counter++;
        if(type == "Employee" && lines_counter > 8)
        {
            lines_counter = 0;
            std::string bd, bm, by, ed, em, ey;
            unsigned int salary;
            if(birth_date[1] == '-' && birth_date[3] == '-')
            {
                bd = birth_date[0];
                bm = birth_date[2];
                by = birth_date.erase(0, 4);
            }
            else if(birth_date[1] == '-' && birth_date[4] == '-')
            {
                bd = birth_date[0];
                bm = birth_date.substr(2, 2);
                by = birth_date.erase(0, 5);
            }
            else if(birth_date[2] == '-' && birth_date[4] == '-')
            {
                bd = birth_date.substr(0, 2);
                bm = birth_date[3];
                by = birth_date.erase(0, 5);
            }
            else if(birth_date[2] == '-' && birth_date[5] == '-')
            {
                bd = birth_date.substr(0, 2);
                bm = birth_date.substr(3, 2);
                by = birth_date.erase(0, 6);
            }
            if(date_employeed[1] == '-' && date_employeed[3] == '-')
            {
                ed = date_employeed[0];
                em = date_employeed[2];
                ey = date_employeed.erase(0, 4);
            }
            else if(date_employeed[1] == '-' && date_employeed[4] == '-')
            {
                ed = date_employeed[0];
                em = date_employeed.substr(2, 2);
                ey = date_employeed.erase(0, 5);
            }
            else if(date_employeed[2] == '-' && date_employeed[4] == '-')
            {
                ed = date_employeed.substr(0, 2);
                em = date_employeed[3];
                ey = date_employeed.erase(0, 5);
            }
            else if(date_employeed[2] == '-' && date_employeed[5] == '-')
            {
                ed = date_employeed.substr(0, 2);
                em = date_employeed.substr(3, 2);
                ey = date_employeed.erase(0, 6);
            }
            Date new_birth_date(std::stoi(bd), std::stoi(bm), std::stoi(by));
            Date new_date_employeed(std::stoi(ed), std::stoi(em), std::stoi(ey));
            salary = std::stoi(sal);
            database->add_employee("Employee", name, surname, pesel, gender, new_birth_date, new_date_employeed, salary);
        }
        else if(type == "Manager" && line == "}")
        {
            lines_counter = 0;
            std::string bd, bm, by, ed, em, ey;
            unsigned int salary;
            if(birth_date[1] == '-' && birth_date[3] == '-')
            {
                bd = birth_date[0];
                bm = birth_date[2];
                by = birth_date.erase(0, 4);
            }
            else if(birth_date[1] == '-' && birth_date[4] == '-')
            {
                bd = birth_date[0];
                bm = birth_date.substr(2, 2);
                by = birth_date.erase(0, 5);
            }
            else if(birth_date[2] == '-' && birth_date[4] == '-')
            {
                bd = birth_date.substr(0, 2);
                bm = birth_date[3];
                by = birth_date.erase(0, 5);
            }
            else if(birth_date[2] == '-' && birth_date[5] == '-')
            {
                bd = birth_date.substr(0, 2);
                bm = birth_date.substr(3, 2);
                by = birth_date.erase(0, 6);
            }
            if(date_employeed[1] == '-' && date_employeed[3] == '-')
            {
                ed = date_employeed[0];
                em = date_employeed[2];
                ey = date_employeed.erase(0, 4);
            }
            else if(date_employeed[1] == '-' && date_employeed[4] == '-')
            {
                ed = date_employeed[0];
                em = date_employeed.substr(2, 2);
                ey = date_employeed.erase(0, 5);
            }
            else if(date_employeed[2] == '-' && date_employeed[4] == '-')
            {
                ed = date_employeed.substr(0, 2);
                em = date_employeed[3];
                ey = date_employeed.erase(0, 5);
            }
            else if(date_employeed[2] == '-' && date_employeed[5] == '-')
            {
                ed = date_employeed.substr(0, 2);
                em = date_employeed.substr(3, 2);
                ey = date_employeed.erase(0, 6);
            }
            Date new_birth_date(std::stoi(bd), std::stoi(bm), std::stoi(by));
            Date new_date_employeed(std::stoi(ed), std::stoi(em), std::stoi(ey));
            salary = std::stoi(sal);
            database->add_employee("Manager", name, surname, pesel, gender, new_birth_date, new_date_employeed, salary);
            man_ct++;
        }
    }
    for(auto i : assignments)
    {
        for(int j = 1; j < i.size(); j++)
        {
            database->assign_employee_by_id(i[0], i[j]);
        }
    }
    file.close();
}

void FileHandler::input_db_ptr(Database * database)
{
    this->database = database;
}
