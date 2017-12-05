/*********************************************************************
** Program name:  C++ Agent
** File name: Basement.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size, specific NPC and chat options
*********************************************************************/

#include "Floor.hpp"
#ifndef BASEMENT_HPP
#define BASEMENT_HPP

class Basement : public Floor
{
	protected:
		const char GEORGE = 'G';		//Represents Agent George, an NPC

	public:
		Basement();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~Basement() override;
		virtual std::string interact() override;
};
#endif