#include "../source/include/Force.hpp"
#include "gtest/gtest.h"
#include <iostream>
//Constructors


//static const Speed one = 1 * Length::METER/Duration::SECOND;
//static const Acceleration ac = one/Duration::SECOND;
//static const Force Force::NEWTON = 1 * Weight::KILOGRAM * ac;
//Assign


TEST(Force, Assign){
	Force a = 5 * Force::NEWTON;
	ASSERT_DOUBLE_EQ(a/(Force::NEWTON), 5) << "Force created";
	Force b = 7 * Force::NEWTON;
	a = b;
	ASSERT_DOUBLE_EQ(a/(Force::NEWTON), 7) << "assigned other Force to a Force";
}


TEST(Force, Divide){
	Force a = 4 * Force::NEWTON;
	Force b = 8 * Force::NEWTON;
	Force c = -16 * Force::NEWTON;
	ASSERT_DOUBLE_EQ(b/a, 2) << "Divide positive by positive";
	ASSERT_DOUBLE_EQ(c/b, -2) << "Divide negative by positive";
}

//Smaller
TEST(Force, Smaller){
	Force a = 8 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	EXPECT_EQ(a < b, false) << "a not smaller than b";
	EXPECT_EQ(b < a, true) <<  "b is smaller than a";
}

//Bigger
TEST(Force, Bigger){
	Force a = 6 * Force::NEWTON;
	Force b = 8 * Force::NEWTON;
	EXPECT_EQ(a > b, false) << "a not greater than b";
	EXPECT_EQ(b > a, true) <<  "b is greater than a";
}

//onedd
TEST(Force, Add){
	Force a = 3 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	Force c = 0 * Force::NEWTON;
	Force d = -10 * Force::NEWTON;
	a = a + c;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 3) << "added zero to a Force";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 9) << "added positive Force to positive Force";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -1) << "added negative Force to positive Force";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -11) << "added negative Force to negative Force";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -5) << "added positive Force to negative Force";
}


//AddAssign
TEST(Force, AddAssign){
	Force a = 6 * Force::NEWTON;
	Force b = 5 * Force::NEWTON;
	a += b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 11) << "AddAssign Force"; 
	// no more other test because itern it uses add and assign operator so if you test them properly it isn't nessecarly here.
}

//Subtract
TEST(Force, Subtract){
	Force a = 3 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	Force c = 0 * Force::NEWTON;
	Force d = -10* Force::NEWTON;
	a = a - c;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 3) << "substracted zero form a Force";
	a = a - b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -3) << "substracted positive Force from positive Force";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 7) << "substracted negative Force from negative Force";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 17) << "substracted negative Force from positive Force";
}


//SubtractAssign
TEST(Force, SubtractAssign){
	Force a = 6 * Force::NEWTON;
	Force b = 5 * Force::NEWTON;
	a -= b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 1) << "SubtractAssign Force"; 
	// no more other test because itern it uses subtract and assign operators so if you test them properly it isn't nessecarly here.
}


//Multiply by double

TEST(Force,MultiplyDouble){
	Force a = 8 * Force::NEWTON;
	double pos = 2;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),16) << "Multiply positive by positive";
	a = -8 * Force::NEWTON;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-16) << "Multiply negative by positive";
	double neg = -2;
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),32) << "Multiply negative by negative";
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-64) << "Multiply positive by negative";
	double z = 0;
	a = a * z;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 0) << "Multiply by zero";
	a = 8 * Force::NEWTON;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),16) << "Multiply positive by positive rhs";
	a = -8 * Force::NEWTON;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-16) << "Multiply negative by positive rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),32) << "Multiply negative by negative rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-64) << "Multiply positive by negative rhs";
	a = z * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 0) << "Multiply by zero rhs";
}


//MultiplyAssign by double
TEST(Force, MultiplyAssignDouble){
	Force a = 6 * Force::NEWTON;
	double d = 7;
	a = a * d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 42) << "MultiplyAssign Force"; 
	// no more other test because itern it uses multiply and assign operators so if you test them properly it isn't nessecarly here.
}

TEST(Force, WriteTo){
   std::stringstream stream{};
   Force s = 5 * Force::NEWTON;
   stream << s << std::endl;
   std::string output;
   std::getline(stream, output);
   EXPECT_EQ("5N", output);
   EXPECT_EQ(&stream, &(stream << s)) << "Wrong stream is returned.";
}


TEST(Force, ReadFrom){
	std::stringstream stream{};
	const Force meter_per_second = Force::NEWTON;
	Force Force = meter_per_second;

	// Check whether the coordinate is read in correct form from the stream.
	stream << "15N";
	stream >> Force;
	ASSERT_DOUBLE_EQ(15, Force / meter_per_second);
	
}
