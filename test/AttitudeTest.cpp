//!	Roborescue
//! @file <AttitudeTest.cpp>
//! @date Created: <16-5-16>
//! @version <0.1.0>
//!
//! @author <Remco Nijkamp>
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, 
//! with or without modification, are permitted provided that 
//! the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice, 
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice, 
//!   this list of conditions and the following disclaimer in the documentation 
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht nor 
//!   the names of its contributors may be used to endorse or promote products 
//!   derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
//! BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//! FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY
//! OF APPLIED SCIENCES UTRECHT BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//! SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//! OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//! WHETHER IN CONTRACT, STRICT LIABILITY,
//! OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
//! THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gtest/gtest.h"
#include "../source/include/Attitude.hpp"
#include "../source/include/Angle.hpp"
#include <iostream>
using namespace r2d2;

/*
TEST(Attitude, DefaultConstructor) {
    Attitude a;
    
    Angle a;
	ASSERT_DOUBLE_EQ(a.get_angle(),0.0);
    
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 0.0) << "x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 0.0) << "y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 0.0) << "z";
}

Angle a =  pi * Angle::rad;
Angle b = 180.0 * Angle::deg;


TEST(Attitude, ConstructorValue) {
    Angle 
    
    Attitude a(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 1.0) << "x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 2.0) << "y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 3.0) << "z";
}

TEST(AngleConstructor, ConstructorValue){
	Angle a;
	a = pi * Angle::rad;
	ASSERT_DOUBLE_EQ(a.get_angle(),pi);
}
*/
TEST(Attitude, Assign){
    Attitude a;
    a = Attitude(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
        
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 1.0) << "empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 2.0) << "empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 3.0) << "empty z";
        
    a = Attitude(4 * Angle::rad, 5 * Angle::rad, 6 * Angle::rad);
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 4.0) << "new x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 5.0) << "new y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 6.0) << "new z";  
}

TEST(Attitude, Add) {
    Attitude a;
    Attitude b;
    a = a + b;
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 0.0) << "empty+empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 0.0) << "empty+empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 0.0) << "empty+empty z";
        
    Attitude c(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    b = b + c;
    ASSERT_DOUBLE_EQ(b.get_x() / Angle::rad , 1.0) << "empty+full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Angle::rad , 2.0) << "empty+full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Angle::rad , 3.0) << "empty+full z";
        
    Attitude d(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    Attitude e(4 * Angle::rad, 5 * Angle::rad, 6 * Angle::rad);
    d = d + e;
    ASSERT_DOUBLE_EQ(d.get_x() / Angle::rad , 5.0) << "full+full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Angle::rad , 7.0) << "full+full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Angle::rad , 9.0) << "full+full z";
}

