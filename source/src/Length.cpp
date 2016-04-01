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
	double temp = length;
	length -= rhs.length;
	return *this;
}

bool Length::operator> (const Length& rhs) const {
  if(length > rhs.length){
    return true;
   }else{
    return false;
   }
}

bool Length::operator< (const Length& rhs) const{
   if(length < rhs.length) {
      return true;
   } else {
      return false;
   }	
}

std::ostream& operator<< (std::ostream& lhs, const Length& rhs) {
   lhs << rhs.length << "m";
   return lhs;
}

//==============================================================================================================
std::istream& operator>>( std::istream& is, Length& rhs) {
   double value;
   std::string suffix;
   // Read the value, and remove any trailing whitespace.
   is >> value >> std::ws;
   if (!is) {
      throw std::runtime_error{"Lenght: Reached end of stream before fully reading a length."};
   }
   // Construct the metric suffix.
   while(1) {
      char temp;
      // The end of the stream might coincidence with the end of the metric specifier.
      // As such do not throw an exception but test the current stream.
      if (is >> temp) {
         // A suffix for metric values only consist out of alphabetic characters;
         // anything else could indicate the end of this suffix, and should be put back.
         if (isalpha(temp)) {
            suffix += temp;
         } else {
            // That character is not supposed to be used by this stream;
            // put it back, as some other stream might rely on it.
            is.putback(temp);
            break;
         }
      } else {
         // No point in reading from an empty or corrupt stream.
         break;
      }
   }
   // Specifies all available suffixes, and which value corresponds to it.
   const struct {std::string suffix; const Length & factor;} possible_suffixes[] = {
         {"m", Length::METER},
         {"cm", Length::CENTIMETER}
   };
   for (const auto & possibility : possible_suffixes) {
      if (suffix == possibility.suffix) {
         rhs = value * possibility.factor;
         return is;
      }
   }
   throw std::runtime_error{"Length: Either stream ended, or none of the known extensions match the specified one."};
}