#include "Employee.h"
#include <vector>

class Manager : public Employee
{
private:
    std::vector<int> employees;
    int employees_number;
    //std::string type;
public:
    Manager(){}
    Manager(std::string name, std::string surname, std::string pesel,
        std::string gender, unsigned int employee_id, unsigned int salary,
        Date birth_date, Date date_employeed)
        :Employee(name, surname, pesel, gender, employee_id,
        salary, birth_date, date_employeed)
    {
        this->employees = {};
        this->employees_number = 0;
        // this->type = "Manager";
        type = "Manager";
    }
    int get_employees_number() const;
    void assign_employee(const int id);
    void dismiss_last_employee();
    void dismiss_employee_by_id(const int id);
    void print() const;

    virtual std::vector<int> get_employees() const;
};
