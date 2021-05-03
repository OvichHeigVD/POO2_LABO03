//
// Created by stefa on 21.04.2021.
//

#ifndef LABO03_PERSON_H
#define LABO03_PERSON_H
#include <string>
#include <iostream>

class Person {
public:
    enum PersonType { Family, Police, Thief };
    virtual bool canDrive() const;
    PersonType getType() const;
    virtual bool isChild() const;
    std::string getName() const;
protected:
    Person(std::string name, PersonType type);
private:
    const std::string name;
    PersonType type;
};


#endif //LABO03_PERSON_H
