#include "Character.hpp"
#include "Inventory.hpp"
#include "Camp.hpp"
#include "Volcano.hpp"
#include "Jungle.hpp"
#include "Shore.hpp"
#include "Shipwreck.hpp"
#include "Ocean.hpp"
#include <iostream>
#include <string>
#include <limits>

using std::streamsize;
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main() {
    Character character;
    Camp camp(character.getInventory(), &character);
    Volcano volcano(character.getInventory(), &character);
    Jungle jungle(character.getInventory(), &character);
    Shore shore(character.getInventory(), &character);
    Shipwreck shipwreck(character.getInventory(), &character);
    Ocean ocean(character.getInventory(), &character);

    camp.addBottom(&volcano);
    camp.addRight(&jungle);
    camp.addTop(&shore);

    jungle.addLeft(&camp);

    volcano.addTop(&camp);

    shore.addBottom(&camp);
    shore.addTop(&ocean);
    shore.addLeft(&shipwreck);

    shipwreck.addRight(&shore);

    character.setLocation(&camp);




    while (character.getAlive() && !character.getWonGame()) {
        character.characterMenu();
        if (character.getAlive() && !character.getWonGame()) {
            character.ageCharacter();
            character.interactInventory();
        }
    }

    if (!character.getAlive()) {
        cout << "\nYour character has died. Game Over!" << endl;
    }
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

    return 0;
}