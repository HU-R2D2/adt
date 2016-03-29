#include <ctime>
#include "Duration.hpp"
#ifndef _MOMENT_HPP
#define _MOMENT_HPP
#define MAX_DOUBLE_VALUE 0xffffffff
/**
	ToDo implementation of a moment
	Review
	Testing
	
*	@author 		Ferdi Stoeltie
*	@date			13-03-2016
*	@version		0.1
*	@brief	This class provides a timestamp of a moment in time. Due to its use in R2D2 (as of yet), a Moment object can only be created by the Clock.

*/
class Moment{
friend class Clock;
public:
	/// Constructor of a moment, is private so that it is only accessible by the Clock
	/**
		@brief Creates a timestamp with the current moment of time as its default timestamp
	*/
	Moment(); // must be private
	// Creates a moment out of a given amount of seconds
	/**
		@brief Creates a timestamp by its given parameter in seconds
	*/
	Moment(double seconds); // must be private
//public:
	/// assignment operator for a moment
	Moment& operator= (const Moment&);

	// adds a duration to a moment and results in a moment
	Moment operator+ ( const Duration & rhs ) const;

	// Subtracts a duration to a moment and results in a moment
	Moment operator- ( const Duration & rhs ) const;

	// Subtracts a moment from a moment and results in a duration
	Duration operator- (const Moment & rhs) const;

	// adds a duration to a moment and returns this moment
	Moment& operator+= (const Duration & rhs);

	/*Moment & operator= (const moment &);
	/// adds a duration to a moment and results in a moment
	Moment operator+ ( const duration & rhs ) const;
	/// substracts a duration from a moment and results in a moment
	Moment operator- ( const duration & rhs ) const;
	/// sunstracts a moment from a moment and results in a duration
	duration operator- (const moment & rhs) const;
	/// adds a duration to a moment and returns this moment
	Moment & operator+= (const duration & rhs);
	/// substracts a duration from a moment and returns this moment
	Moment & operator-= (const duration & rhs);
	/// appends a moment to an ostream and return an ostream
	ostream& operator<< (ostream & os, const moment &rhs) const;
	/// writes a moment to an istream and return istream
	istream & operator>> (istream & is, moment & rhs);
private:*/
	double seconds;
};
#endif 