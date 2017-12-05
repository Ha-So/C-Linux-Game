/*********************************************************************
** Program name:  C++ Agent
** File name: Skyscraper.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** This class holds all the Floor and agent objects, calling functions 
** from each to move the Agent and overall run the entire game by handling]
** starting, ending and all the floor transitions 
*********************************************************************/

#include "Skyscraper.hpp"
#include "menu.hpp"
#include <sstream>

using namespace std;


/*********************************************************************
**                    		   Skyscraper()
** Sets pinters to new Floor objects, assigns direction pointers from each floor
** sets bool values to start the game and the objective. 
*********************************************************************/

Skyscraper::Skyscraper()
{
	//Set all Floor pointers
	base = new Basement;
	first = new First;
	second = new Second;
	third = new Third;
	fourth = new Fourth;
	fifth = new Fifth;

	//Set current and up/down pointers
	current = base;
	current->setUp(first);
	first->setDown(base); 
	first->setUp(second);
	second->setDown(first);
	second->setUp(third);
	third->setDown(second);
	third->setUp(fourth);
	fourth ->setDown(third); 
	fourth ->setUp(fifth); 

	//Set bool values and starting objective 
	final = false; 
	lCheck = false; 
	objective = current->getObjective();
}

/*********************************************************************
**                    		~Skyscraper()
** Deletes each new Floor object
*********************************************************************/

Skyscraper::~Skyscraper()
{
		delete base;
		delete first;
		delete second;
		delete third; 
		delete fourth;
		delete fifth;
}

/*********************************************************************
**                    		startGame()
** Opens up the game initially with a instructional message, takes in
** enter to continue and prints the first room
*********************************************************************/

void Skyscraper::startGame()
{
	//Place Agent in room
	current->updateAgent(James.returnRow(), James.returnCol());

	//Print opening, then first room
	opening(); 
	clearScreen();
	printRoom();
}


/*********************************************************************
**                    		  clearScreen()
** Clears the terminal and places the cursor at the bottom of the screen
**Reference: Code utlized from Dylan Markovic - Final Project CS162
*********************************************************************/

void Skyscraper::clearScreen()
{
	system("clear");
	string newline(100, '\n');
	cout << newline << endl;
}

/*********************************************************************
**                    		   opening()
** Clears screen and displays intro info to start the game
*********************************************************************/

void Skyscraper::opening()
{
	clearScreen();
	readMenu('A');
}

/*********************************************************************
**                    		  runGame()
** This loop runs the entire game and accepts/verifies all user commands. 
** Loop can move the Agent, examine, view inventory and show the legend.
** The loop ends if Stealth Points dip below 0, user selects q or the boss
** is defeated. 
*********************************************************************/

void Skyscraper::runGame()
{
	char value; 
	do
	{
		
		//Asks user for command choice
	 if(menu('A', &value))
	   {
	   	//Conver to lowercase
	   	value = tolower(value);

		//move character
		if (value == 'w' || value == 's' || value == 'a' || value == 'd')
		{
			move(value); 
			
		}

		//examine nearby objects 
		else if(value == 'e')
		{
			examine();
		}

		//view inventory 
		else if(value == 'i')
		{
			viewInventory();
		}
		//View Legend/controls
		else if (value == 'l')
		{
			printRoom();
			cout << endl <<"      ACTION LIST      " << endl;
			cout <<"_______________________" << endl << endl;
			cout <<"w - Move up" << endl;
			cout <<"s - Move down" << endl;
			cout <<"a - Move left" << endl;
			cout <<"d - Move right" << endl;
			cout <<"e - Examine/talk/investigate" << endl;
			cout <<"i - View inventory" << endl;
			cout <<"l - Action list" << endl;
			cout <<"x - Quit game" << endl;
			cout <<"_______________________" << endl << endl;
			cout << endl <<"      LEGEND      " << endl;
			cout <<"_______________________" << endl << endl;
			cout <<"++++ - Stairs" << endl;
			cout <<"G - George" << endl;
			cout <<"$ - Receptionist" << endl;
			cout <<"V - Laser" << endl;
			cout <<"# - Wall" << endl;
			cout <<"O - Guard" << endl;
			cout <<"@ - Computer" << endl;
			cout <<"P - Dr. Python" << endl;
			cout <<"& - Agent(You)" << endl;
			cout <<"_______________________" << endl << endl;
		}
	   }

	   //If none apply, re-print room and invalid input
	  else
	  {
	 	printRoom();
		cout << "Invalid input." << endl; 
	  }

	 //End loop once stealth is less than 0, q is selected or boss is defeated
	}while(James.returnStealth() > 0 && value!= 'x' && value!= 'X' && final != true);


	//Three alternate ending messages
	if(James.returnStealth() <= 0)
	{
		printRoom();
		cout << "Your Stealth Points went below 0 and you were discovered!" << endl; 
		cout << "Try being more stealthy!" << endl << endl;
		cout << "GAME OVER" << endl << endl; 
	}
	else if (final == true)
	{
		printRoom();
		cout << "DR. PYTHON: Noooooo! The virus from the USB is taking over my new body...system shutting down..." << endl;
		cout << "Python is supreme!..." << endl << endl;

		cout << "CONGRATULATIONS! You have defeated Dr. Python and won the game!" << endl << endl;
	}
	else
	{
		printRoom();
		cout << "Quitting Game." << endl << endl;
	}
}


