#include "../include/Duration.hpp"
#include <stdexcept>

const Duration Duration::SECOND(1);
const Duration Duration::MILLISECOND(1/1000);
const Duration Duration::MINUTE(60);

Duration::Duration():
	seconds{0.0}
{}

Duration::Duration(double seconds): 
	seconds{seconds} 
{}

Duration Duration::operator+( const Duration& rhs) const {
	double result = seconds + rhs.seconds;
	return Duration(result);
}

Duration Duration::operator- (const Duration& rhs) const {
	double result = seconds - rhs.seconds;
	return Duration(result);
}

Duration& Duration::operator+= (const Duration& rhs) {
	this->seconds += rhs.seconds;
	return *this;
}
	
Duration& Duration::operator-= (const Duration& rhs) {
	seconds -= rhs.seconds;
	return *this;
}

Duration Duration::operator* (const double& rhs) const {
	return Duration{seconds * rhs};
}

Duration Duration::operator/ (const double& rhs) const {
	Duration temp {*this};
	if(rhs != 0) {
		temp.seconds = temp.seconds / rhs;
	}
	return temp; 
}
bool Duration::operator< (const Duration& rhs) const {
	return seconds < rhs.seconds;
}
bool Duration::operator> (const Duration& rhs) const {
	return seconds > rhs.seconds;
}
double Duration::operator/ (const Duration & rhs) const
{
	return seconds / rhs.seconds;
}

std::ostream& operator<<(std::ostream& lhs, const Duration& rhs) {
	lhs<< rhs.seconds << "s";
	return lhs;
}

Duration operator* ( double n, const Duration & rhs) {
	return Duration{n * rhs.seconds};
}

std::istream & operator>>(std::istream & lhs, Duration & rhs) {
	std::string prefix;
	double seconds;
	lhs >> std::ws >> prefix;
	if (prefix != "Duration") {
		throw std::runtime_error{"Expecting prefix \"duration\", got something else."};
	}
	lhs >> seconds;
	if (!lhs) {
		throw std::runtime_error{"Duration wasn't read in its entirety when end of stream was reached. "};
	}
	rhs.seconds = seconds;
	return lhs;
}

Duration& Duration::operator=(const Duration& rhs) {
	seconds = rhs.seconds;
	return *this;
}

double Duration::get_seconds() const {
	return seconds;
}
