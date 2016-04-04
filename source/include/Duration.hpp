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
class Speed;
class Length;
class Duration {
	friend class Moment;
	private:
		//! @brief
		//!
		//! @param seconds
		Duration(double seconds);
		
	public:
		//! @brief Default constructor
		Duration();
		

		

		//! @brief assignment operator for a duration
		//!
		//! @param rhs
		//! @return Duration
		Duration & operator= (const Duration & rhs);
 
		//! @brief  adds a duration to a duration and returns a duration
		//!
		//! @param rhs
		//! @return Duration
		Duration operator+ ( const Duration & rhs ) const;

		//! @brief substracts a duration from a duration and returns a duration
		//!
		//! @param rhs
		//! @return Duration
		Duration operator- ( const Duration & rhs ) const;

		//! @brief multiplies a duration by a number and returns a duration
		//!
		//! @param rhs
		//! @return Duration
		Duration operator* (const double & rhs) const;

		//! @brief divides a duration by a number and returns a duration
		//!
		//! @param rhs
		//! @return Duration
		Duration operator/ (const double & rhs) const;

		//! @brief adds a duration to a duration and returns this duration
		//!
		//! @param rhs
		//! @return Duration
		Duration & operator+= (const Duration & rhs);

		//! @brief substracts a duration from a duration and returns this duration
		//!
		//! @param rhs
		//! @return Duration
		Duration & operator-= (const Duration & rhs);

		//! @brief compares to durations to eachother and return a boolean (true if 1st greater than 2nd)
		//!
		//! @param rhs
		//! @return Duration
		bool operator> (const Duration & rhs) const;

		//! @brief compares two durations to each other and returns a boolean (true if 1st smaller than 2nd)
		//!
		//! @param rhs
		//! @return Duration
		bool operator< (const Duration & rhs) const;


		//! @brief
		//!
		//! @param
		//! @return
		double operator/ (const Duration & rhs) const;

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



	private:
		double seconds;
};
#endif

