/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Police.cpp
 * @date 05.05.2021
 *
 * @brief Implementation of Police class
 */
#include "Police.h"

Police::Police() : Person("policier") { }

bool Police::isFamily() const {
    return false;
}

bool Police::isPolice() const {
    return true;
}
