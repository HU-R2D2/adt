#include "Moment.hpp"

Moment::Moment( )	{
	time_t t = time(0);
	seconds = t;
}

Moment::Moment(double seconds) : seconds{seconds}	{
	//if(seconds < 0)
	//	seconds = 0;
}

Moment& Moment::operator= (const Moment& m)	{
	if(&m == this)
    	return *this;
    seconds = m.seconds;
    return *this;
}
Moment Moment::operator+ ( const Duration & rhs ) const	{
	// Return new Moment that is the result of adding a given Duration
	// Old Moment is not modified
	return Moment(this->seconds + rhs.seconds);
}
Moment Moment::operator- ( const Duration & rhs ) const	{
	// Return new Moment that is the result of subtracting a given Duration
	// Old Moment not modified
	// If Subtraction results in a time smaller than 0, return 0
	double savedResult;
	if( (savedResult = (this->seconds - rhs.seconds) ) < 0)
		return Moment(0);
	return Moment(savedResult);

}
Duration Moment::operator- (const Moment & rhs) const	{
	// Return new Duration that is the result of subtracting a given Moment
	// Old Moment not modified
	// If Subtracting results in a time smaller than 0, return Duration of 0
	double savedResult;
	if( (savedResult = (this->seconds - rhs.seconds) ) < 0)
		return Duration(0);
	return Duration(savedResult);
}

Moment& Moment::operator+= (const Duration & rhs)	{
	//Needs to return same Moment
	//Does not change Duration
	this->seconds -= rhs.seconds;
	return *this;
}