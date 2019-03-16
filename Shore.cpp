/***************************************************************************************************************************************
** Program name: Shore impementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them. Contains virtual menu function which will display options for user, scavengeSupplies method which will be used by player to
** gather resources, and finally a change location method, which enables user to change their location on the map
****************************************************************************************************************************************/ 
#include "Shore.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************************************************************************
** Function name: Shore constructor
** Description: Constructor will initalize shore objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables.
***********************************************************************************************************************************/
Shore::Shore(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Shore";
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overriden method from base class, which dispays options user has to interact with current space. Prompts user to either
** change their location on the island or interact with current space by searching for supplies and then run functions to accomplish users
** choice
***********************************************************************************************************************************/
void Shore::spaceMenu() {
    int menuChoice;
    //Prompt user to select a choice
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "   - Travel to a new location on the island" << endl;
    cout << "2. Scavenge for supplies" << endl;
    cout << "   - Search the shore for washed up food, water or plastic" << endl;
    //Validate the input
    validateInt(&menuChoice, 1, 2);
    //Run method corresponding to user input
    if (menuChoice == 1) {
        changeLocation();
    }
    else {
        scavengeSupplies();
    }
}

/*********************************************************************************************************************************
** Function name: changeLocation method
** Description: Prompt user to select from one of the neighboring spaces and then will change characters current location accordingly.
** Will also make sure user has the items required to travel to selected space.
***********************************************************************************************************************************/
void Shore::changeLocation() {
    int location;
    //Prompt user to select location to travel to
    cout << "Where would you like to travel?" << endl;
    cout << "1. Ocean" << endl;
    cout << "   - Set sail for home!" << endl;
    cout << "2. Shipwreck" << endl;
    cout << "   - Old sunken ship, may contain instruments to navigate your way home" << endl;
    cout << "3. Camp" << endl;
    cout << "   - Base camp to craft new items" << endl;
    cout << "4. Don't Travel" << endl;
    //Validate input
    validateInt(&location, 1, 4);
    switch (location) {
        //If user selected Ocean
        case 1:
            //Check if they have boat, compass, bow and arrows and food necessary to travel there.
            if (this->character->inventory->boat > 0 && this->character->inventory->compass > 0 && this->character->inventory->bowAndArrows > 0 
                && this->character->inventory->food >= 5) {
                //Change their current location and print their new position on the map
                this->character->currentLocation = this->top;
                this->character->currentLocation->printLocation();
            }
            else {
                //If they dont have required items, notify them
                cout << "The ocean is a dangerous place, you'll need a boat" << endl;
                cout << "a compass, 5 piecse of food, and bow and arrows to go here" << endl;
            }
            break;
        //If user wants to travel to shipwreck
        case 2:
            //Check if they have items required to travel there.
            if (this->character->inventory->airtank > 0) {
                //Change their current location and print their new position on the map
                this->character->currentLocation = this->left;
                this->character->currentLocation->printLocation();
            }
            else {
                //If they dont have required items, notify them
                cout << "The shipwreck is underwater, you'll need an airtank to go here" << endl;
            }
            break;
        //If user wants to travel to camp
        case 3:
            //Change their current location and print their new position on the map
            this->character->currentLocation = this->bottom;
            this->character->currentLocation->printLocation();
            break;
        //If user does not want to travel do nothing
        case 4:
            cout << "You stay where you are" << endl;
            break;
    }
}

/*********************************************************************************************************************************
** Function name: scavengeSupplies method
** Description: Method which randomly returns random amount of food, water or plastic to user.
***********************************************************************************************************************************/
void Shore::scavengeSupplies() {
    //Generate random number to determine whether to return plastic, food or water
    int random = 1 + rand() % 100;
    //Generate random number to determine quantity of resource found 
    int supplies = 1 + rand() % 10;

    //If between 0 and 33, player gains random amount of plastic
    if (random > 0 && random < 34) {
        cout << "You find " << supplies << " pieces of plastic on the shore!" << endl;
        this->character->inventory->plastic += supplies;
    }
    //If between 34 and 67, player gains random amount of water
    else if (random >= 34 && random < 68) {
        cout << "You find " << supplies << " bottles of water on the shore!" << endl;
        this->character->inventory->water += supplies;
    }
    //If between 68 and 100, player gains random amount of food
    else {
        cout << "You find " << supplies << " tins of food on the shore!" << endl;
        this->character->inventory->food += supplies;
    }
}