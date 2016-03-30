#include "../source/include/Speed.hpp"
#include "gtest/gtest.h"
//Constructors


//Assign
TEST(SpeedTestAssign,Speed){
	Speed a = 5 * Length::METER / Duration::SECOND;
	ASSERT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 5) << "speed created";
	Speed b = 7 * Length::METER / Duration::SECOND;
	a = b;
	ASSERT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 7) << "assigned other speed to a speed";
}


TEST(SpeedTestDivide, Speed){
	Speed a = 4 * Length::METER / Duration::SECOND;
	Speed b = 8 * Length::METER / Duration::SECOND;
	Speed c = -16 * Length::METER / Duration::SECOND;
	ASSERT_DOUBLE_EQ(b/a, 2) << "Divide positive by positive";
	ASSERT_DOUBLE_EQ(c/b, -2) << "Divide negative by positive";
}

//Smaller
TEST(SpeedTestSmaller,Speed){
	Speed a = 8 * Length::METER / Duration::SECOND;
	Speed b = 6 * Length::METER / Duration::SECOND;
	EXPECT_EQ(a < b, false) << "a not smaller than b";
	EXPECT_EQ(b < a, true) <<  "b is smaller than a";
}

//Bigger
TEST(SpeedTestBigger,Speed){
	Speed a = 6 * Length::METER / Duration::SECOND;
	Speed b = 8 * Length::METER / Duration::SECOND;
	EXPECT_EQ(a > b, false) << "a not greater than b";
	EXPECT_EQ(b > a, true) <<  "b is greater than a";
}

//onedd
TEST(SpeedTestAdd, Speed){
	Speed a = 3 * Length::METER / Duration::SECOND;
	Speed b = 6 * Length::METER / Duration::SECOND;
	Speed c = 0 * Length::METER / Duration::SECOND;
	Speed d = -10 * Length::METER / Duration::SECOND;
	a = a + c;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 3) << "added zero to a speed";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 9) << "added positive speed to positive speed";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), -1) << "added negative speed to positive speed";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), -11) << "added negative speed to negative speed";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), -5) << "added positive speed to negative speed";
}


//AddAssign
TEST(SpeedTestAddAssign, Speed){
	Speed a = 6 * Length::METER / Duration::SECOND;
	Speed b = 5 * Length::METER / Duration::SECOND;
	a += b;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 11) << "AddAssign speed"; 
	// no more other test because itern it uses add and assign operator so if you test them properly it isn't nessecarly here.
}

//Subtract
TEST(SpeedTestSubtract, Speed){
	Speed a = 3 * Length::METER / Duration::SECOND;
	Speed b = 6 * Length::METER / Duration::SECOND;
	Speed c = 0 * Length::METER / Duration::SECOND;
	Speed d = -10* Length::METER / Duration::SECOND;
	a = a - c;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 3) << "substracted zero form a speed";
	a = a - b;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), -3) << "substracted positive speed from positive speed";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 7) << "substracted negative speed from negative speed";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 17) << "substracted negative speed from positive speed";
}


//SubtractAssign
TEST(SpeedTestSubtractAssign, Speed){
	Speed a = 6 * Length::METER / Duration::SECOND;
	Speed b = 5 * Length::METER / Duration::SECOND;
	a -= b;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 1) << "SubtractAssign speed"; 
	// no more other test because itern it uses subtract and assign operators so if you test them properly it isn't nessecarly here.
}

//multiply by Duration
TEST(SpeedTestMultiply, Duration){
	Speed a = 6 * Length::METER / Duration::SECOND;
	Duration dur = 7 * Duration::SECOND;
	Length l = a * dur;
	EXPECT_DOUBLE_EQ(l/Length::METER, 42) << "Multiply speed by duration";
}


//divide by Duration
/*
TEST(SpeedTestDivide, Duration){
	Speed a = 14 * Length::METER / Duration::SECOND;
	Duration dur = 7 * SECOND;
	Acceleration le = a / dur;
	Acceleration oneUnit = 1 * Length::METER / Duration::SECOND / Duration::SECOND;
	EXPECT_DOUBLE_EQ(le/oneUnit, 2) << "Multiply speed by duration";
}
!--Not testable because Acceleration isnt implemented
*/

//Multiply by double

TEST(SpeedTestMultiply, double){
	Speed a = 8 * Length::METER/ Duration::SECOND;
	double pos = 2;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),16) << "Multiply positive by positive";
	a = -8 * Length::METER/ Duration::SECOND;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),-16) << "Multiply negative by positive";
	double neg = -2;
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),32) << "Multiply negative by negative";
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),-64) << "Multiply positive by negative";
	double z = 0;
	a = a * z;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 0) << "Multiply by zero";
	a = 8 * Length::METER/ Duration::SECOND;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),16) << "Multiply positive by positive rhs";
	a = -8 * Length::METER/ Duration::SECOND;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),-16) << "Multiply negative by positive rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),32) << "Multiply negative by negative rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND),-64) << "Multiply positive by negative rhs";
	a = z * a;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 0) << "Multiply by zero rhs";
}


//MultiplyAssign by double
TEST(SpeedTestMultiplyAssign, double){
	Speed a = 6 * Length::METER / Duration::SECOND;
	double d = 7;
	a = a * d;
	EXPECT_DOUBLE_EQ(a/(Length::METER/Duration::SECOND), 42) << "MultiplyAssign speed"; 
	// no more other test because itern it uses multiply and assign operators so if you test them properly it isn't nessecarly here.
}


//Divide by Speed