/*********************************************************************
**                    		 viewInventory()
** Displays the inventory vector and allows the user to examine
** any items in their inventory 
*********************************************************************/
void Skyscraper::viewInventory()
{
	int size = inventory.size();
	cout << "  ELECTRICIAN'S BAG" << endl;
	cout <<"_______________________" << endl << endl;
	for(int i = 0; i < size; i++)
	{
		cout <<i+1 <<". " << inventory[i] << endl;
	}
	cout << endl;

	//Allow user to select what item they want to see
	if (size == 0)
	{
		cout << "Empty, try picking up some items" << endl << endl;
	}
	
	else
	{
	 cout << "Which item do you wish to examine?" << endl;
	 cout << "Selection: ";
	 string input = " "; 
	 getline(cin,input);
	 int type;
	 stringstream myStream(input);
		if(myStream >> type)
		{
			if(type<= size && type > 0)
			{
				printRoom();
				switch(type)
				{
					case 1: cout << "This is the keycard to access the stairwells." << endl;
							cout << "The stairs open automatically as long as I carry this." << endl;
					break;
					case 2: cout << "This USB Drive can be used to beat Dr. Python." << endl; 
							if(current->getName() == "Fifth Floor")
							{
								if(current->around(James.returnRow() - 1, James.returnCol()) == 'P')
								{
										final = true;
								}
								else
								{
								cout << "I need to be next to Dr. Python to use this." << endl;
								}
							}
							else
							{
								cout << "I need to be next to Dr. Python to use this." << endl;
							}
					break;	
				}
			}

			else
			{
			cin.sync();
			printRoom();
			cout << "Invalid input." << endl;
			}


		}

		else
		{
		cin.sync();
		printRoom();
		cout << "Invalid input." << endl;
		}
	}
}


/*********************************************************************
**                    		 examine()
** User can select what area around them they wish to examine. If
** the area is not empty, further information/progress is returned.
*********************************************************************/

void Skyscraper::examine()
{
	
//Asks user what area around them to examine
string temp;
if(menu('B', &eValue))
 {
 	eValue = tolower(eValue);
 	
	switch(eValue)
	{
		case 'w':tempRow = James.returnRow() - 1;
				 tempCol = James.returnCol();
		break;

		case 's':tempRow = James.returnRow() + 1;
				 tempCol = James.returnCol();
		break;

		case 'a':tempRow = James.returnRow();
				 tempCol = James.returnCol() - 1;
		break;

		case 'd':tempRow = James.returnRow();
				 tempCol = James.returnCol() + 1;
		break; 
	}

	//Returns character in that area
	eValue = current->around(tempRow, tempCol);
	
	//Print out info about that character
	switch(eValue)
	{
		case '#':	printRoom();
		 cout << "It's just a wall..." << endl;
		break;
		case ' ': 	printRoom();
		cout << "You need glasses, there's nothing there." << endl; 
		break;
		case 'G': 	printRoom();
					current->interact(); 
					objective = current->getObjective();
		break;
		case '$':
				
				temp = current->interact();
				printRoom();
				cout << endl << endl << "RECEPTIONIST: ";
				cout << temp << endl; 
				if(temp[0] == 'O')
				{
					objective = current->getObjective();
					inventory.push_back("Stairwell Keycard");
				}
		break;
		case '=':
				printRoom();
		 		cout << "It's a gorgeous wooden desk!" << endl;
		break; 
		case '!':
				
				temp = current->interact();
				objective = current->getObjective();
				printRoom();
				cout << temp << endl; 
				inventory.push_back("USB Drive");
				
		break;
		case 'V':printRoom();
		 		cout << "Looks like a dangerous laser machine!" << endl;
		break; 
		case '<':printRoom();
		 		cout << "Looks like a dangerous laser machine!" << endl;
		break; 
		case '-':printRoom();
		 		cout << "A dangerous laser field, better not touch it!" << endl;
		break; 
		case 'O':printRoom();
		 		cout << "GUARD: Watch out, we have high level security on the third and fourth floor." << endl;
		break; 
		case '@':
				temp = current->interact();
				objective = current->getObjective();
				printRoom();
				cout << endl << endl << "COMPUTER: ";
				cout << temp << endl;
		break; 
		case 'P':
				printRoom();
		 		cout << "DR. PYTHON: Yes...examine me, I am glorious! If only you had a USB drive to use on me..." << endl;
		 		cout <<" Perhaps open your inventory? Just a thought, Muhahahaha." << endl;
		break; 
		case '%':
				printRoom();
		 		cout << "A bunch of weird computer stuff...I should have went to med school." << endl;
		 		
		break; 
		case 'X':
				printRoom();
		 		cout << "Looks like a lot of shipping boxes, reads \"Amazon Prime\"..." << endl;
		 		
		break; 
		case 'L':
				printRoom();
		 		cout << "Oooh, a really comfy chair..." << endl;
		 		
		break; 
	}
  }
  else
  {
  		cin.sync();
  		printRoom();
		cout << "Invalid input." << endl; 
  }
}


