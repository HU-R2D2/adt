//!
//! @author Casper Wolf & Job Verhaar
//! @date 14-03-16
//! @version 0.1
//!
//! @brief A length of time (interval between two moments).
//! Duration is a ratio scale: addition and subtraction of differences are meaningful (and yield durations), and so are multiplication and division by a scalar (also yield a duration).

#ifndef  _DURATION_HPP
#define _DURATION_HPP

#include <iostream>
#include "Moment.hpp"
#include "ADT_Base.hpp"
#include "gtest/gtest.h"

class Speed;
class Length;
class Acceleration;
class Duration : public ADT_Base<Duration>{
	protected:
		//! @brief
		//!
		//! @param seconds
		explicit Duration(double value);
		
	public:
		friend ADT_Base<Duration>;
		//friend class Acceleration;
		//! @brief Default constructor
		Duration();
		//! @brief
		//!
		//! @param seconds
		double get_seconds() const;

		//constant declaration:
		static const Duration SECOND;
		static const Duration MILLISECOND;
		static const Duration MINUTE;

		//friend declaration:
		friend Duration operator* ( double n, const Duration & rhs);
		friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs);
		friend Speed;


		//! @brief appends a duration to an ostream and return an ostream
		//!
		//! @param is
		//! @param rhs
		//! @return std::istream
		friend std::istream & operator>> (std::istream & is, Duration & rhs);	

		//! @brief appends a duration to an ostream and return an ostream
		//!
		//! @param 
		//! @param
		//! @return
		friend std::ostream& operator<< (std::ostream & os, const Duration &rhs);

		FRIEND_TEST(Duration, ConstructorDouble);
	private:
		//double seconds;
};
#endif

