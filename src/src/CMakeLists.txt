cmake_minimum_required(VERSION 3.10)
project(SensorDataApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find libraries
find_package(SQLite3 REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)

# Include directories
include_directories(${SQLite3_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS})

# Add executable for console application
add_executable(SensorDataApp_Console
    main_consulta.cpp
    base_datos.cpp
    sensores.cpp
)
target_link_libraries(SensorDataApp_Console ${SQLite3_LIBRARIES})

# Add executable for GUI application
add_executable(SensorDataApp_GUI
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Ensure UI files are processed
qt5_wrap_ui(UI_HEADERS mainwindow.ui)

# Ensure MOC is run on the headers containing Q_OBJECT
qt5_wrap_cpp(MOC_SOURCES mainwindow.h)

# Add MOC sources to the executable
target_sources(SensorDataApp_GUI PRIVATE ${MOC_SOURCES})

# Link libraries to GUI application
target_link_libraries(SensorDataApp_GUI Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)
