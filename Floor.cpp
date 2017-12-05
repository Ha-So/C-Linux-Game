/*********************************************************************
** Program name:  C++ Agent
** File name: Floor.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** The abstract Floor class is used to created derived Floors that link to 
** each other via direction pointers. Each Floor is displayed as a 2d array
** contains an objective, name, bool locks to monitor progression. As well
** as functions that can move the Agent, monitor laser status, and check
** bounds/ ends of the array  
*********************************************************************/

#include "Floor.hpp"

using namespace std; 


/*********************************************************************
**                            updateAgent()
*Takes in row and col parameters and prints out the AGENT body int
* the new location
*********************************************************************/
void Floor::updateAgent(int row, int col)
{
	spaceArray[row][col] = AGENT; 
}

/*********************************************************************
**                            updateAgent()
*Takes in previous row and col parameters and deletes Agent body from 
*prior location
*********************************************************************/
void Floor::deleteAgent(int row, int col)
{
	spaceArray[row][col] = EMPTY;
}

/*********************************************************************
**                            print()
* Prints out the current array of the current floor
*********************************************************************/
void Floor::print()
{

	
	for(int i = 0; i < maxRows; i++)
	{
		for(int j = 0; j < maxCols; j++)
		{
			cout << spaceArray[i][j];
		}
		cout << endl;
	}
	cout << "Previous Action Result: "; 
}

/*********************************************************************
**                            bounds()
* Checks if the next intended move is not a wall or object. Returns true
* if the space is empty, false otherwise 
*********************************************************************/
bool Floor::bounds(char direct, int curRow, int curCol)
{

	switch(direct)
	{ 
		case 'w': if(spaceArray[curRow-1][curCol] == EMPTY || spaceArray[curRow-1][curCol] == '|')
					{
						return true; 
					}
				  else
					{
						return false;
					}
		break;

		case 's':if(spaceArray[curRow+1][curCol] == EMPTY || spaceArray[curRow+1][curCol] == '|')
					{
					return true;
					} 
				  else
					{
						return false;
					}
		break;

		case 'a':if(spaceArray[curRow][curCol - 1] == EMPTY || spaceArray[curRow][curCol - 1] == '|')
					{
						return true;
					}
				   else
					{
						return false;
					}

		break;

		case 'd':if (spaceArray[curRow][curCol+1] == EMPTY || spaceArray[curRow][curCol+1] == '|')
					{
						return true; 
					}
				   else
					{
						return false;
					}
		break;
	}
	return false;
}

/*********************************************************************
**                           doors()
*Takes in  the intended row and col as parameters and checks to see if the 
* next move will move the player into a '+' door symbol. If so it returns true. 
*********************************************************************/
bool Floor::doors(char direct, int curRow, int curCol)
{

	switch(direct)
	{ 
		case 'w': if(spaceArray[curRow-1][curCol] == '+')
					{
						return true; 
					}
				  else
					{
						return false;
					}
		break;

		case 's':if(spaceArray[curRow+1][curCol] == '+')
					{
					return true;
					} 
				  else
					{
						return false;
					}
		break;

		case 'a':if(spaceArray[curRow][curCol - 1] == '+')
					{
						return true;
					}
				   else
					{
						return false;
					}

		break;

		case 'd':if (spaceArray[curRow][curCol+1] == '+')
					{
						return true; 
					}
				   else
					{
						return false;
					}
		break;
	}
	return false;
}

/*********************************************************************
**                           around()
*Takes in  the the intended examine area as row and col, returns
the character in that space.  
*********************************************************************/
char Floor::around(int row, int col)
{
	return spaceArray[row][col]; 
}

string Floor::getName()
{
	return name; 
}

Floor* Floor::getUp()
{
	return up;
}
Floor* Floor::getDown()
{
	return down;
}
Floor* Floor::getLeft()
{
	return left;
}
Floor* Floor::getRight()
{
	return right;
}

void  Floor::setUp(Floor* x)
{
	up = x;
}

void  Floor::setDown(Floor* x)
{
 	down = x;
}

void Floor::setLeft(Floor* x)
{
		left = x;
}

void Floor::setRight(Floor* x)
{
	right = x;
}

bool Floor::getLock()
{
	return lock; 
}

Floor::Floor()
{
	//VOID
}

Floor::~Floor()
{
	//VOID
}

string Floor::getObjective() 
{
	return objective;
}
