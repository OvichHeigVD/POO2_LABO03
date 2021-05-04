/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Daughter.h
 * @date 05.05.2021
 *
 * @brief Class representing the daughter of the family, a sub-class of Child
 */

#ifndef LABO03_DAUGHTER_H
#define LABO03_DAUGHTER_H

#include "Child.h"

class Daughter : public Child {

public:
    /**
     * Constructor of Daughter
     * @param name - the name of the Daughter
     * @param mommy - a pointer to her Mother
     * @param daddy - a pointer to her Father
     */
    Daughter(std::string name, const Mother* mommy, const Father* daddy);

    /**
     * Overriding method checking if the Daughter is with her father
     * and/or her mother
     * @param fatherPresent - boolean if father is present
     * @param motherPresent - boolean if mother is present
     * @return true if mother and father are present, otherwise false
     * if only father is present (corresponds to constraint #5)
     */
    bool isAccompaniedCorrectly(bool fatherPresent,
                                bool motherPresent) const override;
};

#endif //LABO03_DAUGHTER_H