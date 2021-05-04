/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Thief.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of the Thief class
 */

#include "Thief.h"

Thief::Thief() : Person("voleur", PersonType::Thief) {}

bool Thief::canDrive() const {
    return false;
}