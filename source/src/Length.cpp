#include "../include/Length.hpp"

const Length Length::METER(1);
const Length Length::CENTIMETER(1/100);

Length::Length(double l):
	l{l}
{}

Length& Length::operator= (const Length& rhs){
	l = rhs.l;
	return *this;
}

Length Length::operator+ (const Length& rhs) const {
  Length temp {*this};
  temp.l = temp.l + rhs.l;
  return temp;
}

Length Length::operator- (const Length& rhs) const {
	Length temp {*this};
	temp.l = temp.l - rhs.l;
	return temp;	
}

Length Length::operator* (double number) const {
  Length temp {*this};
  temp.l = number * temp.l;
  return temp;	
}

Length operator* (double n, const Length & rhs) {
  Length temp {rhs};
  temp.l = temp.l * n;
  return temp;
}

Length Length::operator/ (double number) const {		// mag niet delen door 0!!
	Length temp {*this};
	if(number != 0) {
		temp.l = temp.l / number;
	}
	return temp; 
}

double Length::operator/ (const Length & rhs) const{
	double temp = l;
	if(rhs.l != 0) {
		temp = temp / rhs.l;
	}
	return temp; 
}

Length& Length::operator+= (const Length & rhs) {
  l += rhs.l;
  return *this;
}

Length& Length::operator-= (const Length & rhs) {
	double temp = l;
	l -= rhs.l;
	return *this;
}

bool Length::operator> (const Length& rhs) const {
  if(l > rhs.l){
    return true;
   }else{
    return false;
   }
}

bool Length::operator< (const Length& rhs) const{
  if(l < rhs.l){
    return true;
   }else{
    return false;
   }	
}

std::ostream& operator<< (std::ostream& lhs, const Length& rhs) {
	lhs << rhs.l;
    return lhs;
}

//==============================================================================================================
std::istream& operator>>( std::istream& is, Length& rhs){  //?
	
}		