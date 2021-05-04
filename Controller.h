/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Controller.h
 * @date 05.05.2021
 *
 * @brief Class controlling the River program with defined rules and displaying
 *        the River with people, boat and banks
 */

#ifndef LABO03_CONTROLLER_H
#define LABO03_CONTROLLER_H

#include <iostream>
#include <vector>
#include "container/Boat.h"

class Controller {

public:
    /**
     * Default constructor of Controller
     */
    Controller();

    /**
     * Destructor of Controller
     */
    ~Controller();

    /**
     * Method showing the Menu with all commands available
     */
    static void showMenu();

    /**
     *
     */
    void display() const;

    /**
     *
     */
    void nextTurn();

    /**
     *
     * @return
     */
    bool notEnd() const;

private:
    int turn;
    bool isEnd;
    Bank* rightBank;
    Bank* leftBank;
    Boat* boat;

    /**
     *
     */
    enum MenuOptions { Display, Embark, Disembark, Sail, Reinitialize, Exit, Menu, Unknown, Error };

    /**
     *
     */
    void initPersons();

    /**
     *
     * @param command
     */
    void handleCommand(std::string command);

    /**
     *
     * @param who
     * @return
     */
    bool embark(const std::string& who);

    /**
     *
     * @param who
     * @return
     */
    bool disembark(const std::string& who);

    /**
     *
     */
    void sail();

    /**
     *
     */
    void reinitialize();

    /**
     *
     */
    void destroyPeople();

    /**
     *
     * @return
     */
    static std::string separator();

    /**
     *
     * @return
     */
    static std::string riverSeparator();

    /**
     *
     * @param bank
     */
    void displayAnchoredBank(Bank* bank) const;

    /**
     *
     * @param str
     * @param delimiter
     * @return
     */
    static std::vector<std::string> split(const std::string& str, char delimiter);

    /**
     *
     * @param line
     * @return
     */
    static std::string& trim(std::string& line);

    /**
     *
     * @param option
     * @return
     */
    static MenuOptions resolveMenu(const std::string& option);

    /**
     *
     * @param from
     * @param to
     * @param who
     * @return
     */
    static bool controlAccompanimentRules(Container* from, Container* to, const Person *who);

    /**
     *
     * @param where
     * @return
     */
    static bool controlAccompanimentRulesOnBank(Container* where);

    /**
     *
     * @param where
     * @param who
     * @return
     */
    static bool checkChildAccompanimentRules(Container *where, const Person *who);

    /**
     *
     * @param hasPoliceman
     * @param hasThief
     * @return
     */
    static bool checkFamilyAccompanimentRules(bool hasPoliceman, bool hasThief);
};

#endif //LABO03_CONTROLLER_H