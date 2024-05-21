#include "base_datos.h"
#include <iostream>
#include <sqlite3.h>
#include <ctime>
#include <limits>

BaseDeDatos::BaseDeDatos(const std::string& nombre_db) : db(nullptr) {
    int rc = sqlite3_open(nombre_db.c_str(), &db);
    if (rc) {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    } else {
        std::cout << "Base de datos abierta correctamente." << std::endl;
        crearTablas();
    }
}

BaseDeDatos::~BaseDeDatos() {
    if (db) {
        sqlite3_close(db);
    }
}

void BaseDeDatos::crearTablas() {
    char* error_msg = nullptr;
    const char* create_table_query = "CREATE TABLE IF NOT EXISTS datos_sensores ("
                                     "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                     "timestamp INTEGER,"
                                     "temperatura REAL,"
                                     "humedad INTEGER,"
                                     "humedad_suelo INTEGER,"
                                     "velocidad_viento REAL,"
                                     "direccion_viento REAL,"
                                     "precipitacion REAL,"
                                     "intensidad_luz INTEGER"
                                     ");";

    int rc = sqlite3_exec(db, create_table_query, nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al crear la tabla 'datos_sensores': " << error_msg << std::endl;
        sqlite3_free(error_msg);
    } else {
        std::cout << "Tabla 'datos_sensores' creada correctamente." << std::endl;
    }

    const char* create_min_prom_max_table_query = "CREATE TABLE IF NOT EXISTS datos_sensores_min_prom_max ("
                                                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                                  "timestamp INTEGER,"
                                                  "min_temperatura REAL,"
                                                  "prom_temperatura REAL,"
                                                  "max_temperatura REAL,"
                                                  "min_humedad INTEGER,"
                                                  "prom_humedad REAL,"
                                                  "max_humedad INTEGER,"
                                                  "min_humedad_suelo INTEGER,"
                                                  "prom_humedad_suelo REAL,"
                                                  "max_humedad_suelo INTEGER,"
                                                  "min_velocidad_viento REAL,"
                                                  "prom_velocidad_viento REAL,"
                                                  "max_velocidad_viento REAL,"
                                                  "min_direccion_viento REAL,"
                                                  "prom_direccion_viento REAL,"
                                                  "max_direccion_viento REAL,"
                                                  "min_precipitacion REAL,"
                                                  "prom_precipitacion REAL,"
                                                  "max_precipitacion REAL,"
                                                  "min_intensidad_luz INTEGER,"
                                                  "prom_intensidad_luz REAL,"
                                                  "max_intensidad_luz INTEGER"
                                                  ");";

    rc = sqlite3_exec(db, create_min_prom_max_table_query, nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al crear la tabla 'datos_sensores_min_prom_max': " << error_msg << std::endl;
        sqlite3_free(error_msg);
    } else {
        std::cout << "Tabla 'datos_sensores_min_prom_max' creada correctamente." << std::endl;
    }
}

