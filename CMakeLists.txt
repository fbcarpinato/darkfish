cmake_minimum_required(VERSION 3.25)
project(darkfish VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Add the executable and include necessary files
add_executable(darkfish
        main.cpp
        src/engine/Board.cpp
        src/engine/Board.h
        src/engine/Piece.h
        src/gui/BoardPrinter.cpp
        src/gui/BoardPrinter.h
        src/gui/GUI.cpp
        src/gui/GUI.h)

# Link against the required Qt libraries
target_link_libraries(darkfish PRIVATE Qt6::Widgets)
