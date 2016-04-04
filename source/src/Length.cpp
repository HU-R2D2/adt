#include "../include/Length.hpp"
#include <stdexcept>

const Length Length::METER(1);
const Length Length::CENTIMETER(1/100.0);

Length::Length():
  length{0.0}
{}
Length::Length(double length):
	length{length}
{}

Length& Length::operator= (const Length& rhs){
	length = rhs.length;
	return *this;
}

Length Length::operator+ (const Length& rhs) const {
  Length temp {*this};
  temp.length = temp.length + rhs.length;
  return temp;
}

Length Length::operator- (const Length& rhs) const {
	Length temp {*this};
	temp.length = temp.length - rhs.length;
	return temp;	
}

Length Length::operator* (double number) const {
  Length temp {*this};
  temp.length = number * temp.length;
  return temp;	
}

Length operator* (double n, const Length & rhs) {
  Length temp {rhs};
  temp.length = temp.length * n;
  return temp;
}

Length Length::operator/ (double number) const {		// mag niet delen door 0!!
	Length temp {*this};
	if(number != 0) {
		temp.length = temp.length / number;
	}
	return temp; 
}

double Length::operator/ (const Length & rhs) const{
	double temp = length;
	if(rhs.length != 0) {
		temp = temp / rhs.length;
	}
	return temp; 
}

Length& Length::operator+= (const Length & rhs) {
  length += rhs.length;
  return *this;
}

Length& Length::operator-= (const Length & rhs) {
	length -= rhs.length;
	return *this;
}

bool Length::operator> (const Length& rhs) const {
  return(length > rhs.length);
}

bool Length::operator< (const Length& rhs) const{
   return(length < rhs.length);	
}

std::ostream& operator<< (std::ostream& lhs, const Length& rhs) {
   lhs << rhs.length << "m";
   return lhs;
}

//==============================================================================================================
std::istream & operator>>(std::istream & lhs, Length & rhs) {
	std::string prefix;
	double length;
	lhs >> std::ws >> prefix;
	if (prefix != "Length") {
		throw std::runtime_error{"Expecting prefix \"Length\", got something else."};
	}
	lhs >> length;
	if (!lhs) {
		throw std::runtime_error{"Length wasn't read in its entirety when end of stream was reached. "};
	}
	rhs.length = length;
	return lhs;
}