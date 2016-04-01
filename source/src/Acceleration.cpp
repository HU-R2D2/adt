#include "../include/Acceleration.hpp"

Acceleration::Acceleration()
{
	value = 0.0;
}

Acceleration::Acceleration(double value):
	value{value}
{
}

Acceleration::Acceleration(Distance dist, Duration dur)
{
	
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

}

Acceleration Acceleration::operator* (const double & lhs) const
{

}

Acceleration Acceleration::operator/ (const double & rhs) const
{

}

Duration Acceleration::operator/ (const Distance & lhs) const
{

}

bool Acceleration::operator> (const Acceleration & rhs) const
{

}

bool Acceleration::operator< (const Acceleration & rhs) const
{

}

std::ostream & operator <<(std::ostream & lhs, const Acceleration & rhs) {

}


std::istream & operator >>(std::istream & lhs, Acceleration & rhs){



}