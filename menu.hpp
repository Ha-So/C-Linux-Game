/*********************************************************************
** Program name:  C++ Agent
** File name: menu.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** The menu functions handle user input and menu navigation during the program.
** Then any input is passed through the inputVal function to verify. 
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <string>


bool menu(char type, char *x);
bool readMenu(char);
bool inputVal(char type, char *charInput); 



#endif