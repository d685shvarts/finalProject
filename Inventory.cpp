#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>

using std::endl;
using std::cout;

Inventory::Inventory() {
    cout << "Initializing Inventory" << endl;
    this->capacity = 50;
    this->food = this->water = this->trap = this->torch = 
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
    cout << "7. Airtanks: " << this->airtank << endl;
    validateInt(&chooseItem, 1, 7);

    switch (chooseItem) {
        case 1:
            cout << "How much food would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->food - quantity >= 0) {
                this->food -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 2:
            cout << "How much water would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->water - quantity >= 0) {
                this->water -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 3:
            cout << "How many traps would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->trap - quantity >= 0) {
                this->trap -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 4:
            cout << "How many torches would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->torch - quantity >= 0) {
                this->torch -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 5:
            cout << "How much wood would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->wood - quantity >= 0) {
                this->wood -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 6:
            cout << "How much plastic would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->plastic - quantity >= 0) {
                this->plastic -= quantity;
                this->weight -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 7:
            cout << "How many airtanks would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->airtank - quantity >= 0) {
                this->airtank -= quantity;
                this->airtank -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
    }
    cout << "Exiting drop items screen" << endl;

}

int Inventory::getPlastic() {
    return this->plastic;
}

int Inventory::getWood() {
    return this->wood;
}

void Inventory::setPlastic(int plastic) {
    this->plastic += plastic;
    this->weight += plastic;
    exceedCapacity();
}


void Inventory::setWood(int wood) {
    this->wood += wood;
    this->weight += wood;
    exceedCapacity();
}

void Inventory::setAirtank(int airtank) {
    this->airtank += airtank;
    this->weight += airtank;
    exceedCapacity();
}

void Inventory::setTorch(int torch) {
    this->torch += torch;
    this->weight += torch;
    exceedCapacity();
}

void Inventory::setTrap(int trap) {
    this->trap += trap;
    this->weight += trap;
    exceedCapacity();
}

void Inventory::exceedCapacity() {
    if (this->weight > this-> capacity){
        cout << "You are holding too many items, you must drop some" << endl;
        dropItems();
    }
}