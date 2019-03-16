/***************************************************************************************************************************************
** Program name: Ocean header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them, also will initialize the value of the boss' health, damage, and character damage. Contains virtual menu function which 
** will display options for user, and a change location method, which enables user to change their location on the map. Also contains function
** which will introduce the boss, print a picture of the boss, allow user to do battle with the boss and update user with the stats of the battle
**************************************************************************************************************************************/ 
#ifndef OCEAN_HPP
#define OCEAN_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Ocean : public Space {
private:
    //Int variable to store the bosses current health
    int bossHealth,
        //Int variables to store damage boss and character can do
        bossDamage,
        characterDamage;
public:
    //Ocean constructor
    Ocean(Inventory* inventory, Character* character);
    //Overidden spaceMenu method to enable user to interact with the Space
    virtual void spaceMenu();
    //Method to introduce the boss
    void bossIntro();
    //Method fight the boss
    void bossBattle();
    //Method to give user options to fight boss
    void battleMenu(int& menuChoice);
    //Method to update user with information about the battle
    void battleStats();
    //Method to display a picture of the boss
    void printBoss();
};
#endif