#include "../include/Clock.hpp"

//===============
//Class Clock
//===============

namespace r2d2{
TimeStamp Clock::get_current_time()
{
	return TimeStamp(
                     (double)std::chrono::high_resolution_clock::now()
                     .time_since_epoch().count()
                     / (TIME_FACTOR) //convert to seconds scale
    );
}
}