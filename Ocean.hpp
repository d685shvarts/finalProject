#ifndef OCEAN_HPP
#define OCEAN_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Ocean : public Space {
public:
    Ocean(Inventory* inventory, Character* character);
    virtual void spaceMenu();
};
#endif