#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>

using std::endl;
using std::cout;

Inventory::Inventory(Character* character) {
    cout << "Initializing Inventory" << endl;
    this->capacity = 50;
    this->food = this->water = this->compass = this->bowAndArrows = this->boat =
    this->airtank = this->weight = this->wood = this->plastic = this->axe =  0;
    this->character = character;
}

void Inventory::printInventory() {
    this->weight = this->food + this->water + this->plastic + this->wood + this->bowAndArrows
    + this->axe + this->compass + this->airtank + this->boat;

    cout << "Your capacity is: " << this->weight << "/" << this->capacity << endl;
    cout << "Your inventory contains: " << endl;
    cout << "Food: " << this->food << endl;
    cout << "Water: " << this->water << endl;
    cout << "Plastic: " << this-> plastic << endl;
    cout << "Wood: " << this-> wood << endl;
    cout << "Bow and Arrows: " << this->bowAndArrows << endl;
    cout << "Axe: " << this->axe << endl;
    cout << "Compass: " << this->compass << endl;
    cout << "Airtank: " << this->airtank << endl;
    cout << "Boat: " << this->boat << endl;
}

void Inventory::dropItems() {
    int chooseItem,
        quantity;
    cout << "Which items would you like to drop?" << endl;
    cout << "1. Food: " << this->food << endl;
    cout << "2. Water: " << this->water << endl;
    cout << "3. Plastic: " << this->plastic << endl;
    cout << "4. Wood: " << this->wood << endl;
    cout << "5. Bow And Arrows: " << this->bowAndArrows << endl;
    cout << "6. Axe: " << this->axe << endl;
    cout << "7. Compass: " << this->compass << endl;
    cout << "8. Airtank: " << this->airtank << endl;
    validateInt(&chooseItem, 1, 7);

    switch (chooseItem) {
        case 1:
            cout << "How much food would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->food - quantity >= 0) {
                this->food -= quantity;
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
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 3:
            cout << "How much plastic would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->plastic - quantity >= 0) {
                this->plastic -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 4:
            cout << "How much wood would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            if (this->wood - quantity >= 0) {
                this->wood -= quantity;
            }
            else {
                cout << "You cant drop that many items" << endl;
            }
            break;
        case 5:
            cout << "Do you really want to drop your bow and arrows?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            if (quantity == 1 && this->bowAndArrows > 0) {
                this->bowAndArrows--;
            }
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            else {
                cout << "You dont have bow and arrows to drop" << endl;
            }
            break;
        case 6:
            cout << "Do you really want to drop you axe?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            if (quantity == 1 && this->axe > 0) {
                this->axe--;
            }
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            else {
                cout << "You don't have an axe to drop" << endl;
            }
            break;
        case 7:
            cout << "Do you really want to drop you compass?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            if (quantity == 1 && this->compass > 0) {
                this->compass--;
            }
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            else {
                cout << "You don't have a compass to drop" << endl;
            }
            break;
        case 8:
            cout << "Do you really want to drop you airtank?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            if (quantity == 1 && this->airtank > 0) {
                this->airtank--;
            }
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            else {
                cout << "You don't have an airtank to drop" << endl;
            }
            break;
    }
    cout << "Exiting drop items menu" << endl;
}

void Inventory::exceedCapacity() {
    while (this->weight > this->capacity){
        cout << "You are holding too many items, you must drop some" << endl;
        dropItems();
    }
}