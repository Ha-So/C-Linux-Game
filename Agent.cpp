/*********************************************************************
** Program name:  C++ Agent
** File name: Agent.cpp
** Author: Haris Sohail
** Date:  06/12/17
** Description: Definition file, creates an Agent object that is able to move around in between
** rooms. Contains Stealth(health) and positioning as variables. Functions
** set the position and return the variables. 
*********************************************************************/

#include "Agent.hpp"


/*********************************************************************
**                            Agent()
**Sets initial Agent position and Stealth points 
*********************************************************************/

Agent::Agent()
{
	curRow = 10;
	curCol = 10; 
	direction ='w'; 
	stealth = 1000; 

}

/*********************************************************************
**                            moveAgent()
** Takes in a character for the direction of the Agent and sets the
** new position
*********************************************************************/
void Agent::moveAgent(char x)
{
	stealth--; 
	switch(x)
	{ 
		case 'w': curRow--;
		break;

		case 's':curRow++;
		break;

		case 'a':curCol--;
		break;

		case 'd':curCol++;
		break;
	}
}

/*********************************************************************
**                            updateStealth()
** Reduces stealth by 50 when Agent is hit by a laser beam
*********************************************************************/
void Agent::updateStealth()
{
	stealth -= 50; 
}

int Agent::returnRow()
{
	return curRow;
}

int Agent::returnCol()
{
	return curCol;
}

int Agent::returnStealth()
{
	return stealth; 
}

void Agent::setRow(int r)
{
	curRow = r; 
}

void Agent::setCol(int c)
{
	curCol = c;
}
