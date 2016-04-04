//!@file Rotation.hpp
//!@author Casper Wolf
//!@version 1.2

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