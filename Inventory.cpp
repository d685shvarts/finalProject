/***************************************************************************************************************************************
** Program name: Inventory header file
** Author: Daniel Shvarts
** Date: 03/19/2019
** Description: Inventory class which will be used by character class to store, access, view and modify items in the inventory. Contains 
** constructor to initialize each of the item counts, function to print contents of inventory, function to enable use to drop items, 
** and function to check whether current inventory weight exceeds capacity.
**************************************************************************************************************************************/ 
#include "Inventory.hpp"
#include "Menu.hpp"
#include <iostream>
#include <limits>

using std::streamsize;
using std::cin;
using std::endl;
using std::cout;


/*********************************************************************************************************************************
** Function name: Inventory constructor
** Description: Constructor will initalize each int variable within the inventory class
***********************************************************************************************************************************/
Inventory::Inventory() {
    //Max inventory capacity set to 0
    this->capacity = 100;
    //Each item count and current weight set to 0
    this->food = this->water = this->compass = this->bowAndArrows = this->boat =
    this->airtank = this->weight = this->wood = this->plastic = this->axe =  0;
}

/*********************************************************************************************************************************
** Function name: printInventory method
** Description: Method to print the item count of each item in the inventory along with the current number of items in inventory
***********************************************************************************************************************************/
void Inventory::printInventory() {
    //Calculate current item total in inventory
    this->weight = this->food + this->water + this->plastic + this->wood + this->bowAndArrows
    + this->axe + this->compass + this->airtank + this->boat;
    //Output item total
    cout << "Your inventory is: " << this->weight << "/" << this->capacity << " full" << endl;
    //Output item count of each item in inventory
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
    cout << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

/*********************************************************************************************************************************
** Function name: dropItems method
** Description: Method to enable user to drop items in inventory. Will prompt user to select a item type, validate user input, 
** then ask how many items user wants to drop, then check whether user has enough of that item to drop, if yes it will lower item count
** by that amount.
***********************************************************************************************************************************/
void Inventory::dropItems() {
    int chooseItem,
        quantity;
    //Output current contents of inventory and ask which item user wants to drop
    cout << "Which items would you like to drop?" << endl;
    cout << "1. Food: " << this->food << endl;
    cout << "2. Water: " << this->water << endl;
    cout << "3. Plastic: " << this->plastic << endl;
    cout << "4. Wood: " << this->wood << endl;
    cout << "5. Bow And Arrows: " << this->bowAndArrows << endl;
    cout << "6. Axe: " << this->axe << endl;
    cout << "7. Compass: " << this->compass << endl;
    cout << "8. Airtank: " << this->airtank << endl;
    //Validate input
    validateInt(&chooseItem, 1, 8);

    switch (chooseItem) {
        //If user selected food
        case 1:
            //Ask how much food user wants to drop
            cout << "How much food would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            //Check if user has that much food to drop and reprompt user if not
            while (this->food - quantity < 0) {
                cout << "You cant drop that many items" << endl;
                cout << "How much food would you like to drop? "<< endl;
                validateInt(&quantity, 1, this->capacity);
            }
            //Subtract user specified quantity from item count
            this->food -= quantity;
            break;
        //If user selected water
        case 2:
            //Ask how much water user wants to drop
            cout << "How much water would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            //Check if user has that much water to drop and reprompt user if not
            while (this->water - quantity < 0) {
                cout << "You cant drop that many items" << endl;
                cout << "How much water would you like to drop? "<< endl;
                validateInt(&quantity, 1, this->capacity);
            }
            //Subtract user specified quantity from item count
            this->water -= quantity;
            break;
        //If user selected plastic
        case 3:
            //Ask how much plastic user wants to drop
            cout << "How much plastic would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            //Check if user has that much plastic to drop and reprompt user if not
            while (this->plastic - quantity < 0) {
                cout << "You cant drop that many items" << endl;
                cout << "How much plastic would you like to drop?" << endl;
                validateInt(&quantity, 1, this->capacity);
            }
            //Subtract user specified quantity from item count
            this->plastic -= quantity;
            break;
        //If user selected wood
        case 4:
            //Ask how much wood user wants to drop
            cout << "How much wood would you like to drop?" << endl;
            validateInt(&quantity, 1, this->capacity);
            //Check if user has that much wood to drop and reprompt user if not
            while (this->wood - quantity < 0) {
                cout << "You cant drop that many items" << endl;
                cout << "How much wood would you like to drop?" << endl;
                validateInt(&quantity, 1, this->capacity);
            }
            //Subtract user specified quantity from item count
            this->wood -= quantity;
            break;
        //If user selected bow and arrows
        case 5: 
            //Verify that user wants to drop bow and arrows
            cout << "Do you really want to drop your bow and arrows?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            //If user wants to drop item and has more than 0, decrease item count by 1
            if (quantity == 1 && this->bowAndArrows > 0) {
                this->bowAndArrows--;
            }
            //If user does not want to drop item, do nothing
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            //If user does not have at least 1 item, do nothing
            else {
                cout << "You dont have bow and arrows to drop" << endl;
            }
            break;
        //If user selected axe
        case 6:
            //Verify that user wants to drop item
            cout << "Do you really want to drop you axe?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            //If user wants to drop item and has more than 0, decrease item count by 1
            if (quantity == 1 && this->axe > 0) {
                this->axe--;
            }
            //If user does not want to drop item, do nothing
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            //If user does not have at least 1 item, do nothing
            else {
                cout << "You don't have an axe to drop" << endl;
            }
            break;
        //If user selected compass
        case 7:
            //Verify that user wants to drop item
            cout << "Do you really want to drop you compass?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            //If user wants to drop item and has more than 0, decrease item count by 1
            if (quantity == 1 && this->compass > 0) {
                this->compass--;
            }
            //If user does not want to drop item, do nothing
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            //If user does not have at least 1 item, do nothing
            else {
                cout << "You don't have a compass to drop" << endl;
            }
            break;
        //If user selected airtank
        case 8:
            //Verify that user wants to drop item
            cout << "Do you really want to drop you airtank?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            validateInt(&quantity, 1, 2);
            //If user wants to drop item and has more than 0, decrease item count by 1
            if (quantity == 1 && this->airtank > 0) {
                this->airtank--;
            }
            //If user does not want to drop item, do nothing
            else if (quantity == 2) {
                cout << "Exiting drop menu" << endl;
            }
            //If user does not have at least 1 item, do nothing
            else {
                cout << "You don't have an airtank to drop" << endl;
            }
            break;
    }
    //Recalculate weight
    this->weight = this->food + this->water + this->plastic + this->wood + this->bowAndArrows
    + this->axe + this->compass + this->airtank + this->boat;
}


/*********************************************************************************************************************************
** Function name: exceedCapacity method
** Description: Method to force user to drop items if their current item count exceeds the inventory capacity. Will compare item count
** to designated capacity, and run dropItems function until the current item count is less than inventory capacity
***********************************************************************************************************************************/
void Inventory::exceedCapacity() {
    //Recalculated weight
    this->weight = this->food + this->water + this->plastic + this->wood + this->bowAndArrows
    + this->axe + this->compass + this->airtank + this->boat;
    //While current item count exceeds inventory capacity, run dropItems
    while (this->weight > this->capacity) {
        cout << "Your inventory is: " << this->weight << "/" << this->capacity << " full" << endl;
        cout << "You are holding too many items, you must drop some" << endl;
        dropItems();
    }
} 