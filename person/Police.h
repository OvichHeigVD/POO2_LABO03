/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Police.h
 * @date 05.05.2021
 *
 * @brief Class representing the policeman, a sub-class of Person
 */

#ifndef LABO03_POLICE_H
#define LABO03_POLICE_H
#include "Person.h"

class Police : public Person {
public:
    /**
     * Default constructor of Police
     */
    Police();

    /**
     * Overriding abstract isFamily() method
     * @return false, a Policeman is not a family member
     */
    bool isFamily() const override;

    /**
     * Overriding abstract isPolice() method
     * @return true
     */
    bool isPolice() const override;
};

#endif //LABO03_POLICE_H