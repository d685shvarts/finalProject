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
        airtank;
public:
    Inventory();
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

};
#endif