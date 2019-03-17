/***************************************************************************************************************
** Program name: Menu functions header file
** Author: Daniel Shvarts
** Date: 03/10/2019
** Description: Contains function to validate user integer input, function to start game and function to introduce
** player to game story
*********************************************************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::numeric_limits;

/***************************************************************************************************************
** Function name: validateInput function
** Description: Function will be used to make sure that user input is within defined bounds, and will not crash
** the program. Contains 3 paramters, the first one is an int pointer to the variable that holds user input,
** and the remaining two ints are the lower and upper bounds respectively. The int pointer will be compared to
** these bounds to make sure that input is within the bounds. Will also check that input is no a float, char
** string or contains spaces which may crash program
*********************************************************************************************************/
void validateInt(int* input, int lowerBound, int upperBound) {
	//Local char variable to make sure input contains no unneccessary spaces
	char placeHolder;

	//While the user input cannot be assigned to int variable, or is outside of specified bounds, or contains random spaces
	while (!(cin >> *input) || !(*input >= lowerBound && *input <= upperBound) || (std::cin.get(placeHolder) && !(placeHolder == '\n')))
	{
		//Clear error flag on cin
		cin.clear();
		//Discard remaining characters in input stream
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//Reprompt user to input integers within bounds
		cout << "Please only enter integers from " << lowerBound << " through " << upperBound << "." << endl;
	}
}

/***************************************************************************************************************
** Function name: startGame function
** Description: Function to ask user whether they want to start the game, will return true or false based on answer
** and is used by main to determine whether the game should be initialized.
*********************************************************************************************************/
bool startGame() {
	int menuChoice;
	cout << "Welcome to CS162: Island Survival Final Project" << endl;
	cout << "Please enter an integer corresponding to your desired action" << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Quit Game" << endl;
	validateInt(&menuChoice, 1, 2);
	if (menuChoice == 1) {
		return true;
	}
	else { 
		return false;
	}
}


/***************************************************************************************************************
** Function name: gameIntro function
** Description: Function to display backstory, objective and game tips for user starting the game
*********************************************************************************************************/
void gameIntro() {
	cout << "Press enter to iterate through game" << endl;
	cout << "You awake drenched in seawater, alone on the shore of a mysterious island" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "You remember a rough storm hitting your ship and a unknown force pulling your ship under" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "The island is small but has enough resources to sustain you" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "You must get off the island and return home\n" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "Objective: Gather the supplies necessary to get off this island" << endl;
	cout << "	- You'll need a boat, compass, food and bow and arrows to set sail in the ocean for home" << endl;
	cout << "	- Explore and interact with the island to gather and create supplies" << endl;
	cout << "	- Monitor your hunger, thirst and health levels to avoid dying" << endl;
	cout << "		- Collect water and food on the shore to avoid dehydration and hunger" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

