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