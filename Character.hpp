#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Inventory.hpp"
#include "Space.hpp"

class Space;

class Character {
private:
    int health,
        thirst,
        hunger;
    bool hasAxe,
        hasBoat,
        hasBowAndArrows,
        hasCompass,
        hasAirtank,
        alive;
    Space* currentLocation;
    Inventory inventory;
public:
    Character();
    void characterMenu();
    bool getAlive();
    void setBoat(bool boat);
    void setAxe(bool axe);
    void setCompass(bool compass);
    void setAlive(bool alive);
    Inventory* getInventory();
    void setLocation(Space* location);
    friend class Camp;
    friend class Jungle;
    friend class Ocean;
    friend class Shipwreck;
    friend class Volcano;
    friend class Shore;
    friend class Inventory;

};
#endif
