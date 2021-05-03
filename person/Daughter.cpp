//
// Created by stefa on 28.04.2021.
//

#include "Daughter.h"

Daughter::Daughter(std::string name, const Mother* mama, const Father* papa)
: Child(std::move(name), mama, papa, Child::Gender::Female) {

}

bool Daughter::isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const {
    return !(fatherPresent && !motherPresent);
}
