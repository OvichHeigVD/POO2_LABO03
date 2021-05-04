/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Container.h
 * @date 05.05.2021
 *
 * @brief Abstract class Container that can either be a Boat or a Bank
 */

#ifndef LABO03_CONTAINER_H
#define LABO03_CONTAINER_H

#include <string>
#include <list>
#include "../person/Person.h"

class Container {
    // Using an alias std::list<const Person*> as List
    using List = std::list<const Person*>;

    /**
     * Overloading the output stream, displaying the content of a List
     * @param os - an ostream
     * @param rhs - a Container (a Bank or a Boat)
     * @return an ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Container& rhs);

public:
    //Using an alias List::iterator as Iterator
    using Iterator = List::iterator;

    /**
     * Constructor of a Container
     * @param name - the name of the Container
     */
    explicit Container(std::string name);

    /**
     * Method adding a Person to the Container
     * @param person - a pointer to the Person
     */
    virtual void add(const Person* person);

    /**
     * Method removing a Persom from the Container
     * @param person - a pointer to the Person
     */
    void remove(const Person* person);

    /**
     * Method checking if a person is in the container
     * @param person - a pointer to the Person
     * @return true if the person is in the Container, false otherwise
     */
    bool contains(const Person* person) const;

    /**
     * Method deleting the content of the List
     */
    void clear();

    /**
     * Method getting an Iterator at the beginning of the List
     * @return an Iterator at the beginning
     */
    Iterator begin();

    /**
     * Method getting an Iterator at the end of the List
     * @return an Iterator at the end
     */
    Iterator end();

    /**
     * Method getting an Iterator at the position of a Person in the Container
     * @param name - the name of the Person (checking by its name)
     * @return an Iterator at current position of person
     */
    Iterator findByName(const std::string& name);

protected:
    /**
     * Method displaying the content (Person) of the Container
     * @return a list as a string of Person in the Container
     */
    virtual std::string getContent() const;

    List list; // std::list<const Person*>
private:
    std::string name; // the name of the Container
};

#endif //LABO03_CONTAINER_H