#include "coordinate.hpp"

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
      
      std::ostream & operator<<(std::ostream & lhs, const coordinate & rhs) {
         // Since a coordinate is specified as a distance in meters to an arbitrary origin,
         // the symbol for meter, 'm',  is added.
         // Metric prefixes are not included as to keep the code concise.
         lhs << "coordinate(" << rhs.x << "m, " << rhs.y << "m, " << rhs.z << "m)";
         return lhs;
      }
   }
}

