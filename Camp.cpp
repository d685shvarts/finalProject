#include "Camp.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

Camp::Camp(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Camp";
}

void Camp::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "2. Craft items" << endl;
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    
    else if (menuChoice == 2) {
        craft();
    }
        
}

void Camp::craft() {
    int craftInt;
    cout << endl;
    cout << "Which items would you like to craft?" << endl;
    cout << "1. Airtank" << endl;
    cout << "2. Bow and Arrows" << endl;
    cout << "3. Boat" << endl;
    cout << "4. Exit craft menu" << endl;
    validateInt(&craftInt, 1, 4);
    switch (craftInt) {
        case 1: 
            cout << "Crafting an airtank requires 10 pieces of plastic" << endl;
            cout << "Would you still like to build an airtank?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&craftInt, 1,2);
            if (craftInt == 1 && this->inventory->plastic >= 10) {
                cout << "You've built 1 airtank!" << endl;
                this->inventory->airtank++;
                this->inventory->plastic -= 10;
                cout << "You have " << this->inventory->plastic << " plastic left." << endl;
            }
            else if (craftInt == 2) {
                cout << "You decide to craft nothing" << endl;
            }
            else {
                cout << "You do not have enough plastic" << endl;
            }
            cout << "Exiting craft menu" << endl;
            break;
        case 2: 
            cout << "Crafting bow and arrows requires 1 piece of wood and 1 piece of plastic" << endl;
            cout << "Would you still like to build bow and arrows?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&craftInt, 1, 2);
            if (craftInt == 1 && this->inventory->wood >= 1 && this->inventory->plastic >= 1) {
                cout << "You built 1 set of bow and arrows!" << endl;
                this->inventory->bowAndArrows++;
                this->inventory->plastic--;
                this->inventory->wood--;
                cout << "You have " << this->inventory->wood << " wood left." << endl;
                cout << "You have " << this->inventory->plastic << " plastic left." << endl;
            }
            else if (craftInt == 2) {
                cout << "You decide to craft nothing" << endl;
            }
            else {
                cout << "You do not have enough wood and plastic " << endl;
            }
            cout << "Exiting craft menu" << endl;
            break;
        case 3: 
            cout << "Crafting a boat requires 50 wood" << endl;
            cout << "Would you still like to build a boat?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&craftInt, 1,2);
            if (craftInt == 1 && this->inventory->wood >= 50) {
                cout << "You built a boat!" << endl;
                this->inventory->boat++;
                this->inventory->wood -= 50;
                cout << "You have " << this->inventory->wood << " wood left." << endl;
            }
            else if (craftInt == 2) {
                cout << "You decide to craft nothing" << endl;
            }
            else {
                cout << "You do not have enough wood" << endl;
            }
            cout << "Exiting craft menu" << endl;
            break;                                                
    }
}

void Camp::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Shore" << endl;
    cout << "2. Jungle" << endl;
    cout << "3. Volcano" << endl;
    cout << "4. Don't Travel" << endl;
    validateInt(&location, 1, 4);
    switch (location) {
        case 1:
            this->character->currentLocation = this->top;
            this->character->currentLocation->printLocation();
            break;
        case 2:
            if (this->character->inventory->axe > 0) {
                this->character->currentLocation = this->right;
                this->character->currentLocation->printLocation();
            }
            else {
                cout << "The jungle is covered in thick foliage. You need an axe to enter." << endl;
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