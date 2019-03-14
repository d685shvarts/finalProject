#ifndef SPACE_HPP
#define SPACE_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include <string>

using std::string;
class Character;
class Inventory;

class Space {
protected: 
    Space* top,
        *left,
        *right,
        *bottom;
    string name;
    Inventory* inventory;
    Character* character;
public:
    Space(Inventory* inventory, Character* character);
    void addTop(Space* top);
    void addBottom(Space* bottom );
    void addLeft(Space* left);
    void addRight(Space* right);
    string getName();
    virtual void spaceMenu() = 0;
    void printLocation();

};
#endif