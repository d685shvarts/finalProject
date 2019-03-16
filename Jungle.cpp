/***************************************************************************************************************************************
** Program name: Jungle implementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them. Contains virtual menu function which will display options for user, and a change location method, which enables user to 
** change their location on the map. Also contains function enter jungle and chopwood
**************************************************************************************************************************************/ 
#include "Jungle.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************************************************************************
** Function name: Jungle constructor
** Description: Constructor will initalize jungle objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables.
***********************************************************************************************************************************/
Jungle::Jungle(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Jungle";
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overriden method from base class, which dispays options user has to interact with current space. Prompts user to either
** change their location on the island or interact with current space by chopping wood and then run functions to accomplish users
** choice
***********************************************************************************************************************************/
void Jungle::spaceMenu() {
    int menuChoice;
    //Prompt user to select a choice
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "   - Travel to a new location on the island" << endl;
    cout << "2. Chop Wood" << endl;
    cout << "   - Enter dense foliage to chop wood, it's dangerous in there, beware!" << endl;
    //Validate input then run respective function
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    else {
        chopWood();
    }
}

/*********************************************************************************************************************************
** Function name: changeLocation method
** Description: Prompt user to select from one of the neighboring spaces and then will change characters current location accordingly.
** Will also make sure user has the items required to travel to selected space.
***********************************************************************************************************************************/
void Jungle::changeLocation() {
    int location;
    //Prompt user to select location to travel to
    cout << "Where would you like to travel?" << endl;
    cout << "1. Camp" << endl;
    cout << "   - Base camp to craft new items" << endl;
    cout << "2. Don't travel" << endl;
    //Validate input
    validateInt(&location, 1, 2);
    switch (location) {
        //If user selected camp, change location to camp and print location details
        case 1:
            this->character->currentLocation = this->left;
            this->character->currentLocation->printLocation();
            break;
        //If user selected dont travel, do nothing
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}


/*********************************************************************************************************************************
** Function name: chopwood method
** Description: Method which will randomly determine whether user obtains wood, gets attacked by animals which deal damage, or 
** swarmed by monkeys which steal food. If play has bow and arrows, the animal and monkey attacks will stop.
***********************************************************************************************************************************/
void Jungle::chopWood() {
    int random; 
    int jungleEvent;
    //If player has bow and arrow generate random int between 1 and 50, thus only wood gathering will happen
    if (this->character->inventory->bowAndArrows >= 1) {
        random = 1 + rand() % 50;
    }
    //If player has no bow and arrow, generate random int between 1 and 100 which allows monkey and animal attacks to occur
    else {
        random = 1 + rand() % 100;
    }
    //If random number is between 1 and 50, players gathers random amount of wood from 1-10
    if (random > 0 && random <= 50) {
        jungleEvent = 1 + rand() % 10;
        cout << "You chop " <<  jungleEvent << " pieces of wood." << endl;
        this->character->inventory->wood += jungleEvent;
    }
    //If random int between 50  and 75, animals attack character and deal random damage from 1-50
    else if (random > 50 && random <= 75) {
        jungleEvent = 1 + rand() % 50;
        cout << "You are attacked by wild animals! They deal " << jungleEvent << " damage to you!" << endl;
        cout << "If only you had bow and arrows to fend them off..." << endl;
        this->character->health -= jungleEvent;
    }
    //If random int between 76 and 100
    else {
        //If player has more than two food in inventory
        if (this->character->inventory->food >= 2) {
            //Generate a random int between 1 and half the players current food
            jungleEvent = 1 + (rand() % (this->character->inventory->food / 2));
            cout << "You are swarmed by monkeys that steal " << jungleEvent << " pieces of food from you" << endl;
            cout << "If only you had bow and arrows to fend them off..." << endl;
            //Subtract random int from players food inventory
            this->character->inventory->food -= jungleEvent;
        }
        //If player has less than 2 food, do nothing
        else {
            cout << "You are swarmed by monkeys but you dont have enough food to steal!" << endl;
        }
    }
}