// ++--++
// Roborescue
// @file <Force.hpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
// @author <Job Verhaar>
//
// @section LICENSE
// License: newBSD
//
// Copyright © 2016, HU University of Applied Sciences Utrecht.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ++--++
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
		\param val the value for force in kg*m\sÂ²
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