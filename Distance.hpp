/**
  *@author		Remco Nijkamp
  *@date 		14-03-16
  *@version 	0.1
  *@brief		Distance is a .....
*/

#ifndef  _DISTANCE_HPP
#define _DISTANCE_HPP

class Distance{
	private:
		Distance(double x=0, double y=0, double z=0);
		
	public:
		/// assignment operator for a distance
		Distance& operator= (const Distance& rhs);
		/// adds a distance to a distance and returns a distance
		Distance operator+ (const Distance& rhs) const;
		/// substracts a Distance from a Distance and returns a Distance
		Distance operator- ( const Distance& rhs ) const;
		/// multiplies a distance by a number and returns a distance
		Distance operator* (double number) const;
		/// divides a Distance by a number and returns a Distance
		Distance operator/ (double number) const;
		/// adds a distance to a distance and returns this distance
		Distance& operator+= (const Distance& rhs);
		/// substracts a distance from a distance and returns this distance
		Distance& operator-= (const Distance& rhs);
		/// compares two distanced to eachother and returns a boolean (true if 1st is greater than 2nd)
		bool operator> (const Distance& rhs) const;
		/// compares two distanced to eachother and returns a boolean (true if 1st is smaller than 2nd)
		bool operator< (const Distance& rhs) const;
		/// appends a distance to an ostream and returns an ostream
		ostream& operator<< (ostream& os, const Distance& rhs) const;
		/// adds an istream to a distance
		istream& operator>>( istream& is, Distance& rhs)
		
	private:
		double x,y,z
}

#endif