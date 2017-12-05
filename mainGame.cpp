/*********************************************************************
** Program name:  C++ Agent
** File name: mainGame.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** Main function here initates the game and prints the exit message
*********************************************************************/

#include "Skyscraper.hpp"


int main()
{
	Skyscraper skyObj;
	skyObj.startGame();
	skyObj.runGame(); 
	cout << endl <<"END OF PROGRAM - Thanks for playing!" << endl;
	return 0;
}