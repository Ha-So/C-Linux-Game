/*********************************************************************
** Program name:  C++ Agent
** File name: First.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size, specific NPC and chat options
*********************************************************************/

#include "Floor.hpp"
#ifndef FIRST_HPP
#define FIRST_HPP
#include "menu.hpp"

class First : public Floor
{
	protected:
		const char REP = '$';		//Represents the receptionist NPC

	public:
		First();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~First() override;
		virtual std::string interact() override;
	
};
#endif