//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_MOTHER_H
#define LABO03_MOTHER_H
#include "Parent.h"
#include "Daughter.h"
#include "Son.h"
class Mother : public Parent{
public:
    Mother();
    Daughter* makeDaughter(std::string name, const Father* papa);
    Son* makeSon(std::string name, const Father* papa);
};


#endif //LABO03_MOTHER_H
