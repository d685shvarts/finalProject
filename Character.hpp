/***************************************************************************************************************************************
** Program name: Character header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Character class which will be used to keep track of players health, thirst, hunger, inventory and current location.
** Contains int member variables to track health, hunger and thirst, bool member variables to track whether theyre alive and have won the game
** and finally pointers to the players current location and inventory object. Contains constructor to initialize all variables, destructor
** to free dynamically allocated memory. Also contains functions print menu of options for player to choose from, functions to return
** alivea and won game bools, and inventory pointers. Has functions to change what the space pointer points to, functions to print
** character stats, interact with the inventroy and finally a function to track and increase player thirst, hunger, and health.
**************************************************************************************************************************************/ 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Inventory.hpp"
#include "Space.hpp"
#include <string>

using std::string;

class Space;
class Inventory;

class Character {
private:
    //Ints to track player hunger, thirst, and health
    int health,
        thirst,
        hunger;
    //Bools to track whether player is alive or has won game
    bool alive,
        wonGame;
    //Pointer to current space
    Space* currentLocation;
    //Pointer to players inventory
    Inventory* inventory;
public:
    //Character constructor and destructor
    Character();
    ~Character();
    //Print menu to enable user to quit or keep playing
    void characterMenu();
    //Get function for alive bool
    bool getAlive();
    //Getter for inventory pointer
    Inventory* getInventory();
    //Setter for currentLocation pointer
    void setLocation(Space* location);
    //Will print hunger, thirst, and health on screen
    void printCharacterStats();
    //Will check water and food and increase hunger and thirst if missing
    void ageCharacter();
    //Method to print inventory and check if weight exceeds capacity
    void interactInventory();
    //Getter for wonGame bool
    bool getWonGame();
    //Will print current space player is in, and a map of the island
    void printLocation();
    //Define other classes as friends to enable them to access and modify character vars
    friend class Camp;
    friend class Jungle;
    friend class Ocean;
    friend class Shipwreck;
    friend class Volcano;
    friend class Shore;
    friend class Inventory;

};
#endif
