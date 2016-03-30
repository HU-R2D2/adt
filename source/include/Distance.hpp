/**
  *@author		Remco Nijkamp
  *@date 		14-03-16
  *@version 	0.1
  *@brief		Distance is a 3-vector with an x, y and z value.
				A Distance can be described as the difference between two Coordinates.
*/

#ifndef  _DISTANCE_HPP
#define _DISTANCE_HPP

#include "gtest/gtest.h"
#include <iostream>
#include <math.h> 

class Coordinate;	// Forward declaration. Used to declare as friend.

class Distance {
		friend class Coordinate;
	public:		// moet eigenlijk friend ofzo worden....
		Distance(double x = 0.0, double y = 0.0, double z = 0.0);
		
	public:
		/// gets the x value of the Distance and returns it
		double getX();
		/// gets the y value of the Distance and returns it
		double getY();
		/// gets the z value of the Distance and returns it
		double getZ();
		/// gets the Length of the Distance and returns it
		double getLength() const;
		
		/// sets the x value of the Distance to the given value
		void setX(double x);
		/// sets the y value of the Distance to the given value
		void setY(double y);
		/// sets the z value of the Distance to the given value
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
		/// compares two Distances to each other and returns a boolean (true if 1st is greater than 2nd)
		bool operator> (const Distance& rhs) const;
		/// compares two Distances to each other and returns a boolean (true if 1st is smaller than 2nd)
		bool operator< (const Distance& rhs) const;
		
	private:
		double x,y,z;
		FRIEND_TEST(Distance, DefaultConstructor);	// Friend classes (So tests can access private parts.)
};

/// appends a Distance to an ostream and returns an ostream
std::ostream& operator<< (std::ostream& lhs, Distance& rhs);
/// adds an istream to a Distance
Distance& operator>>(std::istream& input, Distance& rhs);

#endif
