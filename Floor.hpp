/*********************************************************************
** Program name:  C++ Agent
** File name: Floor.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** The abstract Floor class is used to created derived Floors that link to 
** each other via direction pointers. Each Floor is displayed as a 2d array
** contains an objective, name, bool locks to monitor progression. As well
** as functions that can move the Agent, monitor laser status, and check
** bounds/ ends of the array  
*********************************************************************/

#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "Agent.hpp"

#include <string>
#include <iostream>

class Floor
{
	protected:
		int maxRows;			//Total rows in the array
		int maxCols;  			//Total cols in the array
		char **spaceArray;		//2d array to print the room
		bool lock; 				//Locks access to stairs 
		bool chat1;				//monitors chat options with NPCs
		bool chat2; 
		std::string name;		//Name of the floor
		std::string objective;	//Floor objective
		const int ZERO = 0; 
		const char EMPTY = ' ';
		const char WALL = '#';
		const char AGENT = '&';
		const char UP = 'w';
		const char DOWN = 's';
		const char LEFT = 'a';
		const char RIGHT = 'd';
		Floor *up;				//Points to the Floor above
		Floor *down;			//Points to the Floor below
		Floor *right;			//Points to the Floor to the right
		Floor *left; 			//Points to the Floor to the left



	public:
		Floor();
		virtual ~Floor();
		void updateAgent(int row, int col); 
		void deleteAgent(int row, int col);
		void print(); 
		bool bounds(char direct, int curRow, int curCol);
		char around(int row, int col);
		std::string getName(); 
		Floor* getUp();
		Floor* getDown();
		Floor* getLeft();
		Floor* getRight();
		void setUp(Floor*);
		void setDown(Floor*);
		void setLeft(Floor*);
		void setRight(Floor*);
		bool getLock(); 
		bool doors(char direct, int curRow, int curCol);
	    std::string getObjective();
	    virtual void laser() = 0;
		virtual bool checkLaser(int row, int col) = 0;
		virtual std::string interact() = 0;

};
#endif