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
    cout << "2. Chop Wood" << endl;

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
    int random; 
    int jungleEvent;
    if (this->character->inventory->bowAndArrows >= 1) {
        random = 1 + rand() % 50;
        cout << "bow and arrow rand: " << random << endl;
    }
    else {
        random = 1 + rand() % 100;
        cout << "NO bow and arrow rand: " << random << endl;
    }
    if (random > 0 && random <= 50) {
        jungleEvent = 1 + rand() % 10;
        cout << "You chop " <<  jungleEvent << " pieces of wood." << endl;
        this->character->inventory->wood += jungleEvent;
    }
    else if (random > 50 && random <= 75) {
        jungleEvent = 1 + rand() % 50;
        cout << "You are attacked by wild animals! They deal " << jungleEvent << " damage to you!" << endl;
        cout << "If only you had a weapon to fend them off..." << endl;
        this->character->health -= jungleEvent;
    }
    else {
        jungleEvent = 1 + (rand() % (this->character->inventory->food / 2));
        cout << "You are swarmed by monkeys that steal " << jungleEvent << " pieces of food from you" << endl;
        this->character->inventory->food -=jungleEvent;
    }
}