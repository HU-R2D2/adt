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

		//!@brief Substracts the rotation_radians value on the right hand from this and returns the resulting Rotation
		//!@param rhs Rotation of which the rotation_radians value has to be substracted from this
		Rotation & Operator-=( const Rotation rhs& );

		//!@brief Multplies the righthand Double with this' rotation_radians value
		//!@param rhs Double to multiply this with
		Rotation & Operator*=( const double rhs& );

		//!@brief Divides this by the righthand Double
		//!@param rhs The Rotation to divide this with
		Rotation & Operator/=( const double rhs& );

		//!@brief
		//!@param
		bool Operator<( const Rotation rhs& );

		//!@brief
		//!@param
		bool Operator>( const Rotation rhs& );

		//!@brief
		//!@param
		Rotation Operator+( const Rotation rhs& );

		//!@brief
		//!@param
		Rotation Operator-( const Rotation rhs& );

		//!@brief
		//!@param
		Rotation Operator*( const double rhs&);

		//!@brief
		//!@param
		Rotation Operator/( const double rhs& );

		//!@brief
		//!@param
		friend std::ostream & Operator<<( std::ostream lhs&, Rotation rhs& );

		double get_Rotation();
};
#endif