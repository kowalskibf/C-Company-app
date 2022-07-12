#include "Database.h"

class FileHandler
{
    Database * database;
public:
    FileHandler(){}
    void save(std::string const path);
    void load(std::string const path);
    void input_db_ptr(Database * database);
};
