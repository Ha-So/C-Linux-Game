/*********************************************************************
** Program name:  C++ Agent
** File name: Fourth.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size and a switchable laser field that blocks progress
*********************************************************************/

#include "Fourth.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
**                    		   Fourth()
** Sets array size and walls of the room. Places stairs and sets
** bool variables to lock in laser field
*********************************************************************/
Fourth::Fourth()
{
	maxRows = 25;
	maxCols = 14;
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

	spaceArray[3][12] = '<';
	spaceArray[6][12] = '<';
	spaceArray[9][12] = '<';
	spaceArray[12][12] = '<';
	name = "Fourth Floor";
	objective = "Need to deactivate the laser field from the computer (@) to go to the fifth floor...";


	for(int i = 11; i > 0; i--)
	{
		spaceArray[3][i] = '-';
	}
	for(int i = 11; i > 0; i--)
	{
		spaceArray[6][i] = '-';
	}
	for(int i = 11; i > 0; i--)
	{
		spaceArray[9][i] = '-';
	}
	for(int i = 11; i > 0; i--)
	{
		spaceArray[12][i] = '-';
	}
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = true; 

	spaceArray[24][5] = '+';
	spaceArray[24][6] = '+';
	spaceArray[24][7] = '+';
	spaceArray[24][8] = '+';
	spaceArray[24][9] = '+';

	
	spaceArray[0][5] = '+';
	spaceArray[0][7] = '+';
	spaceArray[0][6] = '+';
	spaceArray[0][8] = '+';
	spaceArray[0][9] = '+';

	
	spaceArray[14][12] = '@';

}

/*********************************************************************
**                         ~Fourth()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
Fourth::~Fourth()
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
**  Allows user to interact with computer to turn off the field
*********************************************************************/
string Fourth::interact() 
{
	char type;
	if(lock)
	{
		if(menu('D', &type))
		{
			switch(type)
			{
				case'1': lock = false;
						objective = "Time to beat Dr. Python on the fifth floor!"; 

						for(int i = 11; i > 0; i--)
						{
							spaceArray[3][i] = ' ';
						}
						for(int i = 11; i > 0; i--)
						{
							spaceArray[6][i] = ' ';
						}
						for(int i = 11; i > 0; i--)
						{
							spaceArray[9][i] = ' ';
						}
						for(int i = 11; i > 0; i--)
						{
							spaceArray[12][i] = ' ';
						}
				return "Welcome back Dr. Python! Laser field has been turned off.";
				break;
				case'2': return "Incorrect, only Dr. Python knows the answer. ";
				break;
				
			}
			
		}
		else
		{
			return "Learn to type you savage.";
		}
	}
	else if(!lock)
	{
		return "Oh my God, it's a mac...bleh.";
	}
	
	else
	{
	return "Invalid Input.";
	}

	return "Invalid Input.";
}

/*Laser functions not used on this floor*/
void Fourth::laser()
{
	//VOID
}
bool Fourth::checkLaser(int row, int col)
{
	return true; 
}