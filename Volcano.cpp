/***************************************************************************************************************************************
** Program name: Volcano implementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact
** and modify them. Contains virtual menu function which will display options for user, volcanoRiddle method to have user play a game
** of riddles to get a reward, and finally a change location method, which enables user to change their location on the map
**************************************************************************************************************************************/ 
#include "Volcano.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
#include <limits>

using std::streamsize;
using std::endl;
using std::cout;
using std::cin;

/*********************************************************************************************************************************
** Function name: Volcano constructor
** Description: Constructor will initalize volcano objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables.
***********************************************************************************************************************************/
Volcano::Volcano(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Volcano";
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overriden method from base class, which dispays options user has to interact with current space. Prompts user to either
** change their location on the island or interact with current space by entering volcano and then run functions to accomplish users
** choice
***********************************************************************************************************************************/
void Volcano::spaceMenu() {
    int menuChoice;
    //Prompt user to select a choice
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "   - Travel to a new location on the island" << endl;
    cout << "2. Approach Volcano" << endl;
    cout << "   - Investigate the mysterious volcano" << endl;
    //Validate input
    validateInt(&menuChoice, 1, 2);
    //Run method corresponding to user input
    if (menuChoice == 1) {
        changeLocation();
    }
    else if (menuChoice == 2) {
        volcanoRiddle();
    }
}

/*********************************************************************************************************************************
** Function name: changeLocation method
** Description: Prompt user to select from one of the neighboring spaces and then will change characters current location accordingly.
** Will also make sure user has the items required to travel to selected space.
***********************************************************************************************************************************/
void Volcano::changeLocation() {
    int location;
    //Prompt user to select location to travel to
    cout << "Where would you like to travel?" << endl;
    cout << "1. Camp" << endl;
    cout << "   - Base camp to craft new items" << endl;
    cout << "2. Don't travel" << endl;
    //Validate input
    validateInt(&location, 1, 2);
    switch (location) {
        //If user selects camp
        case 1:
            //Change location to camp, and output position on map
            this->character->currentLocation = this->top;
            this->character->currentLocation->printLocation();
            break;
        //If user doesnt want to travel
        case 2:
            //Do nothing
            cout << "You stay where you are" << endl;
            break;
    }
}

/*********************************************************************************************************************************
** Function name: volcanoRiddle method
** Description: Method that will engage the user in a game of riddles in order to gain an item necessry to win game. User will be 
** given a riddle and then a set of possible answers to choose from. User's answer will be validated, if incorrect they will take damage
** and exit method, otherwise they will continue untill they win.
***********************************************************************************************************************************/
void Volcano::volcanoRiddle() {
    int answer;
    //Print narrative on screen
    cout << "Press enter to iterate through this level. \n" << endl;
    cout << "You see small entrance hidden behind some brush..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You peek inside the entrance and see a dark unlit tunnel.." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You crawl through the entrance and begin carefully feeling your way through the tunnel..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Suddenly, the ground gives way under your feet and you plummet into darkness!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You hit your head during the fall and lose conciousness..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You awaken to a massive being hovering above you!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Spirit: \"It has been a long time since I've met one of your kind.\"" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Spirit: \"It's been awfully lonely down here, wont you play a game of riddles with me?\"" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Spirit: \"I'll give you a handsome reward if you succeed!\"" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Spirit: \"Let's begin!\"" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    //Print riddle on screen
    cout << "\"What has roots as nobody sees, " << endl;
    cout << "Is taller that trees," << endl;
    cout << "Up, up it goes," << endl;
    cout << "and yet never grows?\"" << endl;
    cout << endl;
    //Print answer choices on screen
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Tree" << endl;
    cout << "2. Mountain" << endl;
    cout << "3. Cloud" << endl;
    cout << "4. Bird" << endl;
    //Validate user input
    validateInt(&answer, 1, 4);
    //If correct input, notify user and continue
    if (answer == 2) {
        cout << endl;
        cout << "Spirit: \"Correct! You're more clever than you look!" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    //Otherwise tell user their input was incorrect, lower their health and exit method
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        return;
    }
    //Print riddle on screen
    cout << "Spirit: \"Let's try something a little harder...\"" << endl;
    cout << "\"Thirty white horses on a red hill, " << endl;
    cout << "First they champ, " << endl;
    cout << "Then they stamp, " << endl;
    cout << "Then they stand still.\"" << endl;
    cout << endl;
    //Print answer choices on screen
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Daisies" << endl;
    cout << "2. Rain" << endl;
    cout << "3. Snow" << endl;
    cout << "4. Teeth" << endl;
    //Validate user input
    validateInt(&answer, 1, 4);
    //If correct input, notify user and continue
    if (answer == 4) {
        cout << endl;
        cout << "Spirit: \"Correct again! How wise!\"" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    //Otherwise tell user their input was incorrect, lower their health and exit method
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        return;
    }
    //Print riddle on screen
    cout << "Spirit: \"I'll have to give you my hardest riddle yet!" << endl;
    cout << "\"Voiceless it cries, " << endl;
    cout << "Wingless flutters," << endl;
    cout << "toothless bites," << endl;
    cout << "Mouthless mutters.\"" << endl;
    cout << endl;
    //Print answer choices on screen
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Time" << endl;
    cout << "2. Echo" << endl;
    cout << "3. Wind" << endl;
    cout << "4. Reflection" << endl;
    //Validate user input
    validateInt(&answer, 1, 4);
    //If correct input, notify user and give them an axe 
    if (answer == 3) {
        cout << endl;
        cout << "Spirit: \"No one's ever managed to answer all of my riddles!\"" << endl;
        cout << "\"For winning my riddle game, I'll give you this ancient axe!\"" << endl;
        this->inventory->axe++;
        cout << "You recieve a magical axe from the spirit." << endl;
        cout << "You can use this axe to enter new areas and get new items!" << endl;
        cout << "The spirit escorts you outside the volcano" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    //Otherwise tell user their input was incorrect, lower their health and exit method
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        return;
    }
}
