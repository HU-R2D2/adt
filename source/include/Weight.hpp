//!
//! @author		Job Verhaar
//! @date 		04-04-16
//! @version 	0.1
//! @brief		Weight is a .....
//!

#ifndef _WEIGHT_HPP
#define _WEIGHT_HPP

#include "gtest/gtest.h"

#include <iostream> 

class Weight final {
	private:
		//! @fn		Weight::Weight(double l)
		//!
		//! @brief	Constructor of a Weight
		//!
		//! @param	Weight the 
		Weight(double Weight);
	public:
		//! @fn 	Weight::Weight()
		//!
		//! @brief 	Defaut constructor of Weight
		Weight();
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	assignment operator of a Weight
		//!
		//! @param	rhs the right hand side Weight, this one is being assigned to another Weight
		Weight& operator= (const Weight& rhs);
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	Add operator of a Weight
		//!
		//! @param	number the number to add to the Weight
		Weight operator+ (const Weight& rhs) const; 
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	substract operator of a Weight
		//!
		//! @param	number the number to subtrackt from the Weight
		Weight operator- (const Weight& rhs) const;
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	multiply operator of a Weight
		//!
		//! @param	number the number to multyply the Weight by
		Weight operator* (double number) const;
		
		//! @fn 	Weight::Weight(const Weight& rhs)
		//!
		//! @brief	division operator of a Weight
		//!
		//! @param	number the number to devide the Weight by
		Weight operator/ (double number) const;
		
		//! @fn 	Weight::Weight(const Weight& rhs)
		//!
		//! @brief	division operator of a Weight
		//!
		//! @param	number the number to devide the Weight by
		double operator/ (const Weight & rhs) const;

		//! @fn	Weight::Weight(const Weight& rhs)
		//!
		//! @brief	Add assign operator of a Weight
		//!
		//! @param	number the number to add to the Weight 

		Weight& operator+= (const Weight& rhs);
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	subtract assign operator of a Weight
		//!
		//! @param	number 		the number to subtract from the Weight
		Weight& operator-= (const Weight& rhs);
		
		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	greater then operator of a Weight
		//!
		//! @param	rhs 		the right hand side to compare 
		bool operator> (const Weight& rhs) const;

		//! @fn		Weight::Weight(const Weight& rhs)
		//!
		//! @brief	smaller then operator of a Weight
		//!
		//! @param	rhs 		the right hand side to compare 
		bool operator< (const Weight& rhs) const;

		//! @fn
		//!
		//! @brief	appends a Weight to an ostream and returns an ostream
		//!
		//! @param	rhs 		the right hand side to compare 
		friend std::ostream& operator<< (std:: ostream& os, const Weight& rhs);

		//! @fn		
		//!
		//! @brief	adds an istream to a Weight
		//!
		//! @param
		friend std::istream& operator>>(std::istream& is, Weight& rhs);

		//! @fn		
		//!
		//! @brief	multiply a Weight by another Weight and returns a Weight
		//!
		//! @param
		friend Weight operator* (double n, const Weight& rhs);

		FRIEND_TEST(Weight, doubleConstructor);
		static const Weight KILOGRAM;
		static const Weight GRAM;
	private:
		double value;
};

#endif