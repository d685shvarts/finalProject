#ifndef JUNGLE_HPP
#define JUNGLE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Character;
class Inventory;

class Jungle : public Space {
public:
    Jungle(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void changeLocation();
    void chopWood();
};
#endif