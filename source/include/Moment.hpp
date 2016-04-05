#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <stdint.h>
#ifndef _MOMENT_HPP
#define _MOMENT_HPP
//namespace adt	{
using namespace std;
/*
	[ToDo (not ordered)
	implementation of a moment
	Testing
	Review
	Add a DateTime 
	Test on Linux
	Add a timestamp struct and Enums]
*/

class MomentException : public exception
{
public:
	MomentException(string error) : error{error} {
	}
	virtual const char* what() const throw()
	{
		return error.c_str();
	}
	string error;
};
class Duration;
//!	@author 		Ferdi Stoeltie 1665045
//!	@date			31-03-2016
//!	@version		0.4
//!	@brief			This class provides a timestamp of a moment in time. Due to its use in R2D2 (as of yet), a Moment object can only be created by the Clock.
class Moment{
friend class Clock;
public:
	/// Constructor of a moment, is private so that it is only accessible by the Clock
	
	//!	@brief Public default constructor with time 0. A filled Moment can be obtained by the Clock
	Moment(); // Public default ctor
	// Creates a moment out of a given amount of seconds

	
	// Test constructor for tests only!
//public:
	/// assignment operator for a moment
	//!	@brief Assigns a given Moment and its values, to the current Moment
	//!	@param [in] refMoment Uses this Moment and its values
	//!	@return Current Moment with values from given Moment
	Moment& operator= (const Moment& refMoment);

	// adds a duration to a moment and results in a moment
	//!	@brief Adds a given Duration to the current Moment and returns a new Moment
	//!	@param [in] refDuration uses this Duration to add (positive values only!)
	//!	@return new Moment that is the result of adding a given Duration from current Moment
	Moment operator+ ( const Duration& refDuration ) const;

	// Subtracts a duration to a moment and results in a moment
	
	//!	@brief Subtracts a given Duration to the current Moment and returns a new Moment
	//!	@param [in] refDuration uses this Duration to subtract (positive values only!)
	//!	@return new Moment that is the result of subtracting a given Duration from current Moment
	//!	@warning Only accepts Durations with positive values
	Moment operator- ( const Duration& refDuration ) const;

	// Subtracts a moment from a moment and results in a duration
	//!	@brief Subtracts a given Moment from the current Moment a duration
	//!	@param [in] a given Moment
	//!	@return new Duration that is the result of subtracting a given Moment from current Moment
	//!	@warning Only accepts Durations with positive values
	Duration operator- (const Moment& refMoment) const;

	// adds a duration to a moment and returns this moment
	//!	@brief Adds a Duration to the current moment and returns the current moment with added result
	//!	@param [in] Duration const reference
	//!	@return Same Moment with added duration
	Moment& operator+= (const Duration& refDuration);

	/// substracts a duration from a moment and returns this moment
	//!	@brief Subtracts a Duration to the current moment and returns the current moment with added result
	//!	@param [in] Duration const reference
	//!	@return Same Moment with subtracted duration
	//!	@warning Only accepts Durations with positive values
	Moment & operator-= (const Duration& refDuration);

	//!	@brief Reads Moment into given ostream
	//!	@param [in] lhs The ostream to which should be written
	//!	@param [in] The Moment that contains the data
	//!	@return Same ostream for chaining
	friend ostream& operator<< (ostream& lhs, const Moment& refDuration);
	
	//!	@brief Reads from stream data into Moment
	//!	@param [in] lhs The istream from which should be read
	//!	@param [in] The Moment that will contain the data
	//!	@return Same istream for chaining
	friend istream& operator>> (istream& lhs, Moment& refDuration);
	
	//! @brief Returns current moment in time as a double
	//! @return Current time held by this moment as a double
	double get_time() const;
private:
	//!	@brief Creates a Moment by its given parameter in seconds
	//!	@param seconds Time that will be added to current time, for a new moment in time
	Moment(double seconds) throw (MomentException); // must be private, and friendly acces to Clock
	double moment = 0;
};
// Dummy for test of Moment
class Clock{
public:
	Moment getMoment()	{
		return Moment(time(0));
	}
	Moment getMoment(double time)	{
		return Moment(time);
	}
};
//};

#endif 