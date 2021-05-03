//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_SON_H
#define LABO03_SON_H
#include "Child.h"

class Son : public Child{
public:
    Son(std::string name, const Mother* mama, const Father* papa);
    bool isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const override;
};


#endif //LABO03_SON_H
