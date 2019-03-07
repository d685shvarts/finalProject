#include "Ocean.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

Ocean::Ocean(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Ocean";
}

void Ocean::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "2. Quit game" << endl;
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        
    }
    else {
        this->character->alive = false;
    }

}
