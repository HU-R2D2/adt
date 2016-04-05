//!
//! @author		Remco Nijkamp & Koen de Groot
//! @date 		15-03-16
//! @version 	0.1
//! @brief		Length is a .....
//!

#ifndef _LENGTH_HPP
#define _LENGTH_HPP

#include "gtest/gtest.h"

#include "Acceleration.hpp"
#include "Duration.hpp"
#include "ADT_Base.hpp"

#include <iostream> 

class Speed;
class Distance;

class Length: public ADT_Base<Length>{
	friend class Distance;
	friend class Acceleration;

	protected:
		//! @fn		Length::Length(double l)
		//!
		//! @brief	Constructor of a Length
		//!
		//! @param	l The coordinate of the distance
		Length(double length);
	
	public:
		
		friend ADT_Base<Length>;
		//! @fn 	Length::Length()
		//!
		//! @brief 	Defaut constructor of length
		Length();
		
		//! @fn
		//!
		//! @brief	appends a Length to an ostream and returns an ostream
		//!
		//! @param	rhs 		the right hand side to compare 
		friend std::ostream& operator<< (std:: ostream& os, const Length& rhs);

		//! @fn		
		//!
		//! @brief	adds an istream to a Length
		//!
		//! @param
		friend std::istream& operator>>(std::istream& is, Length& rhs);

		//! @fn		
		//!
		//! @brief	multiply a Length by another Length and returns a Length
		//!
		//! @param
		friend Length operator* (double n, const Length& rhs);

		//! @fn		
		//!
		//! @brief	divide length by duration and return the speed
		//!
		//! @param	
		//friend Speed operator/ (const Length & length, const Duration & d);

		FRIEND_TEST(Length, doubleConstructor);
		static const Length METER;
		static const Length CENTIMETER;
	private:
		//double length;
};

#endif
