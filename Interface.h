#include "FileHandler.h"
#include <iostream>

class Interface
{
private:
    Database * database;
    FileHandler * file_handler;
public:
    Interface(){}
    void input_db_ptr(Database * database);
    void input_fh_ptr(FileHandler * file_handler);
    void main_menu() const;
    void clear_screen() const;
    void add_person() const;
    void remove_person() const;
    void edit_person() const;
    void show_all() const;
    void show_employees() const;
    void show_managers() const;
    void save_database() const;
    void load_database() const;
    void quit_app() const;
};
