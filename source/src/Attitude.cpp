////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                     
//
// @file Attitude.cpp
// @date Created: 06-04-16
// @version 1.0.0
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

#include "Attitude.hpp"

Attitude( double x, double y, double z ){
    double xlen = std::sqrt(std::pow(x,2.0) + std::pow(z,2.0)); // length of 2D vector <x,z> using Pythage 
    double vector_length = std::sqrt(std::pow(xlen,2.0) + std::pow(y,2.0)) // length of 3D vector <x,y,z> using length of <x,z> and height y
    x{ x/vector_length };
    y{ y/vector_length };
    z{ z/vector_length };
}
Attitude( Angle x, Angle y ){
    double x = x.get_angle();
    double y = y.get_angle();
    double normAngle = x%(M_PI/2.0); // 1/4 circle
    double tempx = (x > middle_angle) ? 
        -std::sin(normAngle) : std::sin(normAngle); // pitch
    double tempy = (y > middle_angle) ?
         -std::sin(y) : std::sin(y); // yaw
    double tempz = (x < middle_angle - (angle_amp/2.0) &&
         x > middle_angle + (angle_amp/2.0)) ? 
         -std::cos(normAngle) : std::cos(normAngle); // roll
    x {tempx};
    y {tempy};
    z {tempz};
}
Attitude::Attitude &operator=( const Attitude &rhs ){
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}
Attitude::Attitude &operator+=( const relative_direction &rhs ){
    Attitude temp{ *this };
    temp.x += rhs.x;
    temp.y += rhs.y;
    temp.z += rhs.z;
    return temp;
}
Attitude::Attitude &operator+( const relative_direction &rhs ){
    this+=rhs;
    return this*;
}
Attitude::Attitude &operator-=( const relative_direction &rhs ){
    Attitude temp{ *this };
    temp.x -= rhs.x;
    temp.y -= rhs.y;
    temp.z -= rhs.z;
    return temp;
}
Attitude::Attitude &operator-( const relative_direction &rhs ){
    this-=rhs;
    return this*;
}
translation operator*( const Length &rhs ){
    return translation { x * rhs, y * rhs, z * rhs };
}
translation operator/( const Length &rhs ){
    return translation { x / rhs, y / rhs, z / rhs };
}
friend std::ostream &operator<<( std::ostream lhs& ,const Attitude &rhs ){
    return lhs<< "x: " << x << ", y:" << y << ", z: " << z;
}
