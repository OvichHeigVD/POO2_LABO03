//
// Created by stefa on 28.04.2021.
//

#include "Son.h"


Son::Son(std::string name, const Mother* mama, const Father* papa) : Child(std::move(name), mama, papa, Child::Gender::Male) {}

bool Son::isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const {
    return !(motherPresent && !fatherPresent);
}

/*          m f   r
 *          0 0 = 1         =>  1
 *          0 1 = 1         =>  1
 *          1 0 = 0         =>  0
 *          1 1 = 1         =>  1
 *
 *
 * */