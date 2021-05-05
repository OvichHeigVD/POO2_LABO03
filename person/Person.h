/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Person.h
 * @date 05.05.2021
 *
 * @brief Abstract class of Person
 */

#ifndef LABO03_PERSON_H
#define LABO03_PERSON_H

#include <string>
#include <iostream>

class Person {
public:

    /**
     * Abstract Method checking if a Person can drive the boat
     * @return true by default if able, false otherwise
     */
    virtual bool canDrive() const;

    /**
     * Abstract Method cheking if a Person is a child
     * @return true if child, otherwise false (by default)
     */
    virtual bool isChild() const;

    /**
     * Abstract Method cheking if a Person is a family member
     * @return false if not family, otherwise true (by default)
     */
    virtual bool isFamily() const;

    /**
     * Abstract Method cheking if a Person is a Thief
     * @return true if thief, otherwise false (by default)
     */
    virtual bool isThief() const;

    /**
     * Abstract Method cheking if a Person is a Police
     * @return true if police, otherwise false (by default)
     */
    virtual bool isPolice() const;

    /**
     * Getter of name
     * @return the name of a Person
     */
    std::string getName() const;

protected:
    /**
     * Common constructor for all Person type
     * @param name - the name of the Person
     */
    Person(std::string name);
private:
    const std::string name; // name of a Person
};

#endif //LABO03_PERSON_H