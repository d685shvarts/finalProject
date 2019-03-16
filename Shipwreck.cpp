/***************************************************************************************************************************************
** Program name: Shipwreck implementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them and airtank var. Contains virtual menu function which will display options for user, and a change location method, which 
** enables user to change their location on the map. Also contains a private member variable airtank to store users current airsupply, along 
** with functions to return current airsupply and return true or false if its above 0. Finally contains dive method which will let user 
** dive into the shipwreck to explore it for resources
**************************************************************************************************************************************/ 
#include "Shipwreck.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
#include <limits>

using std::streamsize;
using std::cin;
using std::endl;
using std::cout;

/*********************************************************************************************************************************
** Function name: Shipwreck constructor
** Description: Constructor will initalize shiwreck objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables. Will also intialize initial airSupply value
***********************************************************************************************************************************/
Shipwreck::Shipwreck(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Shipwreck";
    this->airSupply = 100;
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overriden method from base class, which dispays options user has to interact with current space. Prompts user to either
** change their location on the island or interact with current space to search shipwreck and then run functions to accomplish users
** choice
***********************************************************************************************************************************/
void Shipwreck::spaceMenu() {
    int menuChoice;
    //Prompt user to select a choice
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "   - Travel to a new location on the island" << endl;
    cout << "2. Dive into shipwreck" << endl;
    cout << "   - Investigate the undisturbed shipwreck" << endl;
    //Validate input
    validateInt(&menuChoice, 1, 2);
    //Run method corresponding to user input
    if (menuChoice == 1) {
        changeLocation();
    }
    else {
        this->dive();
    }

}

/*********************************************************************************************************************************
** Function name: changeLocation method
** Description: Prompt user to select from one of the neighboring spaces and then will change characters current location accordingly.
** Will also make sure user has the items required to travel to selected space.
***********************************************************************************************************************************/
void Shipwreck::changeLocation() {
    int location;
    //Prompt user to select location to travel to
    cout << "Where would you like to travel?" << endl;
    cout << "1. Shore" << endl;
    cout << "   - Explore the shore for washed up supplies" << endl;
    cout << "2. Don't travel" << endl;
    //Validate input
    validateInt(&location, 1, 2);
    switch (location) {
        //If user selected shore
        case 1:
            //Change their location to shore and print current location
            this->character->currentLocation = this->right;
            this->character->currentLocation->printLocation();
            break;
        //Otherwise do nothing
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}

/*********************************************************************************************************************************
** Function name: dive method
** Description: Method to enable user to explore the shipwreck and obtain item necessary to win game. Will show user a number of 
** possible entrances to choose from and allow them to choose which one to enter. Will decrease their airSupply with each choice,
** and constantly check that they have enough air to continue exploring.
***********************************************************************************************************************************/
void Shipwreck::dive() {
    //Reset airsupply to 100 at start of dive method
    this->airSupply = 100;
    int answer;
    cout << "Press enter to iterate through this level. \n" << endl;
    cout << "You put on your airtank and dive under water..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You swim up to the shipwreck, it looks completely undisturbed..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    //Prompt user to select entrance
    cout << "There are multiple entrances to this shipwreck. Which one do you choose?" << endl;
    cout << "Enter the integer corresponding to you choice" << endl;
    cout << "1. A rusty hatch at the bow of the ship" << endl;
    cout << "2. A chained door near the crew's quarters" << endl;
    cout << "3. A broken window near the starboard" << endl;
    cout << "4. A small crack in the hull of the ship" << endl;
    //Validate user input
    validateInt(&answer, 1, 4);
    //While user choice is incorrect and they have air
    while (answer != 2 && this->checkAirtank()) {
        switch (answer) {
            //Notify user that choice 1 is incorrect
            case 1:
                cout << "You swim up to the hatch and try to undo it..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's attached too tightly, you can't undo it!" << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                break;
            //Notify user that choice 2 is incorrect
            case 3: 
                cout << "You swim up to the broken window and try to weasel your way through it..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's too small, you can't fit!" << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                break;
            //Notify user that choice 4 is incorrect
            case 4:
                cout << "You swim up to the crack and try to slide through it..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's too narrow, you can't fit" << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');           
                break;
        }
        //Decrease airsupply by 10 and print user's current airsupply
        this->airSupply -= 10;
        this->getAirtank();
        //If user still has air left, reprompt them to select an entrance
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');  
            cout << "Enter the integer corresponding to you choice" << endl;
            cout << "1. A rusty hatch at the bow of the ship" << endl;
            cout << "2. A chained door near the crew's quarters" << endl;
            cout << "3. A broken window near the starboard" << endl;
            cout << "4. A small crack in the hull of the ship" << endl;
            //Validate user input
            validateInt(&answer, 1, 4);
        }
    }
    //If user still has air, decrease airsupply by 10, and print current airsupply
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    //If user still has air
    if (this->checkAirtank()) {
        //Notify them that their choice was correct
        cout << "You swim up to chained door and give it a tug..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "The chain snaps! Must've been pretty old." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You enter the crew quarters..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It's cramped in here, but you spot several entrances to investigate " << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        //Prompt user to select new entrance
        cout << "Enter the integer corresponding to you choice \n" << endl;
        cout << "1. An entrance to the ship's cafeteria " << endl;
        cout << "2. A crack in the roof with sunlight filtering through" << endl;
        cout << "3. An door labeled \"Captain's Quarters\" " << endl;
        cout << "4. A trapdoor held down by a large cask" << endl;
        //Validate user input 
        validateInt(&answer, 1, 4);
    }
    //While user input is incorrect and they still have air
    while (answer != 3 && this->checkAirtank()) {
        switch (answer) {
            //Notify user that choice 1 is incorrect
            case 1:
                cout << "You swim up to peer inside the cafeteria... " << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "Aside from a couple over turned tables and chairs, its completely empty" << endl;
                break;
            //Notify user that choice 2 is incorrect
            case 2: 
                cout << "You swim up to peer into the crack..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "That just leads outside the ship, that won't do" << endl;
                break;
            //Notify user that choice 4 is incorrect
            case 4:
                cout << "You swim up to the trapdoor and try to move the cask..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's too heavy, it wont budge!" << endl;
                break;
        }
        //Decrease airsupply by 10 and print user's current airsupply
        this->airSupply -= 10;
        this->getAirtank();
        //If user still has air left, reprompt them to select an entrance
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the integer corresponding to you choice \n" << endl;
            cout << "1. An entrance to the ship's cafeteria " << endl;
            cout << "2. A crack in the roof with sunlight filtering through" << endl;
            cout << "3. An door labeled \"Captain's Quarters\" " << endl;
            cout << "4. A trapdoor held down by a large cask" << endl;
            //Validate user input
            validateInt(&answer, 1, 4);
        }
    }
    //If user input was correct, lower air supply and print their current air supply
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    //If user still has air
    if (this->checkAirtank()) {
        cout << "You swim up to Captain's quarters and try to open the door..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "The door just opens up, must've been pretty bad security" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You let yourself into the Captain's quarters..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It's cluttered mess but there's plenty of things to investigate" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        //Ask them to select an item in the room to search
        cout << "Enter the integer corresponding to you choice \n" << endl;
        cout << "1. A massive wooden desk with dozens of drawers" << endl;
        cout << "2. A heavy iron safe in the corner of the room" << endl;
        cout << "3. An ornamental wooden chest with a broken lock" << endl;
        cout << "4. A bookshelf overflowing with massive books and maps" << endl;
        //Validate input 
        validateInt(&answer, 1, 4);
    }
    //If user input was incorrect and they still have air
    while (answer != 3 && this->checkAirtank()) {
        switch (answer) {
            //Notify user that choice 1 is incorrect
            case 1:
                cout << "You start opening every drawer of the desk..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's full of random nick nacks and scraps of paper this is useless!" << endl;
                break;
            //Notify user that choice 2 is incorrect
            case 2: 
                cout << "You try to turn the knob on the safe..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "It's locked! I guess some other adventurer will have to open it..." << endl;
                break;
            //Notify user that choice 4 is incorrect
            case 4:
                cout << "You pore over the dozens of books and maps..." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "They're interesting but not useful for you..." << endl;
                break;
        }
        //Decrease airsupply by 10 and print user's current airsupply
        this->airSupply -= 10;
        this->getAirtank();

        //If user still has air left, reprompt them to select an entrance
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the integer corresponding to you choice \n" << endl;
            cout << "1. A massive wooden desk with dozens of drawers" << endl;
            cout << "2. A heavy iron safe in the corner of the room" << endl;
            cout << "3. An ornamental wooden chest with a broken lock" << endl;
            cout << "4. A bookshelf overflowing with massive books and maps" << endl;
            //Validate input
            validateInt(&answer, 1, 4);
        }
    }

    //If user input was correct, lower air supply and print their current air supply
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    //If user still has air, notify them that their choice was correct, give compass and exit level
    if (checkAirtank()) {
        cout << "You try to remove the broken lock..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It comes right off! You peer inside..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You find a compass!" << endl;
        cout << "It's no treasure but it'll be pretty useful to get off this island!" << endl;
        //Put compass in player inventory
        this->character->inventory->compass++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "With your remaining air you swim to surface of the shipwreck" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }

    //If user ran out of air, notify them, decrease their health, and exit function
    if (!checkAirtank()) {
        cout << "You have run out of air!" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You lose conciousness and take 50 damage!" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        this->character->health -= 50;
        cout << "You awaken at the surface of the shipwreck..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************************************************************************
** Function name: getAirtank method
** Description: Method to print users current air supply on screen
***********************************************************************************************************************************/
void Shipwreck::getAirtank() {
    cout << "You have " << this->airSupply << "/100 air remaining in your tank.\n" << endl;
}

/*********************************************************************************************************************************
** Function name: checkAirtank method
** Description: Method to return false if airSupply drops below 0, and return true otherwise
***********************************************************************************************************************************/
bool Shipwreck::checkAirtank() {
    if (this->airSupply <= 0) {
        return false;
    }
    else {
        return true;
    }
}