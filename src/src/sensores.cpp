#include "sensores.h"
#include <cstdlib>
#include <ctime>

// Simulación de la lectura de datos de sensores
DatosSensores leerDatosSensores() {
    DatosSensores datos;
    datos.timestamp = std::time(nullptr);
    datos.temperatura = -10.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (45.0 + 10.0)));
    datos.humedad = rand() % 101;
    datos.humedad_suelo = rand() % 101;
    datos.velocidad_viento = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 40.0));
    datos.direccion_viento = -180.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 360.0));
    datos.precipitacion = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 200.0));
    datos.intensidad_luz = rand() % 4001;
    return datos;
}
