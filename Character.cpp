/***************************************************************************************************************************************
** Program name: Character header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Character class which will be used to keep track of players health, thirst, hunger, inventory and current location.
** Contains constructor to initialize all variables, destructor to free dynamically allocated memory. Also contains functions 
** print menu of options for player to choose from, functions to return alive and won game bools, and inventory pointers. 
** Has functions to change what the space pointer points to, functions to print character stats, interact with the inventroy and 
** finally a function to track and increase player thirst, hunger, and health.
**************************************************************************************************************************************/ 
#include "Character.hpp"
#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <limits>

using std::streamsize;
using std::cin;
using std::string;
using std::endl;
using std::cout;


/*********************************************************************************************************************************
** Function name: Character constructor
** Description: Constructor will initalize health, hunger, thirst ints. Will also initialize alive and wonGame bools. And finally
** dynamically allocate a new inventory object to be used by character
***********************************************************************************************************************************/
Character::Character() {
    this->health = 100;
    this->thirst = this->hunger = 0;
    this->currentLocation = nullptr;
    this->alive = true;
    this->wonGame = false;
    this->inventory = new Inventory();
}

/*********************************************************************************************************************************
** Function name: Character destructor
** Description: Destructor to free  dynamically allocated inventory object
***********************************************************************************************************************************/
Character::~Character() {
    delete this->inventory;
}

/*********************************************************************************************************************************
** Function name: characterMenu method
** Description: Method to prompt user to keep playing or quit game every turn. Will display options on screen and then run functions
** or change variables to accomplish player input.
***********************************************************************************************************************************/
void Character::characterMenu() {
    cout << endl;
    int menuChoice;
    //Prompt user to select an option
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Interact with location" << endl;
    cout << "2. Quit game" << endl;
    validateInt(&menuChoice, 1, 2);
    //If player wants to keep playing run the menu of the current space
    if (menuChoice == 1) {
        this->currentLocation->spaceMenu();
    }
    //Otherwise change their alive bool to false
    else {
        this->alive = false;
    }
}

/*********************************************************************************************************************************
** Function name: getAlive method
** Description: Getter method for alive bool
***********************************************************************************************************************************/
bool Character::getAlive() {
    return this->alive;
}

/*********************************************************************************************************************************
** Function name: getInventory method
** Description: Getter method for inventory object pointer
***********************************************************************************************************************************/
Inventory* Character::getInventory() {
    return inventory;
}


/*********************************************************************************************************************************
** Function name: setLocation
** Description: Setter method for space pointer. Will be used by main to initialize initial location
***********************************************************************************************************************************/
void Character::setLocation(Space* location) {
    this->currentLocation = location;
}

/*********************************************************************************************************************************
** Function name: printCharacterStats method
** Description: Method to display characters current health, hunger and thirst for user to see.
***********************************************************************************************************************************/
void Character::printCharacterStats() {
    cout << endl;
    cout << "Your health is: " << this->health << "/100" << endl;
    cout << "You thirst is: " << this->thirst << "/100" << endl;
    cout << "You hunger is: " << this->hunger << "/100" << endl;
    cout << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

/*********************************************************************************************************************************
** Function name: ageCharacter method
** Description: Method to mimic survival on the island. Will check if user has water or food in inventory. If yes will reset hunger
** and thirst to 0 and decrement hunger and thirst. If no will increase hunger and thirst. Once hunger and thirst are above a certain 
** threshold, players health will be lowered. However if hunger and thirst are not above a certain threshold, characters health will
** slowly regenerate. Will also change alive bool if health falls below 0. THIS IS THE STEP LIMIT
***********************************************************************************************************************************/
void Character::ageCharacter() {
    //If health falls to 0 or below change alive bool to false and return to function call
    if (this->health <= 0) {
        cout << "Your health has fallen to 0 or below, you have died!" << endl;
        this->alive = false;
        return;
    }
    //Otherwise check player thirst and hunger
    else {
        //If player has water, consume 1 water and lower thirst to 0
        if (this->inventory->water > 0) {
            cout << "Consuming 1 water, you thirst is back to 0" << endl;
            this->inventory->water--;
            this->thirst = 0;
        }
        //If player has no water increase thirst by 25
        else {
            cout << "You have no water, your thirst is increased!" << endl;
            this->thirst += 25;
        }
        //If player has food, consume 1 food and lower hunger to 0
        if (this->inventory->food > 0) {
            cout << "Consuming 1 food, you hunger is back to 0" << endl;
            this->inventory->food--;
            this->hunger = 0;
        }
        //If player has no food increase hunger by 20
        else {
            cout << "You have no food, your hunger is increased!" << endl;
            this->hunger += 20;
        }
        //If hunger exceeds 100, lower health by 20
        if (this->hunger > 100) {
            cout << "You are starving. Your health has decreased!" << endl;
            this->health -= 20;
        }
        //If thirst exceeds 100, lower health by 25
        if (this->thirst > 100) {
            cout << "You are dehydrated. Your health has decreased!" << endl;
            this->health -= 25;
        }
        //If thirst and hunger are less than 100, restore health slowly
        if (this->hunger < 100 && this->thirst < 100) {
            if (this->health < 100) {
                cout << "You are well nourished you health is restoring slowly" << endl;
                health += 20;
            }
            //If health exceeds 100, set to 100
            if (this->health > 100) {
                this->health = 100;
            }
        }
        //If health falls to 0 or below change alive bool to false and return to function call
        if (this->health <= 0) {
            cout << "Your health has fallen to 0 or below! You have died!" << endl;
            this->alive = false;
        }
    }
    //Now print characterStats at end
    printCharacterStats();
}

/*********************************************************************************************************************************
** Function name: interactInventory method
** Description: Method will print contents of inventory, then check if contents exceed the capacity of the inventory, and force player
** to drop items if it does
***********************************************************************************************************************************/
void Character::interactInventory() {
    this->inventory->printInventory();
    this->inventory->exceedCapacity();
}

/*********************************************************************************************************************************
** Function name: getWonGame method
** Description: Getter method for wonGame bool, used to exit out of while loop after game win in main.
***********************************************************************************************************************************/
bool Character::getWonGame() {
    return this->wonGame;
}

/*********************************************************************************************************************************
** Function name: printLocation method
** Description: Will display name of current location along with a map of the island.
***********************************************************************************************************************************/
void Character::printLocation() {
    this->currentLocation->printLocation();
}