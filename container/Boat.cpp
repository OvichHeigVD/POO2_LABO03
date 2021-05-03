//
// Created by stefa on 21.04.2021.
//

#include <stdexcept>
#include <algorithm>
#include "Boat.h"

Boat::Boat(Bank* defaultAnchor, const size_t maxCapacity) : Container("Bateau"), anchoredAt(defaultAnchor), maxCapacity(maxCapacity) {}

void Boat::add(const Person *person) {
    if(this->list.size() <= maxCapacity){
        Container::add(person);
    }else{
        throw std::length_error("Boat is full!");
    }
}

std::string Boat::getContent() const {
    return " <" + Container::getContent() + " >";
}

void Boat::anchorTo(Bank *bank) {
    this->anchoredAt = bank;
}

Bank *Boat::getAnchoredBank() const {
    return this->anchoredAt;
}

bool Boat::isFull() const {
    return this->list.size() == maxCapacity;
}

bool Boat::hasCaptain() const {
    return std::any_of( this->list.begin(),  this->list.end(), [](const Person* person){
        return person->canDrive();
    });
}

