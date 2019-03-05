#ifndef INVENTORY_HPP
#define INVENTORY_HPP
class Inventory {
private:
    int capacity,
        weight,
        food,
        water,
        wood,
        plastic,
        trap,
        torch,
        axe,
        airtank;
public:
    Inventory();
    void printInventory();
    void dropItems();
    friend class Character;
};
#endif