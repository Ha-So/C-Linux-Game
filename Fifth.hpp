/*********************************************************************
** Program name:  C++ Agent
** File name: Fifth.hpp
** Author: Haris Sohail
** Date: 06/12/17
** Description: Header file
** In addition to the Floor class variables/functions this class has a custom
** array size and the ability to interact with Dr. Python
*********************************************************************/

#include "Floor.hpp"
#ifndef FIFTH_HPP
#define FIFTH_HPP
#include "menu.hpp"

class Fifth : public Floor
{

	public:
		Fifth();
		void laser();
		bool checkLaser(int row, int col);
		virtual ~Fifth() override;
		virtual std::string interact() override;
	
};
#endif