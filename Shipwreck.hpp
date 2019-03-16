/***************************************************************************************************************************************
** Program name: Shipwreck header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them and airtank var. Contains virtual menu function which will display options for user, and a change location method, which 
** enables user to change their location on the map. Also contains a private member variable airtank to store users current airsupply, along 
** with functions to return current airsupply and return true or false if its above 0. Finally contains dive method which will let user 
** dive into the shipwreck to explore it for resources
**************************************************************************************************************************************/ 
#ifndef SHIPWRECK_HPP
#define SHIPWRECK_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Shipwreck : public Space {
protected:
    //Member var to store users current airsupply
    int airSupply;
public:
    //Constructor for derived shipwreck class
    Shipwreck(Inventory* inventory, Character* character);
    //Overidden spaceMenu method to enable user to interact with the Space
    virtual void spaceMenu();
    //Method to enable user to change current Space
    void changeLocation();
    //Method to enable user to explore shipwreck
    void dive();
    //Method to return current capacity of user's airtank
    void getAirtank();
    //Method to return true or false depending on if users airSupply is above 0
    bool checkAirtank();
};
#endif