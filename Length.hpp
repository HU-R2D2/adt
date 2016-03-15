/**
  *@author		Remco Nijkamp
  *@date 		15-03-16
  *@version 	0.1
  *@brief		Length is a .....
*/

#ifndef  _LENGTH_HPP
#define _LENGTH_HPP

class Length{
	private:
		Length(double l=0);
		
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
		/// adds a Length to a Length and returns this Length
		Length& operator+= (const Length& rhs);
		/// substracts a Length from a Length and returns this Length
		Length& operator-= (const Length& rhs);
		/// compares two Lengths to eachother and returns a boolean (true if 1st is greater than 2nd)
		bool operator> (const Length& rhs) const;
		/// compares two Lengths to eachother and returns a boolean (true if 1st is smaller than 2nd)
		bool operator< (const Length& rhs) const;
		/// appends a Length to an ostream and returns an ostream
		ostream& operator<< (ostream& os, const Length& rhs) const;
		/// adds an istream to a Length
		istream& operator>>( istream& is, Length& rhs)
		
	private:
		double l;
}

#endif