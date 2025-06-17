cmake_minimum_required(VERSION 3.31)
project(Examenes_POO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Examenes_POO main.cpp
        P1-Monticulo/monticulo.cpp
        P1-Monticulo/monticulo.hpp
        P2-CAC/cac.cpp
        P2-CAC/cac.hpp
        P3-ADN/adn.cpp
        P3-ADN/adn.hpp)
