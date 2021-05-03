//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_THIEF_H
#define LABO03_THIEF_H
#include "Person.h"

class Thief : public Person{
public:
    Thief();
    bool canDrive() const override;
};


#endif //LABO03_THIEF_H
