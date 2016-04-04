#include "../source/include/Acceleration.hpp"
#include "gtest/gtest.h"


TEST(Acceleration, DefaultConstructor)
{
	Acceleration accel;

	ASSERT_DOUBLE_EQ(0.0, accel.get_acceleration());

}

TEST(Acceleration, ConstructorValue)
{
	Acceleration accel(0.0);
	ASSERT_DOUBLE_EQ(0.0, accel.get_acceleration());

	Acceleration accelTen(10.0);
	ASSERT_DOUBLE_EQ(10.0, accelTen.get_acceleration());

}

TEST(Acceleration, ConstructorDistDur)
{
	Length length;
	Duration dur(10.0 * Duration::SECOND);
	//Acceleration accel(dist, dur);

	// calculate acceleration
	//double rawAccel = 0.0;

	//ASSERT_DOUBLE_EQ(rawAccel, accel.get_acceleration());
}


TEST(Acceleration, get_acceleration)
{
	Acceleration accel;

	ASSERT_DOUBLE_EQ(0.0, accel.get_acceleration());

}

TEST(Acceleration, set_acceleration)
{
	Acceleration accel;

	ASSERT_DOUBLE_EQ(0.0, accel.get_acceleration());

	accel.set_acceleration(10.0);

	ASSERT_DOUBLE_EQ(10.0, accel.get_acceleration());

}

TEST(Acceleration, Assign)
{

}

TEST(Acceleration, MultiplyDouble)
{
	Acceleration accel(5.0);

	accel = accel * 2.0;

	ASSERT_DOUBLE_EQ(10.0, accel.get_acceleration());
}

TEST(Acceleration, DivideDouble)
{
	Acceleration accel(10.0);

	accel = accel / 2.0;

	ASSERT_DOUBLE_EQ(5.0, accel.get_acceleration());
}

TEST(Acceleration, DivideDistance)
{
	// todo
}


TEST(Acceleration, GreaterThan)
{
	Acceleration small(5.0);

	Acceleration big(10.0);

	ASSERT_TRUE(big > small);

	ASSERT_FALSE(small > big);

}

TEST(Acceleration, LessThan)
{
	Acceleration small(5.0);

	Acceleration big(10.0);

	ASSERT_TRUE(small < big);

	ASSERT_FALSE(big < small);
}


TEST(Acceleration, OutputStream)
{
	

}


TEST(Acceleration, InputStream)
{

}