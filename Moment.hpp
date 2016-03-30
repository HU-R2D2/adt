#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include <iostream>
#ifndef _MOMENT_HPP
#define _MOMENT_HPP
using namespace std;
/**
	ToDo implementation of a moment
	Testing
	Review
	Add a timestamp struct
	Add Enums
*	@author 		Ferdi Stoeltie
*	@date			30-03-2016
*	@version		0.2
*	@brief			This class provides a timestamp of a moment in time. Due to its use in R2D2 (as of yet), a Moment object can only be created by the Clock.

*/
class Moment{
friend class Clock;
public:
	/// Constructor of a moment, is private so that it is only accessible by the Clock
	/**
		@brief Creates a Moment with the current moment of time as its default Moment
	*/
	Moment(); // MUST BE PRIVATE FOR CLOCK FRIEND
	// Creates a moment out of a given amount of seconds
	/**
		@brief Creates a Moment by its given parameter and current system time in seconds
		@param seconds Time that will be added to current time, for a new moment in time
	*/
	Moment(double seconds); // must be private
	// Test constructor for tests only!
//public:
	/// assignment operator for a moment
	/**
		@brief Assigns a given Moment and its values, to the current Moment
		@param [in] refMoment Uses this Moment and its values
		@return Current Moment with values from given Moment
	*/
	Moment& operator= (const Moment& refMoment);

	// adds a duration to a moment and results in a moment
	/**
		@brief Adds a given Duration to the current Moment and returns a new Moment
		@param [in] refDuration uses this Duration to add (positive values only!)
		@return new Moment that is the result of adding a given Duration from current Moment

	*/
	Moment operator+ ( const Duration& refDuration ) const;

	// Subtracts a duration to a moment and results in a moment
	/**
		@brief Subtracts a given Duration to the current Moment and returns a new Moment
		@param [in] refDuration uses this Duration to subtract (positive values only!)
		@return new Moment that is the result of subtracting a given Duration from current Moment
		@warning Only accepts Durations with positive values
	*/
	Moment operator- ( const Duration& refDuration ) const;

	// Subtracts a moment from a moment and results in a duration
	/**
		@brief Subtracts a given Moment from the current Moment a duration
		@param [in] a given Moment
		@return new Duration that is the result of subtracting a given Moment from current Moment
		@warning Only accepts Durations with positive values
	*/
	Duration operator- (const Moment& refMoment) const;

	// adds a duration to a moment and returns this moment
	/**
		@brief Adds a Duration to the current moment and returns the current moment with added result
		@param [in] Duration const reference
		@return Same Moment with added duration
	*/
	Moment& operator+= (const Duration& refDuration);

	/// substracts a duration from a moment and returns this moment
	/**
		@brief Subtracts a Duration to the current moment and returns the current moment with added result
		@param [in] Duration const reference
		@return Same Moment with subtracted duration
		@warning Only accepts Durations with positive values
	*/
	Moment & operator-= (const Duration& refDuration);

	/**
		@brief Reads Moment into given ostream
		@param [in] lhs The ostream to which should be written
		@param [in] The Moment that contains the data
		@return Same ostream for chaining
	*/
	friend ostream& operator<< (ostream& lhs, const Moment& refDuration);

	/**
		@brief Reads from stream data into Moment
		@param [in] lhs The istream from which should be read
		@param [in] The Moment that will contain the data
		@return Same istream for chaining
	*/
	friend istream& operator>> (istream& lhs, Moment& refDuration);
//private:
	double seconds;
};
#endif 