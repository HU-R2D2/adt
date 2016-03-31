//!@file angle.hpp
//!@author Casper Wolf
//!@version 1.0

#ifndef angle_HPP
#define angle_HPP

class angle{
	private:

		double angleInRadians;

		//!@brief Creates an angle from a double
		//!@brief Anything larger than one circle (2pi) is modulo'd with 2pi
		//!@param angleInRadians The angle in radians
		angle( double angleInRadians);

		//!@brief value in Radians of one full rotation
		constexpr double fullCircle = M_PI * 2; /* angle holds max of 1 circle, multiple rotations are meaningless */

	public:

		angle();
		
		//!@brief create an angle by multiplying with the rad constant when given angle is in Radians
		static constexpr rad angle( 1.0 );

		//!@brief create an angle by multiplying with the deg constant when given angle is in Degrees
		static constexpr deg angle( 180/M_PI );

		//!@brief Copies the righthand value into this and returns a reference to this
		//!@param rhs Value to be copied into this
		angle & angle::Operator=( const angle rhs& );

		//!@brief Add the angleInRadians value on the right hand to this and returns the resulting angle
		//!@param rhs angle of which the angleInRadians value has to be added to this
		angle & angle::Operator+=( const angle rhs& );

		//!@brief Substracts the angleInRadians value on the right hand from this and returns the resulting angle
		//!@param rhs angle of which the angleInRadians value has to be substracted from this
		angle & angle::Operator-=( const angle rhs& );

		//!@brief Multplies the righthand Double with this' angleInRadians value
		//!@param rhs Double to multiply this with
		angle & angle::Operator*=( const double rhs& );

		//!@brief Divides this by the righthand Double
		//!@param rhs The angle to divide this with
		angle & angle::Operator/=( const double rhs& );

		//!@brief
		//!@param
		bool angle::Operator<( const angle rhs& );

		//!@brief
		//!@param
		bool angle::Operator>( const angle rhs& );

		//!@brief
		//!@param
		angle angle::Operator+( const angle rhs& );

		//!@brief
		//!@param
		angle angle::Operator-( const angle rhs& );

		//!@brief
		//!@param
		angle angle::Operator*( const double rhs&);

		//!@brief
		//!@param
		angle angle::Operator/( const double rhs& );

		//!@brief
		//!@param
		friend std::ostream & angle::Operator<<( std::ostream lhs&, angle rhs& );
};
#endif