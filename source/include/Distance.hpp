/**
  *@author		Remco Nijkamp
  *@date 		14-03-16
  *@version 	0.1
  *@brief		Distance is a 3-vector with an x, y and z value.
				A Distance can be described as the difference between two Coordinates.
*/

#ifndef  _DISTANCE_HPP
#define _DISTANCE_HPP

#include "gtest/gtest.h"
#include <iostream>
#include <math.h> 
#include "Length.hpp"

class Coordinate;	// Forward declaration. Used to declare as friend.

class Distance {
	friend class Coordinate;
	public:		// moet eigenlijk friend ofzo worden....
		Distance(){}
		/**********************************************************************************************//**
		 * @fn		Distance::Distance(Length x, Length y, Length z)
		 *
		 * @brief	Constructor of a Distance
		 *
		 * @param	x			The X coordinate of the distance
		 * @param	y			The Y coordinate of the distance
		 * @param	z			The Z coordinate of the distance
		 **************************************************************************************************/
		Distance(Length x, Length y, Length z);
		
	public:
		/**********************************************************************************************//**
		 * @fn		Length Distance::get_x()
		 *
		 * @brief	Gets the x Length value of the Distance and returns it
		 *
		 * @return	Length		The x Length of the distance
		 **************************************************************************************************/
		Length get_x();
		/**********************************************************************************************//**
		 * @fn		Length Distance::get_y()
		 *
		 * @brief	Gets the y Length value of the Distance and returns it
		 *
		 * @return	Length		The y Length of the distance
		 **************************************************************************************************/
		Length get_y();
		/**********************************************************************************************//**
		 * @fn		Length Distance::get_z()
		 *
		 * @brief	Gets the z Length value of the Distance and returns it
		 *
		 * @return	Length		The z Length of the distance
		 **************************************************************************************************/
		Length get_z();
		/**********************************************************************************************//**
		 * @fn		Length Distance::get_length()
		 *
		 * @brief	Gets the calculated Length of the Distance and returns it
		 *
		 * @return	Length		The absolute Length of the distance
		 **************************************************************************************************/
		Length get_length() const;
		
		/**********************************************************************************************//**
		 * @fn		void Distance::set_x(Length x)
		 *
		 * @brief	Sets the x Length value of the Distance to the given value
		 *
		 * @param	x			The x Lengthof the distance
		 **************************************************************************************************/
		void set_x(Length x);
		/**********************************************************************************************//**
		 * @fn		void Distance::set_y(Length y)
		 *
		 * @brief	Sets the y Length value of the Distance to the given value
		 *
		 * @param	y			The y Length of the distance
		 **************************************************************************************************/
		void set_y(Length y);
		/**********************************************************************************************//**
		 * @fn		void Distance::set_z(Length z)
		 *
		 * @brief	Sets the z Length value of the Distance to the given value
		 *
		 * @param	z			The z Length of the distance
		 **************************************************************************************************/
		void set_z(Length z);
	
		/**********************************************************************************************//**
		 * @fn		Distance& Distance::operator= (const Distance& rhs)
		 *
		 * @brief	Assignment operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one is being assigned to another Distance
		 * @return	Distance&	Reference to the Distance on which the assignment operator was called
		 **************************************************************************************************/
		Distance& operator= (const Distance& rhs);
		/**********************************************************************************************//**
		 * @fn		Distance Distance::operator+ (const Distance& rhs) const
		 *
		 * @brief	Add operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one is being added to another Distance
		 * @return	Distance	The Distance on which the add operator was called
		 **************************************************************************************************/
		Distance operator+ (const Distance& rhs) const;
		/**********************************************************************************************//**
		 * @fn		Distance Distance::operator- (const Distance& rhs) const
		 *
		 * @brief	Substract operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one is being substracted from another Distance
		 * @return	Distance	The Distance on which the substract operator was called
		 **************************************************************************************************/
		Distance operator- (const Distance& rhs) const;
		/**********************************************************************************************//**
		 * @fn		Distance Distance::operator* (double number) const
		 *
		 * @brief	Multiply operator of a Distance
		 *
		 * @param	number		The number by which the Distance is being multiplied
		 * @return	Distance	The Distance on which the multiply operator was called
		 **************************************************************************************************/
		Distance operator* (double number) const;
		/**********************************************************************************************//**
		 * @fn		Distance Distance::operator/ (double number) const
		 *
		 * @brief	Division operator of a Distance
		 *
		 * @param	number		The number by which the Distance is being divided
		 * @return	Distance	The Distance on which the division operator was called
		 **************************************************************************************************/
		Distance operator/ (double number) const;
		/**********************************************************************************************//**
		 * @fn		Distance& Distance::operator+= (const Distance& rhs)
		 *
		 * @brief	AddAssign operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one is being added to another Distance
		 * @return	Distance&	Reference to the Distance on which the addAssignment operator was called
		 **************************************************************************************************/	
		Distance& operator+= (const Distance& rhs);
		/**********************************************************************************************//**
		 * @fn		Distance& Distance::operator-= (const Distance& rhs)
		 *
		 * @brief	SubstractAssign operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one is being substracted from another Distance
		 * @return	Distance&	Reference to the Distance on which the substractAssignment operator was called
		 **************************************************************************************************/	
		Distance& operator-= (const Distance& rhs);
		/**********************************************************************************************//**
		 * @fn		bool Distance::operator> (const Distance& rhs) const
		 *
		 * @brief	GreaterThan operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one will be compared to another Distance
		 * @return	bool		True if length is greater, False if not
		 **************************************************************************************************/
		bool operator> (const Distance& rhs) const;
		/**********************************************************************************************//**
		 * @fn		bool Distance::operator< (const Distance& rhs) const
		 *
		 * @brief	LessThan operator of a Distance
		 *
		 * @param	rhs			The right hand sight Distance, this one will be compared to another Distance
		 * @return	bool		True if length is smaller, False if not
		 **************************************************************************************************/
		bool operator< (const Distance& rhs) const;
		
	private:
		Length x,y,z;
};

/**********************************************************************************************//**
 * @fn		std::ostream& Distance::operator<< (std::ostream& lhs, const Distance& rhs) const
 *
 * @brief	Output operator of a Distance
 *
 * @param	lhs			The left hand sight ostream, to this ostream the Distance will be added
 * @param	rhs			The right hand sight Distance, this one will be added to the lhs ostream
 * @return	ostream&	Reference to the tweaked lhs ostream
 **************************************************************************************************/
std::ostream& operator<< (std::ostream& lhs, Distance& rhs);
/**********************************************************************************************//**
 * @fn		Distance& Distance::operator>>(std::istream& lhs, Distance& rhs)
 *
 * @brief	Input operator of a Distance
 *
 * @param	input		The istream, from this istream the Distance will be adapted
 * @param	rhs			The right hand sight Distance, this one will be adapted by the lhs istream
 * @return	Distance&	Reference to rhs Distance which is adapted by information from the lhs
 **************************************************************************************************/
Distance& operator>>(std::istream& input, Distance& rhs);

#endif
