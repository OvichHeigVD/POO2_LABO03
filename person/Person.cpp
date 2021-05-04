/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Person.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of Person class
 */

#include "Person.h"

Person::Person(std::string name, PersonType type) : name(name), type(type) { }

bool Person::canDrive() const {
    return true;
}

bool Person::isChild() const {
    return false;
}

std::string Person::getName() const {
    return this->name;
}

Person::PersonType Person::getType() const {
    return this->type;
}