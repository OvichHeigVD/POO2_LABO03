/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Controller.cpp
 * @date 05.05.2021
 *
 * @brief Implementing the Controller class
 */

#include <sstream>
#include "Controller.h"
#include "person/Father.h"
#include "person/Mother.h"
#include "person/Police.h"
#include "person/Thief.h"

Controller::Controller() : turn(0), isEnd(false), rightBank(new Bank("Droite")),
                           leftBank(new Bank("Gauche")), boat(new Boat(leftBank, 2)) {
    this->initPersons();
}

Controller::~Controller() {
    //Destroying every objects allocated dynamically
    this->destroyPeople();
    delete this->leftBank;
    delete this->rightBank;
    delete this->boat;
}

void Controller::showMenu() {
    std::cout   << "p      : afficher" << std::endl
                << "e <nom>: embarquer <nom>" << std::endl
                << "d <nom>: debarquer <nom>" << std::endl
                << "m      : deplacer bateau" << std::endl
                << "r      : reinitialiser" << std::endl
                << "q      : quitter" << std::endl
                << "h      : menu" << std::endl;
}

void Controller::display() const {
    // Displaying the left bank
    std::cout << Controller::separator() << std::endl;
    std::cout << *this->leftBank << std::endl;
    std::cout << Controller::separator() << std::endl;

    // Displaying the left side of the river (with or without boat)
    displayAnchoredBank(this->leftBank);
    std::cout << Controller::riverSeparator() << std::endl;

    // Displaying the right side of the river (with or without boat)
    displayAnchoredBank(this->rightBank);

    // Displaying the right bank
    std::cout << Controller::separator() << std::endl;
    std::cout << *this->rightBank << std::endl;
    std::cout << Controller::separator() << std::endl;
}

void Controller::nextTurn() {
    std::cout << turn << ">";
    std::string command;
    // get user's input
    std::getline(std::cin, command);
    this->handleCommand(command);
    ++turn;
}

bool Controller::notEnd() const {
    return !isEnd;
}

void Controller::initPersons() {
    // Creating every Person
    Father* pere        = new Father();
    Mother* mere        = new Mother();

    Daughter* jeanne    = mere->makeDaughter("jeanne", pere);
    Daughter* julie     = mere->makeDaughter("julie", pere);

    Son* paul           = mere->makeSon("paul", pere);
    Son* pierre         = mere->makeSon("pierre", pere);

    Police* policier    = new Police();
    Thief* voleur       = new Thief();

    // Adding them all in the leftBank
    leftBank->add(pere);
    leftBank->add(mere);
    leftBank->add(paul);
    leftBank->add(pierre);
    leftBank->add(julie);
    leftBank->add(jeanne);
    leftBank->add(policier);
    leftBank->add(voleur);
}

void Controller::handleCommand(std::string command) {
    // Using an alias
    using Menu = Controller::MenuOptions;

    // Split
    std::vector<std::string> tokens = Controller::split(
            Controller::trim(command), ' ');
    Menu option;

    // Check if command provided is empty
    if(tokens.empty()) {
        option = Menu::Error; // returns an error
    } else { // check if embark/disembark have 1 parameter
        option = Controller::resolveMenu(tokens[0]);
        if((option == Menu::Embark || option == Menu::Disembark)
           && tokens.size() != 2) {
            option = Menu::Error; // returns an error if doesn't have 1 parameter
        }
    }

    switch(option){
        // Displaying the river ('p')
        case Menu::Display :
            this->display();
            break;
        // Displaying the menu with commands ('h')
        case Menu::Menu :
            this->showMenu();
            break;
        // Exiting the program ('q')
        case Menu::Exit :
            this->isEnd = true;
            break;
        // Resetting the program ('r')
        case Menu::Reinitialize :
            this->reinitialize();
            this->display();
            break;
        // Moving the boat ('m')
        case Menu::Sail :
            this->sail();
            break;
        // Adding Person to the boat ('e <name>')
        case Menu::Embark :
            if(this->embark(tokens[1])){
                this->display();
            }
            break;
        // Removing Person to the boat ('d <name>')
        case Menu::Disembark :
            if(this->disembark(tokens[1])){
                this->display();
            }
            break;
        // In case, invalid input
        case Menu::Error :
            std::cout << "Parametre invalide" << std::endl;
            break;
        // In case, wrong command
        case Menu::Unknown :
        default:
            std::cout << "Commande inconnue" << std::endl;
            break;
    }
}

bool Controller::embark(const std::string& who) {
    // Check first if the Boat is full
    if(!this->boat->isFull()) {
        Container::Iterator it = this->boat->getAnchoredBank()->findByName(who);
        if(it != this->boat->getAnchoredBank()->end()) { // found the Person (who)
            // Check if the Person can embark based on constraints
            if(Controller::controlAccompanimentRules(this->boat->getAnchoredBank(),
                                               this->boat, *it)) {
                // Removing the Person from one Container, then adding to the other
                this->boat->getAnchoredBank()->remove(*it);
                this->boat->add(*it);
                return true;
            }
        } else {
            // Person not found in the Boat
            std::cout << who << " pas trouve!" << std::endl;
        }
    } else { // Cannot add a Person to the Boat
        std::cout << "### Le bateau est plein." << std::endl;
    }
    return false;
}

