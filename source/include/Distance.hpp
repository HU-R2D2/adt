/**
  *@author		Remco Nijkamp
  *@date 		14-03-16
  *@version 	0.1
  *@brief		Distance is a .....
*/

#ifndef  _DISTANCE_HPP
#define _DISTANCE_HPP

#include "gtest/gtest.h" // needed for friend_test
#include <iostream>

class Distance{
	public:		// moet eigenlijk friend ofzo worden....
		Distance(double x = 0.0, double y = 0.0, double z = 0.0);
		
	public:
	
	
	
		double getX();
		double getY();
		double getZ();
		void setX(double x);
		void setY(double y);
		void setZ(double z);
	
	
	
		/// assignment operator for a Distance
		Distance& operator= (const Distance& rhs);
		/// adds a Distance to a Distance and returns a Distance
		Distance operator+ (const Distance& rhs) const;
		/// substracts a Distance from a Distance and returns a Distance
		Distance operator- (const Distance& rhs) const;
		/// multiplies a Distance by a number and returns a Distance
		Distance operator* (double number) const;
		/// divides a Distance by a number and returns a Distance
		Distance operator/ (double number) const;
		/// adds a Distance to a Distance and returns this Distance
		Distance& operator+= (const Distance& rhs);
		/// substracts a Distance from a Distance and returns this Distance
		Distance& operator-= (const Distance& rhs);
		/// compares two Distances to eachother and returns a boolean (true if 1st is greater than 2nd)
		bool operator> (const Distance& rhs) const;
		/// compares two Distances to eachother and returns a boolean (true if 1st is smaller than 2nd)
		bool operator< (const Distance& rhs) const;
		
	private:
		double x,y,z,Length;
		
		// Friend classes (So tests can access private parts.)
		FRIEND_TEST(Distance, DefaultConstructor);
};

/// appends a Distance to an ostream and returns an ostream
std::ostream& operator<< (std::ostream& lhs, Distance& rhs);
/// adds an istream to a Distance
Distance& operator>>(std::istream& input, Distance& rhs);		// WAT WIL JE HIER TERUGKRIJGEN?? een Distance lijkt me?

#endif
