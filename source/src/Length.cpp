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

Length Length::operator+ (const Length& rhs) const{
  Length temp {*this};
  temp.l = temp.l + rhs.l;
  return temp;
}

Length Length::operator- (const Length& rhs) const{		// let op geen negatieve lengte!!
  Length temp {*this};
  if ((temp.l - rhs.l) >= 0) {		// als uitkomst negatief, uitkomst wordt 0
	temp.l = temp.l - rhs.l;
  }
  else temp.l = 0;
  return temp;	
}

Length Length::operator* (double number) const{
  Length temp {*this};
  temp.l = number * temp.l;
  return temp;	
}

Length Length::operator/ (double number) const {		// mag niet delen door 0!!
	Length temp {*this};
	if(number != 0) {
		temp.l = temp.l / number;
	}
	return temp; 
}

Length& Length::operator+= (const Length & rhs){
  l += rhs.l;
  return *this;
}

Length& Length::operator-= (const Length & rhs) {		// let op geen negatieve lengte!!
	double temp = l;
	if((temp -= rhs.l) >= 0) {
		l -= rhs.l;
	}
	else l = 0;
	return *this;
}

double Length::operator/ (const Length & rhs) const{
  return l / rhs.l;
}

bool Length::operator> (const Length& rhs) const{
  if(l > rhs.l){
    return true;
   }else{
    return false;
   }
}


//=============================================================================================================
Length operator* (double n, const Length & rhs){
  Length temp {rhs};
  temp.l = temp.l * n;
  return temp;
}

Length operator/ (double n, const Length & rhs){
  Length temp {rhs};
  temp.l = temp.l / n;
  return temp;
}
//=============================================================================================================


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