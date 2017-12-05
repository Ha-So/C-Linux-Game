/*********************************************************************
** Program name:  C++ Agent
** File name: Fifth.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size and the ability to interact with Dr. Python
*********************************************************************/

#include "Fifth.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
**                    		   Fifth()
** Sets array size and walls of the room. Places stairs and sets
** bool variables to determine progress
*********************************************************************/
Fifth::Fifth()
{
	maxRows = 15;
	maxCols = 32;
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

	for (int i = 1; i < 31; i++)
	{
		spaceArray[14][i] = '#';
	}

	for (int i(13), j(1); (i >= 0 && j < 16); i--, j++)
	{
		spaceArray[i][j] = '#';
	}
	for (int i(13), j(30);( i >= 0 && j > 16); i--, j--)
	{
		spaceArray[i][j] = '#';
	}



	for(int i = 12; i < 20; i ++)
	{
		spaceArray[3][i] = '%';
	}

		spaceArray[3][15] = 'P';
		spaceArray[2][13] = 'O';
		spaceArray[2][18] = 'O';
	
	
	name = "Fifth Floor";
	objective = "Inject the USB from my inventory into Dr. Python! (P)";

	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = false; 
	
}

/*********************************************************************
**                         ~Fifth()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
Fifth::~Fifth()
{
	 //For loop first deletes the 1D array of rows, then the columns.
    for (int i = ZERO; i < maxRows; ++i)
        {
            delete [] spaceArray[i];
            
        }
    delete [] spaceArray;
}




/*Laser and interact functions not used on this floor*/
string Fifth::interact() 
{
	return " ";
}

void Fifth::laser()
{
	//VOID
}
bool Fifth::checkLaser(int row, int col)
{
	return true; 
}