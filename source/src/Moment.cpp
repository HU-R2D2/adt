#include "../include/Moment.hpp"
//#include "../include/Duration.hpp"
//namespace adt	{

Moment::Moment( )	{
	//time_t t = time(0);
	//seconds = t;
}
Moment::Moment(double moment) throw (MomentException) : moment{moment} 	{
	//time_t t = time(0);
	if(this->moment < 0)
		throw MomentException("Moment smaller than 0, constructor called wrongly");
	//this->seconds = seconds;
}
Moment& Moment::operator= (const Moment& m)	{
	if(&m == this)
    	return *this;
    this->moment = m.moment;
    return *this;
}
Moment Moment::operator+ ( const Duration & rhs ) const	{
	// Return new Moment that is the result of adding a given Duration
	// Old Moment is not modified
	Moment rMoment(0);
	rMoment.moment = this->moment + rhs.get_seconds();
	return rMoment;
}
Moment Moment::operator- ( const Duration & rhs ) const	{
	// Return new Moment that is the result of subtracting a given Duration
	// Old Moment not modified
	// If Subtraction results in a time smaller than 0, return 0
	assert(rhs.get_seconds() > 0);
	double saved_result;
	Moment rMoment(0);
	if( (saved_result = (this->moment - rhs.get_seconds()) ) < 0)	{
		rMoment.moment = 0;
		return rMoment;
	}
	rMoment.moment = saved_result;
	return rMoment;
}
Duration Moment::operator- (const Moment & rhs) const	{
	// Return new Duration that is the result of subtracting a given Moment
	// Old Moment not modified
	// If Subtracting results in a time smaller than 0, return Duration of 0
	assert(rhs.moment > 0);
	double saved_result;
	if( (saved_result = (this->moment - rhs.moment) ) < 0)
		return (0 * Duration::SECOND);
	return (saved_result * Duration::SECOND);
}

Moment& Moment::operator+= (const Duration & rhs)	{
	//Needs to return same Moment but with greater time in seconds
	//Does not change Duration
	assert(rhs.get_seconds() > 0);
	this->moment += rhs.get_seconds();
	return *this;
}

Moment& Moment::operator-= (const Duration & rhs)	{
	//Needs to return same Moment, but with smaller time in seconds
	//Does not change Duration
	assert(rhs.get_seconds() > 0);
	this->moment -= rhs.get_seconds();
	return *this;
}

double Moment::get_time() const	{
	return this->moment;
}

ostream& operator<< (ostream & lhs, const Moment &rhs)	{
	lhs << rhs.moment;
	return lhs;
}

istream& operator>> (istream & lhs, Moment & rhs)	{
	double read_error = -1;
	lhs >> read_error;
	if(read_error <= -1)	{
		throw MomentException("value of moment cannot be negative, istream error ");
	}
	rhs.moment = read_error;
	return lhs;
}
bool operator>(const Moment& m1, const Moment& m2)	{
	if (m1.get_time() > m2.get_time())
		return true;
	return false;
}
bool operator<(const Moment& m1, const Moment& m2)	{
	if (m1.get_time() < m2.get_time())
		return true;
	return false;
}
//};