#include "Datetime.hpp"
namespace adt{
DATETIME::DATETIME(uint16_t year, uint8_t mday, MONTH month, 
		uint8_t hour, uint8_t minute, uint8_t second) : 
	dt{year, mday, month, hour, minute, second}{}
	/*day{t_day}, month{t_month}, mday{mday}, year{year}, 
	hour{hour}, minute{minute}, second{second}	{}*/

DATETIME::DATETIME(double gtime)	{
		// ToDo figure out what to do with gtime, could be unnecessary
		time_t givenTime = (time_t)gtime;
		struct tm * now = localtime( & givenTime );
		year 	= (now->tm_year + 1900);
		month 	= (MONTH)(now->tm_mon + 1);
		mday 	= now->tm_mday;
		dt = proto_datetime(2015, 12, MONTH::MARCH);
	}
DAY DATETIME::calculateDay(proto_datetime& dt)	{
		//Todo maybe init datetime struct?
		//ToDo ready for testing

		const int year = dt.year;
		const int digitYear = dt.year - (dt.year - dt.year % 100);
		const int yearCalculation = calculateCenturyPattern(year) + digitYear + (int)(digitYear / 4);
		// ToDo Determine best way to split big calculation into smaller more readable pieces
		dt.day = (DAY)(uint8_t)((yearCalculation + calculateMonthlyPattern(year, dt.month) + dt.mday) % 7);
		return dt.day;
	}
DAY DATETIME::calculateMonthDayPattern(int16_t mday)	{
		return (DAY)(mday % 7);
	}
int DATETIME::calculateMonthlyPattern(int year, int month)	{
		//ToDo Still needs divider by 100 and 400 to work correctly (see wikipedia for more information)
		int FirstTwoMonths[2] = {0, 3}; // Common years have 0 and 3 for January and February
		// if year is leap year
		if(int(year / 4) == (float)(year/4))	{
			// Leap years have 6 and 2 for the first two months
			FirstTwoMonths[0] = 6;
			FirstTwoMonths[1] = 2;
		}
		const int monthlyValues[12] = {FirstTwoMonths[0], FirstTwoMonths[1], 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
		return monthlyValues[month - 1];
	}
int DATETIME::calculateCenturyPattern(int year)	{
		// The reason for this century pattern is because every 400 year, the pattern repeats itself (4,2,0,6)
		// The numbers are necessary for calculating the week day of a current date.
		const int centuryPattern[4] = {4, 2, 0, 6};	// Year pattern (starting 1700)
		const int startingCentury = 1700;			// Starting century of pattern

		int difference = (year - startingCentury);	// Get the difference between a given century and the starting century (1700)

		int number = ((int)(difference / 100) % 4); // Get the number for the array element that contains the correct century number
		if(number < 0)								// If number is negative, add 4 for the correct array element
			number += 4;
		return centuryPattern[number];				// Return century value for day calculation
}
DAY DATETIME::getDay() const{
	return dt.day;
}
MONTH DATETIME::getMonth() const	{
	return dt.month;
}

int DATETIME::getSecond		()	const	{
	return dt.HT.second;
}
int DATETIME::getMinute		()	const	{
	return dt.HT.minute;
}
int DATETIME::getHour			()	const	{
	return dt.HT.hour;
}
int DATETIME::getMonthDay		() const	{
	return dt.mday;
}
int DATETIME::getMonthNumber	()	const	{
	return dt.month;
}
int DATETIME::getYear			()	const	{
	return dt.year;
}

};