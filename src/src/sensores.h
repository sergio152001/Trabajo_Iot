#pragma once

#include <cstdint>
#include <ctime>

struct DatosSensores {
    time_t timestamp;      // Hora en la que se tomaron las mediciones
    float temperatura;     // -10°C – 45°C
    uint8_t humedad;       // 0 – 100%
    uint8_t humedad_suelo; // 0 – 100%
    float velocidad_viento; // 0 – 40 m/s
    float direccion_viento; // -180° – 180° Norte
    float precipitacion;   // 0 – 200 mm
    uint16_t intensidad_luz; // 0 – 4000 lúmenes
};

DatosSensores leerDatosSensores();
