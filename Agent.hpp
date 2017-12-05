/*********************************************************************
** Program name:  C++ Agent
** File name: Agent.hpp
** Author: Haris Sohail
** Date:  06/12/17
** Description: Header file, creates an Agent object that is able to move around in between
** rooms. Contains Stealth(health) and positioning as variables. Functions
** set the position and return the variables. 
*********************************************************************/

#ifndef AGENT_HPP
#define AGENT_HPP


class Agent
{
	protected:
		int curCol;			//Current column Agent is in
		int curRow;			//Current row Agent is in
		int stealth; 		//Total Health/timer for game
		char direction; 	//Current direction Agent is facing or moving in
		char UP = 'w';		
		char DOWN = 's';
	    char LEFT = 'a';
		char RIGHT = 'd';
		char AGENT = '&';

/*See definitions in cpp file*/
	public:
		Agent();
		void moveAgent(char x);
		int returnRow();
		int returnCol();
		int returnStealth();
		void setRow(int);
		void setCol(int);
		void updateStealth();
};
#endif