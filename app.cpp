#include "Interface.h"

int main()
{
    Database database;
    Database * db = & database;
    FileHandler file_handler;
    FileHandler * fh = & file_handler;
    file_handler.input_db_ptr(db);
    Interface interface;
    interface.input_db_ptr(db);
    interface.input_fh_ptr(fh);
    interface.main_menu();
    return 0;
}