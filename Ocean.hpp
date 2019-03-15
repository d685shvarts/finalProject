#ifndef OCEAN_HPP
#define OCEAN_HPP
#include "Inventory.hpp"
#include "Character.hpp"
#include "Space.hpp"

class Ocean : public Space {
private:
    int bossArms,
        bossHealth,
        bossDamage,
        characterDamage;
public:
    Ocean(Inventory* inventory, Character* character);
    virtual void spaceMenu();
    void bossIntro();
    void bossBattle();
    void battleMenu(int& menuChoice);
    void battleStats();
    void printBoss();
};
#endif