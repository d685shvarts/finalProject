#ifndef VOLCANO_HPP
#define VOLCANO_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Volcano : public Space {
public:
    Volcano(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void changeLocation();
    void volcanoRiddle();
};
#endif