////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//
//
// @file AngleTest.cpp
// @date Created: 31-03-16
// @version 2.1.0
//
// @author Casper Wolf
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
////



#include "gtest/gtest.h"
#include "../source/include/Angle.hpp"
#include <iostream>

using namespace r2d2;

double pi = 3.14159265358979323846;

TEST(Angle, DefaultConstructor){
	Angle a;
	ASSERT_DOUBLE_EQ(a.get_angle(),0.0);
}

TEST(Angle, ConstructorValue){
	Angle a;
	a = M_PI * Angle::rad;
	ASSERT_DOUBLE_EQ(a.get_angle(),M_PI);
}

TEST(Angle, ConversionRadians_Degrees){
	Angle a =  M_PI * Angle::rad;
	Angle b = 180.0 * Angle::deg;
	ASSERT_DOUBLE_EQ(a.get_angle(),b.get_angle());
}

TEST(Angle, Assign){
	Angle a{};
	a = ((M_PI/2) * Angle::rad);
	Angle b{};
	EXPECT_DOUBLE_EQ((M_PI/2),a.get_angle());
	EXPECT_DOUBLE_EQ(0.0,b.get_angle());
	b = a;
	ASSERT_DOUBLE_EQ((M_PI/2),b.get_angle());
}

TEST(Angle, SmallerThan){
	Angle a = (M_PI/4) * Angle::rad;
	Angle b = (M_PI/8) * Angle::rad;
	ASSERT_EQ(a < b, false);
	ASSERT_EQ(b < a, true);
}

TEST(Angle, GreaterThan){
	Angle a = (M_PI/16) * Angle::rad;
	Angle b = (M_PI/4) * Angle::rad;
	ASSERT_EQ(a > b, false);
	ASSERT_EQ(b > a, true);
}

TEST(Angle, SingleAddOperator){
	Angle a = (M_PI/2) * Angle::rad;
	Angle b = (M_PI/2) * Angle::rad;
	Angle c = a + b;
	ASSERT_DOUBLE_EQ(c.get_angle(),(M_PI));
}

TEST(Angle, DualAddOperator){
	Angle a = (M_PI/4) * Angle::rad;
	Angle b = (M_PI/4) * Angle::rad;
	const Angle * const temp = &a;
	EXPECT_EQ(temp, &(a += b));
	ASSERT_DOUBLE_EQ(a.get_angle(),(M_PI/2));
}

TEST(Angle, SingleSubstractionOperator){
	Angle a = M_PI * Angle::rad;
	Angle b = (M_PI/2) * Angle::rad;
	Angle c = a - b;
	ASSERT_DOUBLE_EQ(c.get_angle(),(M_PI/2));
}

TEST(Angle, DualSubstractionOperator){
	Angle a = (2 * M_PI) * Angle::rad;
	Angle b = M_PI * Angle::rad;
	const Angle * const temp = &a;
	EXPECT_EQ(temp, &(a -= b));
	ASSERT_DOUBLE_EQ(a.get_angle(),M_PI);
}

TEST(Angle, SingleMultiplicationOperator){
	Angle a = M_PI * Angle::rad;
	a = a * 2.0;
	ASSERT_DOUBLE_EQ(a.get_angle(),(M_PI * 2));
}

TEST(Angle, DualMultiplicationOperator){
	Angle a = (M_PI/4) * Angle::rad;
	const Angle * const temp = &a;
	a *= 4.0;
	EXPECT_EQ(temp,&a);
	ASSERT_DOUBLE_EQ(a.get_angle(),M_PI);
}

TEST(Angle, SingleDivisionOperator){
	Angle a = (M_PI*2) * Angle::rad;
	a = a / 2.0;
	ASSERT_DOUBLE_EQ(a.get_angle(),M_PI);

}

TEST(Angle, DualDivisionOperator){
	Angle a = M_PI * Angle::rad;
	const Angle * const temp = &a;
	a /= 2.0;
	EXPECT_EQ(temp,&a);
	ASSERT_DOUBLE_EQ(a.get_angle(),(M_PI/2));
}
#include <sstream>

TEST(Angle, RotatationOutstream){
	Angle a = Angle::rad;
	std::stringstream stream{};
	stream << a;
	std::string temp;
	getline(stream, temp);
	EXPECT_EQ("1 rad", temp);
}

TEST(Angle, PositiveNormalize){
    Angle a = M_PI * 5.5 * Angle::rad;
    Angle b = a.normalize();
    ASSERT_EQ(b.in_range(M_PI*1.5*Angle::rad), true);
}
TEST(Angle, NegativeNormalize){
    Angle a = M_PI * -5.2 * Angle::rad;
    Angle b = a.normalize();
    ASSERT_EQ(b.in_range(M_PI*0.8*Angle::rad), true);
}
TEST(Angle, in_range){
    Angle a = M_PI*1.0 * Angle::rad;
    ASSERT_EQ(true, a.in_range(M_PI*1.0*Angle::rad));
}
