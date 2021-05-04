//
// Created by stefa on 21.04.2021.
//

#ifndef LABO03_BOAT_H
#define LABO03_BOAT_H

#include "Container.h"
#include "Bank.h"

class Boat : public Container{
public:
    Boat(Bank* defaultAnchor, size_t maxCapacity);
    void anchorTo(Bank* bank);
    Bank* getAnchoredBank() const;
    void add(const Person* person) override;
    bool isFull() const;
    bool hasCaptain() const;
private:
    Bank* anchoredAt;
private:
    std::string getContent() const override;
    const size_t maxCapacity;
};


#endif //LABO03_BOAT_H
