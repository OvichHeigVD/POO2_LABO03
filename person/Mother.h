/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Mother.h
 * @date 05.05.2021
 *
 * @brief Class representing the mother of the family, a sub-class of Parent
 */

#ifndef LABO03_MOTHER_H
#define LABO03_MOTHER_H

#include "Parent.h"
#include "Daughter.h"
#include "Son.h"

class Mother : public Parent {
public:
    /**
     * Default constructor of Mother
     */
    Mother();

    /**
     * Method creating a Daughter and passing a reference to her father
     * and her mother
     * @param name - the name of the Daughter
     * @param daddy - a pointer to the father
     * @return a pointer to the Daughter
     */
    Daughter* makeDaughter(std::string name, const Father* daddy);

    /**
     * Method creating a Son and passing a reference to her mother
     * @param name - the name of the Son
     * @param daddy - a pointer to the father
     * @return a pointer to the Son
     */
    Son* makeSon(std::string name, const Father* daddy);
};

#endif //LABO03_MOTHER_H