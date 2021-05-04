/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Daughter.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Daughter class
 */

#include "Daughter.h"

Daughter::Daughter(std::string name, const Mother* mommy, const Father* daddy)
    : Child(std::move(name), mommy, daddy, Child::Gender::Girl) { }

bool Daughter::isAccompaniedCorrectly(bool fatherPresent,
                                      bool motherPresent) const {
    return !(fatherPresent && !motherPresent); // return true if (true, false)
}