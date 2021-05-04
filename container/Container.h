//
// Created by stefa on 21.04.2021.
//

#ifndef LABO03_CONTAINER_H
#define LABO03_CONTAINER_H

#include <string>
#include <list>
#include "../person/Person.h"

class Container {

    using List = std::list<const Person*>;
    friend std::ostream& operator<<(std::ostream& os, const Container& rhs);

public:
    using Iterator = List::iterator;
    explicit Container(std::string name);
    virtual void add(const Person* person);
    void remove(const Person* person);
    bool contains(const Person* person) const;
    void clear();
    Iterator begin();
    Iterator end();

    Iterator findByName(const std::string& name);

private:
    std::string name;

protected:
    virtual std::string getContent() const;

    List list;
};


#endif //LABO03_CONTAINER_H
