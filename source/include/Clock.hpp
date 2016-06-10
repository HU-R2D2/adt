#ifndef HPP_Clock
#define HPP_Clock

#include <chrono>
#include "duration.hpp"
#include "timestamp.hpp"

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
