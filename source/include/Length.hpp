/**
  *@author		Remco Nijkamp & Koen de Groot
  *@date 		15-03-16
  *@version 	0.1
  *@brief		Length is a .....
*/

#include <iostream> 
#include "Duration.hpp"

#ifndef  _LENGTH_HPP
#define _LENGTH_HPP
class Speed;

class Length{
	private:
		Length(double l = 0);
		
	public:
		/// assignment operator for a Length
		Length& operator= (const Length& rhs);
		/// adds a Length to a Length and returns a Length
		Length operator+ (const Length& rhs) const; 
		/// substracts a Length from a Length and returns a Length
		Length operator- (const Length& rhs) const;
		/// multiplies a Length by a number and returns a Length
		Length operator* (double number) const;
		/// divides a Length by a number and returns a Length
		Length operator/ (double number) const;
		/// multiply a Length by a double and returns a Length
		friend Length operator* ( double n, const Length & rhs );

		friend Length operator/ ( double n, const Length & rhs );
		friend Speed;
		friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs);
		/// adds a Length to a Length and returns this Length
		Length& operator+= (const Length& rhs);
		/// substracts a Length from a Length and returns this Length
		Length& operator-= (const Length& rhs);
		/// compares two Lengths to eachother and returns a boolean (true if 1st is greater than 2nd)
		bool operator> (const Length& rhs) const;
		/// compares two Lengths to eachother and returns a boolean (true if 1st is smaller than 2nd)
		bool operator< (const Length& rhs) const;

		double operator/(const Length & rhs) const;
		/// appends a Length to an ostream and returns an ostream
		friend std::ostream& operator<< (std:: ostream& os, const Length& rhs);
		/// adds an istream to a Length
		friend std::istream& operator>>(std::istream& is, Length& rhs);
		
		static const Length METER;
		static const Length CENTIMETER;
	private:
		double l;
};

#endif
