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
#include "Acceleration.hpp"
#include "Duration.hpp"
#include "ADT_Base.hpp"
#include <iostream> 

class Speed;
class Translation;

class Length: public ADT_Base<Length>{
	friend class Translation;
	friend class Acceleration;
	friend class Speed;

	protected:
		//! @fn		Length::Length(double l)
		//!
		//! @brief	Constructor of a Length
		//!
		//! @param	l The length value
		Length(double length);
	
	public:
		friend ADT_Base<Length>;
		//! @fn 	Length::Length()
		//!
		//! @brief 	Defaut constructor of length
		Length();

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
		friend Speed operator/ (const Length & length, const Duration & d);

		FRIEND_TEST(Length, doubleConstructor);
		static const Length METER;
		static const Length CENTIMETER;
	private:
};

#endif
