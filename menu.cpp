/*********************************************************************
** Program name:  C++ Agent
** File name: menu.cpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Definition file
** The menu functions handle user input and menu navigation during the program.
** Then any input is passed through the inputVal function to verify. 
*********************************************************************/
#include "menu.hpp"
#include <iostream>


using namespace std;

/*********************************************************************
**                              menu()
*This is the main menu function. It utilizes switch functionality so it can 
*display multiple menu options to the user depending on the parameter. The 
*parameter entered is a single character which is used to navigate to each
* case. 
*********************************************************************/

bool menu(char mainType, char *x)
{

	switch(mainType)
	{
	 /*Case A allows the user to input any command*/
	  case 'A':
		cout << endl <<"Enter your action('l' for list of controls) - "<< endl;
		cout << "Selection: ";
		return(inputVal('A', x));
	  break;

	  /*Case B allows the user to examine around them*/
	  case 'B':
	 
	cout << "What area around you do you want to examine?" << endl;
	cout << "w - Above; s - Below; a - Left; d - right" << endl;
	cout << "Selection: ";
    	return inputVal('C', x);
	  break;

	  /*Case C initates dialogue between the Receptionist and user*/
	   case 'C':
	   cout << endl << endl; 
		cout << "RECEPTIONIST: Welcome to Totally Not Evil Industries! What brings you in today?" << endl;
			cout << "Select your reply -" << endl;
			cout << "1. Looking for a hot date." << endl;
			cout << "2. Oh! I'm here to er...uh...do some plumbing?" << endl;
			cout << "3. My dad's the boss around here, you should let me in." << endl;
			cout << "4. Electrician from Generic Electrics. Had an appointment at 3:30 p.m, right?" << endl;
			cout << "5. Hi..." << endl; 
		return inputVal('D', x);
	  break;

	  /*Case D is the laser deactivation terminal*/
	  case 'D':
    	cout << endl << endl; 
		cout << "COMPUTER: Welcome to the Dr. Python's Laser Control System. Answer this to unlock the field." << endl;
		cout << "What is the greatest programming language ever?" << endl;
		cout << "Input your reply -" << endl;
		cout << "1. Python" << endl;
		cout << "2. C++" << endl;
		cout << "Selection: ";
		return inputVal('E', x);
	 	break;
	 
	}
	return 0;
}

/*********************************************************************
**                     inputVal(char type, char *input)
** Input is taken in as a string via pointer, verified to be one character, then
** the function returns true if the input is valid. Otherwise it is false.
REFERENCE: 
http://www.cplusplus.com/forum/articles/6046/
*********************************************************************/
bool inputVal(char type, char *charInput)
{

bool validIn = false;
string input = " ";
 switch(type)
  {

  	//Main command selection
   case 'A':
		getline(cin,input);

		if(input.length() == 1)
		{
			*charInput = input[0];
			type = tolower(*charInput);
			if(type == 'w' || type == 's' || type == 'a' || type == 'd' || type == 'e' || type == 'i' || type == 'l' || type == 'x')
			{
				validIn = true;
			}
		}
		cin.sync();
		return validIn; 
	break;

	//Takes in an enter to continue
	case 'B':
		cin.sync(); 
		cin.get();
		return true; 
	break;

	//Verifies looking around the user 
	case 'C':
		
		getline(cin,input);

		if(input.length() == 1)
		{
			*charInput = input[0];
			type = tolower(*charInput);
			if(type == 'w' || type == 's' || type == 'a' || type == 'd')
			{
				validIn = true;
			}
		}
		cin.sync();
		return validIn; 
	break;

	//Verifies speaking to the recptionist
	case 'D':

		getline(cin,input);

		if(input.length() == 1)
		{
			*charInput = input[0];
			type = tolower(*charInput);
			if(type == '1' || type == '2' || type == '3' || type == '4' || type == '5')
			{
				validIn = true;
			}
		}
		cin.sync();
		return validIn; 
	break;

	//Verifies computer input
	case 'E':

		getline(cin,input);

		if(input.length() == 1)
		{
			*charInput = input[0];
			type = tolower(*charInput);
			if(type == '1' || type == '2')
			{
				validIn = true;
			}
		}
		cin.sync();
		return validIn; 
	break;

   }

   return false; 
}



/*********************************************************************
**                              readMenu()
* This menu simple displays and takes in an enter to continue
*********************************************************************/
bool readMenu(char type)
{
	switch(type)
	{
	  /*Case A is the opening message*/
	  case 'A':
	  	cout << "____________________________________________________________________________" << endl;
	 	cout << "Hello! Welcome to THE C++ AGENT" << endl << endl;
		cout << "Your objective is to play as a secret agent, go through each tower floor " << endl;
		cout << "pickup the USB drive on the second floor and inject it into the evil villain " << endl;
		cout << "Dr. Python on the 5th floor. Press ENTER to start. " << endl;
		cout << "____________________________________________________________________________" << endl;
		cin.get();
		return true; 
	  break;
	  case 'B':
	  				cout << "DR. PYTHON: Welcome...Agent James to my secret lair. I have sealed the doors behind you, ";
					cout << "so there is no escape." << endl;
					cout << "You see it is my life wish to spread the joy of the Python language to all people." << endl; 
					cout << "Thus I have fused my body with this A.I. system so I can digitally infect computers ";
					cout << "all over the world!" << endl;
					cout << "I am immortal...only a USB drive containing a very specific virus injected directly " << endl;
					cout << "into me could kill me, but I'm totally sure you don't have that." << endl;
					cout << "Once my guards finish installing me, they will kill you. Goodbye, Agent James." << endl << endl;
	  break;
	}
	return false; 
}