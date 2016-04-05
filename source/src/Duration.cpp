#include "../include/Duration.hpp"

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

Duration operator* ( double n, const Duration & rhs){
	return Duration{n * rhs.value};
}

std::istream& operator>>(std::istream& lhs, Duration& rhs){
}


double Duration::get_seconds() const
{
	return value;
}
