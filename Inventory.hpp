#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Character.hpp"
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
    friend class Character;
    int getPlastic();
    void setPlastic(int plastic);
    int getWood();
    void setWood(int wood);
    void setAirtank(int airtank);
    void setTorch(int torch);
    void setTrap(int trap);
    void exceedCapacity();
    friend class Volcano;
    friend class Camp;
    friend class Shipwreck;
    friend class Shore;

};
#endif