/***************************************************************************************************************************************
** Program name: Space implementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Implementation of abstract Space class that will be used to create 6 other derived Space classes for player to inhabit. 
**  Its functions include a constructor to initialize the derived Space objects, 4 functions to initialize the Space pointers to point 
** to their respective space, getter function for space name, abstract menu function for the space, and function to output characters 
** position on the map. 
****************************************************************************************************************************************/ 
#include "Space.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>
#include <limits>

using std::streamsize;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************************************************************************
** Function name: Space constructor
** Description: Constructor to initialize character and inventory pointers of Space obect along with name. Its arguments are pointers
** to the character and inventory objects, to intialize character and inventory pointers of Space class, so it can interact with and modify
** them. 
***********************************************************************************************************************************/
Space::Space(Inventory* inventory, Character* character) {
    this->top = nullptr;
    this->right = nullptr;
    this->bottom = nullptr;
    this->left = nullptr;
    this->inventory = inventory;
    this->character = character;

    this->name = "unitialized...";
}

/*********************************************************************************************************************************
** Function name: addTop method
** Description: Method to initialize the Space pointer top to point to the Space pointer within the argument. Will be used to link the
** spaces together.
***********************************************************************************************************************************/
void Space::addTop(Space* top) {
    this->top = top;
}

/*********************************************************************************************************************************
** Function name: addBottom method
** Description: Method to initialize the Space pointer bottom to point to the Space pointer within the argument. Will be used to link the
** spaces together.
***********************************************************************************************************************************/
void Space::addBottom(Space* bottom) {
    this->bottom = bottom;
}

/*********************************************************************************************************************************
** Function name: addLeft method
** Description: Method to initialize the Space pointer left to point to the Space pointer within the argument. Will be used to link the
** spaces together.
***********************************************************************************************************************************/
void Space::addLeft(Space* left) {
    this->left = left;
}

/*********************************************************************************************************************************
** Function name: addRight method
** Description: Method to initialize the Space pointer right to point to the Space pointer within the argument. Will be used to link the
** spaces together.
***********************************************************************************************************************************/
void Space::addRight(Space* right) {
    this->right = right;
}

/*********************************************************************************************************************************
** Function name: printLocation method
** Description: Method to print players current location on the map, the spaces surrounding the player and a visual representation of 
** the map itself
***********************************************************************************************************************************/
void Space::printLocation() {
    //Output players location and surrounding spaces if they exist
    cout << "Your current location is: " << this->name << endl;

    cout << endl;
    //Print visual representation of the map
    printMap();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

/*********************************************************************************************************************************
** Function name: printMap method
** Description: Method to print visual representation of map to make navigation easier
***********************************************************************************************************************************/
void Space::printMap() {
    cout << R"(
               Ocean
                 |
    Shipwreck--Shore
                 |
                Camp--Jungle
                 |
               Volcano
      
)" << '\n';
}

