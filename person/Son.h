/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Son.h
 * @date 05.05.2021
 *
 * @brief Class representing the son of the family, a sub-class of Child
 */

#ifndef LABO03_SON_H
#define LABO03_SON_H

#include "Child.h"

class Son : public Child {
public:
    /**
     * Constructor of Son
     * @param name - the name of the Son
     * @param mommy - a pointer to his Mother
     * @param daddy - a pointer to his Father
     */
    Son(std::string name, const Mother* mommy, const Father* daddy);

    /**
     * Overriding method checking if the Son is with his father
     * and/or his mother
     * @param fatherPresent - boolean if father is present
     * @param motherPresent - boolean if mother is present
     * @return true if mother and father are present, otherwise false
     * if only mother is present (corresponds to constraint #4)
     */
    bool isAccompaniedCorrectly(bool fatherPresent,
                                bool motherPresent) const override;
};

#endif //LABO03_SON_H