// ++--++
// Roborescue
// @file <Duration.hpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
// @author <Casper Wolf & Job Verhaar>
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
//! @author Casper Wolf & Job Verhaar
//! @date 14-03-16
//! @version 0.1
//!
//! @brief A length of time (interval between two moments).
//! Duration is a ratio scale: addition and subtraction of differences are meaningful (and yield durations), and so are multiplication and division by a scalar (also yield a duration).

#ifndef  _DURATION_HPP
#define _DURATION_HPP

#include <iostream>
#include "Moment.hpp"
#include "ADT_Base.hpp"
#include "gtest/gtest.h"

class Speed;
class Length;
class Acceleration;
class Duration : public ADT_Base<Duration>{
	protected:
		//! @brief
		//!
		//! @param seconds
		explicit Duration(double value);
		
	public:
		friend ADT_Base<Duration>;
		//friend class Acceleration;
		//! @brief Default constructor
		Duration();
		//! @brief
		//!
		//! @param seconds
		double get_seconds() const;

		//constant declaration:
		static const Duration SECOND;
		static const Duration MILLISECOND;
		static const Duration MINUTE;

		//friend declaration:
		friend Duration operator* ( double n, const Duration & rhs);
		friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs);
		friend Speed;


		//! @brief appends a duration to an ostream and return an ostream
		//!
		//! @param is
		//! @param rhs
		//! @return std::istream
		friend std::istream & operator>> (std::istream & is, Duration & rhs);	

		//! @brief appends a duration to an ostream and return an ostream
		//!
		//! @param 
		//! @param
		//! @return
		friend std::ostream& operator<< (std::ostream & os, const Duration &rhs);

		FRIEND_TEST(Duration, ConstructorDouble);
	private:
		//double seconds;
};
#endif