/*********************************************************************
**                    		   move()
** Checks multiple bounds via the direction parameter then moves the
** Agent only if it is a valid move
*********************************************************************/
void Skyscraper::move(char value)
{	
			//Checks if the next move is a door
			if(current->doors(value, James.returnRow(), James.returnCol()))
			{
				//Checks if room is locked
				if(current->getLock() && value == 'w')
				{
					//Prints out appropriate error message
					if(current->getName() == "First Floor")
					{
					printRoom();
					cout << "The stairwell door is locked! Maybe the receptionist can help?" << endl; 
					}
					else if(current->getName() == "Basement")
					{
						printRoom();
						cout << "I should talk to that weird guy before moving on." << endl; 
					}
					else if(current->getName() == "Second Floor")
					{
						printRoom();
						cout << "I can't leave without the USB drive!" << endl; 
					}
				}

				//If lock is open, room is changed
				else
				{
					changeRooms(value);
					current->updateAgent(James.returnRow(), James.returnCol());
					printRoom();
					cout  << "Agent has moved!" << endl; 
					if(current->getName() == "Fifth Floor")
					{
						readMenu('B');
					}

				}
			}
			
			//Checks if nothing is blocking the player
			else if(current->bounds(value, James.returnRow(), James.returnCol()))
			{

				//Updates the room if true
				current->deleteAgent(James.returnRow(), James.returnCol());
				James.moveAgent(value);

				//Checks if the player is touching the laser on the 3rd floor
				if(current->getName() == "Third Floor")
				{
	 				current->laser();
					if(current->checkLaser(James.returnRow(), James.returnCol()))
					{
						James.updateStealth();
						current->updateAgent(James.returnRow(), James.returnCol());
						printRoom();
						cout << "You were hit by the laser and lost stealth points!" << endl;
						lCheck = true; 
					}
					else
					{
						current->updateAgent(James.returnRow(), James.returnCol());
					}

				}
				else
				{
					current->updateAgent(James.returnRow(), James.returnCol());
				}
				if(!lCheck)
				{
				printRoom();
				cout << "Agent James has moved!" << endl; 
				}
				else
				{
					lCheck = false;
				}

			}

			//Prints if no move is possible
			else
			{
				printRoom();
				cout << "Can't move there, something is in the way!" << endl; 
			}
		
}



/*********************************************************************
**                    		   printRoom()
** Calls both the clear and print function, while printing out
** current game data with each print
*********************************************************************/
void Skyscraper::printRoom()
{
	clearScreen();
	cout << "______________________________" << endl;
	cout <<"Current Floor: " << current->getName() << endl;
	cout <<"Current Objective: "<< objective << endl; 
	cout <<"Stealth Points: " << James.returnStealth() << endl; 
	cout << "______________________________" << endl;
	current->print();
}



/*********************************************************************
**                    		 changeRooms()
** If the next intended move is towards '+' stairs, the room is then changed
** based on the player direction and current move. Then the new room is printed
*********************************************************************/
void Skyscraper::changeRooms(char x)
{
	//Checks direction to determine up or down
	if(x == 'w')
	{

		//Changes to up based on current room
		if(current->getName() == "Basement")
		 {
			current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getUp();
			current = tempPtr; 
			James.setRow(23);
			objective = current->getObjective();
		  }

		else if(current->getName() == "First Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getUp();
			current = tempPtr; 
			James.setRow(11);
			James.setCol(James.returnCol() - 23);
			objective = current->getObjective();
		  }

		else if(current->getName() == "Second Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getUp();
			current = tempPtr; 
			James.setRow(11);
			objective = current->getObjective();
		  }
		else if(current->getName() == "Third Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getUp();
			current = tempPtr; 
			James.setRow(23);
			James.setCol(James.returnCol() + 4 );
			objective = current->getObjective();
		  }
		else if(current->getName() == "Fourth Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getUp();
			current = tempPtr; 
			James.setRow(13);
			James.setCol(15);
			objective = current->getObjective();
		  }
	}
	else if (x =='s')
	{	
		//Changes to down based on current room
		if(current->getName() == "First Floor")
		{
			current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getDown();
			current = tempPtr; 
			James.setRow(1);
		}
		if(current->getName() == "Second Floor")
		{
			current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getDown();
			current = tempPtr; 
			James.setRow(1);
			James.setCol(James.returnCol() + 23);
		}
		else if(current->getName() == "Third Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getDown();
			current = tempPtr; 
			James.setRow(1);
			
		  }
		else if(current->getName() == "Fourth Floor")
		  {
		  	current->deleteAgent(James.returnRow(), James.returnCol());
			Floor *tempPtr = current->getDown();
			current = tempPtr; 
			James.setRow(1);
			James.setCol(James.returnCol() - 4);
			
		  }
	}
	printRoom();
}