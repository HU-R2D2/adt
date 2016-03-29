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
   // TODO: Add the individual axis from the distance to this coordinate.
   return *this;
}

Coordinate & Coordinate::operator -=(const Distance & rhs) {
   // TODO: Subtract the individual axis from the distance from this coordinate.
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
   return Distance{};
}

std::ostream & operator <<(std::ostream & lhs, const Coordinate & rhs) {
   // Since a coordinate is specified as a distance in meters to an arbitrary origin,
   // the symbol for meter, 'm',  is added.
   // Metric prefixes are not (yet) included as to keep the code concise.
   lhs << "coordinate (" << rhs.x << "m, " << rhs.y << "m, " << rhs.z << "m)";
   return lhs;
}

std::istream & operator >>(std::istream & lhs, Coordinate & rhs) {
   // Make sure the data that is being decoded is a coordinate.
   std::string prefix;
   lhs >> std::ws >> prefix;
   if (prefix != "coordinate") {
      // TODO: throw an exception. Also don't forget to update documentation.
      std::cerr << "Expecting prefix \"coordinate\", got \"" << prefix << "\"." << std::endl;
      return lhs;
   }
   char temp;
   lhs >> std::ws >> temp;
   if (temp != '(') {
      // TODO: throw an exception. Also don't forget to update documentation.
      std::cerr << "No opening brace encountered" << std::endl;
      return lhs;
   }

   // To guarantee the coordinate remains unchanged when an error occurs,
   // a temporary storage is needed for the values.
   // TODO: Determine whether the separators are the correct ones.
   // If not, throw an exception or something along those lines.
   double x, y, z;
   lhs >> std::ws >> x >> std::ws >> temp >> temp;
   lhs >> std::ws >> y >> std::ws >> temp >> temp;
   lhs >> std::ws >> z >> std::ws >> temp >> temp;

   if (!lhs) {
      std::cerr << "Coordinate wasn't read in its entirety when end of stream was reached. " << std::endl;
      // TODO: throw an exception.
   }

   rhs.x = x;
   rhs.y = y;
   rhs.z = z;

   return lhs;
}
