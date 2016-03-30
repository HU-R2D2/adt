#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include <iostream>
#ifndef _MOMENT_HPP
#define _MOMENT_HPP
/**
	ToDo implementation of a moment
	Testing
	Review
	
*	@author 		Ferdi Stoeltie
*	@date			13-03-2016
*	@version		0.2
*	@brief			This class provides a timestamp of a moment in time. Due to its use in R2D2 (as of yet), a Moment object can only be created by the Clock.

*/
using namespace std;
class Moment{
friend class Clock;
public:
	/// Constructor of a moment, is private so that it is only accessible by the Clock
	/**
		@brief Creates a timestamp with the current moment of time as its default timestamp
	*/
	Moment(); // MUST BE PRIVATE FOR CLOCK FRIEND
	// Creates a moment out of a given amount of seconds
	/**
		@brief Creates a timestamp by its given parameter and current system time in seconds
		@param seconds Time that will be added to current time, for a new moment in time(positive values only!)
	*/
	Moment(double seconds); // must be private
//public:
	/// assignment operator for a moment
	/**
		@brief Assigns a given Moment and its values, to the current Moment
		@param [in] refMoment Uses this Moment and its values
	*/
	Moment& operator= (const Moment& refMoment);

	// adds a duration to a moment and results in a moment
	/**
		@brief Adds a given Duration to the current Moment and returns a new Moment
		@param [in] refDuration uses this Duration to add (positive values only!)
	*/
	Moment operator+ ( const Duration & refDuration ) const;

	// Subtracts a duration to a moment and results in a moment
	/**
		@brief Subtracts a given Duration to the current Moment and returns a new Moment
		@param [in] refDuration uses this Duration to subtract (positive values only!)
	*/
	Moment operator- ( const Duration & refDuration ) const;

	// Subtracts a moment from a moment and results in a duration
	Duration operator- (const Moment & refDuration) const;

	// adds a duration to a moment and returns this moment
	Moment& operator+= (const Duration & refDuration);

	/// substracts a duration from a moment and returns this moment
	Moment & operator-= (const Duration & refDuration);

	friend ostream& operator<< (ostream & lhs, const Moment &refDuration);
	friend istream& operator>> (istream & lhs, Moment & refDuration);
	// appends a moment to an ostream and return an ostream
	//ostream& operator<< (ostream & lhs, const Moment &rhs) const;

	// writes a moment to an istream and return istream
	//istream& operator>> (istream & lhs, Moment & rhs);
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