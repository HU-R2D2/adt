#include "../include/Speed.hpp"
// Constructors
Speed::Speed(double val): value{val}{}

// Operators
Speed operator/ ( const Length & l, const Duration & d){
  return Speed{l.length /d.seconds}; 
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
  Length l = value * rhs.seconds * Length::METER;
  return l;
}

Length operator*(const Duration & lhs, const Speed & rhs){
  Length l = lhs.seconds * rhs.value * Length::METER;
  return l;
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
  if(rhs != 0){
    return Speed{value / rhs};
  }
  return *this;
}

Speed & Speed::operator/= ( const double & rhs ){
  if(rhs != 0){
    value /= rhs;
  } 
  return *this;
}

double Speed::operator/(const Speed & rhs){
  return value/rhs.value;
}

std::ostream& operator<<(std::ostream & os, const Speed &rhs){
  os << rhs.value << "m/s";
  return os;
}

std::istream& operator>>(std::istream & is, Speed & rhs){
   Length distance;
   char per;
   std::string time_span;
   // TODO: make sure any characters beyond timespan are not considered.
   is >> distance >> std::ws >> per >> std::ws >> time_span;
   if (per != '/') {
      throw std::runtime_error{"Speed: Missing character \'/\'."};
   }
   const struct {std::string suffix; const Duration & factor;} possible_suffixes[] = {
      {"s", Duration::SECOND},
      {"ms", Duration::MILLISECOND}
   };
   for (const auto & possibility : possible_suffixes) {
      if (time_span == possibility.suffix) {
        rhs = distance / possibility.factor;
        return is;
      }
   }
  throw std::runtime_error{"Speed: Either stream ended, or none of the known extensions match the specified one."};
}