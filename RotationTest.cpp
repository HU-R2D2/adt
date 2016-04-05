////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file RotationTest.cpp
// @date Created: 31-03-16
// @version 1.1.0
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
#include "../source/include/Rotation.hpp"
#include <iostream>

double pi = 3.14159265358979323846;

TEST(RotationConstructor, Default){
	Rotation a;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),0.0);
}

TEST(RotationConstructor, ConstructorValue){
	Rotation a;
	a = pi * Rotation::rad;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),pi);
}

TEST(RotationConversion, Radians_Degrees){
	EXPECT_DOUBLE_EQ(pi,3.14159265358979323846) << "Is Pi equal to the assigned variable or is the double still considered unequal anyway";
	Rotation a =  pi * Rotation::rad;
	Rotation b = 180.0 * Rotation::deg;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),b.get_Rotation());
}

TEST(RotationAssign, Assign){
	Rotation a();
	a = (pi/2) * Rotation::rad;
	Rotation b();
	EXPECT_DOUBLE_EQ((pi/2),a.get_Rotation());
	EXPECT_DOUBLE_EQ(0.0,b.get_Rotation());
	b = a;
	ASSERT_DOUBLE_EQ((pi/2),b.get_Rotation());
}
	
TEST(RotationComparison, Smaller){
	Rotation a = (pi/4) * Rotation::rad;
	Rotation b = (pi/8) * Rotation::rad;
	ASSERT_EQ(a < b, false);
	ASSERT_EQ(b < a, true);
}

TEST(RotationComparison, Bigger){
	Rotation a = (pi/16) * Rotation::rad;
	Rotation b = (pi/4) * Rotation::rad;
	ASSERT_EQ(a > b, false);
	ASSERT_EQ(b > a, true);
}

TEST(RotationAdding, singleOperator){
	Rotation a = (pi/2) * Rotation::rad;
	Rotation b = (pi/2) * Rotation::rad;
	Rotation c = a + b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),(pi));
}

TEST(RotationAdding, dualOperator){
	Rotation a = (pi/4) * Rotation::rad;
	Rotation b = (pi/4) * Rotation::rad;
	a += b;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),(pi/2));
}

TEST(RotationSubstraction, singleOperator){
	Rotation a = pi * Rotation::rad;
	Rotation b = (pi/2) * Rotation::rad;
	Rotation c = a - b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),(pi/2));
}

TEST(RotationSubstraction, dualOperator){
	Rotation a = (2 * pi) * Rotation::rad;
	Rotation b = pi * Rotation::rad;
	a -= b;
	ASSERT_DOUBLE_EQ(c.get_Rotation(),pi);
}

TEST(RotationMultiplication, singleOperator){
	Rotation a = pi * Rotation::rad;
	a = a * 2.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),(pi * 2));
}

TEST(RotationMultiplication, dualOperator){
	Rotation a = (pi/4) * Rotation::rad;
	a *= 4.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),pi);
}

TEST(RotationDivision, singleOperator){
	Rotation a = (pi*2) * Rotation::rad;
	a = a / 2.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),pi);
}

TEST(RotationDivision, dualOperator){
	Rotation a = pi * Rotation::rad;
	a /= 2.0;
	ASSERT_DOUBLE_EQ(a.get_Rotation(),(pi/2));
}

TEST(RotatationOutstream, rotation){
	Rotation a = pi * Rotation::rad;
}