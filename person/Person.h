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
     * Enum of category of person. Can be a family member, a policeman or a thief
     */
    enum PersonType { Family, Police, Thief };

    /**
     * Method checking if a Person can drive the boat
     * @return true by default if able, false otherwise
     */
    virtual bool canDrive() const;

    /**
     * Method cheking if a Person is a child
     * @return true if child, otherwise false (by default)
     */
    virtual bool isChild() const;

    /**
     * Getter of name
     * @return the name of a Person
     */
    std::string getName() const;

    /**
     * Getter of type
     * @return the type of a Person
     */
    PersonType getType() const;

protected:
    /**
     * Common constructor for all Person type
     * @param name - the name of the Person
     * @param type - the category they belong (Family, Police, Thief)
     */
    Person(std::string name, PersonType type);
private:
    const std::string name; // name of a Person
    PersonType type; // type of a Person
};

#endif //LABO03_PERSON_H