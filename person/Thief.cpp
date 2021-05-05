/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Thief.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of the Thief class
 */

#include "Thief.h"

Thief::Thief() : Person("voleur") {}

bool Thief::canDrive() const {
    return false;
}

bool Thief::isFamily() const{
    return false;
}

bool Thief::isThief() const{
    return true;
}