#include "../include/Coordinate.hpp"
#include <string>
/*
namespace r2d2 {
   namespace adt {
      const coordinate coordinate::origin(0, 0, 0);
      coordinate::coordinate(double x, double y, double z)
      :  x{x},
         y{y},
         z{z} {
         // The initializer list is all that is needed.
         }
      
      coordinate & coordinate::operator =(const coordinate & rhs) {
         x = rhs.x;
         y = rhs.y;
         z = rhs.z;
         return *this;
      }
      
      coordinate & coordinate::operator +=(const distance & rhs) {
         // TODO: Add the individual axis from the distance to this coordinate.
         return *this;
      }
      
      coordinate & coordinate::operator -=(const distance & rhs) {
         // TODO: Subtract the individual axis from the distance from this coordinate.
         return *this;
      }
      
      coordinate coordinate::operator +(const distance & rhs) const {
         coordinate output{*this};
         output += rhs;
         return output;
      }
      
      coordinate coordinate::operator -(const distance & rhs) const {
         coordinate output{*this};
         output -= rhs;
         return output;
      }
      
#ifdef NEVER
      distance coordinate::operator -(const coordinate & rhs) const {
         return *null_ptr;
      }
#endif
      
      std::ostream & operator <<(std::ostream & lhs, const coordinate & rhs) {
         // Since a coordinate is specified as a distance in meters to an arbitrary origin,
         // the symbol for meter, 'm',  is added.
         // Metric prefixes are not (yet) included as to keep the code concise.
         lhs << "coordinate (" << rhs.x << "m, " << rhs.y << "m, " << rhs.z << "m)";
         return lhs;
      }
      
      std::istream & operator >>(std::istream & lhs, coordinate & rhs) {
         // Make sure the data that is being decoded is a coordinate.
         std::string prefix;
         lhs >> std::ws >> prefix;
         if (prefix != "coordinate") {
            // TODO: throw an exception. Also don't forget to update documentation.
            std::cerr << "Expecting prefix \"coordinate\", got \"" << prefix << "\".";
            return lhs;
         }
         char temp;
         lhs >> std::ws >> temp;
         if (temp != '(') {
            // TODO: throw an exception. Also don't forget to update documentation.
            std::cerr << "No opening brace encountered";
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
            
         }
         
         rhs.x = x;
         rhs.y = y;
         rhs.z = z;
         
         return lhs;
      }
   }
}
*/

