// @file TimeStamp.hpp
// @date Created: 10-6-16
// @version <0.0.0>
//
// @author Zehna van den Berg, Aydin Biber
//
// @section LICENSE
// License: newBSD
//
// Copyright � 2016, HU University of Applied Sciences Utrecht.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with
// or without modification, are permitted provided
// that the following conditions are met:
// - Redistributions of source code must retain the above
// copyright notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the
// above copyright notice, this list of conditions and the
// following disclaimer in the documentation and/or
// other materials provided with the distribution.
// - Neither the name of the HU University of
// Applied Sciences Utrecht nor the names of its contributors
// may be used to endorse or promote products derived
// from this software without specific prior written permission.
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
#ifndef HPP_Clock
#define HPP_Clock

#include <chrono>
#include "Duration.hpp"
#include "Timestamp.hpp"

/// The main Clock object, which holds Clock::Duration and Clock::TimeStamp
/// The Clock class is the main class which will be used
/// to refer to Clock::Duration and Clock::TimeStamp.
/// \author Thijs Hendrickx, Zehna van den Berg, Waila Woe, Aydin Biber
/// \version 1.0
/// \date 31-3-2016

namespace r2d2{
#define timeFactor (1000 * 1000 * 1000) // makes time_point scale to seconds
    class Clock {      
    public:
        //!   @brief Gets the current time using std::chrono and returns it as TimeStamp
        //!   @return TimeStamp with the current time_point as value
        static TimeStamp get_current_time();
    };
}
#endif
