#include "../include/Duration.hpp"

const Duration Duration::SECOND(1);
const Duration Duration::MILLISECOND(1/1000);
const Duration Duration::MINUTE(60);

Duration::Duration():
	seconds{0.0}
{}

Duration::Duration(double seconds): 
	seconds{seconds} 
{}

Duration Duration::operator+( const Duration& rhs) const{
	double result = seconds + rhs.seconds;
	return Duration(result);
}

Duration Duration::operator- (const Duration& rhs) const {
	double result = seconds - rhs.seconds;
	return Duration(result);
}

Duration Duration::operator* (const double& rhs) const{
	return Duration{seconds * rhs};
}

Duration Duration::operator/ (const double& rhs) const{
	return Duration{seconds / rhs};
}
bool Duration::operator< (const Duration& rhs) const{
	return seconds < rhs.seconds;
}
bool Duration::operator> (const Duration& rhs) const{
	return seconds > rhs.seconds;
}
double Duration::operator/ (const Duration & rhs) const
{
	return seconds / rhs.seconds;
}

std::ostream& operator<<(std::ostream& lhs, const Duration& rhs){
	lhs<< rhs.seconds << "s";
	return lhs;
}

Duration operator* ( double n, const Duration & rhs){
	return Duration{n * rhs.seconds};
}

std::istream& operator>>(std::istream& lhs, Duration& rhs){
}

Duration& Duration::operator=(const Duration& rhs){
	seconds = rhs.seconds;
	return *this;
}

double Duration::get_seconds() const
{
	return seconds;
}
