/**
  *@author Casper Wolf
  *@date 14-03-16
  *@version 0.1

	A length of time (interval between two moments). 
	Duration is a ratio scale: addition and subtraction of differences are meaningful (and yield durations), and so are multiplication and division by a scalar (also yield a duration).


*/
#ifndef  _DURATION_HPP
#define _DURATION_HPP

class Duration{
	private:
		/// constructor of a duration
		Duration();
		Duration(double seconds);
	public:
		const Duration 1_second();
		double minute = 60;
		double hour = 60 * minute;
		/// assignment operator for a duration
		Duration & operator= (const duration &);
		/// adds a duration to a duration and returns a duration
		Duration operator+ ( const duration & rhs ) const;
		/// substracts a duration from a duration and returns a duration
		Duration operator- ( const duration & rhs ) const;
		/// multiplies a duration by a number and returns a duration
		Duration operator* (const double & rhs) const;
		/// divides a duration by a number and returns a duration
		Duration operator/ (const double & rhs) const;
		/// adds a duration to a duration and returns this duration
		Duration & operator+= (const duration & rhs);
		/// substracts a duration from a duration and returns this duration
		Duration & operator-= (const duration & rhs);
		/// compares to durations to eachother and return a boolean (true if 1st greater than 2nd)
		bool operator> (const duration & rhs) const;
		/// compares two durations to each other and returns a boolean (true if 1st smaller than 2nd)
		bool operator< (const Duration & rhs) const;
		/// appends a duration to an ostream and return an ostream
		ostream& operator<< (ostream & os, const Duration &rhs) const;
		/// Writes a duration to an istream and returns an istream
		istream & operator>> (istream & is, Duration & rhs);
	private:
		double seconds;
};
#endif;
