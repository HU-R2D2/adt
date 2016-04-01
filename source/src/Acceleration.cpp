#include "../include/Acceleration.hpp"

Acceleration::Acceleration()
{
	value = 0.0;
}

Acceleration::Acceleration(double value):
	value{value}
{
}

Acceleration::Acceleration(const Length & lt, const Duration & dur)
{
	double travelLength = lt.l * 2;

	double travelTime = dur.get_seconds();

	value = (2 * travelTime) / (travelLength * travelLength);
}

const double Acceleration::get_acceleration() const
{
	return value;
}

void Acceleration::set_acceleration(const double val)
{
	value = val;
}


Acceleration & Acceleration::operator= (const Acceleration & rhs)
{
	value = rhs.value;

	return *this;
}

Acceleration Acceleration::operator* (const double & rhs) const
{
	return value * rhs;
}

Acceleration Acceleration::operator/ (const double & rhs) const
{
	return value / rhs;

}

Duration Acceleration::operator/ (const Length & rhs) const
{

}

bool Acceleration::operator> (const Acceleration & rhs) const
{
	if(value > rhs.value)
	{
		return true;
	}

	return false;
}

bool Acceleration::operator< (const Acceleration & rhs) const
{
	if(value < rhs.value)
	{
		return true;
	}

	return false;

}

std::ostream & operator <<(std::ostream & lhs, const Acceleration & rhs) {
	lhs << "acceleration (" << rhs.value << " m/sec)";
	return lhs;
}


std::istream & operator >>(std::istream & lhs, Acceleration & rhs){



}