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

class Coordinate;	// Forward declaration. Used to declare as friend.

class Distance {
		friend class Coordinate;
	public:		// moet eigenlijk friend ofzo worden....
		/**********************************************************************************************//**
		 * @fn		Distance::Distance(double x, double y, double z)
		 *
		 * @brief	Constructor of a Distance
		 *
		 * @param	x			The X coordinate of the distance
		 * @param	y			The Y coordinate of the distance
		 * @param	z			The Z coordinate of the distance
		 **************************************************************************************************/
		Distance(double x = 0.0, double y = 0.0, double z = 0.0);
		
	public:
		/**********************************************************************************************//**
		 * @fn		double Distance::getX()
		 *
		 * @brief	Gets the x value of the Distance and returns it
		 *
		 * @return	double		The x coordinate of the distance
		 **************************************************************************************************/
		double getX();
		/**********************************************************************************************//**
		 * @fn		double Distance::getY()
		 *
		 * @brief	Gets the y value of the Distance and returns it
		 *
		 * @return	double		The y coordinate of the distance
		 **************************************************************************************************/
		double getY();
		/**********************************************************************************************//**
		 * @fn		double Distance::getZ()
		 *
		 * @brief	Gets the z value of the Distance and returns it
		 *
		 * @return	double		The z coordinate of the distance
		 **************************************************************************************************/
		double getZ();
		/**********************************************************************************************//**
		 * @fn		double Distance::getLength()
		 *
		 * @brief	Gets the calculated Length of the Distance and returns it
		 *
		 * @return	double		The Length of the distance
		 **************************************************************************************************/
		double getLength() const;
		
		/**********************************************************************************************//**
		 * @fn		void Distance::setX(double x)
		 *
		 * @brief	Sets the x value of the Distance to the given value
		 *
		 * @param	x			The x coordinate of the distance
		 **************************************************************************************************/
		void setX(double x);
		/**********************************************************************************************//**
		 * @fn		void Distance::setY(double y)
		 *
		 * @brief	Sets the y value of the Distance to the given value
		 *
		 * @param	y			The y coordinate of the distance
		 **************************************************************************************************/
		void setY(double y);
		/**********************************************************************************************//**
		 * @fn		void Distance::setZ(double z)
		 *
		 * @brief	Sets the z value of the Distance to the given value
		 *
		 * @param	z			The z coordinate of the distance
		 **************************************************************************************************/
		void setZ(double z);
	
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
		double x,y,z;
		FRIEND_TEST(Distance, DefaultConstructor);	// Friend classes (So tests can access private parts.)
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
