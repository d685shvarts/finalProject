#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Character.hpp"
class Inventory;
class Character;
class Inventory {
protected:
    int capacity,
        weight,
        food,
        water,
        wood,
        plastic,
        trap,
        torch,
        boat,
        axe,
        bowAndArrows,
        compass,
        airtank;
    Character* character;
public:
    Inventory(Character* character);
    void printInventory();
    void dropItems();
    void exceedCapacity();
    friend class Character;
    friend class Volcano;
    friend class Jungle;
    friend class Camp;
    friend class Shipwreck;
    friend class Shore;

};
#endif