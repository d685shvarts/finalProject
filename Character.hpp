#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Inventory.hpp"

class Character {
private:
    int health,
        thirst,
        hunger;
    bool hasAxe,
        hasFishingPole,
        hasBoat,
        hasDesalinator,
        hasAirtank,
        alive;
    Inventory inventory;
public:
    Character();
    void characterMenu();
    bool getAlive();

};
#endif
