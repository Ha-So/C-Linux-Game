/*********************************************************************
** Program name:  C++ Agent
** File name: Third.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size and a set of alternating lasers
*********************************************************************/

#include "Floor.hpp"
#ifndef THIRD_HPP
#define THIRD_HPP
#include "menu.hpp"

class Third: public Floor
{
	protected:
		bool on;		//Bool values turn lasers on and off in alternating fashions
		bool off;
		bool on1;
		bool off1; 
		
	

	public:
		Third();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~Third() override;
		virtual std::string interact() override;
	
};
#endif