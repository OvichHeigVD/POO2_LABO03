/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Thief.h
 * @date 05.05.2021
 *
 * @brief Abstract class of Thief, a sub-class of Person
 */

#ifndef LABO03_THIEF_H
#define LABO03_THIEF_H

#include "Person.h"

class Thief : public Person {
public:
    /**
     * Default constructor of Thief
     */
    Thief();

    /**
     * Overriding canDrive() method
     * @return false, a Thief cannot drive
     */
    bool canDrive() const override;
};

#endif //LABO03_THIEF_H