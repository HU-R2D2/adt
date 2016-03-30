	/**
  *@author Casper Wolf & Job Verhaar
  *@date 14-03-16
  *@version 0.1

	A length of time (interval between two moments). 
	Duration is a ratio scale: addition and subtraction of differences are meaningful (and yield durations), and so are multiplication and division by a scalar (also yield a duration).


*/

#include <iostream>

#ifndef  _DURATION_HPP
#define _DURATION_HPP
class Speed;
class Length;

class Duration{
	private:
		/// constructor of a duration
		Duration(){}
		Duration(double seconds);
	public:
		/// assignment operator for a duration
		Duration & operator= (const Duration & rhs);
		/// adds a duration to a duration and returns a duration
		Duration operator+ ( const Duration & rhs ) const;
		/// substracts a duration from a duration and returns a duration
		Duration operator- ( const Duration & rhs ) const;
		/// multiplies a duration by a number and returns a duration
		Duration operator* (const double & rhs) const;
		/// divides a duration by a number and returns a duration
		Duration operator/ (const double & rhs) const;
		/// adds a duration to a duration and returns this duration
		Duration & operator+= (const Duration & rhs);
		/// substracts a duration from a duration and returns this duration
		Duration & operator-= (const Duration & rhs);
		/// compares to durations to eachother and return a boolean (true if 1st greater than 2nd)
		bool operator> (const Duration & rhs) const;
		/// compares two durations to each other and returns a boolean (true if 1st smaller than 2nd)
		bool operator< (const Duration & rhs) const;
		/// appends a duration to an ostream and return an ostream

		
		/// Writes a duration to an istream and returns an istream
		friend std::istream & operator>> (std::istream & is, Duration & rhs);		

		//constant declaration:
		static const Duration SECOND;
		static const Duration MILLISECOND;
		static const Duration MINUTE;
		//friend declaration:
		friend Duration operator* ( double n, const Duration & rhs);
		friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs);
		friend Speed;
		friend std::ostream& operator<< (std::ostream & os, const Duration &rhs);
	private	:
		double seconds;
};
#endif

