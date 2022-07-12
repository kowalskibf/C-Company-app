#include "Interface.h"
#include <iostream>
#include <limits>
#include <cmath>

bool is_number(std::string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

void Interface::input_db_ptr(Database * database)
{
    this->database = database;
}

void Interface::input_fh_ptr(FileHandler * file_handler)
{
    this->file_handler = file_handler;
}

void Interface::main_menu() const
{
    clear_screen();
    std::cout << "MAIN MENU" << std::endl << std::endl;
    std::cout << "1. Add a new person" << std::endl;
    std::cout << "2. Remove an existing person" << std::endl;
    std::cout << "3. Edit an existing person" << std::endl;
    std::cout << "4. Show all existing persons" << std::endl; // chyba ze people ale tutaj chyba persons
    std::cout << "5. Show employees" << std::endl;
    std::cout << "6. Show managers" << std::endl;
    std::cout << "7. Save database to file" << std::endl;
    std::cout << "8. Load database from file" << std::endl;
    std::cout << "Anything else. Quit" << std::endl << std::endl;
    std::cout << "Choose by pressing a specific number on your keyboard and press enter" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice)
    {
    case 1:
        add_person();
        break;
    case 2:
        remove_person();
        break;
    case 3:
        edit_person();
        break;
    case 4:
        show_all();
        break;
    case 5:
        show_employees();
        break;
    case 6:
        show_managers();
        break;
    case 7:
        save_database();
        break;
    case 8:
        load_database();
        break;
    default:
        quit_app();
        break;
    }
}

