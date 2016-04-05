//!
//! @author 	Job Verhaar
//! @date 		04-04-2016
//! @version 	0.1
//!
#ifndef _FORCE_HPP
#define _FORCE_HPP

#include "gtest/gtest.h"
#include "Weight.hpp"
#include "Acceleration.hpp"
#include <iostream>

class Force : public ADT_Base<Force>
{
private:
	//! Constructor for force
	/*!
		\param val the value for force in kg*m\s²
	*/
	Force(double value);
public:
  friend ADT_Base<Force>;
	Force();
	//! Assigns a Force to this Force. 
    /*!
      \param rhs a Force
      \return the assigned Force.
    */
    friend Force operator* ( double n, const Force & rhs );

	//! @brief Appends a Force to an std::ostream and returns the ostream
  //!
  //! @param os the std::ostream to append to
  //! @param rhs Object to append
  //! @return std::ostream
	friend std::ostream& operator<<(std::ostream & os, const Force &rhs);

	//! @brief Reads a Force from an std::istream and returns the istream
  //!
  //! @param os the std::istream to read it from;
  //! @param rhs Object to read
  //!	@return std::istream
	friend std::istream& operator>>(std::istream & is, Force & rhs);

  //! @brief Calculates acceleration based on Speed and Duration.
  //!
  //! @param s the Speed
  //! @param d the Duration
  //! @return the caclculated acceleration
	friend Acceleration operator/ (Speed & s, Duration &d);

	//! @brief Multiplies a Weight by a Accceleration.
  //!
  //! @param w the Weight
  //! @param a the Accelation
  //! @return the calculated Force.
	friend Force operator* ( const Weight & lhs, const Acceleration & rhs);

  static const Force NEWTON;
};
Force operator* ( const Weight & lhs, const Acceleration & rhs);

#endif