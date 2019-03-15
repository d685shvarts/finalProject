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

Ocean::Ocean(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Ocean";
    this->bossArms = 8;
    this->bossHealth = 100;
    this->bossDamage = 10;
    this->characterDamage = 10;
}

void Ocean::spaceMenu() {
    bossIntro();

}

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
    bossBattle();



}


void Ocean::printBoss() {
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

void Ocean::bossBattle() {
    int krakenAttack,
        characterAttack,
        attackChoice;
    cout << "You must fight the Kraken to the death!" << endl;
    while (this->character->health > 0 && this->bossHealth > 0) {
        battleMenu(attackChoice);
        if (attackChoice == 1) {
            characterAttack = 1 + rand() % this->characterDamage;
            cout << "You fire your bow and deal " << characterAttack << " damage to the kraken\n" << endl;
            this->bossHealth -= characterAttack;
        }
        else {
            cout << "You eat 1 food and restore some health\n" << endl;
            this->character->health += 50;
            if (this->character->health > 100) {
                this->character->health = 100;
            }
            this->character->inventory->food--;
        }
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        if (this->bossHealth > 0) {
            krakenAttack = 1 + rand() % this->bossDamage;
            cout << "The Kraken lashes out and deals " << krakenAttack << " damage to you\n" << endl;
            this->character->health -= krakenAttack;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        battleStats();
        
    }

    if (this->bossHealth <= 0) {
        cout << "You have defeated the Kraken!" << endl;
        this->character->wonGame = true;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    else {
        cout << "The kraken has slain you!" << endl;
        this->character->alive = false;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        
    }


}

void Ocean::battleMenu(int& menuChoice) {
    cout << "What would you like to do?" << endl;
    cout << "1. Shoot Kraken" << endl;
    cout << "   - Will shoot kraken with bow and arrow to deal damage" << endl;
    cout << "2. Eat food" << endl;
    cout << "   - Eat food to restore your own health" << endl;
    validateInt(&menuChoice, 1, 2);
}

void Ocean::battleStats() {
    cout << "Your Health: " << this->character->health << "/100" << endl;
    cout << "Food Remaining: " << this->character->inventory->food << "\n" << endl;

    cout << "Kraken Health: " << this->bossHealth << "/100" << endl;
    printBoss();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

}

