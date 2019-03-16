/***************************************************************************************************************************************
** Program name: Volcano header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them. Contains virtual menu function which will display options for user, volcanoRiddle method to have user play a game
** of riddles to get a reward, and finally a change location method, which enables user to change their location on the map
**************************************************************************************************************************************/ 
#ifndef VOLCANO_HPP
#define VOLCANO_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Volcano : public Space {
public:
    //Volcano constructor
    Volcano(Inventory* inventory, Character* character);
    //Overidden spaceMenu method to enable user to interact with the Space
    virtual void spaceMenu();
    //Method to enable user to change current Space
    void changeLocation();
    //Method to play a riddle game
    void volcanoRiddle();

};
#endif