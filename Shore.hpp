#ifndef SHORE_HPP
#define SHORE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Shore.hpp"

class Shore : public Space {
public:
    Shore(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void scavengeSupplies();
    void changeLocation();
};
#endif