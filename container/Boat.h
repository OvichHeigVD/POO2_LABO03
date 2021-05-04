/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Boat.h
 * @date 05.05.2021
 *
 * @brief Class representing the Boat, a sub-class of Container
 */

#ifndef LABO03_BOAT_H
#define LABO03_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container {
public:
    /**
     * Constructor of Boat
     * @param defaultAnchor - the initial position in the River
     *      (left bank by default)
     * @param maxCapacity - the number maximum of people in the boat
     */
    Boat(Bank* defaultAnchor, size_t maxCapacity);

    /**
     * Method moving the boat from one side of the river to the other
     * (Setter of AnchoredAt)
     * @param bank - one of the two banks of the river
     */
    void anchorTo(Bank* bank);

    /**
     * Getter of anchoredAt
     * @return the current bank where the Boat is anchored
     */
    Bank* getAnchoredBank() const;

    /**
     * Method adding a Person to the Boat
     * @param person - a pointer to a Person
     * @throws an exception in case a Person is added to a full Boat
     */
    void add(const Person* person) override;

    /**
     * Method checking is the boat is full
     * @return true if full, false otherwise
     */
    bool isFull() const;

    /**
     * Method checking if anyone on the Boat can drive it
     * @return true if someone can drive, false otherise
     */
    bool hasCaptain() const;

private:

    /**
     * Method getting the content of the Boat (people in it) with a
     * certain format
     * @return a string with every people on the Boat
     */
    std::string getContent() const override;

    Bank* anchoredAt; // current position in the River
    const size_t maxCapacity; // capacity of Boat
};

#endif //LABO03_BOAT_H