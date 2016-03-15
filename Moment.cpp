#include "Moment.hpp"

Moment::Moment( )	{
	time_t t = time(0);
	seconds = t;
}

Moment::Moment(double seconds) : seconds{seconds}	{
	
}

Moment& Moment::operator= (const Moment& m)	{
	if(&m == this)
    	return *this;
    seconds = m.seconds;

    return *this;
}