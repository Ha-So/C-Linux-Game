/*********************************************************************
** Program name:  C++ Agent
** File name: Third.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** In addition to the Floor class variables/functions this class has a custom
** array size and a set of alternating lasers
*********************************************************************/

#include "Third.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
**                    		    Third()
** Sets array size and walls of the room. Places stairs and sets
** bool variables to alternate lasers firing
*********************************************************************/
Third::Third()
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
	spaceArray[1][10] = 'V';
	spaceArray[1][15] = 'V';
	spaceArray[1][20] = 'V';
	spaceArray[1][25] = 'V';
	
	name = "Third Floor";
	objective = "Need to pass the lasers (V) so I can get up to the fourth floor...";

	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	chat1 = true;
	chat2 = true; 
	lock = false; 

	spaceArray[12][58] = '+';
	spaceArray[12][57] = '+';
	spaceArray[12][56] = '+';
	spaceArray[12][55] = '+';
	spaceArray[12][54] = '+';

	
	spaceArray[0][1] = '+';
	spaceArray[0][2] = '+';
	spaceArray[0][3] = '+';
	spaceArray[0][4] = '+';
	spaceArray[0][5] = '+';

	on = true;
	off = false; 
	on1 = false;
	off1 = true; 

}

/*********************************************************************
**                         ~Third()
** Deletes the entire 2d dynamically allocated array 
*********************************************************************/
Third::~Third()
{
	 //For loop first deletes the 1D array of rows, then the columns.
    for (int i = ZERO; i < maxRows; ++i)
        {
            delete [] spaceArray[i];
            
        }
    delete [] spaceArray;

}


/*********************************************************************
**                         laser()
** Sets a series of 4 lasers that alternate on and off. If the bool 
** value is on, this prints out a straight line to resemble a laser. 
** If off, the line is deleted. 
*********************************************************************/
void Third::laser()
{

	//If on, prints out line as a laser in the room
  if(on)
   {
   	 on = false;
	 off = true;
	for(int i = 2; i < 12; i++)
	 {
		if(spaceArray[i][10] == ' ')
		{
			spaceArray[i][10] = '|';
		}
		else
		{	
		
			break;
		}
	 }

	 for(int i = 2; i < 12; i++)
	 {
		if(spaceArray[i][20] == ' ')
		{
			spaceArray[i][20] = '|';
		}
		else
		{	
		
			break;
		}
	 }

	}

	//If off, deletes the printed line
  else if (off)
  {
  	on = true;
	off = false;
	for(int i = 11 ; i > 1; i--)
	 {
		if(spaceArray[i][10] == '|')
		{
			spaceArray[i][10] = ' ';
		}
	 }

	  for(int i = 11 ; i > 1; i--)
	 {
		if(spaceArray[i][20] == '|')
		{
			spaceArray[i][20] = ' ';
		}
	 }
  }


  if(on1)
   {
   	 on1 = false;
	 off1 = true;

	 for(int i = 2; i < 12; i++)
	 {
		if(spaceArray[i][15] == ' ')
		{
			spaceArray[i][15] = '|';
		}
		else
		{	
		
			break;
		}
	 }
	 	 for(int i = 2; i < 12; i++)
	 {
		if(spaceArray[i][25] == ' ')
		{
			spaceArray[i][25] = '|';
		}
		else
		{	
		
			break;
		}
	 }



	}
  else if (off1)
  {
  	on1 = true;
	off1 = false;

	 for(int i = 11 ; i > 1; i--)
	 {
		if(spaceArray[i][15] == '|')
		{
			spaceArray[i][15] = ' ';
		}
	 }
	  for(int i = 11 ; i > 1; i--)
	 {
		if(spaceArray[i][25] == '|')
		{
			spaceArray[i][25] = ' ';
		}
	 }
  }
}

/*********************************************************************
**                         checkLaser()
** Checks if the Agent will be hit by the laser by passing
** the Agent's row and col coordinates. Returns true if so 
*********************************************************************/
bool Third::checkLaser(int row, int col)
{
	if((off && col == 10) || (off1 && col == 15)|| (off && col == 20) || (off1 && col == 25))
	{
		return true;
	}
	else 
	{
		return false; 
	}
}

/*********************************************************************
**                         interact()
** No interaction done on this level 
*********************************************************************/
string Third::interact() 
{
	return " ";
}
