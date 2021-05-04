/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @file Controller.h
 * @date 05.05.2021
 *
 * @brief Launches the program, initialises it and runs the controller
 */

#include "container/Container.h"
#include "Controller.h"
#include <sstream>
using namespace std;

void commonControllerRunTest();
void solutionCommands();
void sonWithMotherButWithoutFatherTest();
void daughterWithFatherButWithoutMotherTest();
void thiefMustNotBeWithFamilyWithoutPoliceman();
void thiefMustNotBeWithFamilyWithoutPoliceman();
void onlyTwoPeopleOnTheBoat();

int main() {
    Controller ctrl;
    ctrl.showMenu();
    ctrl.display();
    while(ctrl.notEnd()){
        ctrl.nextTurn();
    }

//    solutionCommands();
//    sonWithMotherButWithoutFatherTest();
//    daughterWithFatherButWithoutMotherTest();
//    thiefMustNotBeWithFamilyWithoutPoliceman();

    return EXIT_SUCCESS;
}


void commonControllerRunTest() {
    Controller ctrl;
    ctrl.showMenu();
    ctrl.display();
    while(ctrl.notEnd()){
        ctrl.nextTurn();
    }
}

void solutionCommands() {
    cout << "---- Solution scenario : ----" << endl;

    istringstream iss("e voleur\ne policier\nm\nd voleur\nm\ne jeanne\nm\n"
                      "d policier\nd jeanne\ne voleur\ne policier\nm\nd policier\n"
                      "d voleur\ne julie\ne mere\nm\nd julie\nm\ne pere\nm\n"
                      "d mere\nm\nd pere\ne voleur\ne policier\nm\nd policier\n"
                      "d voleur\ne mere\nm\ne pere\nm\nd mere\nm\ne paul\nm\n"
                      "d pere\nd paul\ne voleur\ne policier\nm\nd policier\n"
                      "d voleur\ne pierre\ne policier\nm\nd pierre\nm\ne voleur\n"
                      "m\nd policier\nd voleur\nq");
    cin.rdbuf(iss.rdbuf());

    commonControllerRunTest();
}

void sonWithMotherButWithoutFatherTest() {
    cout << "---- Son with mother but without father scenario : ----" << endl;

    istringstream iss("e pere\n e pierre\n e pere\nq");
    cin.rdbuf(iss.rdbuf());

    commonControllerRunTest();
}

void daughterWithFatherButWithoutMotherTest() {
    cout << "---- Daughter with father but without mother scenario : ----" << endl;

    istringstream iss("e mere\ne jeanne\ne mere\nq");
    cin.rdbuf(iss.rdbuf());

    commonControllerRunTest();
}

void thiefMustNotBeWithFamilyWithoutPoliceman() {
    cout << "---- Thief must NOT be with the family without policeman around : ----" << endl;

    istringstream iss("e policier\ne voleur\ne policier\nm\nd voleur\nm\ne jeanne\nm\nd jeanne\nq");
    cin.rdbuf(iss.rdbuf());

    commonControllerRunTest();
}

void onlyTwoPeopleOnTheBoat() {
    cout << endl << "---- Only two people in the boat : ----" << endl;

}
