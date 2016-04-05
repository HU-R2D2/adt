////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                     
//
// @file Angle.hpp
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
#ifndef Angle_HPP
#define Angle_HPP

class Angle{
	private:

		double angle_radians;

		//!@brief Creates an Angle from a double
		//!@brief Anything larger than one circle (2pi) is modulo'd with 2pi
		//!@param angle_radians The Angle in radians
		Angle( double angle_radians);

		//!@brief value in Radians of one full angle
		constexpr double full_circle = M_PI * 2.0; /* Angle holds max of 1 circle, multiple angles are meaningless */

	public:

		Angle();
		
		//!@brief create an Angle by multiplying with the rad constant when given Angle is in Radians
		static constexpr rad Angle( 1.0 );

		//!@brief create an Angle by multiplying with the deg constant when given Angle is in Degrees
		static constexpr deg Angle( 180.0/M_PI );

		//!@brief Copies the righthand value into this and returns a reference to this
		//!@param rhs Value to be copied into this
		Angle & Operator=( const Angle rhs& );

		//!@brief Add the angle_radians value on the right hand to this and returns the resulting Angle
		//!@param rhs Angle of which the angle_radians value has to be added to this
		Angle & Operator+=( const Angle rhs& );

		//!@brief Subtracts the angle_radians value on the right hand from this and returns the resulting Angle
		//!@param rhs Angle of which the angle_radians value has to be substracted from this
		Angle & Operator-=( const Angle rhs& );

		//!@brief Multplies the righthand Double with this' angle_radians value
		//!@param rhs Double to multiply this with
		Angle & Operator*=( const double rhs& );

		//!@brief Divides this by the righthand Double
		//!@param rhs The Angle to divide this with
		Angle & Operator/=( const double rhs& );

		//!@brief compares two Angles to each other and return a boolean (true if 1st greater than 2nd)
		//!@param rhs The Angle that is being compared to the other Angle
		bool Operator<( const Angle rhs& );

		//!@brief compares two Angles to each other and return a boolean (true if 1st smaller  than 2nd)
		//!@param rhs The Angle that is being compared to the other Angle
		bool Operator>( const Angle rhs& );

		//!@brief add the Angle in Radians value on the right hand to this and returns a Angle
		//!@param rhs Angle of which the angle_radians value has to be added to this
		Angle Operator+( const Angle rhs& );

		//!@brief subtracts the angle_radians value on the right hand from this and returns the a Angle
		//!@param rhs Angle of which the angle_radians value has to be substracted from this
		Angle Operator-( const Angle rhs& );

		//!@brief multiplies the Angle by a number and returns a Angle
		//!@param rhs The number by which the Angle will be multiplied
		Angle Operator*( const double rhs&);

		//!@brief divides the Angle by a number and return a Angle
		//!@param rhs The number by which the Angle will be divided
		Angle Operator/( const double rhs& );

		//!@brief Output operator of a Angle
		//!@param lhs The ostream that will be appended
		//!@param rhs The Angle that will be added to the ostream
		friend std::ostream & Operator<<( std::ostream lhs&, Angle rhs& );

		double get_angle();
};
#endif