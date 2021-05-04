/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Bank.h
 * @date 05.05.2021
 *
 * @brief Class representing one of the Bank of the river,
 * a sub-class of Container
 */

#ifndef LABO03_BANK_H
#define LABO03_BANK_H

#include "Container.h"

class Bank : public Container {
public:
    /**
     * Constructor of Bank
     * @param name - the name of the bank (left or right)
     */
    explicit Bank(std::string name);
};

#endif //LABO03_BANK_H