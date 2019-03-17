/***************************************************************************************************************
** Program name: Menu functions header file
** Author: Daniel Shvarts
** Date: 03/10/2019
** Description: Contains function to validate user integer input, function to start game and function to introduce
** player to game story
*********************************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP


//Integer validating function
void validateInt(int* input, int lowerBound, int upperBound);

//Function to ask user whether they would like to play the game at start
bool startGame();

//Function to introduce player to objective of the game
void gameIntro();
#endif