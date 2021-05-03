//
// Created by stefa on 28.04.2021.
//

#include "Parent.h"


Parent::Parent(std::string name) : Person(std::move(name), PersonType::Family) {}

bool Parent::canDrive() const {
    return Person::canDrive();
}

