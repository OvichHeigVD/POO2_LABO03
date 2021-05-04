/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Son.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Son class
 */

#include "Son.h"

Son::Son(std::string name, const Mother* mommy, const Father* daddy) :
    Child(std::move(name), mommy, daddy, Child::Gender::Boy) {}

bool Son::isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const {
    return !(motherPresent && !fatherPresent); // return true if (true, false)
}