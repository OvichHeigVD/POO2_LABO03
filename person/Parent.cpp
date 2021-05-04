/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Parent.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of Parent class
 */

#include "Parent.h"

Parent::Parent(std::string name) : Person(std::move(name), PersonType::Family) { }

bool Parent::canDrive() const {
    return Person::canDrive();
}