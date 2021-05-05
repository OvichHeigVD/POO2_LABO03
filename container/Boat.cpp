/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Boat.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Boat class
 */

#include <stdexcept>
#include <algorithm>
#include "Boat.h"

Boat::Boat(Bank* defaultAnchor, const size_t maxCapacity) :
    Container("Bateau"), anchoredAt(defaultAnchor), maxCapacity(maxCapacity) { }

void Boat::anchorTo(Bank *bank) {
    this->anchoredAt = bank;
}

Bank *Boat::getAnchoredBank() const {
    return this->anchoredAt;
}

void Boat::add(const Person *person) {
    if(this->list.size() <= maxCapacity){
        Container::add(person);
    } else {
        throw std::length_error("Boat is full!");
    }
}

bool Boat::isFull() const {
    return this->list.size() == maxCapacity;
}

bool Boat::hasCaptain() const {
    // checks if anyone on the boat can drive it
    return std::any_of(
            this->list.begin(),  this->list.end(), [](const Person* person) {
        return person->canDrive();
    });
}

std::string Boat::getContent() const {
    return " <" + Container::getContent() + " >";
}