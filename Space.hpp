#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>

using std::string;
class Space {
private: 
    Space* top,
        *left,
        *right,
        *bottom;
    string name;
public:
    Space();
    void addTop(Space* top);
    void addBottom(Space* bottom );
    void addLeft(Space* left);
    void addRight(Space* right);
    virtual void spaceMenu() = 0;

};
#endif