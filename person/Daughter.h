//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_DAUGHTER_H
#define LABO03_DAUGHTER_H
#include "Child.h"

class Daughter : public Child {
public:
    Daughter(std::string name, const Mother* mama, const Father* papa);
    bool isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const override;
};


#endif //LABO03_DAUGHTER_H
