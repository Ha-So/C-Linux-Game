/*********************************************************************
** Program name:  C++ Agent
** File name: First.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size, specific NPC and chat options
*********************************************************************/

#include "First.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
**                         First()
** Sets array size and walls of the room. Places stairs, NPC and sets
** bool variables
*********************************************************************/
First::First()
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

	spaceArray[6][15] = '$';
	name = "First Floor";
	objective = "There's the receptionist, she looks like $...";

	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = true; 

	spaceArray[24][13] = '+';
	spaceArray[24][14] = '+';
	spaceArray[24][15] = '+';


	spaceArray[0][25] = '+';
	spaceArray[0][28] = '+';
	spaceArray[0][27] = '+';
	spaceArray[0][26] = '+';
	spaceArray[0][24] = '+';

	spaceArray[12][2] = 'L';
	spaceArray[13][2] = 'L';
	spaceArray[14][2] = 'L';
	spaceArray[15][2] = 'L';



	spaceArray[12][27] = 'L';
	spaceArray[13][27] = 'L';
	spaceArray[14][27] = 'L';
	spaceArray[15][27] = 'L';

	//setup desk for rep
	for(int i = 7; i < 10; ++i)
	{
		for (int j = 13; j < 18; ++j)
		{
			spaceArray[i][j] = '=';
		}
	}

}

/*********************************************************************
**                         ~First()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
First::~First()
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
** Allows the user to intereact with the receptionist when near the NPC 
*********************************************************************/
string First::interact() 
{
	
	char type;
	if(chat1)
	{
		//5 possible replies, only number 4 is correct
		if(menu('C', &type))
		{
			
			switch(type)
			{
				case'1': return "Well keep looking cause you won't find it here.";
				break;
				case'2': return "I'm sorry, I don't see that on the schedule.";
				break;
				case'3': return "Dr. Python is sterile.";
				break;
				case'4': 	chat1 = false; 
							lock = false; 
							objective = "Time to go up to the second floor...";
						return "Oh! of course, here is your key card to get around the stairwells!";
				break;
				case'5': return "...uh, hi.";
				break;
			}
			
		}
	  else
	  {
	 	
		return "Sorry, I can't understand your accent. "; 
	  }
	}
	//If the user has already selected 4 prior
	else if (chat2)
	{
		return "You can go ahead, quit bothering me creep... "; 
		
	}
	return " ";
}

/*Laser functions not used on this floor */
void First::laser()
{
	//VOID
}
bool First::checkLaser(int row, int col)
{
	return true; 
}