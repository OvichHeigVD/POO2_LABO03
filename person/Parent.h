//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_PARENT_H
#define LABO03_PARENT_H
#include "Person.h"
#include "Child.h"
#include <list>
class Parent : public Person{
public:
    bool canDrive() const override;
protected:
    Parent(std::string name);

};


#endif //LABO03_PARENT_H
