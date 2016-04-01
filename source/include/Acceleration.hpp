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

#include "Distance.hpp"
#include "Duration.hpp"
#include "Length.hpp"

#include <iostream>

class Acceleration {
	public:
		
		//! @brief The default constructor
		Acceleration();

		//! @brief Constructor that sets the value to whichever value. value should be in meter per second.
		//!
		//! @param val Raw acceleration value in meter per second
		Acceleration(double val);

		//! @brief Constructs an acceleration from a distance and a duration
		//!
		//! @param dist The distance of the acceleration
		//! @param duration The duration of the acceleration
		Acceleration(Distance dist, Duration dur);


		//! @fn Acceleration::get_acceleration()
		//!
		//! @brief
		const double get_acceleration() const;

		//! @brief
		//!
		//! @param val
		void set_acceleration(double val);

		//! @brief
		//! 
		//! @param rhs
		//! @return Acceleration
		Acceleration & operator= (const Acceleration & rhs);

		//! @brief
		//!
		//! @param rhs
		//! @return Acceleration
		Acceleration operator* (const double & rhs) const;

		//! @brief
		//!
		//! @param rhs
		//! @return Acceleration
		Acceleration operator/ (const double & rhs) const;

		//! @brief
		//!
		//! @param rhs
		//! @return Duration
		Duration operator/ (const Distance & rhs) const;

		//! @brief
		//!
		//! @param rhs
		//! @return bool
		bool operator> (const Acceleration & rhs) const;


		//! @brief
		//!
		//! @param rhs
		//! @return bool 
		bool operator< (const Acceleration & rhs) const;

		//! @brief
		//! 
		//! @param lhs
		//! @param rhs
		//! @return std::istream the inputstream
		friend std::istream &operator>>(std::istream & lhs, Acceleration & rhs);

		//! @brief appends an accelration to an std::ostream and returns the ostream
		//! The format of the accelration will be "acceleration( 1.5 m/sec )"
	    //!
	    //! @param os the std::ostream to append to
	    //! @param rhs Object to append
	    //! @return std::ostream the ostream
		friend std::ostream &operator<<(std::ostream & lhs, const Acceleration & rhs);
	

	private:
		double value;
};

#endif

