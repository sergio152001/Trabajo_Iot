cmake_minimum_required(VERSION 3.10)
project(SensorDataApp)

set(CMAKE_CXX_STANDARD 11)

find_package(SQLite3 REQUIRED)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(SensorDataApp main_consulta.cpp base_datos.cpp sensores.cpp)

target_link_libraries(SensorDataApp ${SQLite3_LIBRARIES})
