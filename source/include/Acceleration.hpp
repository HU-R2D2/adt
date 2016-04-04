//!	ToDo:
//! Write headers
//! Write tests
//! Write methods
//! Test and fix errors
//!	Review
	
//!	@author 		Stephan Vivie
//! @date			01-04-2016
//!	@version		0.1
//!	@brief	       	Acceleration data type stored in meters per second.
	
#ifndef _ACCELERATION_HPP
#define _ACCELERATION_HPP

#include "Duration.hpp"
#include "Speed.hpp"

#include <iostream>

class Acceleration {
	private: 

		//! @brief Constructor that sets the value to whichever value. value should be in meter per second.
		//!
		//! @param val Raw acceleration value in meter per second
		Acceleration(double val);
	public:

		//! @brief The default constructor of and acceleration
		Acceleration();
		
		//! @brief assignment operator for an acceleration
		//! 
		//! @param rhs				the right hand sight acceleration, this one is being assigned to another acceleration
		//! @return Acceleration&	reference to the acceleration on which the assignment operator was called
		Acceleration & operator= (const Acceleration & rhs);

		//! @brief	multiplies an acceleration by a number and returns an acceleration
		//!
		//! @param rhs				the number by which the acceleration is being multiplied
		//! @return Acceleration	the acceleration on which the multiply operator was called
		Acceleration operator* (const double & rhs) const;

		//! @brief	multiplies an acceleration by a number, assign it to current object and return current object
		//!
		//! @param rhs				the number by which the acceleration is being multiplied
		//! @return Acceleration	the acceleration on which the multiply operator was called
		Acceleration operator*= (const double & rhs);

		//! @brief divides an acceleration by a number and returns an acceleration
		//!
		//! @param rhs				the number by which the acceleration is being divided
		//! @return Acceleration	the acceleration on which the division operator was called
		Acceleration operator/ (const double & rhs) const;

		//! @brief divides an acceleration by a number assign it to current object and return current object
		//!
		//! @param rhs				the number by which the acceleration is being divided
		//! @return Acceleration	the acceleration on which the division operator was called
		Acceleration operator/= (const double & rhs);

		double operator/ (const Acceleration & rhs) const;

		//! @brief checks which acceleration is bigger and returns a bool (true if 1st is bigger, false if 2nd)
		//!
		//! @param rhs		The right hand sight acceleration, this one will be compared to another acceleration
		//! @return bool	True if acceleration is greater, false if not
		bool operator> (const Acceleration & rhs) const;


		//! @brief checks which acceleration is smaller and returns a bool (true if 1st is smaller, false if 2nd)
		//!
		//! @param rhs		The right hand sight acceleration, this one will be compared to another acceleration
		//! @return bool 	true if acceleration is smaller, false if not
		bool operator< (const Acceleration & rhs) const;

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
	

		//! @brief Divides a speed with duration
		//!
		//! @param s the speed to divide
		//! @param d the duration
		//! @return Acceleration
  		friend Acceleration operator/ (Speed & s, Duration &d);
	private:
		double value;
};
Acceleration operator/ (Speed & s, Duration &d);
#endif

