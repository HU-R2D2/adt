#include "../include/Moment.hpp"
namespace adt	{


Moment::Moment( )	{
	//time_t t = time(0);
	//seconds = t;
}

Moment::Moment(double seconds) throw (MomentException) : seconds{seconds} 	{
	//time_t t = time(0);
	if(this->seconds < 0)
		throw MomentException();
	//this->seconds = seconds;
}
Moment& Moment::operator= (const Moment& m)	{
	if(&m == this)
    	return *this;
    this->seconds = m.seconds;
    return *this;
}
Moment Moment::operator+ ( const Duration & rhs ) const	{
	// Return new Moment that is the result of adding a given Duration
	// Old Moment is not modified
	Moment rMoment(0);
	rMoment.seconds = this->seconds + rhs.get_seconds();
	return rMoment;
}
Moment Moment::operator- ( const Duration & rhs ) const	{
	// Return new Moment that is the result of subtracting a given Duration
	// Old Moment not modified
	// If Subtraction results in a time smaller than 0, return 0
	assert(rhs.get_seconds() > 0);
	double savedResult;
	Moment rMoment(0);
	if( (savedResult = (this->seconds - rhs.get_seconds()) ) < 0)	{
		rMoment.seconds = 0;
		return rMoment;
	}
	rMoment.seconds = savedResult;
	return rMoment;
}
Duration Moment::operator- (const Moment & rhs) const	{
	// Return new Duration that is the result of subtracting a given Moment
	// Old Moment not modified
	// If Subtracting results in a time smaller than 0, return Duration of 0
	assert(rhs.seconds > 0);
	double savedResult;
	if( (savedResult = (this->seconds - rhs.seconds) ) < 0)
		return Duration(0);
	return Duration(savedResult);
}

Moment& Moment::operator+= (const Duration & rhs)	{
	//Needs to return same Moment but with greater time in seconds
	//Does not change Duration
	assert(rhs.get_seconds() > 0);
	this->seconds += rhs.get_seconds();
	return *this;
}

Moment& Moment::operator-= (const Duration & rhs)	{
	//Needs to return same Moment, but with smaller time in seconds
	//Does not change Duration
	assert(rhs.get_seconds() > 0);
	this->seconds -= rhs.get_seconds();
	return *this;
}

double Moment::getSeconds()	{
	return this->seconds;
}

ostream& operator<< (ostream & lhs, const Moment &rhs)	{
	lhs << rhs.seconds;
	return lhs;
}

istream& operator>> (istream & lhs, Moment & rhs)	{
	lhs >> rhs.seconds;
	return lhs;
}

};