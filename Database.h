#include "Manager.h"
#include <memory>

class Database
{
private:
    std::vector<std::unique_ptr<Employee>> database;
    int max_employees;
public:
    Database();
    bool add_employee(std::string type, std::string name, std::string surname, std::string pesel, std::string gender, Date birth_date, Date date_employeed, unsigned int salary);
    void remove_employee(const int id);
    bool print_employee(const int id) const;
    void print_all_employees() const;
    std::vector<std::unique_ptr<Employee>>* get_db_ptr();
    void clear_database();
    void assign_employee_by_id(const int man_id, const int emp_id);
    void dismiss_employee_by_id(const int man_id, const int emp_id);
    int get_employees_number() const;
    int get_max_employees() const;
    void set_max_employees(const int num);
};
