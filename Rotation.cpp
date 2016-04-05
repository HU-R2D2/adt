////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file Rotation.cpp
// @date Created: 29-03-16
// @version 2.0.0
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
# define M_PI 3.14159265358979323846  /* pi */

#include "Rotation.hpp"

double rotation_radians;
constexpr double full_circle = M_PI * 2.0; /* Rotation holds max of 1 circle, multiple rotations are meaningless */
Rotation::Rotation() : rotation_radians{ 0.0 } {}
Rotation::Rotation( double rotation_radians ) : rotation_radians { rotation_radians%full_circle } {}

static constexpr rad Rotation( 1.0 );
static constexpr deg Rotation( 180.0/M_PI );

Rotation & Rotation::Operator=( const Rotation rhs& ){
	rotation_radians = rhs.rotation_radians;
	return this*;
}

Rotation & Rotation::Operator+=( const Rotation rhs& ){
	rotation_radians += rhs.rotation_radians;
	return this*;
}

Rotation & Rotation::Operator-=( const Rotation rhs& ){
	rotation_radians -= rhs.rotation_radians;
	return this*;
}	

Rotation & Rotation::Operator*=( const double rhs& ){
	rotation_radians *= rhs;
	return this*;	
}

Rotation & Rotation::Operator/=( const Rotation rhs& ){
	rotation_radians /= rhs;
	return this*;
}

bool Rotation::Operator<( const Rotation rhs& ){
	return rotation_radians < rhs.rotation_radians;
}

bool Rotation::Operator>( const Rotation rhs& ){
	return rotation_radians > rhs.rotation_radians;
}

Rotation Rotation::Operator+( const Rotation rhs& ){
	Rotation result{ this* };
	result += rhs;
	return result;
}

Rotation Rotation::Operator-( const Rotation rhs& ){
	Rotation result{ this* };
	result -= rhs;
	return result;
}

Rotation Rotation::Operator*( const double rhs&){
	Rotation result{ this* };
	result *= rhs;
	return result;
}

Rotation Rotation::Operator/( const Rotation rhs& ){
	Rotation result{ this* };
	result /= rhs;
	return result;
}

friend std::ostream & Rotation::Operator<<( std::ostream lhs&, Rotation rhs& ){
	return lhs<< rhs.rotation_radians << " rad";
}

double Rotation::get_rotation(){
	return rotation_radians;
}