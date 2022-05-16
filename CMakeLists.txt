cmake_minimum_required(VERSION 3.10)

project(rpg)

find_package(SFML 2.5
  COMPONENTS
    system window graphics REQUIRED)

set(SOURCES src/main.cpp src/player.cpp src/tilemap.cpp)

add_executable(rpg ${SOURCES})

target_link_libraries(rpg sfml-graphics sfml-window sfml-system)
