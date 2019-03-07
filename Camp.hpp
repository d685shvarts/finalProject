#ifndef CAMP_HPP
#define CAMP_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Camp : public Space {
public:
    Camp(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void craft();
    void changeLocation();
};
#endif