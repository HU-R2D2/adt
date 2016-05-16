//! Roborescue
//! @file <Attitude.cpp>
//! @date Created: <6-4-16>
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

#include "../include/Attitude.hpp"
namespace r2d2{
/*Attitude::Attitude(double x, double y, double z){
    double xlen = std::sqrt(std::pow(x,2.0) + std::pow(z,2.0)); // length of 2D vector <x,z> using Pythage 
    double vector_length = std::sqrt(std::pow(xlen,2.0) + std::pow(y,2.0)); // length of 3D vector <x,y,z> using length of <x,z> and height y
    this->x = x/vector_length;
    this->y = y/vector_length;
    this->z = z/vector_length;
} */
/*
Attitude::Attitude( Angle X, Angle Y, Angle Z){
    double pitch = X.get_angle();
    double yaw = Y.get_angle();
    
    double normAngle = pitch%(M_PI/2.0); // 1/4 circle
    double tempx = (pitch > middle_angle) ? 
        -std::sin(normAngle) : std::sin(normAngle); // pitch
        
    double tempy = (yaw > middle_angle) ?
         -std::sin(yaw) : std::sin(yaw); // yaw
         
    double tempz = (pitch < middle_angle - (angle_amp/2.0) &&
         pitch > middle_angle + (angle_amp/2.0)) ? 
         -std::cos(normAngle) : std::cos(normAngle); // roll
         
    this->x = tempx;
    this->y = tempy;
    this->z = tempz;
}
*/

Attitude& Attitude::operator=(const Attitude& rhs){
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Delta_Attitude Attitude::operator+(const Attitude& rhs){
    Delta_Attitude delta{x + rhs.x, y + rhs.y, z + rhs.z};
    return delta;
}

Delta_Attitude Attitude::operator-(const Attitude& rhs){
    Delta_Attitude delta{x - rhs.x, y - rhs.y, z - rhs.z};
    return delta;
}
/*        
Delta_Attitude& Attitude::operator+=(const Attitude& rhs);
        

Delta_Attitude& Attitude::operator-=(const Attitude& rhs);
*/

Attitude Attitude::operator+(const Delta_Attitude& rhs){
    Attitude temp{*this};
    temp.x += rhs.get_x();
    temp.y += rhs.get_y();
    temp.z += rhs.get_z();
    return temp;
}

Attitude Attitude::operator-(const Delta_Attitude& rhs){
    Attitude temp{*this};
    temp.x -= rhs.get_x();
    temp.y -= rhs.get_y();
    temp.z -= rhs.get_z();
    return temp;
}

Attitude& Attitude::operator+=(const Delta_Attitude& rhs){
    x += rhs.get_x();
    y += rhs.get_y();
    z += rhs.get_z();
    return *this;
}

Attitude& Attitude::operator-=(const Delta_Attitude& rhs){
    x -= rhs.get_x();
    y -= rhs.get_y();
    z -= rhs.get_z();
    return *this;
}

std::ostream& operator<<(std::ostream& lhs,const Attitude& rhs){
    return lhs << "x: " << rhs.x << ", y:" << rhs.y << ", z: " << rhs.z;
}
}