/***************************************************************************************************************
** Program name: Menu functions header file
** Author: Daniel Shvarts
** Date: 03/10/2019
** Description: Contains function prototypes to select queue buffer or stack palindrome, a integer validating 
** function, and a string validating function
*********************************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;

//Function to allow user to queue buffer program, stack palindrome program or exit
int menu();
//Integer validating function
void validateInt(int* input, int lowerBound, int upperBound);

#endif