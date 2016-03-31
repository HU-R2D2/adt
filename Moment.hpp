#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#ifndef _MOMENT_HPP
#define _MOMENT_HPP

namespace adt	{
using namespace std;
/*
	[ToDo implementation of a moment
	Testing
	Review
	Add a timestamp struct and Enums]
*/
/**
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
enum DAY{
	MONDAY = 1,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};
enum MONTH{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};
/*enum MONTH_OFFSET{
	JANUARY = 6,
	FEBRUARY = 2,
	MARCH = 2,
	APRIL = 5,
	MAY = 0,
	JUNE = 3,
	JULY = 5,
	AUGUST = 1,
	SEPTEMBER = 4,
	OCTOBER = 6,
	NOVEMBER = 2,
	DECEMBER = 4
};*/
enum CENTURY_PATTERN	{
	CENTURY_FIRST 	=    4,
	CENTURY_SECOND 	=    2,
	CENTURY_THIRD 	=    0,
	CENTURY_FOURTH 	=    6
};
struct DATETIME{
	
	DAY day;
	MONTH month;
	int mday, year, hour, minute, second;
	DATETIME(DAY t_day, MONTH t_month, int mday, int year, int hour, int minute, int second) : 
	day{t_day}, month{t_month}, mday{mday}, year{year}, 
	hour{hour}, minute{minute}, second{second}	{

	}
	DATETIME(double gtime)	{
		time_t givenTime = (time_t)gtime;
		struct tm * now = localtime( & givenTime );
		year 	= (now->tm_year + 1900);
		month 	= (MONTH)(now->tm_mon + 1);
		mday 	= now->tm_mday;
		//DAY d 	= (DAY)5;



		// value of century divided by 100, modulus 4 + 4

		int test = (int)(mday + 2 + (year - 2000) + ( (int)(year - 2000) / 4 ) ) % 7;
		cout << "test is:\t" << test << "\t and year is: " << year << endl;
		calculateCenturyPattern(year);
		//(d + m + y + absolute(y / 4) + 0) % 7

	}
	int calculateMonthlyPattern(int year, int month)	{
		//ToDo Still needs divider by 100 and 400 to work correctly (see wikipedia for more information)
		int FirstTwoMonths[2] = {0, 3}; // Common years have 0 and 3 for January and February
		// if year is leap year
		if(int(year / 4) == (float)(year/4))	{
			// Leap years have 6 and 2 for the first two months
			FirstTwoMonths[0] = 6;	
			FirstTwoMonths[1] = 2;
		}
		const int monthlyValues[12] = {FirstTwoMonths[0], FirstTwoMonths[1], 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
		return -1;
	}
	int calculateCenturyPattern(int year)	{
		const int centuryPattern[4] = {4, 2, 0, 6};	// Year pattern (starting 1700)
		const int startingCentury = 1700;			// Starting century of pattern

		int difference = (year - startingCentury);	// Get the difference between a given century and the starting century (1700)

		int number = ((int)(difference / 100) % 4); // Get the number for the array element that contains the correct century number
		if(number < 0)								// If number is negative, add 4 for the correct array element
			number += 4;
		return centuryPattern[number];				// Return century value for day calculation
		//cout << "difference is: " << difference << " century is " << year << " and value is " << centuryPattern[number] << " number is: " << number << endl;
	}
};
//ostream& operator<< (ostream& lhs, const Moment& refDuration);
//istream& operator>> (istream& lhs, Moment& refDuration);
}