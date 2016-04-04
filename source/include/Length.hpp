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

#include <iostream> 

class Speed;
class Distance;

class Length final {
	friend class Distance;
	friend class Acceleration;
	
	public:
		//! @fn		Length::Length(double l)
		//!
		//! @brief	Constructor of a Length
		//!
		//! @param	l The coordinate of the distance
		Length(double length);

		//! @fn 	Length::Length()
		//!
		//! @brief 	Defaut constructor of length
		Length();
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	assignment operator of a Length
		//!
		//! @param	rhs the right hand side Length, this one is being assigned to another Length
		Length& operator= (const Length& rhs);
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	Add operator of a Length
		//!
		//! @param	number the number to add to the length
		Length operator+ (const Length& rhs) const; 
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	substract operator of a Length
		//!
		//! @param	number the number to subtrackt from the length
		Length operator- (const Length& rhs) const;
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	multiply operator of a Length
		//!
		//! @param	number the number to multyply the length by
		Length operator* (double number) const;
		
		//! @fn 	Length::Length(const Length& rhs)
		//!
		//! @brief	division operator of a Length
		//!
		//! @param	number the number to devide the length by
		Length operator/ (double number) const;
		
		//! @fn 	Length::Length(const Length& rhs)
		//!
		//! @brief	division operator of a Length
		//!
		//! @param	number the number to devide the length by
		double operator/ (const Length & rhs) const;

		//! @fn	Length::Length(const Length& rhs)
		//!
		//! @brief	Add assign operator of a Length
		//!
		//! @param	number the number to add to the length 

		Length& operator+= (const Length& rhs);
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	subtract assign operator of a Length
		//!
		//! @param	number 		the number to subtract from the length
		Length& operator-= (const Length& rhs);
		
		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	greater then operator of a Length
		//!
		//! @param	rhs 		the right hand side to compare 
		bool operator> (const Length& rhs) const;

		//! @fn		Length::Length(const Length& rhs)
		//!
		//! @brief	smaller then operator of a Length
		//!
		//! @param	rhs 		the right hand side to compare 
		bool operator< (const Length& rhs) const;

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
		friend Speed operator/ (const Length & length, const Duration & d);

		FRIEND_TEST(Length, doubleConstructor);
		static const Length METER;
		static const Length CENTIMETER;
	private:
		double length;
};

#endif
