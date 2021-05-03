cmake_minimum_required(VERSION 3.19)
project(LABO03)

set(CMAKE_CXX_STANDARD 14)

add_executable(LABO03 main.cpp person/Person.cpp person/Person.h container/Container.cpp container/Container.h container/Boat.cpp container/Boat.h container/Bank.cpp container/Bank.h Controller.cpp Controller.h person/Father.cpp person/Father.h person/Mother.cpp person/Mother.h person/Parent.cpp person/Parent.h person/Child.cpp person/Child.h person/Daughter.cpp person/Daughter.h person/Son.cpp person/Son.h person/Police.cpp person/Police.h person/Thief.cpp person/Thief.h)