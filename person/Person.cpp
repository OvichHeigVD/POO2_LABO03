/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Person.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of Person class
 */

#include "Person.h"

Person::Person(std::string name) : name(std::move(name)) { }

bool Person::canDrive() const {
    return true;
}

bool Person::isChild() const {
    return false;
}

bool Person::isFamily() const {
    return true;
}

bool Person::isThief() const {
    return false;
}

bool Person::isPolice() const {
    return false;
}

std::string Person::getName() const {
    return this->name;
}