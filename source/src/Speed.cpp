#include "../include/Speed.hpp"
// Constructors
Speed::Speed(double val): value{val}{}

// Operators
Speed operator/ ( const Length & l, const Duration & d){
  Speed s{l.l / d.seconds};
  return s; 
}

Speed & Speed::operator= (const Speed & rhs){
  value = rhs.value;
  return *this;
}

bool Speed::operator< (const Speed & rhs) const{
  return value < rhs.value;
}

bool Speed::operator> (const Speed & rhs) const{
  return value > rhs.value;
}

Speed Speed::operator+ ( const Speed & rhs ) const{
  return Speed{value + rhs.value};
}

Speed & Speed::operator+= ( const Speed & rhs){
  value += rhs.value;
  return *this;
}

Speed Speed::operator- ( const Speed & rhs ) const{
  return Speed{value - rhs.value};
}

Speed & Speed::operator-= ( const Speed & rhs ){
  value -= rhs.value;
  return *this;
}

Length Speed::operator*(const Duration & rhs) const{
  return Length{value * rhs.seconds};
}

Length operator*(const Duration & lhs, const Speed & rhs){
  return Length{lhs.seconds * rhs.value};
}

Speed Speed::operator* ( const double & rhs ) const{
  return Speed{value * rhs};
}

Speed & Speed::operator*= ( const double & rhs ){
  value *= rhs;
  return *this;
}
  
Speed operator* ( double n, const Speed & rhs ){
  return Speed{rhs.value * n};
}

Speed Speed::operator/ ( const double & rhs ) const{
  return Speed{value / rhs};
}

Speed & Speed::operator/= ( const double & rhs ){
  value /= rhs;
  return *this;
}

Speed operator/ ( double n, const Speed & rhs ){
  return Speed{rhs.value / n};
}


double Speed:: operator/(const Speed & rhs){
  return value/rhs.value;
}

std::ostream& operator<<(std::ostream & os, const Speed &rhs){}

std::istream& operator>>(std::istream & is, Speed & rhs){}

