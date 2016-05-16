//! Roborescue
//! @file <Delta_Attitude.cpp>
//! @date Created: <7-4-16>
//! @version <0.5.0>
//!
//! @author <Casper Wolf & Remco Nijkamp>
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

#include "../include/Delta_Attitude.hpp"
namespace r2d2{ /*
Delta_Attitude::Delta_Attitude(double x, double y, double z){
    double xlen = std::sqrt(std::pow(x,2.0) + std::pow(z,2.0)); // length of 2D vector <x,z> using Pythage 
    double vector_length = std::sqrt(std::pow(xlen,2.0) + std::pow(y,2.0)); // length of 3D vector <x,y,z> using length of <x,z> and height y
    x{ x/vector_length };
    y{ y/vector_length };
    z{ z/vector_length };
}
*/

Angle Delta_Attitude::get_x() const {
    return x;
}

Angle Delta_Attitude::get_y() const {
    return y;
}

Angle Delta_Attitude::get_z() const {
    return z;
}

Delta_Attitude::Delta_Attitude(Angle x, Angle y, Angle z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Delta_Attitude& Delta_Attitude::operator=( const Delta_Attitude &rhs ){
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Delta_Attitude Delta_Attitude::operator+(const Delta_Attitude &rhs){
    Delta_Attitude temp{*this};
    temp.x += rhs.x;
    temp.y += rhs.y;
    temp.z += rhs.z;
    return temp;
}

Delta_Attitude Delta_Attitude::operator-(const Delta_Attitude &rhs){
    Delta_Attitude temp{*this};
    temp.x -= rhs.x;
    temp.y -= rhs.y;
    temp.z -= rhs.z;
    return temp;
}

Delta_Attitude& Delta_Attitude::operator+=(const Delta_Attitude &rhs){
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Delta_Attitude& Delta_Attitude::operator-=( const Delta_Attitude &rhs ){
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

std::ostream& operator<<(std::ostream& lhs, const Delta_Attitude& rhs){
    return lhs << "x: " << rhs.x << ", y:" << rhs.y << ", z: " << rhs.z;
}
}
/*
Delta_Attitude &Delta_Attitude::operator*=( const double &rhs ){

}
Delta_Attitide &Delta_Attitude::operator/=( const double &rhs )
Delta_Attitude Delta_Attitude::operator*( const double &rhs )
double Delta_Attitude::operator/( const double &rhs)
Delta_Attitude Delta_Attitude::operator/( const double &rhs )
Delta_Attitude Delta_Attitude::operator+( const Delta_Attitude &rhs )
Delta_Attitude Delta_Attitude::operator-( const Delta_Attitude &rhs )
*/