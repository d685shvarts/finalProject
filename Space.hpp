/***************************************************************************************************************************************
** Program name: Space header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Declaration of abstract Space class that will be used to create 6 other derived Space classes for player to inhabit. Contains
** member variables of 4 pointers to other Space objects which will be used to link the space objects together. Also contains variables to store
** the Space's name and pointers to the Character and Inventory object in order to interact with and modify them. Its function include a 
** constructor to initialize the derived Space objects, 4 functions to initialize the Space pointers to point to their respective space, 
** getter function for space name, abstract menu function for the space, and function to output characters position on the map. 
****************************************************************************************************************************************/ 
#ifndef SPACE_HPP
#define SPACE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include <string>


using std::string;
class Character;
class Inventory;

class Space {
protected:
    //4 pointers to Spsace objects to link spaces together
    Space* top,
        *left,
        *right,
        *bottom;
    //String to store spaces name
    string name;
    //Pointers to inventory and character objects
    Inventory* inventory;
    Character* character;
public:
    //Space constructor
    Space(Inventory* inventory, Character* character);
    //Function to initialize Space pointers to point to other spaces
    void addTop(Space* top);
    void addBottom(Space* bottom );
    void addLeft(Space* left);
    void addRight(Space* right);
    //Abstract menu for space objects
    virtual void spaceMenu() = 0;
    //Function to output characters location
    void printLocation();
    void printMap();

};
#endif