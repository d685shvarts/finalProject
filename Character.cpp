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
    this->hasAxe = this->hasBoat = this->hasBowAndArrows = this->hasCompass = this->hasAirtank = false;
    this->alive = true;
    this->currentLocation = nullptr;
    Inventory inventory;
}

void Character::characterMenu() {
    int menuChoice,
        inventoryChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Access inventory" << endl;
    cout << "2. Interact with location" << endl;
    validateInt(&menuChoice, 1, 2);

    if (menuChoice == 1) {
        cout << "What would you like to do?" << endl;
        cout << "1. Print inventory" << endl;
        cout << "2. Drop items" << endl;
        validateInt(&inventoryChoice, 1, 2);
        if (inventoryChoice == 1) {
            this->inventory.printInventory();
        }
        else {
            this->inventory.dropItems();
        }
    }
    else {
        this->currentLocation->spaceMenu();
    }
    
}

bool Character::getAlive() {
    return this->alive;
}

void Character::setBoat(bool boat) {
    this->hasBoat = boat;
}

void Character::setAxe(bool axe) {
    this->hasAxe = axe;
}

void Character::setCompass(bool compass) {
    this->hasCompass = compass;
}

void Character::setAlive(bool alive) {
    this->alive = alive;
}

Inventory* Character::getInventory() {
    return &inventory;
}

void Character::setLocation(Space* location) {
    this->currentLocation = location;
}
