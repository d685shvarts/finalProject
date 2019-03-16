/***************************************************************************************************************************************
** Program name: Camp header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them. Contains virtual menu function which will display options for user, and a change location method, which enables user to 
** change their location on the map. Also contains function to craft items from other items in the inventory.
**************************************************************************************************************************************/ 
#include "Camp.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;


/*********************************************************************************************************************************
** Function name: Camp constructor
** Description: Constructor will initalize camp objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables.
***********************************************************************************************************************************/
Camp::Camp(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Camp";
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overriden method from base class, which dispays options user has to interact with current space. Prompts user to either
** change their location on the island or interact with current space by crafting items and then run functions to accomplish users
** choice
***********************************************************************************************************************************/
void Camp::spaceMenu() {
    int menuChoice;
    //Prompt user to select a choice
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "   - Travel to a new location on the island" << endl;
    cout << "2. Craft items" << endl;
    cout << "   - Construct new items from items in your inventory" << endl;
    //Validate input then run respective function
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    else if (menuChoice == 2) {
        craft();
    }
        
}

/*********************************************************************************************************************************
** Function name: craft method
** Description: Method to enable user to craft items from other items in their inventory. Will ask user what item they want crafted,
** then check that their inventory contains the items necessary to craft item, if yes it will make new item and remove required resources.
** These items will be necesary to get off the island.
***********************************************************************************************************************************/
void Camp::craft() {
    int craftInt;
    cout << endl;
    //Prompt user to select an item to craft
    cout << "Which items would you like to craft?" << endl;
    cout << "1. Airtank" << endl;
    cout << "   - A container that can store air, will enable you to dive underwater" << endl;
    cout << "2. Bow and Arrows" << endl;
    cout << "   - Bow and Arrows to enable you to fight creatures on and off the island" << endl;
    cout << "3. Boat" << endl;
    cout << "   - A boat needed to get off this island" << endl;
    cout << "4. Exit craft menu" << endl;
    //Validate input
    validateInt(&craftInt, 1, 4);
    switch (craftInt) {
        //If user wants to craft an airtank
        case 1:
            //Make sure that they want to craft an airtank
            cout << "Crafting an airtank requires 10 pieces of plastic" << endl;
            cout << "Would you still like to build an airtank?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            //Validate input
            validateInt(&craftInt, 1,2);
            //If the still want to craft an airtank and have enough plastic
            if (craftInt == 1 && this->inventory->plastic >= 10) {
                //Add airtank to inventory and subtract plastic required to craft it
                cout << "You've built 1 airtank!" << endl;
                this->inventory->airtank++;
                this->inventory->plastic -= 10;
                cout << "You have " << this->inventory->plastic << " plastic left.\n" << endl;
            }
            //If they dont want to craft anything do nothing
            else if (craftInt == 2) {
                cout << "You decide to craft nothing\n" << endl;
            }
            //If they dont have enough plastic, do nothing
            else {
                cout << "You do not have enough plastic\n" << endl;
            }
            break;
        //If user wants to craft bow and arrows
        case 2: 
            //Make sure that they want to craft an bow and arrows
            cout << "Crafting bow and arrows requires 1 piece of wood and 1 piece of plastic" << endl;
            cout << "Would you still like to build bow and arrows?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            //validate input
            validateInt(&craftInt, 1, 2);
            //If the still want to craft an bow and arrows and have enough plastic and wood
            if (craftInt == 1 && this->inventory->wood >= 1 && this->inventory->plastic >= 1) {
                cout << "You built 1 set of bow and arrows!" << endl;
                //Add bow and arrows to inventory and subtract required wood and plastic
                this->inventory->bowAndArrows++;
                this->inventory->plastic--;
                this->inventory->wood--;
                cout << "You have " << this->inventory->wood << " wood left." << endl;
                cout << "You have " << this->inventory->plastic << " plastic left.\n" << endl;
            }
            //If they dont want to craft anything do nothing
            else if (craftInt == 2) {
                cout << "You decide to craft nothing\n" << endl;
            }
            //If they dont have enough plastic or wood, do nothing
            else {
                cout << "You do not have enough wood and plastic\n" << endl;
            }
            break;
        //If user wants to craft a boat
        case 3: 
            //Confirm that they want to craft a boat
            cout << "Crafting a boat requires 50 wood" << endl;
            cout << "Would you still like to build a boat?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            //validate input 
            validateInt(&craftInt, 1,2);
            //If user wants to craft a boat and has enough wood 
            if (craftInt == 1 && this->inventory->wood >= 50) {
                cout << "You built a boat!" << endl;
                //Add boat to inventory and subtract required wood 
                this->inventory->boat++;
                this->inventory->wood -= 50;
                cout << "You have " << this->inventory->wood << " wood left.\n" << endl;
            }
            //If they dont want to craft anything do nothing
            else if (craftInt == 2) {
                cout << "You decide to craft nothing\n" << endl;
            }
            //If they dont have enough wood, do nothing
            else {
                cout << "You do not have enough wood\n" << endl;
            }
            break;                                                
    }
}

/*********************************************************************************************************************************
** Function name: changeLocation method
** Description: Prompt user to select from one of the neighboring spaces and then will change characters current location accordingly.
** Will also make sure user has the items required to travel to selected space.
***********************************************************************************************************************************/
void Camp::changeLocation() {
    int location;
    //Prompt user to select a location to travel to
    cout << "Where would you like to travel?" << endl;
    cout << "1. Shore" << endl;
    cout << "   - Explore the shore for washed up supplies" << endl;
    cout << "2. Jungle" << endl;
    cout << "   - Explore jungle to gather wood" << endl;
    cout << "3. Volcano" << endl;
    cout << "   - Explore the mysterious volcano looming over the island" << endl;
    cout << "4. Don't Travel" << endl;
    //Validate input
    validateInt(&location, 1, 4);
    switch (location) {
        //If user selected shore, change current space to shore and print location details
        case 1:
            this->character->currentLocation = this->top;
            this->character->currentLocation->printLocation();
            break;
        //If user selected jungle
        case 2:
            //Check if they have an axe in their inventory, if so change location and print details
            if (this->character->inventory->axe > 0) {
                this->character->currentLocation = this->right;
                this->character->currentLocation->printLocation();
            }
            //If no axe notify them
            else {
                cout << "The jungle is covered in thick foliage. You need an axe to enter." << endl;
            }
            break;
        //If user selected volcano change location and print location details 
        case 3:
            this->character->currentLocation = this->bottom;
            this->character->currentLocation->printLocation();
            break;
        //If user does not want to travel, do nothing
        case 4:
            cout << "You stay where you are" << endl;
            break;
    }
}