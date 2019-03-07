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
    cout << "3. Quit game" << endl;
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    
    else if (menuChoice == 2) {
        craft();
    }
    else {
        this->character->alive = false;
    }
        

}

void Camp::craft() {
    int craftInt;
    cout << endl;
    cout << "Which items would you like to craft?" << endl;
    cout << "1. Airtank" << endl;
    cout << "2. Bow and Arrows" << endl;
    cout << "3. Boat" << endl;
    cout << "4. Desalinator" << endl;
    cout << "5. Exit craft menu" << endl;
    validateInt(&craftInt, 1, 6);
    switch (craftInt) {
        case 1: 
            cout << "Crafting an airtank requires 10 pieces of plastic" << endl;
            cout << "Would you still like to build an airtank?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&craftInt, 1,2);
            if (craftInt == 1 && this->inventory->getPlastic() >= 10) {
                this->inventory->setPlastic(-10);
                cout << "You have " << this->inventory->getPlastic() << " plastic left." << endl;
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
            validateInt(&craftInt, 1,2);
            if (craftInt == 1 && this->inventory->getWood() >= 1 && this->inventory->getPlastic() >= 1) {
                this->inventory->setPlastic(-1);
                this->inventory->setWood(-1);
                cout << "You have " << this->inventory->getWood() << " wood left." << endl;
                cout << "You have " << this->inventory->getPlastic() << " plastic left." << endl;
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
            if (craftInt == 1 && this->inventory->getWood() >= 50) {
                this->inventory->setWood(-50);
                cout << "You have " << this->inventory->getWood() << " wood left." << endl;
            }
            else {
                cout << "You do not have enough wood" << endl;
            }
            cout << "Exiting craft menu" << endl;
            break;            
        case 4: 
            cout << "Crafting a desalinator requires 20 plastic" << endl;
            cout << "Would you still like to build a desalinator?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&craftInt, 1,2);
            if (craftInt == 1 && this->inventory->getPlastic() >= 20) {
                this->inventory->setPlastic(-20);
                cout << "You have " << this->inventory->getPlastic() << " plastic left." << endl;
            }
            else {
                cout << "You do not have enough plastic" << endl;
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
            this->character->currentLocation = this->right;
            this->character->currentLocation->printLocation();
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