bool BaseDeDatos::almacenarDatos(const DatosSensores& datos) {
    char* error_msg = nullptr;
    std::string query = "INSERT INTO datos_sensores ("
                        "timestamp, temperatura, humedad, humedad_suelo, "
                        "velocidad_viento, direccion_viento, precipitacion, intensidad_luz) "
                        "VALUES (" + std::to_string(datos.timestamp) + ", " +
                        std::to_string(datos.temperatura) + ", " +
                        std::to_string(datos.humedad) + ", " +
                        std::to_string(datos.humedad_suelo) + ", " +
                        std::to_string(datos.velocidad_viento) + ", " +
                        std::to_string(datos.direccion_viento) + ", " +
                        std::to_string(datos.precipitacion) + ", " +
                        std::to_string(datos.intensidad_luz) + ");";

    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al almacenar los datos: " << error_msg << std::endl;
        sqlite3_free(error_msg);
        return false;
    }

    return true;
}
bool BaseDeDatos::almacenarMinPromedioMax(const std::vector<DatosSensores>& mediciones) {
    if (mediciones.empty()) return false;

    char* error_msg = nullptr;

    // Inicializar los valores mínimos, promedio y máximos para cada sensor
    float min_temperatura = std::numeric_limits<float>::max();
    float max_temperatura = std::numeric_limits<float>::min();
    float sum_temperatura = 0.0;
    int count_temperatura = 0;

    int min_humedad = std::numeric_limits<int>::max();
    int max_humedad = std::numeric_limits<int>::min();
    int sum_humedad = 0;
    int count_humedad = 0;

    int min_humedad_suelo = std::numeric_limits<int>::max();
    int max_humedad_suelo = std::numeric_limits<int>::min();
    int sum_humedad_suelo = 0;
    int count_humedad_suelo = 0;

    float min_velocidad_viento = std::numeric_limits<float>::max();
    float max_velocidad_viento = std::numeric_limits<float>::min();
    float sum_velocidad_viento = 0.0;
    int count_velocidad_viento = 0;

    float min_direccion_viento = std::numeric_limits<float>::max();
    float max_direccion_viento = std::numeric_limits<float>::min();
    float sum_direccion_viento = 0.0;
    int count_direccion_viento = 0;

    float min_precipitacion = std::numeric_limits<float>::max();
    float max_precipitacion = std::numeric_limits<float>::min();
    float sum_precipitacion = 0.0;
    int count_precipitacion = 0;

    int min_intensidad_luz = std::numeric_limits<int>::max();
    int max_intensidad_luz = std::numeric_limits<int>::min();
    int sum_intensidad_luz = 0;
    int count_intensidad_luz = 0;

    // Calcular los valores mínimos, promedio y máximos para cada sensor
    for (const auto& medicion : mediciones) {
        // Temperatura
        if (medicion.temperatura < min_temperatura) {
            min_temperatura = medicion.temperatura;
        }
        if (medicion.temperatura > max_temperatura) {
            max_temperatura = medicion.temperatura;
        }
        sum_temperatura += medicion.temperatura;
        count_temperatura++;

        // Humedad
        if (medicion.humedad < min_humedad) {
            min_humedad = medicion.humedad;
        }
        if (medicion.humedad > max_humedad) {
            max_humedad = medicion.humedad;
        }
        sum_humedad += medicion.humedad;
        count_humedad++;

        // Humedad del suelo
        if (medicion.humedad_suelo < min_humedad_suelo) {
            min_humedad_suelo = medicion.humedad_suelo;
        }
        if (medicion.humedad_suelo > max_humedad_suelo) {
            max_humedad_suelo = medicion.humedad_suelo;
        }
        sum_humedad_suelo += medicion.humedad_suelo;
        count_humedad_suelo++;

        // Velocidad del viento
        if (medicion.velocidad_viento < min_velocidad_viento) {
            min_velocidad_viento = medicion.velocidad_viento;
        }
        if (medicion.velocidad_viento > max_velocidad_viento) {
            max_velocidad_viento = medicion.velocidad_viento;
        }
        sum_velocidad_viento += medicion.velocidad_viento;
        count_velocidad_viento++;

        // Dirección del viento
        if (medicion.direccion_viento < min_direccion_viento) {
            min_direccion_viento = medicion.direccion_viento;
        }
        if (medicion.direccion_viento > max_direccion_viento) {
            max_direccion_viento = medicion.direccion_viento;
        }
        sum_direccion_viento += medicion.direccion_viento;
        count_direccion_viento++;

        // Precipitación
        if (medicion.precipitacion < min_precipitacion) {
            min_precipitacion = medicion.precipitacion;
        }
        if (medicion.precipitacion > max_precipitacion) {
            max_precipitacion = medicion.precipitacion;
        }
        sum_precipitacion += medicion.precipitacion;
        count_precipitacion++;

        // Intensidad de luz
        if (medicion.intensidad_luz < min_intensidad_luz) {
            min_intensidad_luz = medicion.intensidad_luz;
        }
        if (medicion.intensidad_luz > max_intensidad_luz) {
            max_intensidad_luz = medicion.intensidad_luz;
        }
        sum_intensidad_luz += medicion.intensidad_luz;
        count_intensidad_luz++;
    }

    // Calcular los promedios
    float prom_temperatura = sum_temperatura / count_temperatura;
    float prom_humedad = static_cast<float>(sum_humedad) / count_humedad;
    float prom_humedad_suelo = static_cast<float>(sum_humedad_suelo) / count_humedad_suelo;
    float prom_velocidad_viento = sum_velocidad_viento / count_velocidad_viento;
    float prom_direccion_viento = sum_direccion_viento / count_direccion_viento;
    float prom_precipitacion = sum_precipitacion / count_precipitacion;
    float prom_intensidad_luz = static_cast<float>(sum_intensidad_luz) / count_intensidad_luz;

    // Construir la consulta SQL con los valores calculados
    std::string query = "INSERT INTO datos_sensores_min_prom_max ("
                        "timestamp, min_temperatura, prom_temperatura, max_temperatura, "
                        "min_humedad, prom_humedad, max_humedad, "
                        "min_humedad_suelo, prom_humedad_suelo, max_humedad_suelo, "
                        "min_velocidad_viento, prom_velocidad_viento, max_velocidad_viento, "
                        "min_direccion_viento, prom_direccion_viento, max_direccion_viento, "
                        "min_precipitacion, prom_precipitacion, max_precipitacion, "
                        "min_intensidad_luz, prom_intensidad_luz, max_intensidad_luz) "
                        "VALUES (" + std::to_string(mediciones[0].timestamp) + ", " +
                        std::to_string(min_temperatura) + ", " +
                        std::to_string(prom_temperatura) + ", " +
                        std::to_string(max_temperatura) + ", " +
                        std::to_string(min_humedad) + ", " +
                        std::to_string(prom_humedad) + ", " +
                        std::to_string(max_humedad) + ", " +
                        std::to_string(min_humedad_suelo) + ", " +
                        std::to_string(prom_humedad_suelo) + ", " +
                        std::to_string(max_humedad_suelo) + ", " +
                        std::to_string(min_velocidad_viento) + ", " +
                        std::to_string(prom_velocidad_viento) + ", " +
                        std::to_string(max_velocidad_viento) + ", " +
                        std::to_string(min_direccion_viento) + ", " +
                        std::to_string(prom_direccion_viento) + ", " +
                        std::to_string(max_direccion_viento) + ", " +
                        std::to_string(min_precipitacion) + ", " +
                        std::to_string(prom_precipitacion) + ", " +
                        std::to_string(max_precipitacion) + ", " +
                        std::to_string(min_intensidad_luz) + ", " +
                        std::to_string(prom_intensidad_luz) + ", " +
                        std::to_string(max_intensidad_luz) + ");";

    // Ejecutar la consulta SQL
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al almacenar los datos: " << error_msg << std::endl;
        sqlite3_free(error_msg);
        return false;
    }

    return true;
}
