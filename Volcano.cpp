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
    string answer;
    cout << "You see small entrance hidden behind some brush..." << endl;
    cin.get();
    cin.clear();
    cout << "You peek inside the entrance and see a dark unlit tunnel.." << endl;
    cin.get();
    cin.clear();
    cout << "You crawl through the entrance and begin carefully feeling your way through the tunnel..." << endl;
    cin.get();
    cin.clear();
    cout << "Suddenly, the ground gives way under your feet and you plummet into darkness!" << endl;
    cin.get();
    cin.clear();
    cout << "You hit your head during the fall and lose conciousness..." << endl;
    cin.get();
    cin.clear();
    cout << "You awaken to a massive being hovering above you!" << endl;
    cin.get();
    cin.clear();
    cout << "Spirit: \"It has been a long time since I've met one of your kind.\"" << endl;
    cin.get();
    cin.clear();
    cout << "Spirit: \"It's been awfully lonely down here, wont you play a game of riddles with me?\"" << endl;
    cin.get();
    cin.clear();
    cout << "Spirit: \"I'll give you a handsome reward if you succeed!\"" << endl;
    cin.get();
    cin.clear();
    cout << "Spirit: \"Let's begin!\"" << endl;
    cin.get();
    cin.clear();
    cout << "\"What has roots as nobody sees, " << endl;
    cout << "Is taller that trees," << endl;
    cout << "Up, up it goes," << endl;
    cout << "and yet never grows?\"" << endl;
    answer = playerAnswer();
    if (checkAnswer(answer, "mountain") || checkAnswer(answer, "Mountain")) {
        cout << "\"For answering my riddle correctly, I'll give you this ancient axe!\"" << endl;
        this->inventory->axe++;
        this->character->hasAxe = true;
        cout << "You recieve a magical axe from the spirit." << endl;
        cout << "You can use this axe to enter new areas and get new items!" << endl;
    }
    else {
        cout << "\"You foolish mortal, leave me!\"" << endl;
        this->character->health -= 50;
        cout << "The spirit banishes you from the volcano and deals 50 damage to you" << endl;
        return;
    }


}


/***************************************************************************************************************
** Function name: checkString function
** Description: Prompts user to input a string and then returns that string to function call. Will be used to
** provide main with a string that will be reversed
*********************************************************************************************************/
string Volcano::playerAnswer() {
    cout << "Please enter your answer" << endl;
	string input = "";
	//While string input has a length of 0, reprompt user to enter a string
	while (input.length() == 0) {
		getline(cin, input);
	}
	//then return string to function call
	return input;
}

bool Volcano::checkAnswer(string guess, string answer) {
    string guessAgain = " ";
    int guessNum = 2;
    if (guess == answer) {
        cout << "Correct! You're wiser than you look!" << endl;
        return true;
    }
    else {
        while (guessAgain != answer && guessNum > 0) {
            cout << "Wrong! You have " << guessNum << " tries remaining!" << endl;
            guessAgain = playerAnswer();
            if (guessAgain == answer) {
                cout << "Correct! You're wiser than you look!" << endl;
                return true;
            }
            guessNum--;
        }
    }
    cout << "You've failed my game of riddles!" << endl;
    return false;

}

