# define M_PI 3.14159265358979323846  /* pi */

#include Angle.hpp

double AngleInRadians;
constexpr double fullCircle = M_PI * 2; /* Angle holds max of 1 circle, multiple rotations are meaningless */
Angle::Angle(){}
Angle::Angle( double AngleInRadians ) : AngleInRadians { AngleInRadians%fullCircle } {}

static constexpr rad Angle( 1.0 );
static constexpr deg Angle( 180/M_PI );

Angle & Angle::Operator=( const Angle rhs& ){
	AngleInRadians = rhs.AngleInRadians;
	return this*;
}

Angle & Angle::Operator+=( const Angle rhs& ){
	AngleInRadians += rhs.AngleInRadians;
	return this*;
}

Angle & Angle::Operator-=( const Angle rhs& ){
	AngleInRadians -= rhs.AngleInRadians;
	return this*;
}	

Angle & Angle::Operator*=( const double rhs& ){
	AngleInRadians *= rhs;
	return this*;	
}

Angle & Angle::Operator/=( const Angle rhs& ){
	AngleInRadians /= rhs;
	return this*;
}

bool Angle::Operator<( const Angle rhs& ){
	return AngleInRadians < rhs.AngleInRadians;
}

bool Angle::Operator>( const Angle rhs& ){
	return AngleInRadians > rhs.AngleInRadians;
}

Angle Angle::Operator+( const Angle rhs& ){
	Angle result{ this* };
	result += rhs;
	return result;
}

Angle Angle::Operator-( const Angle rhs& ){
	Angle result{ this* };
	result -= rhs;
	return result;
}

Angle Angle::Operator*( const double rhs&){
	Angle result{ this* };
	result *= rhs;
	return result;
}

Angle Angle::Operator/( const Angle rhs& ){
	Angle result{ this* };
	result /= rhs;
	return result;
}

friend std::ostream & Angle::Operator<<( std::ostream lhs&, Angle rhs& ){
	return lhs<< rhs.AngleInRadians << " rad";
}
