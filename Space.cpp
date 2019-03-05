#include "Space.hpp"
#include <string>

using std::string;

Space::Space() {
    this->top = nullptr;
    this->right = nullptr;
    this->bottom = nullptr;
    this->left = nullptr;

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