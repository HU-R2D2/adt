#include "Duration.hpp"

namespace r2d2 {
	namespace adt{
		private:
			Duration(){
				seconds(moment);
			}
			Duration(double seconds): seconds{seconds} {};
		public:
			const Duration 1_second(){
				return Duration(1);
			}
			Duration operator+( const duration& rhs){
				double result = seconds + rhs.seconds;
				return Duration(result);
			}
			Duration operator- (const duration& rhs){
				double result = seconds - rhs.seconds;
				return Duration(result);
			}
			double operator* (const duration& rhs){
				double result = seconds * rhs.seconds;
				return result;
			}
			double operator/ (const duration& rhs){
				double result = seconds/rhs.seconds;
				return result;
			}
			bool operator< (const duration& rhs){
				return seconds < rhs.seconds;
			}
			bool operator> (const duration& rhs){
				return seconds > rhs.seconds;
			}
			friend std::ostream& operator<<(std::ostream& lhs, const duration& rhs){
				lhs<< "duration: " << rhs.seconds << "s";
				return lhs;
			}
			friend std::istream& operator>>(std::istream& lhs, duration& rhs){
				std::cout<< "enter duration in seconds: " << std::endl;
				lhs>>rhs.seconds;
				return lhs;
			}
			Duration& operator=(const duration& rhs){
				seconds = rhs.seconds;
				return *this;
			}
		private:
			double seconds;
	}
}

