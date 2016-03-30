#include "../include/Coordinate.hpp"
#include "../include/Distance.hpp"
#include <string>

const Coordinate Coordinate::origin(0, 0, 0);
Coordinate::Coordinate(double x, double y, double z)
:  x{x},
   y{y},
   z{z} {
   // The initializer list is all that is needed.
}

Coordinate & Coordinate::operator =(const Coordinate & rhs) {
   x = rhs.x;
   y = rhs.y;
   z = rhs.z;
   return *this;
}

Coordinate & Coordinate::operator +=(const Distance & rhs) {
   this->x += rhs.x;
   this->y += rhs.y;
   this->z += rhs.z;
   return *this;
}

Coordinate & Coordinate::operator -=(const Distance & rhs) {
   this->x -= rhs.x;
   this->y -= rhs.y;
   this->z -= rhs.z;
   return *this;
}

Coordinate Coordinate::operator +(const Distance & rhs) const {
   Coordinate output{*this};
   output += rhs;
   return output;
}

Coordinate Coordinate::operator -(const Distance & rhs) const {
   Coordinate output{*this};
   output -= rhs;
   return output;
}

Distance Coordinate::operator-(const Coordinate &rhs) const {
   return Distance{this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};
}

std::ostream & operator <<(std::ostream & lhs, const Coordinate & rhs) {
   // Since a coordinate is specified as a distance in meters to an arbitrary origin,
   // the symbol for meter, 'm',  is added.
   // Metric prefixes are not (yet) included as to keep the code concise.
   // TODO: remove the 'm', as this is the task of the underlying "distance"(?) type.
   lhs << "coordinate (" << rhs.x << "m, " << rhs.y << "m, " << rhs.z << "m)";
   return lhs;
}

std::istream & operator >>(std::istream & lhs, Coordinate & rhs) {
   // Make sure the data that is being decoded is a coordinate.
   std::string prefix;
   lhs >> std::ws >> prefix;
   if (prefix != "coordinate") {
      throw std::runtime_error{"Expecting prefix \"coordinate\", got something else."};
   }
   char temp;
   lhs >> std::ws >> temp;
   if (temp != '(') {
      throw std::runtime_error{"No opening brace encountered"};
   }

   // To guarantee the coordinate remains unchanged when an error occurs,
   // a temporary storage is needed for the values.
   // If not, throw an exception or something along those lines.
   double x, y, z;
   auto ReadComponent = [](std::istream & lhs, char expectedUnit, char expectedSeperator) {
      double value;
      char unit, separator;
      lhs >> value >> unit >> separator;
      if(unit != expectedUnit) {
         throw std::runtime_error{"Wrong or missing unit indicator."};
      }
      if(separator != expectedSeperator){
         throw std::runtime_error{"Wrong or missing seperator."};
      }
      return value;
   };
   x = ReadComponent(lhs, 'm', ',');
   y = ReadComponent(lhs, 'm', ',');
   z = ReadComponent(lhs, 'm', ')');

   if (!lhs) {
      throw std::runtime_error{"Coordinate wasn't read in its entirety when end of stream was reached. "};
   }

   rhs.x = x;
   rhs.y = y;
   rhs.z = z;

   return lhs;
}

const double & Coordinate::getX() const {
   return x;
}

const double & Coordinate::getY() const {
   return y;
}

const double & Coordinate::getZ() const {
   return z;
}