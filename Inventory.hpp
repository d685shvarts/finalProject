/***************************************************************************************************************************************
** Program name: Inventory header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Inventory class which will be used by character class to store, access, view and modify items in the inventory. Contains
** several member int variables to keep track and store each item. Contains constructor to initialize each of the int items, function to
** print contents of inventory, function to enable use to drop items, and function to check whether current inventory weight exceeds capacity.
**************************************************************************************************************************************/ 
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Character.hpp"


class Inventory {
protected:
    //Variable to store max capacity of inventory
    int capacity,
    //Variable to store current capacity of inventory
        weight,
    //Variable to store item counts of each item
        food,
        water,
        wood,
        plastic,
        trap,
        torch,
        boat,
        axe,
        bowAndArrows,
        compass,
        airtank;
public:
    //Inventory Constructor
    Inventory();
    //Method to print contents of inventory
    void printInventory();
    //Method to enable use to drop items
    void dropItems();
    //Method to check whether current weight exceeds inventory capacity
    void exceedCapacity();

    //Define other classes as friends to enable them to access and modify inventory vars
    friend class Character;
    friend class Volcano;
    friend class Jungle;
    friend class Ocean;
    friend class Camp;
    friend class Shipwreck;
    friend class Shore;
};
#endif