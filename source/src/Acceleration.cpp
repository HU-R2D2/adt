#include "../include/Acceleration.hpp"

#include <iostream>

Acceleration::Acceleration()
{
	value = 0.0;
}

Acceleration::Acceleration(double value):
	value{value}
{}

Acceleration & Acceleration::operator= (const Acceleration & rhs)
{
	value = rhs.value;

	return *this;
}

Acceleration Acceleration::operator* (const double & rhs) const
{
	return Acceleration{value * rhs};
}

Acceleration Acceleration::operator*= (const double & rhs)
{
	value *= rhs;

	return * this;
}

Acceleration Acceleration::operator/ (const double & rhs) const
{
	
	if(rhs != 0.0)
		return Acceleration{value / rhs};
	
	return * this;

}
double Acceleration::operator/ (const Acceleration & rhs) const
{
	double temp = value;
  	if(rhs.value != 0) {
    	temp = temp / rhs.value;
  	}
  	return temp;
}

Acceleration Acceleration::operator/= (const double & rhs)
{
	if(rhs != 0)
	{
		value = value / rhs;
	}
	return * this;

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
	lhs << "acceleration( " << rhs.value << " m/sec )";
	return lhs;
}


std::istream & operator >>(std::istream & lhs, Acceleration & rhs){
 	// Make sure the data that is being decoded is an acceleration.
   std::string prefix;
   lhs >> std::ws >> prefix;
   if (prefix != "acceleration") {
      throw std::runtime_error{"Expecting prefix \"acceleration\", got something else."};
   }
   char temp;
   lhs >> std::ws >> temp;
   if (temp != '(') {
      throw std::runtime_error{"No opening brace encountered"};
   }

   // To guarantee the box remains unchanged when an error occurs,
   // a temporary storage is needed for the values.
   // If not, throw an exception or something along those lines.
   double acceleration;

   // The different values are separated by certain characters.
   // As they require multiple similar steps, this small lambda is defined.
   auto ReadComponent = [](std::istream & lhs, char expectedSeperator) {
      double value;
      char separator;
      lhs >> value >> separator;
      if(separator != expectedSeperator){
      	std::cout << "sep: " << separator << std::endl;
         throw std::runtime_error{"Wrong or missing seperator."};
      }
      return value;
   };

   acceleration = ReadComponent(lhs, 'm');

   if (!lhs) {
      throw std::runtime_error{"Acceleration wasn't read in its entirety when end of stream was reached. "};
   }

   rhs.value = acceleration;

   return lhs;

}

Acceleration operator/ (const Speed & s, const Duration & d)
{
	double durationValue = d / Duration::SECOND;
	double speedValue = s / (1 * Length::METER / Duration::SECOND);

	if (durationValue == 0.0 || speedValue == 0.0)
	{
		return Acceleration{0.0};
	}
	return Acceleration{ speedValue / durationValue };
	
}