#include <ctime>
#include <assert.h> 
#include "Duration.hpp"
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <stdint.h>

namespace adt{
using namespace std;
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
struct proto_hourlyTimes{
	uint8_t hour, minute, second;
	proto_hourlyTimes(uint8_t hour = 0, uint8_t minute = 0, uint8_t second = 0) : 
	hour{hour}, minute{minute}, second{second}	{}
};
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
};
class DATETIME{


public:
	DATETIME(DAY day, MONTH month, int mday, int year, int hour, int minute, int second);
	DATETIME(double gtime);
private:
	
	DAY calculateDay(proto_datetime& dt);
	DAY calculateMonthDayPattern(int16_t mday);
	int calculateMonthlyPattern(int year, int month);
	int calculateCenturyPattern(int year);
	DAY day;
	MONTH month;
	int mday, year, hour, minute, second;

};
}