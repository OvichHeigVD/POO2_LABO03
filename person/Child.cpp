//
// Created by stefa on 28.04.2021.
//

#include "Child.h"

Child::Child(std::string name, const Mother* momy, const Father* dady, const Gender gender)
: Person(std::move(name), PersonType::Family), momy(momy), dady(dady), gender(gender) {}

bool Child::canDrive() const {
    return false;
}

const Mother* Child::myMom() const {
    return this->momy;
}

const Father* Child::myDad() const {
    return this->dady;
}

bool Child::isChild() const{
    return true;
}

Child::Gender Child::getGender() const {
    return this->gender;
}
