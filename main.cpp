#include "container/Container.h"
#include "Controller.h"

int main() {
    Controller ctrl;
    ctrl.showMenu();
    ctrl.display();
    while(ctrl.notEnd()){
        ctrl.nextTurn();
    }
    return EXIT_SUCCESS;
}
