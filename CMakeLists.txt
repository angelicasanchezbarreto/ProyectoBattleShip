cmake_minimum_required(VERSION 3.13)
project(ProyectoBattleShip)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ProyectoBattleShip
        ComputerGame.cpp
        ComputerGame.h
        Game.cpp
        Game.h
        main.cpp
        Ship.cpp
        Ship.h)
