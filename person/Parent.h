/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Parent.h
 * @date 05.05.2021
 *
 * @brief Abstract class of Parent, a sub-class of Person
 */

#ifndef LABO03_PARENT_H
#define LABO03_PARENT_H

#include "Person.h"

class Parent : public Person {
public:
    /**
     * Overriding canDrive method
     * @return true, a Parent can drive the boat
     */
    bool canDrive() const override;

protected:
    /**
     * Constructor of parent
     * @param name - the name of the Parent
     */
    explicit Parent(std::string name);
};

#endif //LABO03_PARENT_H