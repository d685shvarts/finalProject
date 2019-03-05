#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>

using std::endl;
using std::cout;

Inventory::Inventory() {
    cout << "Initializing Inventory" << endl;
    this->capacity = 20;
    this->food = this->water = this->trap = this->torch = this->axe = 
    this->airtank = this->weight = this->wood = this->plastic =  0;
}

void Inventory::printInventory() {
    cout << "Your capacity is: " << this->weight << "/" << this->capacity << endl;
    cout << "Your inventory contains: " << endl;
    cout << "Food: " << this->food << endl;
    cout << "Water: " << this->water << endl;
    cout << "Traps: " << this->trap << endl;
    cout << "Torches: " << this->torch << endl;
    cout << "Wood: " << this-> wood << endl;
    cout << "Plastic: " << this-> plastic << endl;
    cout << "Axe: " << this->axe << endl;
    cout << "Airtank: " << this->airtank << endl;
}

void Inventory::dropItems() {
    int chooseItem,
        quantity;
    cout << "Which items would you like to drop?" << endl;
    cout << "1. Food: " << this->food << endl;
    cout << "2. Water: " << this->water << endl;
    cout << "3. Traps: " << this->trap << endl;
    cout << "4. Torches: " << this->torch << endl;
    cout << "5. Wood: " << this-> wood << endl;
    cout << "6. Plastic: " << this-> plastic << endl;
    validateInt(&chooseItem, 1, 6);

    switch (chooseItem) {
        case 1:
            cout << "How much food would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->food -= quantity;
            if (this->food < 0) {
                cout << "You cant drop that much food, setting food to 0" << endl;
                this->food = 0;
            }
            break;
        case 2:
            cout << "How much water would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->water -= quantity;
            if (this->water < 0) {
                cout << "You cant drop that much water, setting water to 0" << endl;
                this->water = 0;
            }
            break;
        case 3:
            cout << "How many traps would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->trap -= quantity;
            if (this->trap < 0) {
                cout << "You cant drop that many traps, setting traps to 0" << endl;
                this->trap = 0;
            }
            break;
        case 4:
            cout << "How many torches would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->torch -= quantity;
            if (this->torch < 0) {
                cout << "You cant drop that many torches, setting torches to 0" << endl;
                this->torch = 0;
            }
            break;
        case 5:
            cout << "How much wood would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->wood -= quantity;
            if (this->wood < 0) {
                cout << "You cant drop that much wood, setting wood to 0" << endl;
                this->wood = 0;
            }
            break;
        case 6:
            cout << "How much plastic would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            this->plastic -= quantity;
            if (this->plastic < 0) {
                cout << "You cant drop that much plastic, setting plastic to 0" << endl;
                this->plastic = 0;
            }
            break;
    }

}


