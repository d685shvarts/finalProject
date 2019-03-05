#include "Character.hpp"
#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>

using std::endl;
using std::cout;

Character::Character() {
    cout << "Initializing Character" << endl;
    this->health = 100;
    this->thirst = this->hunger = 0;
    this->hasAxe = this->hasFishingPole = this->hasBoat = this->hasDesalinator = this->hasDesalinator = this->hasAirtank = false;
    this->alive = true;
    Inventory inventory;
}

void Character::characterMenu() {
    int menuChoice,
        inventoryChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Access inventory" << endl;
    cout << "2. Change location" << endl;
    validateInt(&menuChoice, 1, 2);

    if (menuChoice == 1) {
        cout << "What would you like to do?" << endl;
        cout << "1. Print inventory" << endl;
        cout << "2. Drop items" << endl;
        validateInt(&inventoryChoice, 1, 2);
        if (menuChoice == 1) {
            this->inventory.printInventory();
        }
        else {
            this->inventory.dropItems();
        }

    }
}

bool Character::getAlive() {
    return this->alive;
}