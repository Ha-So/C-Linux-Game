/*********************************************************************
** Program name:  C++ Agent
** File name: Second.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size and a pickup-able object
*********************************************************************/

#include "Floor.hpp"
#ifndef SECOND_HPP
#define SECOND_HPP
#include "menu.hpp"

class Second : public Floor
{
	protected:
		const char USB = '!';		//Pickup-able object
		
	

	public:
		Second();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~Second() override;
		virtual std::string interact() override;
	
};
#endif