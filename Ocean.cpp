/***************************************************************************************************************************************
** Program name: Ocean implementation file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Derived from Space base class. Contains constructor to initialize the class with character and inventory objects to interact with
** and modify them, also will initialize the value of the boss' health, damage, and character damage. Contains virtual menu function which 
** will display options for user, and a change location method, which enables user to change their location on the map. Also contains function
** which will introduce the boss, print a picture of the boss, allow user to do battle with the boss and update user with the stats of the battle
**************************************************************************************************************************************/ 
#include "Ocean.hpp"
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
** Function name: ocean constructor
** Description: Constructor will initalize shore objects name and also pass the character and inventory object pointers the base 
** space class to initialize member variables. Will also intialize the boss health, damage, and character damage.
***********************************************************************************************************************************/
Ocean::Ocean(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Ocean";
    this->bossHealth = 100;
    this->bossDamage = 35;
    this->characterDamage = 20;
}

/*********************************************************************************************************************************
** Function name: spaceMenu method
** Description: Overridden spacemenu method which will immediately enter boss battle upon run
***********************************************************************************************************************************/
void Ocean::spaceMenu() {
    bossIntro();
}

/*********************************************************************************************************************************
** Function name: bossIntro method
** Description: Method which will set up narrative of the boss battle then run the actual battle function
***********************************************************************************************************************************/
void Ocean::bossIntro() {
    cout << "You launch your boat from the shore and set sail on the high seas!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "The water is calm! The wind is in your sails! You'll be home in no time!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "After some time, the rocking of the boat makes you tired..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Maybe you'll just shut your eyes for a little, get some well deserved rest..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You're awaken by the sudden lurching of your boat!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You look around and see the turbulent water around you, its like a boiling pot!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Suddenly several massive tentacles emerge from the water and grasp you boat!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    printBoss();
    cout << "It's a Kraken! The legend is true!" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    //Run battle function
    bossBattle();
}

/*********************************************************************************************************************************
** Function name: printBoss method
** Description: Method which will print a picture of the boss
** Citation: ASCII art obtained from http://ascii.co.uk/art/octopus
***********************************************************************************************************************************/
void Ocean::printBoss() {
    //Isn't it cute?
    cout << R"(
                        ___
                     .-'   `'.
                    /         \
                    |         ;
                    |         |           ___.--,
           _.._     |0) ~ (0) |    _.---'`__.-( (_.
    __.--'`_.. '.__.\    '--. \_.-' ,.--'`     `""`
   ( ,.--'`   ',__ /./;   ;, '.__.'`    __
   _`) )  .---.__.' / |   |\   \__..--""  """--.,_
  `---' .'.''-._.-'`_./  /\ '.  \ _.-~~~````~~~-._`-.__.'
        | |  .' _.-' |  |  \  \  '.               `~---`
         \ \/ .'     \  \   '. '-._)
          \/ /        \  \    `=.__`~-.
          / /\         `) )    / / `"".`\
    , _.-'.'\ \        / /    ( (     / /
     `--~`   ) )    .-'.'      '.'.  | (
            (/`    ( (`          ) )  '-;
             `      '-;         (-'
      
)" << '\n';
}

/*********************************************************************************************************************************
** Function name: bossBattle method
** Description: Method which will enable user to actually fight the boss. Each turn the method will prompt user to either attack the 
** boss to deal damage, or eat food to restore health. Will then deal a random int of damage to kraken or restore health. Then if Kraken
** is still alive, it will attack and deal a random int of damage. This continues until one is dead. Will output player health and food
** inventory each turn along with kraken health
***********************************************************************************************************************************/
void Ocean::bossBattle() {
    int krakenAttack,
        characterAttack,
        attackChoice;
    cout << "You must fight the Kraken to the death!" << endl;
    //While both characters are above 0 health
    while (this->character->health > 0 && this->bossHealth > 0) {
        //Prompt player to attack or eat food
        battleMenu(attackChoice);
        //If player chose attack
        if (attackChoice == 1) {
            //Generate a random int of damage to kraken based on defined character damge int
            characterAttack = 1 + rand() % this->characterDamage;
            //Output damage and subtract from boss' health
            cout << "You fire your bow and deal " << characterAttack << " damage to the kraken\n" << endl;
            this->bossHealth -= characterAttack;
        }
        //If player chose to eat food, restore 50 health
        else {
            cout << "You eat 1 food and restore some health\n" << endl;
            this->character->health += 50;
            //If new health exceeds 100, set to 100
            if (this->character->health > 100) {
                this->character->health = 100;
            }
            //Decrease players food ount
            this->character->inventory->food--;
        }
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        //If boss is still alive
        if (this->bossHealth > 0) {
            //Generate a random int of damage for boss
            krakenAttack = 1 + rand() % this->bossDamage;
            //Subtract that damage from character's health
            cout << "The Kraken lashes out and deals " << krakenAttack << " damage to you\n" << endl;
            this->character->health -= krakenAttack;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        //Ootput current health and food count
        battleStats();
        
    }

    //If boss is 0 or below health
    if (this->bossHealth <= 0) {
        cout << "You have defeated the Kraken!" << endl;
        //Change wonGame bool to true which will play victory function in main
        this->character->wonGame = true;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    //If player is below 0 health
    else {
        cout << "The kraken has slain you!" << endl;
        //Change alive bool to false which will end game
        this->character->alive = false;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        
    }
}

/*********************************************************************************************************************************
** Function name: bossBattle method
** Description: Method which will offer use choice to eat food or attack boss. Will be used by battle function to do battle. 
** Its argument is a reference to an int the battle function which will be changed based on user input. Also validates user input.
***********************************************************************************************************************************/
void Ocean::battleMenu(int& menuChoice) {
    //Prompt user to select an option
    cout << "What would you like to do?" << endl;
    cout << "1. Shoot Kraken" << endl;
    cout << "   - Will shoot kraken with bow and arrow to deal damage" << endl;
    cout << "2. Eat food" << endl;
    cout << "   - Eat food to restore your own health" << endl;
    //Validate user input
    validateInt(&menuChoice, 1, 2);
}

/*********************************************************************************************************************************
** Function name: battleStats method
** Description: Method which willupdate user with their current health, remaining food, and krakens health
***********************************************************************************************************************************/
void Ocean::battleStats() {
    cout << "Your Health: " << this->character->health << "/100" << endl;
    cout << "Food Remaining: " << this->character->inventory->food << "\n" << endl;

    cout << "Kraken Health: " << this->bossHealth << "/100" << endl;
    printBoss();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

}

