#include "../include/Weight.hpp"

//constants
const Weight Weight::KILOGRAM(1);
const Weight Weight::GRAM(1/1000);

Weight::Weight(double value):ADT_Base<Weight>(value){

}

Weight::Weight():Weight(0.0){

}

Weight operator* (double n, const Weight& rhs){
	return Weight{rhs.value * n};
}

std::ostream& operator<< (std:: ostream& os, const Weight& rhs){
	os << rhs.value << "Kg";
	return os;
}

std::istream& operator>>(std::istream& is, Weight& rhs){
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
   const struct {std::string suffix; const Weight & factor;} possible_suffixes[] = {
         {"Kg", Weight::KILOGRAM}
   };
   for (const auto & possibility : possible_suffixes) {
      if (suffix == possibility.suffix) {
         rhs = value * possibility.factor;
         return is;
      }
   }
   throw std::runtime_error{"Length: Either stream ended, or none of the known extensions match the specified one."};
}

