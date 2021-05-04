/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Mother.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Mother class
 */

#include "Mother.h"
#include "Father.h"

Mother::Mother() : Parent("mere") { }

Daughter* Mother::makeDaughter(std::string name, const Father* daddy) {
    // creating a Daughter dynamically with references to both parents
    return new Daughter(std::move(name), this, daddy);
}

Son* Mother::makeSon(std::string name, const Father* daddy) {
    // creating a Son dynamically with references to both parents
    return new Son(std::move(name), this, daddy);
}