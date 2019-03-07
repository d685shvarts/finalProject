#include "Volcano.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
#include <windows.h>
#include <dos.h>
using std::endl;
using std::cout;


Volcano::Volcano(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Volcano";
}

void Volcano::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "2. Approach Volcano" << endl;
    cout << "3. Quit game" << endl;
    validateInt(&menuChoice, 1, 3);
    if (menuChoice == 1) {
        changeLocation();
    }
    else if (menuChoice == 2) {
        volcanoRiddle();
    }
    else {
        this->character->alive = false;
    }

}

void Volcano::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Camp" << endl;
    cout << "2. Don't travel" << endl;
    validateInt(&location, 1, 2);
    switch (location) {
        case 1:
            this->character->currentLocation = this->top;
            this->character->currentLocation->printLocation();
            break;
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}

void Volcano::volcanoRiddle() {
    cout << "You see small entrance hidden behind some brush..." << endl;
    Sleep(1000);
    cout << "You peek inside the entrance and see an opening into a cave.." << endl;
    Sleep(1000);
    cout << "You crawl through the entrance  " << endl;

}