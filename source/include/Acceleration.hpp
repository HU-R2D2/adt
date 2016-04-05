//!	ToDo:
//! Check if all methods have been implemented
//!	Review
	
//!	@author 		Stephan Vivie
//! @date			01-04-2016
//!	@version		0.1
//!	@brief	       	Acceleration data type stored in meters per second.
	
#ifndef _ACCELERATION_HPP
#define _ACCELERATION_HPP

#include "Duration.hpp"
#include "ADT_Base.hpp"
#include "Speed.hpp"

#include <iostream>

class Acceleration : public ADT_Base<Acceleration>{
	protected: 
		//! @brief Constructor that sets the value to whichever value. value should be in meter per second.
		//!
		//! @param val Raw acceleration value in meter per second
		Acceleration(double val);
	public:
		friend ADT_Base<Acceleration>;
		//! @brief The default constructor of and acceleration
		Acceleration();

		//! @brief	input operator for an acceleration
		//! 
		//! @param lhs				the istream, from this istream the acceleration will be adapted
		//! @param rhs				the acceleration that will be adapted by the lhs istream
		//! @return std::istream 	the inputstream
		friend std::istream &operator>>(std::istream & lhs, Acceleration & rhs);

		//! @brief appends an accelration to an std::ostream and returns the ostream
		//! The format of the accelration will be "acceleration( 1.5 m/sec )"
	    //!
	    //! @param os 				the std::ostream to append to
	    //! @param rhs 				Object to append
	    //! @return std::ostream 	the ostream
		friend std::ostream &operator<<(std::ostream & lhs, const Acceleration & rhs);

		//! @brief Divides a speed with a duration and returns Acceleration
		//!
		//! @param s the speed to divide
		//! @param d the duration
		//! @return Acceleration the acceleration
  		friend Acceleration operator/ (const Speed & s, const Duration &d);
};
Acceleration operator/( const Speed & s, const Duration &d);
#endif

