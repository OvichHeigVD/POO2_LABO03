/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Child.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Child class
 */

#include "Child.h"

Child::Child(std::string name, const Mother* mommy,
             const Father* daddy, const Gender gender):
             Person(std::move(name)),
             mommy(mommy), daddy(daddy), gender(gender) {}

bool Child::canDrive() const {
    return false;
}

bool Child::isChild() const{
    return true;
}

const Mother* Child::myMom() const {
    return this->mommy;
}

const Father* Child::myDad() const {
    return this->daddy;
}

Child::Gender Child::getGender() const {
    return this->gender;
}