// ++--++
// Roborescue
// @file <Moment.cpp>
// @date Created: <5-3-16>
// @version <1.0.0>
//
// @author <Ferdi Stoeltie 1665045>
//
// @section LICENSE
// License: newBSD
//
// Copyright © 2016, HU University of Applied Sciences Utrecht.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ++--++
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