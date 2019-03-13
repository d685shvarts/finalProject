#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Inventory.hpp"
#include "Space.hpp"

class Space;
class Inventory;

class Character {
private:
    int health,
        thirst,
        hunger;
    bool alive;
    Space* currentLocation;
    Inventory* inventory;
public:
    Character();
    ~Character();
    void characterMenu();
    bool getAlive();
    void setAlive(bool alive);
    Inventory* getInventory();
    void setLocation(Space* location);
    void printCharacterStats();
    void ageCharacter();
    void interactInventory();
    friend class Camp;
    friend class Jungle;
    friend class Ocean;
    friend class Shipwreck;
    friend class Volcano;
    friend class Shore;
    friend class Inventory;

};
#endif
