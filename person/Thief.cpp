//
// Created by stefa on 28.04.2021.
//

#include "Thief.h"

Thief::Thief() : Person("voleur", PersonType::Thief) {}

bool Thief::canDrive() const {
    return false;
}
