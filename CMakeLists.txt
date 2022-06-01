cmake_minimum_required(VERSION 3.10)
project(rpg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(${CMAKE_SOURCE_DIR}/SFML)

set(SOURCES src/main.cpp src/player.cpp src/tilemap.cpp)

add_executable(rpg ${SOURCES})

target_link_libraries(rpg sfml-graphics sfml-window sfml-system)
