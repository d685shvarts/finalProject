#include "Character.hpp"
#include "Inventory.hpp"

int main() {
    Character character;
    while (character.getAlive()) {
        character.characterMenu();
    }
    return 0;
}