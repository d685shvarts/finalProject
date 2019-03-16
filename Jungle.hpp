/***************************************************************************************************************************************
** Program name: Jungle header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them. Contains virtual menu function which will display options for user, and a change location method, which enables user to 
** change their location on the map. Also contains function enter jungle and chopwood
**************************************************************************************************************************************/ 
#ifndef JUNGLE_HPP
#define JUNGLE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Character;
class Inventory;

class Jungle : public Space {
public:
    //Jungle constructor
    Jungle(Inventory* inventory, Character* character);
    //Overidden spaceMenu method to enable user to interact with the Space
    virtual void spaceMenu();
    //Method to enable user to change current Space
    void changeLocation();
    //Method to enable user to enter jungle to gather wood
    void chopWood();
};
#endif