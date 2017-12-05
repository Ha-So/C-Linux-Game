/*********************************************************************
** Program name:  C++ Agent
** File name: Second.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size and a pickup-able object
*********************************************************************/

#include "Second.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
**                         Second()
** Sets array size and walls of the room. Places stairs, USB object and sets
** bool variables
*********************************************************************/
Second::Second()
{
	maxRows = 13;
	maxCols = 60;
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

	spaceArray[10][57] = '!';
	name = "Second Floor";
	objective = "Now where is that USB (!) George hid....?";

	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = true; 

	spaceArray[12][1] = '+';
	spaceArray[12][2] = '+';
	spaceArray[12][3] = '+';
	spaceArray[12][4] = '+';
	spaceArray[12][5] = '+';

	
	spaceArray[0][58] = '+';
	spaceArray[0][57] = '+';
	spaceArray[0][56] = '+';
	spaceArray[0][55] = '+';
	spaceArray[0][54] = '+';
	spaceArray[1][53] = 'O';

	for(int i = 50; i < 59; i++)
	{	
		spaceArray[9][i] = '#';
	}

	for(int i = 1; i < 11; i++)
	{	
		spaceArray[5][i] = '#';
	}
	for(int i = 1; i < 6; i++)
	{	
		spaceArray[i][10] = '#';
	}

	spaceArray[2][5] = '0';
	spaceArray[3][6] = '0';

}

/*********************************************************************
**                         ~Second()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
Second::~Second()
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
** Allows the user to  pick up the USB object when near
*********************************************************************/
string Second::interact() 
{

		spaceArray[10][57] = ' ';
		objective = "Time to go up to the third floor...";
		lock = false; 
		return "I picked up the USB drive!";
	
}

/*Laser functions not used on this floor */
void Second::laser()
{
	//VOID
}
bool Second::checkLaser(int row, int col)
{
	return true; 
}