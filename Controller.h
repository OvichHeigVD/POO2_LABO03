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
     * Method displaying the river, the bank, the boat and their contents
     */
    void display() const;

    /**
     * Method getting user's input, handle that input and incrementing the turn
     */
    void nextTurn();

    /**
     * Method checking if it is the end of the program
     * @return true if not ended, false otherwise
     */
    bool notEnd() const;

private:
    size_t turn; // number of turns
    bool isEnd; // boolean checking the end of the program
    Bank* rightBank; // the right bank of the river
    Bank* leftBank; // the left bank of the river
    Boat* boat; // the boat

    /**
     * Enum with every options the user can make during the program
     */
    enum MenuOptions { Display, Embark, Disembark, Sail, Reinitialize, Exit,
            Menu, Unknown, Error };

    /**
     * Method creating every Person of the program and adding them to
     * the left bank of the river (leftBank)
     */
    void initPersons();

    /**
     * Method applying a method based on user's input
     * @param command - a command (e, d, m, etc...)
     */
    void handleCommand(std::string command);

    /**
     * Method adding a Person to the boat
     * @param who - a name provided by the user (with the command 'e')
     * @return true if the Person embarked, false otherwise
     */
    bool embark(const std::string& who);

    /**
     * Method removing a Person from the boat
     * @param who - a name provided by the user (with the command 'd')
     * @return true if the Person disembarked, false otherwise
     */
    bool disembark(const std::string& who);

    /**
     * Method moving the boat from one bank to the other
     */
    void sail();

    /**
     * Method resetting the program (with the command 'r')
     */
    void reinitialize();

    /**
     * Method destroying the object Person allocated dynamically
     */
    void destroyPeople();

    /**
     * Method displaying seperators for both Bank
     * @return a formatted string with '-'
     */
    static std::string separator();

    /**
     * Method displaying the middle of the river (seperating the left
     * and right bank)
     * @return a formatted string with '='
     */
    static std::string riverSeparator();

    /**
     * Method displaying the boat (on one or the other side)
     * @param bank - a Boat
     */
    void displayAnchoredBank(Bank* bank) const;

    /**
     * Method splitting a string into tokens (used for commands 'e' and 'd', both
     * requesting a parameter)
     * @param str - a string
     * @param delimiter - the character ' ' (space) used for splitting
     * @return a vector of strings
     */
    static std::vector<std::string> split(const std::string& str, char delimiter);

    /**
     * Method triming a string
     * @param line - a line
     * @return a formatted string
     */
    static std::string& trim(std::string& line);

    /**
     * Method getting the appropriate enum based on user's input
     * @param option - a command from user's input
     * @return an option in enum MenuOptions
     */
    static MenuOptions resolveMenu(const std::string& option);

    /**
     * Method checking if a Person can go to the 'to' Container
     * @param from - a Container from a point
     * @param to - a Container to a point
     * @param who - a Person
     * @return true if rule is correct, false otherwise
     */
    static bool controlAccompanimentRules(Container* from, Container* to,
                                          const Person *who);

    /**
     * Check if rules are correct on a specific container
     * @param where - a Container
     * @return true if rule is correct, false otherwise
     */
    static bool controlAccompanimentRulesOnBank(Container* where);

    /**
     * Method checking if current child is with one parent but not the other
     * @param where - the next container
     * @param who - the Person
     * @return true if rule is correct, false otherwise
     */
    static bool checkChildAccompanimentRules(Container *where, const Person *who);

    /**
     * Method checking if the Thief is with the Family without the policeman
     * (corresponds to the constraint #3)
     * @param hasPoliceman - if the policeman is present
     * @param hasThief - if the thief is present
     * @return true if both are present, or no Thief; false otherwise
     */
    static bool checkFamilyAccompanimentRules(bool hasPoliceman, bool hasThief);
};

#endif //LABO03_CONTROLLER_H