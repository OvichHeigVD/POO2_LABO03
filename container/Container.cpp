//
// Created by stefa on 21.04.2021.
//

#include <iostream>
#include <algorithm>
#include "Container.h"

Container::Container(std::string name) : name(std::move(name)){}

void Container::add(const Person* person) {
    this->list.push_back(person);
}


void Container::remove(const Person *person) {
    this->list.remove(person);
}

Container::Iterator Container::begin() {
    return list.begin();
}

Container::Iterator Container::end() {
    return list.end();
}


std::ostream &operator<<(std::ostream &os, const Container &rhs) {
    os << rhs.name + ":";
    os << rhs.getContent();
    return os;
}

std::string Container::getContent() const {
    std::string content;
    for(const Person* person : this->list){
        content += " " + person->getName();
    }
    return content;
}

Container::Iterator Container::findByName(const std::string& nameToSearch) {
    return std::find_if(this->begin(), this->end(), [&nameToSearch](const Person* obj) {return obj->getName() == nameToSearch;});
}

void Container::clear() {
    this->list.clear();
}

bool Container::contains(const Person *person) const {
    return (std::find(this->list.begin(), this->list.end(), person) != this->list.end());;
}





