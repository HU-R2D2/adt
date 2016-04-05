#include "../include/Speed.hpp"
// Constructors
Speed::Speed(double value): ADT_Base<Speed>(value){}

// Operators
Speed operator/ ( const Length & l, const Duration & d){
  if (d.value != 0){
     return Speed{l/Length::METER / (d/Duration::SECOND)}; 
  }
  return Speed{0};
}

Length Speed::operator*(const Duration & rhs) const{
    Length l = value * rhs.value * Length::METER;
    return l;
}

Length operator*(const Duration & lhs, const Speed & rhs){
  Length l = lhs.value * rhs.value * Length::METER;
  return l;
}
  
Speed operator* ( double n, const Speed & rhs ){
  return Speed{rhs.value * n};
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