bool Controller::disembark(const std::string& who) {
    Container::Iterator it = this->boat->findByName(who);
    if(it != this->boat->end()) {
        if(Controller::controlAccompanimentRules(
                this->boat, this->boat->getAnchoredBank(), *it)) {
            this->boat->remove(*it);
            this->boat->getAnchoredBank()->add(*it);
            return true;
        }
    } else {
        std::cout << who << " not found!" << std::endl;
    }
    return false;
}

void Controller::sail() {
    if(this->boat->hasCaptain()) { // Check if someone can drive the Boat
        if(this->boat->getAnchoredBank() == this->leftBank) {
            this->boat->anchorTo(this->rightBank);
        }else{
            this->boat->anchorTo(this->leftBank);
        }
    } else {
        std::cout << "### aucun capitaine a bord" << std::endl;
    }
}

void Controller::reinitialize() {
    turn = 0;
    this->destroyPeople();
    this->rightBank->clear();
    this->leftBank->clear();
    this->boat->clear();
    this->boat->anchorTo(leftBank);
    this->initPersons();
}

void Controller::destroyPeople() {
    // Delete all Person who can be in any of the three containers
    for(const Person* person : *this->leftBank) {
        delete person;
    }
    for(const Person* person : *this->rightBank) {
        delete person;
    }
    for(const Person* person : *this->boat) {
        delete person;
    }
}

std::string Controller::separator() {
    return "----------------------------------------------------------";
}

std::string Controller::riverSeparator() {
    return "==========================================================";
}

void Controller::displayAnchoredBank(Bank* bank) const {
    // Display the boat at the right anchor, display nothing otherwise
    if(boat->getAnchoredBank() == bank){
        std::cout << *boat << std::endl;
    }else{
        std::cout << std::endl;
    }
}

std::vector<std::string> Controller::split(const std::string& str, char delimiter){
    std::vector<std::string> tokens;
    std::stringstream sstr(str);
    std::string item;

    while (getline (sstr, item, delimiter)) {
        tokens.push_back (item);
    }

    return tokens;
}

std::string& Controller::trim(std::string& str) {
    const char* chars = " \t\v\r\n";
    return str.erase(0, str.find_first_not_of(chars)).erase(
            str.find_last_not_of(chars) + 1);
}

Controller::MenuOptions Controller::resolveMenu(const std::string& option) {
    //using an alias
    using Menu = Controller::MenuOptions;

    if(option == "p") {
        return Menu::Display;
    }
    if(option == "e") {
        return Menu::Embark;
    }
    if(option == "d") {
        return Menu::Disembark;
    }
    if(option == "m") {
        return Menu::Sail;
    }
    if(option == "r") {
        return Menu::Reinitialize;
    }
    if(option == "q") {
        return Menu::Exit;
    }
    if(option == "h") {
        return Menu::Menu;
    }
    return Controller::Unknown;
}

bool Controller::controlAccompanimentRules(Container* from, Container* to,
                                           const Person* who) {
    // Temporary copy containers
    Container futureFrom(*from);
    Container futureTo(*to);

    futureFrom.remove(who);
    futureTo.add(who);

    // Check if rules are respected after hypothetically move
    if(!(Controller::controlAccompanimentRulesOnBank(&futureFrom)
         && Controller::controlAccompanimentRulesOnBank(&futureTo))){
        return false;
    }
    return true;
}

bool Controller::controlAccompanimentRulesOnBank(Container* where) {
    bool hasFamilyMember = false;
    bool hasPoliceman = false;
    bool hasThief = false;

    // Check if in the Container, there is any 'type' of Person
    for(const Person* person : *where){
        if(person->isFamily()) {
            hasFamilyMember = true;
        }
        if(person->isPolice()) {
            hasPoliceman = true;
        }
        if(person->isThief()) {
            hasThief = true;
        }
        if(person->isChild()) { // check if Child is accompanied correctly
            if(!Controller::checkChildAccompanimentRules(where, person)){
                return false;
            }
        }
    }

    // Check the constrain #3, a Thief has to be with the Policeman
    // if any member of the familly
    if(hasFamilyMember && !Controller::checkFamilyAccompanimentRules(
            hasPoliceman, hasThief)) {
        std::cout << "### voleur avec un membre de famille "
                     "sans presence de policier" << std::endl;
        return false;
    }
    return true;
}

bool Controller::checkChildAccompanimentRules(Container* where, const Person* who) {
    Child* child = (Child*) who;
    const Father* myDad = child->myDad(); // Get parents
    const Mother* myMom = child->myMom();

    if(!child->isAccompaniedCorrectly(where->contains(myDad), where->contains(myMom))) {
        // If boy or girl, displaying the correct prompt
        if(child->getGender() == Child::Boy) {
            std::cout << "### garcon avec sa mere sans son pere" << std::endl;
        } else {
            std::cout << "### fille avec son pere sans sa mere" << std::endl;
        }
        return false;
    }
    return true;
}

bool Controller::checkFamilyAccompanimentRules(bool hasPoliceman, bool hasThief) {
    return ( hasThief && hasPoliceman ) || !hasThief;
}