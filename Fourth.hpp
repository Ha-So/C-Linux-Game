/*********************************************************************
** Program name:  C++ Agent
** File name: Fourth.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size and a switchable laser field that blocks progress
*********************************************************************/

#include "Floor.hpp"
#ifndef FOURTH_HPP
#define FOURTH_HPP
#include "menu.hpp"

class Fourth : public Floor
{
	public:
		Fourth();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~Fourth() override;
		virtual std::string interact() override;
	
};
#endif