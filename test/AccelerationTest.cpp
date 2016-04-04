#include "../source/include/Length.hpp"
#include "../source/include/Acceleration.hpp"

#include <iostream>

#include "gtest/gtest.h"

static Duration oneSec = 1.0 * Duration::SECOND; // one second
static Speed oneMS = (1.0 * Length::METER) / oneSec; // Speed: one meter er second
static Acceleration oneMA = oneMS / oneSec; // Acceleration: one meter per second 

TEST(Acceleration, DefaultConstructor)
{
	Acceleration accel;
	ASSERT_DOUBLE_EQ(0.0, accel / oneMA);
}
/*
TEST(Acceleration, Assign)
{
	Speed speed = 5 * Length::METER / Duration::SECOND;
	Duration duration = 2 * Duration::SECOND;
	Acceleration accel = speed / duration;


	ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

}

TEST(Acceleration, MultiplyDouble)
{
	Speed speed = (5 * Length::METER) / Duration::SECOND;
	Duration duration = 2 * Duration::SECOND;
	Acceleration accel = speed / duration; //2.5 m/s

	accel = accel * 10;


	ASSERT_DOUBLE_EQ(25.0, accel / oneMA);
}

TEST(Acceleration, DivideDouble)
{
	Speed speed = (50 * Length::METER) / Duration::SECOND;
	Duration duration = 2 * Duration::SECOND;
	Acceleration accel = speed / duration; //2.5 m/s

	accel = accel * 10;
	ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

	// divide by one


	// divide by zero
}

TEST(Acceleration, DivideDistance)
{
	/// ???
}


TEST(Acceleration, GreaterThan)
{
	Speed speed = (5.0 * Length::METER) / Duration::SECOND;
	Duration duration = 2.0 * Duration::SECOND;
	Acceleration accel = speed / duration; //2.5 m/s

	Speed fasterSpeed = (50.0 * Length::METER) / Duration::SECOND;
	Acceleration fasterAccel = fasterSpeed / duration; //25 m/s

	ASSERT_TRUE(fasterAccel > accel);
	ASSERT_FALSE(accel > fasterAccel);

	

}

TEST(Acceleration, LessThan)
{
	Speed speed = (5.0 * Length::METER) / Duration::SECOND;
	Duration duration = 2.0 * Duration::SECOND;
	Acceleration accel = speed / duration; //2.5 m/s

	Speed fasterSpeed = (50.0 * Length::METER) / Duration::SECOND;
	Acceleration fasterAccel = fasterSpeed / duration; //25 m/s

	ASSERT_TRUE(accel < fasterAccel);
	ASSERT_FALSE(fasterAccel < accel);
}


TEST(Acceleration, OutputStream)
{
	

}


TEST(Acceleration, InputStream)
{

}
*/

