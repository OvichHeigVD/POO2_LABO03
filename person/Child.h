//
// Created by stefa on 28.04.2021.
//

#ifndef LABO03_CHILD_H
#define LABO03_CHILD_H
#include "Person.h"

class Mother;
class Father;

class Child : public Person{
public:
    enum Gender { Male, Female };
    bool canDrive() const override;
    bool isChild() const override;
    Gender getGender() const;
    virtual bool isAccompaniedCorrectly(bool fatherPresent, bool motherPresent) const = 0;
    const Mother* myMom() const;
    const Father* myDad() const;
protected:
    Child(std::string name, const Mother* momy, const Father* dady, Gender gender);
private:
    const Mother* momy;
    const Father* dady;
    const Gender gender;
};


#endif //LABO03_CHILD_H
