#include "Space.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>


using std::cout;
using std::endl;
using std::string;

Space::Space(Inventory* inventory, Character* character) {
    this->top = nullptr;
    this->right = nullptr;
    this->bottom = nullptr;
    this->left = nullptr;
    this->inventory = inventory;
    this->character = character;

    this->name = "unitialized...";
}

void Space::addTop(Space* top) {
    this->top = top;
}
void Space::addBottom(Space* bottom) {
    this->bottom = bottom;
}
void Space::addLeft(Space* left) {
    this->left = left;
}
void Space::addRight(Space* right) {
    this->right = right;
}

void Space::printLocation() {
    cout << "Your current location is: " << this->name << endl;
    if (this->right != nullptr) {
        cout << "Right: " << this->right->name << endl;
    }
    if (this->left != nullptr) {
        cout << "Left: " << this->left->name << endl;
    }
    if (this->top != nullptr) {
        cout << "Top: " << this->top->name << endl;
    }
    if (this->bottom != nullptr) {
        cout << "Bottom: " << this->bottom->name << endl;
    }

}
