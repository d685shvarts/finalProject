#include "Shipwreck.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include <iostream>
#include <limits>

using std::streamsize;
using std::cin;
using std::endl;
using std::cout;

Shipwreck::Shipwreck(Inventory* inventory, Character* character) : Space(inventory, character) {
    this->name = "Shipwreck";
    this->airSupply = 100;
}

void Shipwreck::spaceMenu() {
    int menuChoice;
    cout << "Please select a choice by entering the corresponding integer" << endl;
    cout << "1. Change Location" << endl;
    cout << "2. Dive into shipwreck" << endl;
    validateInt(&menuChoice, 1, 2);
    if (menuChoice == 1) {
        changeLocation();
    }
    else {
        this->dive();
    }

}

void Shipwreck::changeLocation() {
    int location;
    cout << "Where would you like to travel?" << endl;
    cout << "1. Shore" << endl;
    cout << "2. Don't travel" << endl;
    validateInt(&location, 1, 2);
    switch (location) {
        case 1:
            this->character->currentLocation = this->right;
            this->character->currentLocation->printLocation();
            break;
        case 2:
            cout << "You stay where you are" << endl;
            break;
    }
}

void Shipwreck::dive() {
    this->airSupply = 100;
    int answer;
    cout << "Press enter to iterate through this level. \n" << endl;
    cout << "You put on your airtank and dive under water..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "You swim up to the shipwreck, it looks completely undisturbed..." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "There are multiple entrances to this shipwreck. Which one do you choose?" << endl;
    cout << "Enter the integer corresponding to you choice" << endl;
    cout << "1. A rusty hatch at the bow of the ship" << endl;
    cout << "2. A chained door near the crew's quarters" << endl;
    cout << "3. A broken window near the starboard" << endl;
    cout << "4. A small crack in the hull of the ship" << endl;
    validateInt(&answer, 1, 4);
    while (answer != 2 && this->checkAirtank()) {
        switch (answer) {
        case 1:
            cout << "You swim up to the hatch and try to undo it..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's attached too tightly, you can't undo it!" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            break;
        case 3: 
            cout << "You swim up to the broken window and try to weasel your way through it..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's too small, you can't fit!" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            break;
        case 4:
            cout << "You swim up to the crack and try to slide through it..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's too narrow, you can't fit" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');           
            break;
        }
        this->airSupply -= 10;
        this->getAirtank();
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');  
            cout << "Enter the integer corresponding to you choice" << endl;
            cout << "1. A rusty hatch at the bow of the ship" << endl;
            cout << "2. A chained door near the crew's quarters" << endl;
            cout << "3. A broken window near the starboard" << endl;
            cout << "4. A small crack in the hull of the ship" << endl;
            validateInt(&answer, 1, 4);
        }
    }
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    if (this->checkAirtank()) {
        cout << "You swim up to chained door and give it a tug..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "The chain snaps! Must've been pretty old." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You enter the crew quarters..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It's cramped in here, but you spot several entrances to investigate " << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the integer corresponding to you choice \n" << endl;
        cout << "1. An entrance to the ship's cafeteria " << endl;
        cout << "2. A crack in the roof with sunlight filtering through" << endl;
        cout << "3. An door labeled \"Captain's Quarters\" " << endl;
        cout << "4. A trapdoor held down by a large cask" << endl;
        validateInt(&answer, 1, 4);
    }
    while (answer != 3 && this->checkAirtank()) {
        switch (answer) {
        case 1:
            cout << "You swim up to peer inside the cafeteria... " << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Aside from a couple over turned tables and chairs, its completely empty" << endl;
            break;
        case 2: 
            cout << "You swim up to peer into the crack..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "That just leads outside the ship, that won't do" << endl;
            break;
        case 4:
            cout << "You swim up to the trapdoor and try to move the cask..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's too heavy, it wont budge!" << endl;
            break;
        }

        this->airSupply -= 10;
        this->getAirtank();
        
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the integer corresponding to you choice \n" << endl;
            cout << "1. An entrance to the ship's cafeteria " << endl;
            cout << "2. A crack in the roof with sunlight filtering through" << endl;
            cout << "3. An door labeled \"Captain's Quarters\" " << endl;
            cout << "4. A trapdoor held down by a large cask" << endl;
            validateInt(&answer, 1, 4);
        }
    }
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    if (this->checkAirtank()) {
        cout << "You swim up to Captain's quarters and try to open the door..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "The door just opens up, must've been pretty bad security" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You let yourself into the Captain's quarters..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It's cluttered mess but there's plenty of things to investigate" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the integer corresponding to you choice \n" << endl;
        cout << "1. A massive wooden desk with dozens of drawers" << endl;
        cout << "2. A heavy iron safe in the corner of the room" << endl;
        cout << "3. An ornamental wooden chest with a broken lock" << endl;
        cout << "4. A bookshelf overflowing with massive books and maps" << endl;
        validateInt(&answer, 1, 4);
    }
    while (answer != 3 && this->checkAirtank()) {
        switch (answer) {
        case 1:
            cout << "You start opening every drawer of the desk..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's full of random nick nacks and scraps of paper this is useless!" << endl;
            break;
        case 2: 
            cout << "You try to turn the knob on the safe..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "It's locked! I guess some other adventurer will have to open it..." << endl;
            break;
        case 4:
            cout << "You pore over the dozens of books and maps..." << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "They're interesting but not useful for you..." << endl;
            break;
        }
        this->airSupply -= 10;
        this->getAirtank();
        if (checkAirtank()) {
            cout << "That didn't work, try another choice.\n" << endl;
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the integer corresponding to you choice \n" << endl;
            cout << "1. A massive wooden desk with dozens of drawers" << endl;
            cout << "2. A heavy iron safe in the corner of the room" << endl;
            cout << "3. An ornamental wooden chest with a broken lock" << endl;
            cout << "4. A bookshelf overflowing with massive books and maps" << endl;
            validateInt(&answer, 1, 4);
        }
    }
    if (checkAirtank()) {
        this->airSupply -= 10;
        this->getAirtank();
    }
    if (checkAirtank()) {
        cout << "You try to remove the broken lock..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "It comes right off! You peer inside..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You find a compass!" << endl;
        cout << "It's no treasure but it'll be pretty useful to get off this island!" << endl;
        this->character->inventory->compass++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "With your remaining air you swim to surface of the shipwreck" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }

    if (!checkAirtank()) {
        cout << "You have run out of air!" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "You lose conciousness and take 50 damage!" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        this->character->health -= 50;
        cout << "You awaken at the surface of the shipwreck..." << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
}

void Shipwreck::getAirtank() {
    cout << "You have " << this->airSupply << "/100 air remaining in your tank.\n" << endl;
}

bool Shipwreck::checkAirtank() {
    if (this->airSupply <= 0) {
        return false;
    }
    else {
        cout << "checkAirtank TRUE!" << endl;
        return true;
    }
}