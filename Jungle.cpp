#include "Jungle.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

Jungle::Jungle(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Jungle";
}

void Jungle::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;

    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }


}

void Jungle::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Camp" << endl;
    cout << "2. Don't travel" << endl;
    validateInt(&location, 1, 2);
    switch (location) {
        case 1:
            this->character->currentLocation = this->left;
            this->character->currentLocation->printLocation();
            break;
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}