void Interface::add_person() const
{
    clear_screen();
    std::cout << "ADD A NEW PERSON" << std::endl << std::endl;
    std::string name, surname, pesel, gender, type;
    unsigned int bd, bm, by, ed, em, ey, salary;
    bool ok = false;
    while(!ok)
    {
        std::cout << "Name: ";
        std::cin >> name;
        if(name.length() < 1 || name.length() > 255)
        {
            std::cout << "Name length must fall within a range of 1 and 255" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    ok = false;
    while(!ok)
    {
        std::cout << "Surname: ";
        std::cin >> surname;
        if(surname.length() < 1 || surname.length() > 255)
        {
            std::cout << "Surname length must fall within a range of 1 and 255" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    ok = false;
    while(!ok)
    {
        std::cout << "PESEL: ";
        std::cin >> pesel;
        if(!is_number(pesel))
        {
            std::cout << "PESEL must be a number" << std::endl;
        }
        else if(pesel.length() != 11)
        {
            std::cout << "PESEL length must be equal to 11" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    ok = false;
    while(!ok)
    {
        std::cout << "Gender: ";
        std::cin >> gender;
        if(gender.length() < 1 || gender.length() > 31)
        {
            std::cout << "Gender length must fall within a range of 1 and 31" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    ok = false;
    while(!ok)
    {
        std::cout << "Birth year: ";
        std::cin >> by;
        if(!std::cin || abs(by) != by || by <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Year must be a positive integer" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    while(!ok)
    {
        std::cout << "Birth month: ";
        std::cin >> bm;
        if(!std::cin || abs(bm) != bm || bm < 1 || bm > 12)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Month must be an integer falling within a range of 1 and 12" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    bool leap_year = (by % 400 == 0 || (by % 4 == 0 && by % 100 != 0));
    bool month_31 = (bm == 1 || bm == 3 || bm == 5 || bm == 7 || bm == 8 || bm == 10 || bm == 12);
    bool month_30 = (bm == 4 || bm == 6 || bm == 9 || bm == 11);
    while(!ok)
    {
        std::cout << "Birth day: ";
        std::cin >> bd;
        if(!std::cin || abs(bd) != bd || bd <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Day must be a positive integer" << std::endl;
        }
        else if(month_31)
        {
            if(bd >= 1 && bd <= 31)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 31" << std::endl;
            }
        }
        else if(month_30)
        {
            if(bd >= 1 && bd <= 30)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 30" << std::endl;
            }
        }
        else if(bm == 2 && leap_year)
        {
            if(bd >= 1 && bd <= 29)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 29" << std::endl;
            }
        }
        else if(bm == 2 && !leap_year)
        {
            if(bd >= 1 && bd <= 28)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 28" << std::endl;
            }
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    while(!ok)
    {
        std::cout << "Employed year: ";
        std::cin >> ey;
        if(!std::cin || abs(ey) != ey || ey <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Year must be a positive integer" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    while(!ok)
    {
        std::cout << "Employed month: ";
        std::cin >> em;
        if(!std::cin || abs(em) != em || em < 1 || em > 12)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Month must be an integer falling within a range of 1 and 12" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    leap_year = (ey % 400 == 0 || (ey % 4 == 0 && ey % 100 != 0));
    month_31 = (em == 1 || em == 3 || em == 5 || em == 7 || em == 8 || em == 10 || em == 12);
    month_30 = (em == 4 || em == 6 || em == 9 || em == 11);
    while(!ok)
    {
        std::cout << "Employed day: ";
        std::cin >> ed;
        if(!std::cin || abs(ed) != ed || ed <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Day must be a positive integer" << std::endl;
        }
        else if(month_31)
        {
            if(ed >= 1 && ed <= 31)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 31" << std::endl;
            }
        }
        else if(month_30)
        {
            if(ed >= 1 && ed <= 30)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 30" << std::endl;
            }
        }
        else if(em == 2 && leap_year)
        {
            if(ed >= 1 && ed <= 29)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 29" << std::endl;
            }
        }
        else if(em == 2 && !leap_year)
        {
            if(ed >= 1 && ed <= 28)
            {
                ok = true;
            }
            else
            {
                std::cout << "Day must fall within a range of 1 and 28" << std::endl;
            }
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    while(!ok)
    {
        std::cout << "Salary: ";
        std::cin >> salary;
        if(!std::cin || abs(salary) != salary || salary <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Salary must be a positive integer" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ok = false;
    while(!ok)
    {
        std::cout << "Type (Employee/Manager): ";
        std::cin >> type;
        if(type != "Employee" && type != "employee" && type != "E" && type != "e" && type != "M" && type != "m" && type != "Manager" && type != "manager")
        {
            std::cout << "Invalid input. For Employee try: Employee, employee, E, e; for Manager try: Manager, manager, M, m" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    database->add_employee(type, name, surname, pesel, gender, Date(bd, bm, by), Date(ed, em, ey), salary);
    main_menu();
}

void Interface::remove_person() const
{
    clear_screen();
    std::cout << "REMOVE A PERSON BY TYPING ID AND PRESSING ENTER" << std::endl << std::endl;
    for(auto &i : *(database->get_db_ptr()))
    {
        std::cout << i->get_id() << ". " << i->get_type() << " " << i->get_name() << " " << i->get_surname() << " " << i->get_pesel() << std::endl;
    }
    unsigned int id;
    bool ok = false;
    while(!ok)
    {
        std::cout << "Id: ";
        std::cin >> id;
        if(!std::cin || id < 0 || abs(id) != id)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Id must be a positive integer" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(auto & i : *(database->get_db_ptr()))
    {
        if(id == i->get_id())
        {
            database->remove_employee(id);
            break;
        }
    }
    main_menu();
}

void Interface::edit_person() const
{
    clear_screen();
    std::cout << "EDIT EMPLOYEE" << std::endl << std::endl;
    for(auto &i : *(database->get_db_ptr()))
    {
        std::cout << i->get_id() << ". " << i->get_type() << " " << i->get_name() << " " << i->get_surname() << " " << i->get_pesel() << std::endl;
    }
    std::cout << "Choose person by entering id" << std::endl;
    unsigned int id;
    bool ok = false;
    while(!ok)
    {
        std::cout << "Id: ";
        std::cin >> id;
        if(!std::cin || id < 0 || abs(id) != id)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Id must be a positive integer" << std::endl;
        }
        else
        {
            ok = true;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(auto & i : *(database->get_db_ptr()))
    {
        if(id == i->get_id())
        {
            clear_screen();
            std::cout << "EDIT AN EMPLOYEE" << std::endl << std::endl;
            std::cout << "1. Name" << std::endl;
            std::cout << "2. Surname" << std::endl;
            std::cout << "3. PESEL" << std::endl;
            std::cout << "4. Gender" << std::endl;
            std::cout << "5. Birth date" << std::endl;
            std::cout << "6. Date employeed" << std::endl;
            std::cout << "7. Salary" << std::endl;
            if(i->get_type() == "Manager")
            {
                std::cout << "8. Assign an Employee" << std::endl;
                std::cout << "9. Dismiss an Employee" << std::endl;
                std::cout << "Choose employee's atribute (1-9) and press enter" << std::endl;
            }
            else
            {
                std::cout << "Choose employee's atribute (1-7) and press enter" << std::endl;
            }
            int choice;
            std::cin >> choice;
            switch(choice)
            {
            case 1:
            {
                std::string name;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Name: ";
                    std::cin >> name;
                    if(name.length() < 1 || name.length() > 255)
                    {
                        std::cout << "Name length must fall within a range of 1 and 255" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                i->set_name(name);
            }
                break;
            case 2:
            {
                std::string surname;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Surname: ";
                    std::cin >> surname;
                    if(surname.length() < 1 || surname.length() > 255)
                    {
                        std::cout << "Surname length must fall within a range of 1 and 255" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                i->set_surname(surname);
            }
                break;
            case 3:
            {
                std::string pesel;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "PESEL: ";
                    std::cin >> pesel;
                    if(!is_number(pesel))
                    {
                        std::cout << "PESEL must be a number" << std::endl;
                    }
                    else if(pesel.length() != 11)
                    {
                        std::cout << "PESEL length must be equal to 11" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                i->set_pesel(pesel);
            }
                break;
            case 4:
            {
                std::string gender;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Gender: ";
                    std::cin >> gender;
                    if(gender.length() < 1 || gender.length() > 31)
                    {
                        std::cout << "Gender length must fall within a range of 1 and 31" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                } 
                i->set_gender(gender);
            }
                break;
            case 5:
            {
                unsigned int bd, bm, by;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Birth year: ";
                    std::cin >> by;
                    if(!std::cin || abs(by) != by || by <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Year must be a positive integer" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ok = false;
                while(!ok)
                {
                    std::cout << "Birth month: ";
                    std::cin >> bm;
                    if(!std::cin || abs(bm) != bm || bm < 1 || bm > 12)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Month must be an integer falling within a range of 1 and 12" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ok = false;
                bool leap_year = (by % 400 == 0 || (by % 4 == 0 && by % 100 != 0));
                bool month_31 = (bm == 1 || bm == 3 || bm == 5 || bm == 7 || bm == 8 || bm == 10 || bm == 12);
                bool month_30 = (bm == 4 || bm == 6 || bm == 9 || bm == 11);
                while(!ok)
                {
                    std::cout << "Birth day: ";
                    std::cin >> bd;
                    if(!std::cin || abs(bd) != bd || bd <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Day must be a positive integer" << std::endl;
                    }
                    else if(month_31)
                    {
                        if(bd >= 1 && bd <= 31)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 31" << std::endl;
                        }
                    }
                    else if(month_30)
                    {
                        if(bd >= 1 && bd <= 30)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 30" << std::endl;
                        }
                    }
                    else if(bm == 2 && leap_year)
                    {
                        if(bd >= 1 && bd <= 29)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 29" << std::endl;
                        }
                    }
                    else if(bm == 2 && !leap_year)
                    {
                        if(bd >= 1 && bd <= 28)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 28" << std::endl;
                        }
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Date d(bd, bm, by);
                i->set_birth_date(d);
            }
                break;
            case 6:
            {
                unsigned int ed, em, ey;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Employeed year: ";
                    std::cin >> ey;
                    if(!std::cin || abs(ey) != ey || ey <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Year must be a positive integer" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ok = false;
                while(!ok)
                {
                    std::cout << "Employeed month: ";
                    std::cin >> em;
                    if(!std::cin || abs(em) != em || em < 1 || em > 12)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Month must be an integer falling within a range of 1 and 12" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ok = false;
                bool leap_year = (ey % 400 == 0 || (ey % 4 == 0 && ey % 100 != 0));
                bool month_31 = (em == 1 || em == 3 || em == 5 || em == 7 || em == 8 || em == 10 || em == 12);
                bool month_30 = (em == 4 || em == 6 || em == 9 || em == 11);
                while(!ok)
                {
                    std::cout << "Employeed day: ";
                    std::cin >> ed;
                    if(!std::cin || abs(ed) != ed || ed <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Day must be a positive integer" << std::endl;
                    }
                    else if(month_31)
                    {
                        if(ed >= 1 && ed <= 31)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 31" << std::endl;
                        }
                    }
                    else if(month_30)
                    {
                        if(ed >= 1 && ed <= 30)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 30" << std::endl;
                        }
                    }
                    else if(em == 2 && leap_year)
                    {
                        if(ed >= 1 && ed <= 29)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 29" << std::endl;
                        }
                    }
                    else if(em == 2 && !leap_year)
                    {
                        if(ed >= 1 && ed <= 28)
                        {
                            ok = true;
                        }
                        else
                        {
                            std::cout << "Day must fall within a range of 1 and 28" << std::endl;
                        }
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Date d(ed, em, ey);
                i->set_date_employeed(d);
            }
                break;
            case 7:
            {
                unsigned int salary;
                bool ok = false;
                while(!ok)
                {
                    std::cout << "Salary: ";
                    std::cin >> salary;
                    if(!std::cin || abs(salary) != salary || salary <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Salary must be a positive integer" << std::endl;
                    }
                    else
                    {
                        ok = true;
                    }
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i->set_salary(salary);
            }
                break;
            case 8:
            {
                if(i->get_type() == "Manager")
                {
                    int emp_id;
                    std::cout << "Id of Employee:" << std::endl;
                    std::cin >> emp_id;
                    database->assign_employee_by_id(id, emp_id);
                    main_menu();
                }
                else
                {
                    break;
                }
            }
                break;
            case 9:
            {
                if(i->get_type() == "Manager")
                {
                    int emp_id;
                    std::cout << "Employees under this Manager" << std::endl << std::endl;
                    for(auto j : i->get_employees())
                    {
                        for(auto & k : *(database->get_db_ptr()))
                        {
                            if(k->get_id() == j)
                            {
                                std::cout << k->get_id() << ". " << k->get_type() << " " << k->get_name() << " " << k->get_surname() << " " << k->get_pesel() << std::endl;
                            }
                        }
                    }
                    std::cout << "Id of Employee:" << std::endl;
                    std::cin >> emp_id;
                    database->dismiss_employee_by_id(id, emp_id);
                    main_menu();
                }
                else
                {
                    break;
                }
            }
                break;
            }
            break;
        }
    }
    main_menu();
}

void Interface::show_all() const
{
    clear_screen();
    std::cout << "SHOWING EVERY PERSON" << std::endl << std::endl;
    database->print_all_employees();
    std::string id;
    std::cin >> id;
    main_menu();
}

void Interface::show_employees() const
{
    clear_screen();
    std::cout << "SHOWING EVERY EMPLOYEE" << std::endl << std::endl;
    for(auto & i : *(database->get_db_ptr()))
    {
        if(i->get_type() == "Employee")
        {
            i->print();
        }
    }
    std::string id;
    std::cin >> id;
    main_menu();
}

void Interface::show_managers() const
{
    clear_screen();
    std::cout << "SHOWING EVERY MANAGER" << std::endl << std::endl;
    for(auto & i : *(database->get_db_ptr()))
    {
        if(i->get_type() == "Manager")
        {
            i->print();
            for(auto j : i->get_employees())
            {
                for(auto & k : *(database->get_db_ptr()))
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
    std::string id;
    std::cin >> id;
    main_menu();
}

void Interface::save_database() const
{
    clear_screen();
    std::cout << "SAVE DATABASE TO FILE" << std::endl << std::endl;
    std::string path;
    std::cout << "Input file path: " << std::endl;
    std::cin >> path;
    while(path.length() < 5 || path.substr(path.size() - 4) != ".txt")
    {
        std::cout << "File path must end with .txt" << std::endl;
        std::cin >> path;
    }
    file_handler->save(path);
    main_menu();
}

void Interface::load_database() const
{
    clear_screen();
    std::cout << "LOAD DATABASE FROM FILE" << std::endl << std::endl;
    std::string path;
    std::cout << "Input file path: " << std::endl;
    std::cin >> path;
    file_handler->load(path);
    main_menu();
}

void Interface::clear_screen() const
{
    std::system("clear");
}

void Interface::quit_app() const
{
    clear_screen();
    std::cout << "Quitting application..." << std::endl;
    exit(0);
}
