/***************************************************************************************************************************************
** Program name: Camp header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them. Contains virtual menu function which will display options for user, and a change location method, which enables user to 
** change their location on the map. Also contains function to craft items from other items in the inventory.
**************************************************************************************************************************************/ 
#ifndef CAMP_HPP
#define CAMP_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Camp : public Space {
public:
    //Camp constructor 
    Camp(Inventory* inventory, Character* character);
    //Overidden spaceMenu method to enable user to interact with the Space
    virtual void spaceMenu();
    //Method to enable user to craft valuable items from other items in the inventory
    void craft();
    //Method to enable user to change current Space
    void changeLocation();
};
#endif