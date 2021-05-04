/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Parent.h
 * @date 05.05.2021
 *
 * @brief Abstract class of Parent, a sub-class to Person
 */

#ifndef LABO03_PARENT_H
#define LABO03_PARENT_H

#include "Person.h"

class Parent : public Person {
public:
    /**
     * Overriding canDrive
     * @return true, parents can drive the boat
     */
    bool canDrive() const override;

protected:
    /**
     * Common constructor for Mother and Father class
     * @param name - the name of a Parent
     */
    Parent(std::string name);
};

#endif //LABO03_PARENT_H