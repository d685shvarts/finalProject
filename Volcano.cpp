#include "Volcano.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;


Volcano::Volcano(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Volcano";
}

void Volcano::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "2. Approach Volcano" << endl;
    validateInt(&menuChoice, 1, 3);
    if (menuChoice == 1) {
        changeLocation();
    }
    else if (menuChoice == 2) {
        volcanoRiddle();
    }

}

void Volcano::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Camp" << endl;
    cout << "2. Don't travel" << endl;
    validateInt(&location, 1, 2);
    switch (location) {
        case 1:
            this->character->currentLocation = this->top;
            this->character->currentLocation->printLocation();
            break;
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}

void Volcano::volcanoRiddle() {
    int answer;
    cout << "You see small entrance hidden behind some brush..." << endl;
    cin.ignore();
    cout << "You peek inside the entrance and see a dark unlit tunnel.." << endl;
    cin.ignore();
    cout << "You crawl through the entrance and begin carefully feeling your way through the tunnel..." << endl;
    cin.ignore();
    cout << "Suddenly, the ground gives way under your feet and you plummet into darkness!" << endl;
    cin.ignore();
    cout << "You hit your head during the fall and lose conciousness..." << endl;
    cin.ignore();
    cout << "You awaken to a massive being hovering above you!" << endl;
    cin.ignore();
    cout << "Spirit: \"It has been a long time since I've met one of your kind.\"" << endl;
    cin.ignore();
    cout << "Spirit: \"It's been awfully lonely down here, wont you play a game of riddles with me?\"" << endl;
    cin.ignore();
    cout << "Spirit: \"I'll give you a handsome reward if you succeed!\"" << endl;
    cin.ignore();
    cout << "Spirit: \"Let's begin!\"" << endl;
    cin.ignore();
    cout << "\"What has roots as nobody sees, " << endl;
    cout << "Is taller that trees," << endl;
    cout << "Up, up it goes," << endl;
    cout << "and yet never grows?\"" << endl;
    cout << endl;
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Tree" << endl;
    cout << "2. Mountain" << endl;
    cout << "3. Cloud" << endl;
    cout << "4. Bird" << endl;
    validateInt(&answer, 1, 4);
    if (answer == 2) {
        cout << endl;
        cout << "Spirit: \"Correct! You're more clever than you look!" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        return;
    }
    cout << "Spirit: \"Let's try something a little harder...\"" << endl;
    cout << "\"Thirty white horses on a red hill, " << endl;
    cout << "First they champ, " << endl;
    cout << "Then they stamp, " << endl;
    cout << "Then they stand still.\"" << endl;
    cout << endl;
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Daisies" << endl;
    cout << "2. Rain" << endl;
    cout << "3. Snow" << endl;
    cout << "4. Teeth" << endl;
    validateInt(&answer, 1, 4);
    if (answer == 4) {
        cout << endl;
        cout << "Spirit: \"Correct again! How wise!\"" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        return;
    }
    cout << "Spirit: \"I'll have to give you my hardest riddle yet!" << endl;
    cout << "\"Voiceless it cries, " << endl;
    cout << "Wingless flutters," << endl;
    cout << "toothless bites," << endl;
    cout << "Mouthless mutters.\"" << endl;
    cout << endl;
    cout << "Enter an integer corresponding to your answer" << endl;
    cout << "1. Time" << endl;
    cout << "2. Echo" << endl;
    cout << "3. Wind" << endl;
    cout << "4. Reflection" << endl;
    validateInt(&answer, 1, 4);
    if (answer == 3) {
        cout << endl;
        cout << "Spirit: \"No one's ever managed to answer all of my riddles!\"" << endl;
        cout << "\"For winning my riddle game, I'll give you this ancient axe!\"" << endl;
        this->inventory->axe++;
        cout << "You recieve a magical axe from the spirit." << endl;
        cout << "You can use this axe to enter new areas and get new items!" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "Spirit: \"Wrong! You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        cout << endl;
        return;
    }
}