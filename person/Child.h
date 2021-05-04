/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Child.h
 * @date 05.05.2021
 *
 * @brief Abstract class of a Child, a sub-class of Person
 */

#ifndef LABO03_CHILD_H
#define LABO03_CHILD_H

#include "Person.h"

class Mother;
class Father;

class Child : public Person {
public:
    /**
     * Enum defining the gender of a Child (can either be a boy or a girl)
     */
    enum Gender { Boy, Girl };

    /**
     * Abstract method checking constraint of children with parents
     * @param fatherPresent - boolean if father is present
     * @param motherPresent - boolean if mother is present
     * @return true if constraint is correct, false otherwise
     */
    virtual bool isAccompaniedCorrectly(bool fatherPresent,
                                        bool motherPresent) const = 0;

    /**
     * Overriding canDrive() method
     * @return false, a child cannot drive the boat
     */
    bool canDrive() const override;

    /**
     * Overriding isChild() method checking if it is a child
     * @return true, a child is indeed a child
     */
    bool isChild() const override;

    /**
     * Getter of Mother, a mother of Child
     * @return a pointer to the Mother
     */
    const Mother* myMom() const;

    /**
     * Getter of Father, a father of Child
     * @return a pointer to the Father
     */
    const Father* myDad() const;

    /**
     * Getter of gender
     * @return the gender of a child
     */
    Gender getGender() const;

protected:
    /**
     * Constructor of Child
     * @param name - the name of a child
     * @param mommy - the pointer to his/her mother
     * @param daddy - the pointer to his/her father
     * @param gender - the gender of the child
     */
    Child(std::string name, const Mother* mommy,
          const Father* daddy, Gender gender);

private:
    const Mother* mommy; // mother of the child
    const Father* daddy; // father of the child
    const Gender gender; // gender of the child
};

#endif //LABO03_CHILD_H