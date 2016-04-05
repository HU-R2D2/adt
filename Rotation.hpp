////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                     
//
// @file Rotation.hpp
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
#ifndef Rotation_HPP
#define Rotation_HPP

class Rotation{
	private:

		double rotation_radians;

		//!@brief Creates an Rotation from a double
		//!@brief Anything larger than one circle (2pi) is modulo'd with 2pi
		//!@param rotation_radians The Rotation in radians
		Rotation( double rotation_radians);

		//!@brief value in Radians of one full rotation
		constexpr double full_circle = M_PI * 2.0; /* Rotation holds max of 1 circle, multiple rotations are meaningless */

	public:

		Rotation();
		
		//!@brief create an Rotation by multiplying with the rad constant when given Rotation is in Radians
		static constexpr rad Rotation( 1.0 );

		//!@brief create an Rotation by multiplying with the deg constant when given Rotation is in Degrees
		static constexpr deg Rotation( 180.0/M_PI );

		//!@brief Copies the righthand value into this and returns a reference to this
		//!@param rhs Value to be copied into this
		Rotation & Operator=( const Rotation rhs& );

		//!@brief Add the rotation_radians value on the right hand to this and returns the resulting Rotation
		//!@param rhs Rotation of which the rotation_radians value has to be added to this
		Rotation & Operator+=( const Rotation rhs& );

		//!@brief Subtracts the rotation_radians value on the right hand from this and returns the resulting Rotation
		//!@param rhs Rotation of which the rotation_radians value has to be substracted from this
		Rotation & Operator-=( const Rotation rhs& );

		//!@brief Multplies the righthand Double with this' rotation_radians value
		//!@param rhs Double to multiply this with
		Rotation & Operator*=( const double rhs& );

		//!@brief Divides this by the righthand Double
		//!@param rhs The Rotation to divide this with
		Rotation & Operator/=( const double rhs& );

		//!@brief compares two Rotations to each other and return a boolean (true if 1st greater than 2nd)
		//!@param rhs The Rotation that is being compared to the other Rotation
		bool Operator<( const Rotation rhs& );

		//!@brief compares two Rotations to each other and return a boolean (true if 1st smaller  than 2nd)
		//!@param rhs The Rotation that is being compared to the other Rotation
		bool Operator>( const Rotation rhs& );

		//!@brief add the Rotation in Radians value on the right hand to this and returns a Rotation
		//!@param rhs Rotation of which the rotation_radians value has to be added to this
		Rotation Operator+( const Rotation rhs& );

		//!@brief subtracts the rotation_radians value on the right hand from this and returns the a Rotation
		//!@param rhs Rotation of which the rotation_radians value has to be substracted from this
		Rotation Operator-( const Rotation rhs& );

		//!@brief multiplies the Rotation by a number and returns a Rotation
		//!@param rhs The number by which the Rotation will be multiplied
		Rotation Operator*( const double rhs&);

		//!@brief divides the Rotation by a number and return a Rotation
		//!@param rhs The number by which the Rotation will be divided
		Rotation Operator/( const double rhs& );

		//!@brief Output operator of a Rotation
		//!@param lhs The ostream that will be appended
		//!@param rhs The Rotation that will be added to the ostream
		friend std::ostream & Operator<<( std::ostream lhs&, Rotation rhs& );

		double get_Rotation();
};
#endif