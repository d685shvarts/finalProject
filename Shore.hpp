/***************************************************************************************************************************************
** Program name: Shore header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them. Contains virtual menu function which will display options for user, scavengeSupplies method which will be used by player to
** gather resources, and finally a change location method, which enables user to change their location on the map
****************************************************************************************************************************************/ 
#ifndef SHORE_HPP
#define SHORE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Shore.hpp"

class Shore : public Space {
public:
    //Shore constructor
    Shore(Inventory* inventory, Character* character);
    //Overridden menu for the shore class
    virtual void spaceMenu();
    //Method to enable player to gather resources
    void scavengeSupplies();
    //Method to enable user to change current Space
    void changeLocation();
};
#endif