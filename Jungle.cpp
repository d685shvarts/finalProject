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
    cout << "2. Chop wood" << endl;

    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    else {
        chopWood();
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

void Jungle::chopWood() {
    int random = 1 + rand() % 100;
    if (random > 0 && random <= 50) {
        int wood = 1 + rand() % 10;
        cout << "You chop " <<  wood << " pieces of wood." << endl;
        this->character->inventory += wood;
    }
    else {
        int damage = 1 + rand() % 50;
        cout << "You are attacked by wild animals! They deal " << damage << " damage to you!" << endl;
        this->character->health -= damage;
    }
}