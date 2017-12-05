/*********************************************************************
** Program name:  C++ Agent
** File name: Basement.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size, specific NPC and chat options
*********************************************************************/

#include "Basement.hpp"

using namespace std;



/*********************************************************************
**                         Basement()
** Sets array size and walls of the room. Places stairs, NPC and sets
** bool variables
*********************************************************************/
Basement::Basement()
{
	maxRows = 25;
	maxCols = 30;
	spaceArray = new char *[maxRows]; 
	for(int i = 0; i < maxRows; ++i)
	{
		spaceArray[i] = new char [maxCols];
	}
	for(int i = ZERO; i < maxRows; ++i)
	{
		for (int j = ZERO; j < maxCols ; ++j)
		{
			spaceArray[i][j] = EMPTY;
		}
	}

	for (int i = 0; i < maxCols; ++i)
	{
		spaceArray[ZERO][i] = WALL;
		spaceArray[maxRows-1][i] = WALL;
	}

	for (int i = 0; i < maxRows; ++i)
	{
		spaceArray[i][ZERO] = WALL;
		spaceArray[i][maxCols-1] = WALL;
	}
	spaceArray[0][13] = '+';
	spaceArray[0][14] = '+';
	spaceArray[0][15] = '+';
	spaceArray[15][15] = 'G';

	for(int i = 1; i < 9; i++)
	{
		spaceArray[20][i] = 'X';
	}
	for(int i = 20; i < 24; i++)
	{
		spaceArray[i][8] = 'X';
	}

	name = "Basement";
	objective = "I should probably talk to that guy shaped like a G...";
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = true; 
}

/*********************************************************************
**                         ~Basement()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
Basement::~Basement()
{
	 //For loop first deletes the 1D array of rows, then the columns.
    for (int i = ZERO; i < maxRows; ++i)
        {
            delete [] spaceArray[i];  
        }
    delete [] spaceArray;

}

/*********************************************************************
**                         interact()
** Allows the user to intereact with George when near the NPC 
*********************************************************************/
string Basement::interact()
{
	if(chat1)
	{
		cout << endl << endl; 
		cout << "GEORGE: Hello... my name is Agent George, I'm here to guide you on your secret mission." << endl;
		cout << "We're currently on the basement level, Dr. Python is on the 5th floor. You must make" << endl;
		cout << " your way up and terminate him. I've hidden a USB drive for you on the 2nd floor, it can kill him. In order to " << endl;
		cout << "get there, I've set up your cover as an electrician so the receptionist will let you in. Good luck!" << endl << endl;
		chat1 = false; 
		lock = false;
		objective = "Time to go to the first floor then...";
		return " ";
	}
	else if (chat2)
	{
		cout << endl << endl;
		cout << "GEORGE: Sigh...they told me you were slow. Listen carefully." << endl; 
		cout << "Destroy man on 5th floor. USB is on 2nd floor. Pretend to be an electrician." << endl;
		cout << "Got it? ...I need a vacation. " << endl << endl; 
		return " ";
	}
	return " ";
}

/*Laser functions not used on this floor */

void Basement::laser()
{
	//VOID
}
bool Basement::checkLaser(int row, int col)
{
	return true; 
}