/***************************************************************************************************************
** Program name: Menu functions implementation file
** Author: Daniel Shvarts
** Date: 03/10/2019
** Description: Contains a integer input validating function that will make sure any input integer within defined bounds, a 
** string validating function which will be used to input a string input for palindrome
*********************************************************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <limits>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
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


