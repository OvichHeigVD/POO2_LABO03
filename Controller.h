//
// Created by stefa on 21.04.2021.
//

#ifndef LABO03_CONTROLLER_H
#define LABO03_CONTROLLER_H

#include <iostream>
#include <vector>
#include "container/Boat.h"

class Controller {

public:
    Controller();
    ~Controller();
    static void showMenu() ;
    void display() const;
    void nextTurn();
    bool notEnd() const;

private:
    int turn;
    bool isEnd;
    Bank* rightBank;
    Bank* leftBank;
    Boat* boat;

    enum MenuOptions { Display, Embark, Disembark, Sail, Reinitialize, Exit, Menu, Unknown, Error };

    void initPersons();
    static std::string separator();
    static std::string riverSeparator();
    void handleCommand(std::string command);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::string& trim(std::string& line);
    static MenuOptions resolveMenu(const std::string& option);

    bool embark(const std::string& who);
    bool disembark(const std::string& who);

    void sail();

    void reinitialize();
    void destroyPeople();

    static bool controlAccompanimentRules(Container* from, Container* to, const Person *who);
    static bool controlAccompanimentRulesOnBank(Container* where);
    static bool checkChildAccompanimentRules(Container *where, const Person *who);
    static bool checkFamilyAccompanimentRules(bool hasPoliceman, bool hasThief);
};


#endif //LABO03_CONTROLLER_H
