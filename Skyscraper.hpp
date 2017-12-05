/*********************************************************************
** Program name:  C++ Agent
** File name: Skyscraper.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** This class holds all the Floor and agent objects, calling functions 
** from each to move the Agent and overall run the entire game by handling]
** starting, ending and all the floor transitions 
*********************************************************************/

#ifndef SKYSCRAPER
#define SKYSCRAPER
#include "Agent.hpp"
#include "Floor.hpp"
#include "Basement.hpp"
#include "First.hpp"
#include "Second.hpp"
#include "Third.hpp"
#include "Fourth.hpp"
#include "Fifth.hpp"
#include <iostream>
#include <vector>


using namespace std;


class Skyscraper
{
	protected:
		Agent James;			//Main Agent object to be moved around
		Floor *current;			// Points to the current floor agent is on
		Floor *base;			// Points to each Floor from basement to fifth
		Floor *first;
		Floor *second;
		Floor *third;
		Floor *fourth;
		Floor *fifth;
		string objective;		//Holds current objective as story progresses
		char eValue;			//The direction the player wasnts to examine
		int tempRow;			//Used to check bounds for rows
		int tempCol;			//Used to check bounds for cols 
		bool lCheck = false;			//Checks laser status as on or off
		bool final = false;				//Checks if Dr. Python has been defeated
		vector <std::string> inventory; 		//Holds inventory 

	public:
		Skyscraper();
		~Skyscraper();
		void startGame();
		void runGame();
		void move(char x);
		void examine();
		void printRoom(); 
		void opening();
		void changeRooms(char);
		void clearScreen(); 
		void viewInventory(); 
		void setObjective();
		
};
#endif