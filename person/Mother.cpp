//
// Created by stefa on 28.04.2021.
//

#include <utility>

#include "Mother.h"
#include "Father.h"

Mother::Mother() : Parent("mere") { }

Daughter* Mother::makeDaughter(std::string name, const Father* papa) {
    return new Daughter(std::move(name), this, papa);
}

Son* Mother::makeSon(std::string name, const Father* papa) {
    return new Son(std::move(name), this, papa);
}


