#include "gtest/gtest.h"
#include "../source/include/Rotation.hpp"
#include <iostream>

// constructors

TEST(RotationConstructor, Default){
	Rotation a;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),0.0);
}

TEST(RotationConstructor, ConstructorValue){
	Rotation a;
	a = 20.0 * Rotation::rad;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),20.0);
}

TEST(RotationConversion, Radians_Degrees){
	double pi = 3.14159265358979323846;
	EXPECT_DOUBLE_EQ(pi,3.14159265358979323846) << "Is Pi equal to the assigned variable or is the double still considered unequal anyway";
	Rotation a =  pi * Rotation::rad;
	Rotation b = 180.0 * Rotation::deg;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),b.get_Rotation());
}

TEST(RotationAssign, Assign){
	Rotation a();
	a = 10.0 * Rotation::rad;
	Rotation b();
	EXPECT_DOUBLE_EQ(10.0,a.get_Rotation());
	EXPECT_DOUBLE_EQ(0.0,b.get_Rotation());
	b = a;
	ASSERT_DOUBLE_EQ(10.0,b.get_Rotation());
}
	
TEST(RotationComparison, Smaller){
	Rotation a = 5.0 * Rotation::rad;
	Rotation b = 3.0 * Rotation::rad;
	ASSERT_EQ(a < b, false);
	ASSERT_EQ(b < a, true);
}

TEST(RotationComparison, Bigger){
	Rotation a = 4.0 * Rotation::rad;
	Rotation b = 6.0 * Rotation::rad;
	ASSERT_EQ(a > b, false);
	ASSERT_EQ(b > a, false);
}

TEST(RotationAdding, singleOperator){
	Rotation a = 5.0 * Rotation::rad;
	Rotation b = 6.0 * Rotation::rad;
	Rotation c = a + b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),11.0);
}

TEST(RotationAdding, dualOperator){
	Rotation a = 5.0 * Rotation::rad;
	Rotation b = 6.0 * Rotation::rad;
	a += b;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),11.0);
}

TEST(RotationSubstraction, singleOperator){
	Rotation a = 5.0 * Rotation::rad;
	Rotation b = 2.0 * Rotation::rad;
	Rotation c = a - b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),3.0);
}

TEST(RotationSubstraction, dualOperator){
	Rotation a = 5.0 * Rotation::rad;
	Rotation b = 2.0 * Rotation::rad;
	a -= b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),3.0);
}

TEST(RotationMultiplication, singleOperator){
	Rotation a = 5.0 * Rotation::rad;
	a = a * 2.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),10.0);
}

TEST(RotationMultiplication, dualOperator){
	Rotation a = 5.0 * Rotation::rad;
	a *= 3.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),15.0);
}

TEST(RotationDivision, singleOperator){
	Rotation a = 5.0 * Rotation::rad;
	a = a / 2.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),10.0);
}

TEST(RotationDivision, dualOperator){
	Rotation a = 5.0 * Rotation::rad;
	a *= 3.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),15.0);
}

