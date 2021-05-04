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
    std::getline(std::cin, command);
    this->handleCommand(command);
    ++turn;
}

bool Controller::notEnd() const {
    return !isEnd;
}

void Controller::initPersons() {
    Father* pere        = new Father();
    Mother* mere        = new Mother();

    Daughter* jeanne    = mere->makeDaughter("jeanne", pere);
    Daughter* julie     = mere->makeDaughter("julie", pere);

    Son* paul           = mere->makeSon("paul", pere);
    Son* pierre         = mere->makeSon("pierre", pere);

    Police* policier    = new Police();
    Thief* voleur       = new Thief();

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
    using Menu = Controller::MenuOptions;
    std::vector<std::string> tokens = Controller::split(Controller::trim(command), ' ');
    Menu option;

    if(tokens.empty()){
        option = Menu::Error;
    }else{
        option = Controller::resolveMenu(tokens[0]);
        if((option == Menu::Embark || option == Menu::Disembark) && tokens.size() != 2) {
            option = Menu::Error;
        }
    }

    switch(option){
        case Menu::Display :
            this->display();
            break;
        case Menu::Menu :
            this->showMenu();
            break;
        case Menu::Exit :
            this->destroyPeople();
            this->isEnd = true;
            break;
        case Menu::Reinitialize :
            this->reinitialize();
            this->display();
            break;
        case Menu::Sail :
            this->sail();
            break;
        case Menu::Embark :
            if(this->embark(tokens[1])){
                this->display();
            }
            break;
        case Menu::Disembark :
            if(this->disembark(tokens[1])){
                this->display();
            }
            break;
        case Menu::Error :
            std::cout << "Parametre invalide" << std::endl;
            break;
        case Menu::Unknown :
        default:
            std::cout << "Commande inconnue" << std::endl;
            break;
    }
}

bool Controller::embark(const std::string& who) {
    if(!this->boat->isFull()){
        Container::Iterator it = this->boat->getAnchoredBank()->findByName(who);
        if(it != this->boat->getAnchoredBank()->end()){
            if(this->controlAccompanimentRules(this->boat->getAnchoredBank(), this->boat, *it)){
                this->boat->getAnchoredBank()->remove(*it);
                this->boat->add(*it);
                return true;
            }
        } else {
            std::cout << who << " pas trouve!" << std::endl;
        }
    } else {
        std::cout << "### Le bateau est plein." << std::endl;
    }
    return false;
}

bool Controller::disembark(const std::string& who) {
    Container::Iterator it = this->boat->findByName(who);
    if(it != this->boat->end()){
        if(this->controlAccompanimentRules(this->boat, this->boat->getAnchoredBank(), *it)) {
            this->boat->remove(*it);
            this->boat->getAnchoredBank()->add(*it);
            return true;
        }
    }else{
        std::cout << who << " not found!" << std::endl;
    }
    return false;
}

void Controller::sail() {
    if(this->boat->hasCaptain()) {
        if(this->boat->getAnchoredBank() == this->leftBank) {
            this->boat->anchorTo(this->rightBank);
        }else{
            this->boat->anchorTo(this->leftBank);
        }
    }else{
        std::cout << "### aucun capitaine a bord" << std::endl;
    }
}

void Controller::reinitialize() {
    turn = 0;
    this->destroyPeople();
    this->rightBank->clear();
    this->leftBank->clear();
    this->boat->clear();
    this->initPersons();
}

void Controller::destroyPeople() {
    for(const Person* person : *this->leftBank){
        delete person;
    }
    for(const Person* person : *this->rightBank){
        delete person;
    }
    for(const Person* person : *this->boat){
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
    return str.erase(
            0, str.find_first_not_of(chars)).erase(str.find_last_not_of(chars) + 1);
}

Controller::MenuOptions Controller::resolveMenu(const std::string& option) {
    using Menu = Controller::MenuOptions;
    if(option == "p") return Menu::Display;
    if(option == "e") return Menu::Embark;
    if(option == "d") return Menu::Disembark;
    if(option == "m") return Menu::Sail;
    if(option == "r") return Menu::Reinitialize;
    if(option == "q") return Menu::Exit;
    if(option == "h") return Menu::Menu;
    return Controller::Unknown;
}

bool Controller::controlAccompanimentRules(Container* from, Container* to, const Person* who) {

    Container futureFrom(*from);
    Container futureTo(*to);

    futureFrom.remove(who);
    futureTo.add(who);

    if(!(Controller::controlAccompanimentRulesOnBank(&futureFrom) && Controller::controlAccompanimentRulesOnBank(&futureTo))){
        return false;
    }
    return true;
}

bool Controller::controlAccompanimentRulesOnBank(Container* where) {
    bool hasFamilyMember = false;
    bool hasPoliceman = false;
    bool hasThief = false;

    for(const Person* person : *where){
        if(person->getType() == Person::Family) {
            hasFamilyMember = true;
        }
        if(person->getType() == Person::Police) {
            hasPoliceman = true;
        }
        if(person->getType() == Person::Thief){
            hasThief = true;
        }
        if(person->isChild()){
            if(!Controller::checkChildAccompanimentRules(where, person)){
                return false;
            }
        }
    }

    if(hasFamilyMember && !Controller::checkFamilyAccompanimentRules(hasPoliceman, hasThief)) {
        std::cout << "### voleur avec un membre de famille sans presence de policier" << std::endl;
        return false;
    }
    return true;
}

bool Controller::checkChildAccompanimentRules(Container* where, const Person* who) {
    Child* child = (Child*) who;
    const Father* myDad = child->myDad();
    const Mother* myMom = child->myMom();

    if(!child->isAccompaniedCorrectly(where->contains(myDad), where->contains(myMom))) {
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