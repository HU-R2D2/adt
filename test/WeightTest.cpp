// ++--++
// @file <filename>
// @date Created: <5-3-16>
// @version <0.0.0>
//
// @author <full name>
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
// ++--++
#include "gtest/gtest.h"
#include "../source/include/Weight.hpp"
#include <iostream>

//constructors
TEST(Weight, DefaultConstructor){
	Weight w;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 0) << "Weight";
}

//Operatoren:
TEST(Weight, AssignWeight){
	Weight w;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 0) << "Empty weight";
	w = 2 * Weight::KILOGRAM;
	ASSERT_DOUBLE_EQ(w/Weight::KILOGRAM, 2) << "Assigned";
}

TEST(Weight, AddWeight) { 						//operator+
	// leeg + leeg
	Weight a = 0 * Weight::KILOGRAM;
	Weight b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0.0) << "empty+empty";
	
	// leeg + vol
	Weight c = 2 * Weight::KILOGRAM;
	b = b + c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 2.0) << "empty+full";
	
	// vol + vol
	Weight d = 3 * Weight::KILOGRAM;
	d = d + c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 5.0) << "full+full";
}

TEST(Weight, SubstractWeight) { 				//operator-
	// leeg - leeg
	Weight a{};
	Weight b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0.0) << "empty-empty";
	
	// leeg - vol
	Weight c = 2 * Weight::KILOGRAM;
	b = b - c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c = c - a;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 2.0) << "full-empty";
	
	// vol - vol
	Weight d = 1 * Weight::KILOGRAM;
	d = d - c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , -1.0) << "full-full neg";
	Weight e= 3 * Weight::KILOGRAM;
	Weight f= 2 * Weight::KILOGRAM;
	e = e - f;
 	ASSERT_DOUBLE_EQ(e/Weight::KILOGRAM , 1.0) << "full-full";
}

TEST(Weight, MultiplyWeightDouble) { 						//operator* (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Weight a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty*0 Weight";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty Weight";
		
	// vol * 0
	Weight b =1 * Weight::KILOGRAM;
	b = b * 0;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 0) << "full*0 Weight";
		
	// vol * getal1
	Weight c =2 * Weight::KILOGRAM;
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 4) << "full*getal1 Weight";
	
	// vol * getal2
	Weight d =3  * Weight::KILOGRAM;
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 7.5) << "full * getal2 Weight";

}

TEST(Weight, MultiplyDoubleWeight) { 						//operator* (2)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Weight a;
	a = 0 * a;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty*0 Weight";
	
	// leeg * getal1
	a = getal1 * a;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty Weight";
		
	// vol * 0
	Weight b =1 * Weight::KILOGRAM;
	b = 0 * b;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 0) << "full*0 Weight";
		
	// vol * getal1
	Weight c =2 * Weight::KILOGRAM;
	c = getal1 * c;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 4) << "full*getal1 Weight";
	
	// vol * getal2
	Weight d =3  * Weight::KILOGRAM;
	d = getal2 * d;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 7.5) << "full * getal2 Weight";

}

TEST(Weight, DivideDouble) { 					//operator/ (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Weight a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty / 0 Weight";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty x";
	
	// vol / 0
	Weight b = 1 * Weight::KILOGRAM;
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 1) << "full / 0 Weight";
	
	// vol / getal1
	Weight c = 1 * Weight::KILOGRAM;
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 0.5) << "full / getal1 Weight";
	
	// vol / getal2
	Weight d =1 * Weight::KILOGRAM;
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 0.4) << "full / getal2 Weight ";
	
}

TEST(Weight, DivideWeight) { 					//operator/ (2)
    Weight a;
	Weight d;
	Weight b = 4 * Weight::KILOGRAM;
	Weight c = 2 * Weight::KILOGRAM;
	
	// leeg / leeg
	double z = a / d;		// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(z , 0) << "empty / empty";	
	
	// vol / leeg
	z = b / a;
	ASSERT_DOUBLE_EQ(z , 4) << "full / empty";
	
	// vol / vol
	z = b / c;
	ASSERT_DOUBLE_EQ(z , 2) << "full / full";	
}

TEST(Weight, AddAssignWeight) {					//operator+=
	// leeg + leeg
	Weight a;
	Weight b;
	a += b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty+empty";
	
	// leeg + vol
	Weight c = 2  * Weight::KILOGRAM;
	b += c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , 2) << "empty+full";
	
	// vol + vol
	Weight d = 3 * Weight::KILOGRAM;
	d += c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , 5) << "full+full"; 
}

TEST(Weight, SubtractAssignWeight) { 			//operator-=
	// leeg - leeg
	Weight a;
	Weight b;
	a -= b;
	ASSERT_DOUBLE_EQ(a/Weight::KILOGRAM , 0) << "empty-empty";
	
	// leeg - vol
	Weight c = 2  * Weight::KILOGRAM;
	b -= c;
	ASSERT_DOUBLE_EQ(b/Weight::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c -= a;
	ASSERT_DOUBLE_EQ(c/Weight::KILOGRAM , 2) << "full-empty";
	
	// vol - vol
	Weight d = 1 * Weight::KILOGRAM;
	d -= c;
 	ASSERT_DOUBLE_EQ(d/Weight::KILOGRAM , -1) << "full-full neg";
	Weight e = 5 * Weight::KILOGRAM;
	Weight f = 3 * Weight::KILOGRAM;
	e -= f;
	ASSERT_DOUBLE_EQ(e/Weight::KILOGRAM , 2) << "full-full";
}	

TEST(Weight, GreaterThan) { 				//operator>
	Weight a(2 * Weight::KILOGRAM);
	Weight b(1 * Weight::KILOGRAM);
	ASSERT_TRUE(a > b) << "greater than";
	ASSERT_FALSE(b > a) << "less than";
}

TEST(Weight, LessThan) { 					//operator>
	Weight a(1 * Weight::KILOGRAM);
	Weight b(2 * Weight::KILOGRAM);
	ASSERT_TRUE(a < b) << "greater than";
	ASSERT_FALSE(b < a) << "less than";
}

TEST(Weight, WriteTo) {
	std::stringstream stream{};
	Weight w = 5 * Weight::KILOGRAM;
	stream << w << std::endl;
	std::string output;
	std::getline(stream, output);
	EXPECT_EQ("5Kg", output);
	EXPECT_EQ(&stream, &(stream << w))<< "Wrong stream is returned.";
}

TEST(Weight, ReadFrom){
	std::stringstream stream{};
	Weight w;
	stream << "20Kg";
	stream >> w;
	ASSERT_DOUBLE_EQ(20,w/Weight::KILOGRAM);
}