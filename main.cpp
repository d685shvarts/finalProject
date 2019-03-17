/***************************************************************************************************************************************
** Program name: main File
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Main program file that will run the Island survival and escape game. The program will ask user whether they want to 
** play and if yes will initialize character, inventory and space objects and link them together. Will then continue running the game as
** long as character is alive and user wants to keep playing. Loop will continue until player wins game by accomplishing the stated objective.
** To run enter "make" to compile and enter "final" to run program.
**************************************************************************************************************************************/ 
#include "Character.hpp"
#include "Inventory.hpp"
#include "Camp.hpp"
#include "Volcano.hpp"
#include "Jungle.hpp"
#include "Shore.hpp"
#include "Shipwreck.hpp"
#include "Ocean.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <limits>

using std::streamsize;
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::srand;

int main() {
    
    //Ask user whether they would like to playgame, if yes run game
    if (startGame()) {
        srand(time(NULL));
        //Initialize character class
        Character character;
        //Initialize each of the derived space classes
        Camp camp(character.getInventory(), &character);
        Volcano volcano(character.getInventory(), &character);
        Jungle jungle(character.getInventory(), &character);
        Shore shore(character.getInventory(), &character);
        Shipwreck shipwreck(character.getInventory(), &character);
        Ocean ocean(character.getInventory(), &character);

        //Link camp space pointers to other spaces
        camp.addBottom(&volcano);
        camp.addRight(&jungle);
        camp.addTop(&shore);

        //Link jungle space pointers to other spaces
        jungle.addLeft(&camp);

        //Link volcano space pointers to other spaces
        volcano.addTop(&camp);

        //Link shore space pointers to other spaces
        shore.addBottom(&camp);
        shore.addTop(&ocean);
        shore.addLeft(&shipwreck);

        //Link shipwreck space pointers to other spaces
        shipwreck.addRight(&shore);

        //Set initial location of character to camp space
        character.setLocation(&camp);

        //Introduce user to game, and give them objective of game
        gameIntro();

        //Displayer character stats and location for user
        character.printCharacterStats();
        character.printLocation();

        //While the character is still alive and has not won the game
        while (character.getAlive() && !character.getWonGame()) {
            //Display character menu which enables user to interact with spaces to quit game
            character.characterMenu();
            //If the character is still alive and has not won the game
            if (character.getAlive() && !character.getWonGame()) {
                //Check and modify characters health, hunger and thirst, this is the step limit!
                character.ageCharacter();
            }
            //If the character is still alive and has not won the game
            if (character.getAlive() && !character.getWonGame()) {
                //Displays contents of inventory and make sure it does not exceed the inventory capacity
                character.interactInventory();
            }
        }

        //Let user know if they have died
        if (!character.getAlive()) {
            cout << "\nYour character has died. Game Over!" << endl;
        }
        //If character is alive and has won game, print final text and congratulate user!
        if (character.getAlive() && character.getWonGame()) {
            cout << "With the Kraken slain, you sail away towards the sun!" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "You arrive to your village just before sunset" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Your village rejoices to see you and hails you as a hero for slaying the Kraken!" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Congratulations on winning the game! Thanks for playing!" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}