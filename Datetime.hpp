#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include "Moment.hpp"
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <stdint.h>
#include <exception>
namespace adt{
using namespace std;
/**
	@brief Contains the Day's of the week and their value, note that Sunday = 0, Saturday = 6.
	The reason for this is because of the "algorithm" that is being used by the DateTime Class.
*/
enum DAY : uint8_t{
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	INVALID = 0xff
	
};
/**
	@brief Contains the Months of a year with January = 1 and December = 12
*/
enum MONTH : uint8_t{
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
/**
	@brief Contains a Daily time (hour, minute and second)
	@warning PROTOTYPE, NOT READY FOR DEPLOYMENT AND SHOULD BE NAMED TIME INFORMATION STRUCT
*/
struct proto_hourlyTimes{
	uint8_t hour, minute, second;
	proto_hourlyTimes(uint8_t hour = 0, uint8_t minute = 0, uint8_t second = 0) : 
	hour{hour}, minute{minute}, second{second}	{}
};
class DateTimeException : public exception
{
public:
	DateTimeException(string error) : error{error} {
		string invalid("Invalid DateTime");
		string failed("failed");
		error = (invalid + error + failed);
	}
	virtual const char* what() const throw()
	{
		return error.c_str();
	}
private:
	string error;
};
/**
*	@author 		Ferdi Stoeltie 1665045
*	@date			31-03-2016
*	@version		0.1
*	@brief			The DateTime class contains a datetime format, together with operations for subtracting, adding, differentiating and streams
*	@details		The difference between this DateTime class and Moment, 
					is that a Moment contains a single double (seconds) and stores it as a moment in time.
					DateTime offers an ordered way of storing this data and also a more human readable method of using Moment.
					Also note that a Moment can be relative to any given moment whereas DateTime always represents the Gregorian  DateTime
	@ToDo			Offer Formatting, link DateTime data to Moment for lossless switching between the two.
*	@warning		STILL UNDER DEVELOPMENT
*	@bug			List bugs here
*/
class DATETIME{
//friend Clock::get_datetime();
private:
	/**
	@brief The proto_datetime contains a time and date
	@warning PROTOTYPE, NOT READY FOR DEPLOYMENT
*/
struct proto_datetime{

	uint16_t 	year; 
	uint8_t 	mday;
	MONTH month;
	DAY day;
	proto_hourlyTimes HT;
	proto_datetime(uint16_t year, uint8_t mday, MONTH month, 
		uint8_t hour = 0, uint8_t minute = 0, uint8_t second = 0) : 
	year{year}, mday{mday}, month{month}, HT{hour, minute, second} {}

	proto_datetime(uint16_t year, uint8_t mday, MONTH month, 
		proto_hourlyTimes HT) : 
	year{year}, mday{mday}, month{month}, HT{HT} {}
	proto_datetime(){}
};
public:
	DATETIME(uint16_t year, uint8_t mday, MONTH month, 
		uint8_t hour = 0, uint8_t minute = 0, uint8_t second = 0) throw(DateTimeException); // Should not be friended to clock class

	DATETIME& operator= (const DATETIME& refDT);

	DATETIME operator+ ( const Duration& refDuration ) const;
	DATETIME operator- ( const Duration& refDuration ) const;

	DATETIME& operator+= (const Duration& refDuration);
	DATETIME& operator-= (const Duration& refDuration);

	Duration operator- (const DATETIME& refDateTime) const;
	Duration operator- (const Moment& refMoment) const;
	friend ostream& operator<< (ostream& lhs, const DATETIME& refDateTime);
	friend istream& operator>> (istream& lhs, DATETIME& refDateTime);

	DAY getDay 			() const;
	MONTH getMonth 		() const;

	int getSecond		() const;
	int getMinute		() const;
	int getHour			() const;
	int getMonthDay		() const;
	int getMonthNumber	() const;
	int getYear			() const;
	
private:
	DATETIME(double gtime); // Should be friend of Clock Class

	bool isValidDay(int year, MONTH month, int mday);

	DAY calculateDay(proto_datetime& dt);
	DAY calculateMonthDayPattern(int16_t mday);
	int calculateMonthlyPattern(int year, int month);
	int calculateCenturyPattern(int year);
	proto_datetime dt;

};
}