TEST(Attitude, Subtract) {
    Attitude a;
    Attitude b;
    a = a - b;
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 0.0) << "empty-empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 0.0) << "empty-empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 0.0) << "empty-empty z";
        
    Attitude c(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    b = b - c;
    ASSERT_DOUBLE_EQ(b.get_x() / Angle::rad , -1.0) << "empty-full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Angle::rad , -2.0) << "empty-full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Angle::rad , -3.0) << "empty-full z";

    Attitude d(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    Attitude e;
    d = d - e;
    ASSERT_DOUBLE_EQ(d.get_x() / Angle::rad , 1.0) << "full-empty x";
    ASSERT_DOUBLE_EQ(d.get_y() / Angle::rad , 2.0) << "full-empty y";
    ASSERT_DOUBLE_EQ(d.get_z() / Angle::rad , 3.0) << "full-empty z";
        
    Attitude f(4 * Angle::rad, 5 * Angle::rad, 6 * Angle::rad);
    Attitude g(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    f = f - g;
    ASSERT_DOUBLE_EQ(f.get_x() / Angle::rad , 3.0) << "full-full x";
    ASSERT_DOUBLE_EQ(f.get_y() / Angle::rad , 3.0) << "full-full y";
    ASSERT_DOUBLE_EQ(f.get_z() / Angle::rad , 3.0) << "full-full z";
}

/*      

TEST(Attitude, AddAssignAttitude) {
    Attitude a;
    Attitude b;
    a += b;
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 0.0) << "empty+empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 0.0) << "empty+empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 0.0) << "empty+empty z";
        
    Attitude c(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    b += c;
    ASSERT_DOUBLE_EQ(b.get_x() / Angle::rad , 1.0) << "empty+full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Angle::rad , 2.0) << "empty+full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Angle::rad , 3.0) << "empty+full z";
        
    Attitude d(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    Attitude e(4 * Angle::rad, 5 * Angle::rad, 6 * Angle::rad);
    d += e;
    ASSERT_DOUBLE_EQ(d.get_x() / Angle::rad , 5.0) << "full+full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Angle::rad , 7.0) << "full+full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Angle::rad , 9.0) << "full+full z"; 
}

TEST(Attitude, SubstractAssignAttitude) {
    Attitude a;
    Attitude b;
    a -= b;
    ASSERT_DOUBLE_EQ(a.get_x() / Angle::rad , 0.0) << "empty-empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Angle::rad , 0.0) << "empty-empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Angle::rad , 0.0) << "empty-empty z";
        
    Attitude c(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    b -= c;
    ASSERT_DOUBLE_EQ(b.get_x() / Angle::rad , -1.0) << "empty-full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Angle::rad , -2.0) << "empty-full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Angle::rad , -3.0) << "empty-full z";
        
    Attitude d(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    Attitude e;
    d -= e;
    ASSERT_DOUBLE_EQ(d.get_x() / Angle::rad , 1.0) << "full-empty x";
    ASSERT_DOUBLE_EQ(d.get_y() / Angle::rad , 2.0) << "full-empty y";
    ASSERT_DOUBLE_EQ(d.get_z() / Angle::rad , 3.0) << "full-empty z";
        
    Attitude f(4 * Angle::rad, 5 * Angle::rad, 6 * Angle::rad);
    Attitude g(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    f -= g;
    ASSERT_DOUBLE_EQ(f.get_x() / Angle::rad , 3.0) << "full-full x";
    ASSERT_DOUBLE_EQ(f.get_y() / Angle::rad , 3.0) << "full-full y";
    ASSERT_DOUBLE_EQ(f.get_z() / Angle::rad , 3.0) << "full-full z";
}

TEST(Attitude, GreaterThan) {
    Attitude a(2 * Angle::rad, 2 * Angle::rad, 2 * Angle::rad);
    Attitude b(1 * Angle::rad, 1 * Angle::rad, 1 * Angle::rad);
    ASSERT_TRUE(a > b) << "greater than";
    ASSERT_FALSE(b > a) << "less than";
}

TEST(Attitude, LessThan) {
    Attitude a(1 * Angle::rad, 1 * Angle::rad, 1 * Angle::rad);
    Attitude b(2 * Angle::rad, 2 * Angle::rad, 2 * Angle::rad);
    ASSERT_TRUE(a < b) << "less than";
    ASSERT_FALSE(b < a) << "greater than";
}

TEST(Attitude, OutputStream) {
    Attitude a(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad);
    std::stringstream stream{};
    stream << a << std::endl;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("(1m, 2m, 3m)", output);
}

TEST(Attitude, ReadFrom) {
    std::stringstream stream{};
    Attitude d;
    const Attitude * const originalPointer = &d;

    stream << "Attitude (15m, 15m, 15m)";
    stream >> d;
    ASSERT_DOUBLE_EQ(d.get_x() / Angle::rad , 15);
    ASSERT_DOUBLE_EQ(d.get_y() / Angle::rad , 15);
    ASSERT_DOUBLE_EQ(d.get_z() / Angle::rad , 15);
    ASSERT_EQ(originalPointer, &d);
}
*/