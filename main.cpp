#include "Character.hpp"
#include "Inventory.hpp"
#include "Camp.hpp"
#include "Volcano.hpp"
#include "Jungle.hpp"
#include "Shore.hpp"
#include "Shipwreck.hpp"
#include "Ocean.hpp"
#include <iostream>

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




    while (character.getAlive() && character.getSpace() != "Ocean") {
        character.characterMenu();
        if (character.getAlive()) {
            character.ageCharacter();
            character.interactInventory();
        }
    }

    if (character.getAlive()) {
        cout << "\nYour character has died. Game Over!" << endl;
    }

    return 0;
}