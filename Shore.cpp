#include "Shore.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

Shore::Shore(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Shore";
}

void Shore::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }


}

void Shore::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Ocean" << endl;
    cout << "2. Shipwreck" << endl;
    cout << "3. Camp" << endl;
    cout << "4. Don't Travel" << endl;
    validateInt(&location, 1, 4);
    switch (location) {
        case 1:
            if (this->character->inventory->boat > 0 && this->character->inventory->compass > 0 && this->character->inventory->bowAndArrows > 0) {
                this->character->currentLocation = this->top;
                this->character->currentLocation->printLocation();
            }
            else {
                cout << "The ocean is a dangerous place, you'll need a boat" << endl;
                cout << "a compass and a bow and arrow to go here" << endl;
            }
            break;
        case 2:
        if (this->character->inventory->airtank > 0) {
            this->character->currentLocation = this->left;
            this->character->currentLocation->printLocation();
        }
        else {
            cout << "The shipwreck is underwater, you'll need an airtank to go here" << endl;
        }
            break;
        case 3:
            this->character->currentLocation = this->bottom;
            this->character->currentLocation->printLocation();
            break;
        case 4:
            cout << "You stay where you are" << endl;
            break;
    }
}