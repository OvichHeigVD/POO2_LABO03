/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Container.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Container class
 */

#include <iostream>
#include <algorithm>
#include "Container.h"

Container::Container(std::string name) : name(std::move(name)) { }

void Container::add(const Person* person) {
    this->list.push_back(person);
}

void Container::remove(const Person *person) {
    this->list.remove(person);
}

bool Container::contains(const Person *person) const {
    return (std::find(
            this->list.begin(), this->list.end(), person) != this->list.end());
}

void Container::clear() {
    this->list.clear();
}

Container::Iterator Container::begin() {
    return list.begin();
}

Container::Iterator Container::end() {
    return list.end();
}

Container::Iterator Container::findByName(const std::string& nameToSearch) {
    // iterate in the List until the Person is found by its name
    return std::find_if(
            this->begin(), this->end(), [&nameToSearch](const Person* obj) {
                return obj->getName() == nameToSearch;
            });
}

std::string Container::getContent() const {
    std::string content;
    // displaying each Person of the List
    for(const Person* person : this->list){
        content += " " + person->getName();
    }
    return content;
}

std::ostream &operator<<(std::ostream &os, const Container &rhs) {
    // displaying the name then each Person of the List
    os << rhs.name + ":";
    os << rhs.getContent();
    return os;
}