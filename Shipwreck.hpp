#ifndef SHIPWRECK_HPP
#define SHIPWRECK_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Shipwreck : public Space {
protected:
    int airSupply;
public:
    Shipwreck(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void changeLocation();
    void dive();
    void getAirtank();
    bool checkAirtank();
};
#endif