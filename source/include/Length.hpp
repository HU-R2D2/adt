//!
//! @author		Remco Nijkamp & Koen de Groot
//! @date 		15-03-16
//! @version 	1.0
//! @brief		Length is a Length is a measurement of a size that is being represented by a single value. 
//!				Length stands on its own, this means it has no such thing as a zero point or a direction.
//!				The only attribute Length has, is the Length itself.
//!

#ifndef _LENGTH_HPP
#define _LENGTH_HPP

#include "gtest/gtest.h"
//#include "Acceleration.hpp"
//#include "Duration.hpp"
#include <iostream> 

class Speed;
class Distance;

class Length {
	friend class Distance;
	friend class Acceleration;
	
	public:
		//! @fn		Length::Length(double l)
		//!
		//! @brief	Constructor of a Length
		//!
		//! @param	l 		The length value
		Length(double length);

		//! @fn 	Length::Length()
		//!
		//! @brief 	Defaut constructor of length
		Length();
		
		//! @fn		Length& Length::Length(const Length& rhs)
		//!
		//! @brief	assignment operator of a Length
		//!
		//! @param	rhs 		The right hand side Length, this one is being assigned to another Length
		//! @return	Length&		The Length on which the assign operator was called
		Length& operator= (const Length& rhs);
		
		//! @fn		Length Length::Length(const Length& rhs)
		//!
		//! @brief	Add operator of a Length
		//!
		//! @param	number the number to add to the length
		//! @return	Length		The result of the addition
		Length operator+ (const Length& rhs) const; 
		
		//! @fn		Length Length::Length(const Length& rhs)
		//!
		//! @brief	substract operator of a Length
		//!
		//! @param	number the number to subtrackt from the length
		//! @return	Length		The result of the subtraction
		Length operator- (const Length& rhs) const;
		
		//! @fn		Length Length::Length(const Length& rhs)
		//!
		//! @brief	multiply operator of a Length
		//!
		//! @param	number the number to multyply the length by
		//! @return	Length		The result of the multiplication
		Length operator* (double number) const;
		
		//! @fn 	Length Length::Length(const Length& rhs)
		//!
		//! @brief	division operator of a Length
		//!
		//! @param	number the number to divide the length by
		//! @return	Length		The result of the division
		Length operator/ (double number) const;
		
		//! @fn 	double Length::Length(const Length& rhs)
		//!
		//! @brief	division operator of a Length
		//!
		//! @param	number the number to devide the length by
		//! @return	double		The result of the multiplication
		double operator/ (const Length & rhs) const;

		//! @fn		Length& Length::Length(const Length& rhs)
		//!
		//! @brief	Add assign operator of a Length
		//!
		//! @param	number the number to add to the length 
		//! @return	Length&		The Length on which the add assign operator is called
		Length& operator+= (const Length& rhs);
		
		//! @fn		Length& Length::Length(const Length& rhs)
		//!
		//! @brief	subtract assign operator of a Length
		//!
		//! @param	number 		the number to subtract from the length
		//! @return	Length&		The Length on which the subtract assign operator is called
		Length& operator-= (const Length& rhs);
		
		//! @fn		bool Length::Length(const Length& rhs)
		//!
		//! @brief	greater then operator of a Length
		//!
		//! @param	rhs 		the right hand side to compare 
		//! @return	bool		true if 1st Length is greater than 2nd, false if not
		bool operator> (const Length& rhs) const;

		//! @fn		bool Length::Length(const Length& rhs)
		//!
		//! @brief	smaller then operator of a Length
		//!
		//! @param	rhs 		the right hand side to compare 
		//! @return	bool		true if 1st Length is smalles than 2nd, false if not
		bool operator< (const Length& rhs) const;

		//! @fn		std::ostream& Length::operator<< (std:: ostream& os, const Length& rhs)
		//!
		//! @brief	appends a Length to an ostream and returns an ostream
		//!
		//! @param	rhs 		the right hand side to compare 
		//! @return	ostream		...
		friend std::ostream& operator<< (std:: ostream& os, const Length& rhs);

		//! @fn		std::istream& Length::operator>>(std::istream& is, Length& rhs)
		//!
		//! @brief	adds an istream to a Length
		//!
		//! @param	is		...
		//! @param	rhs		...
		//! @return	istream		...
		friend std::istream& operator>>(std::istream& is, Length& rhs);

		//! @fn		Length Length::operator* (double n, const Length& rhs)
		//!
		//! @brief	multiply a Length by another Length and returns a Length
		//!
		//! @param	n		...
		//!	@param	rhs		...
		//! @return	Length		The result of the multiplication
		friend Length operator* (double n, const Length& rhs);

		//! @fn		Speed Length::operator/ (const Length & length, const Duration & d)
		//!
		//! @brief	divide length by duration and return the speed
		//!
		//! @param	length		...
		//!	@param	d			...
		//! @return	Speed		The result of the division
		//friend Speed operator/ (const Length & length, const Duration & d);

		FRIEND_TEST(Length, doubleConstructor);
		static const Length METER;
		static const Length CENTIMETER;
	private:
		double length;
};

#endif
