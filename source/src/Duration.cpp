#include "../include/Duration.hpp"
#include <stdexcept>

const Duration Duration::SECOND(1);
const Duration Duration::MILLISECOND(1.0/1000.0);
const Duration Duration::MINUTE(60);

Duration::Duration():
	ADT_Base<Duration>(0.0)
{}

Duration::Duration(double value): 
	ADT_Base<Duration>(value) 
{}

std::ostream& operator<<(std::ostream& lhs, const Duration& rhs){
	lhs<< rhs.value << "s";
	return lhs;
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
	rhs.value = seconds;
	return lhs;
}


double Duration::get_seconds() const
{
	return value;
}
