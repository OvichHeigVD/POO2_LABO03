//
// Created by stefa on 21.04.2021.
//

#include "Person.h"

Person::Person(std::string name, PersonType type) : name(name), type(type) {

}

bool Person::canDrive() const {
    return true;
}

std::string Person::getName() const {
    return this->name;
}

bool Person::isChild() const {
    return false;
}

Person::PersonType Person::getType() const {
    return this->type;
}

