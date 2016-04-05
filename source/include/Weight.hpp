//!
//! @author		Job Verhaar
//! @date 		04-04-16
//! @version 	0.1
//! @brief		Weight is a .....
//!

#ifndef _WEIGHT_HPP
#define _WEIGHT_HPP

#include "gtest/gtest.h"
#include "ADT_Base.hpp"

#include <iostream> 

class Weight : public ADT_Base<Weight>{
	protected:
		//! @fn		Weight::Weight(double l)
		//!
		//! @brief	Constructor of a Weight
		//!
		//! @param	Weight the 
		Weight(double value);

	public:
		friend ADT_Base<Weight>;
		//! @fn 	Weight::Weight()
		//!
		//! @brief 	Defaut constructor of Weight
		Weight();

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
};

#endif