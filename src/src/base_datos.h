#pragma once
#include <string>
#include <vector>
#include "sensores.h"
#include <sqlite3.h>

class BaseDeDatos {
public:
    BaseDeDatos(const std::string& nombre_db);
    ~BaseDeDatos();
    void crearTablas();
    bool almacenarDatos(const DatosSensores& datos);
    bool almacenarMinPromedioMax(const std::vector<DatosSensores>& mediciones);

private:
    sqlite3* db;
};
