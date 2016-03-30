#include "../include/Speed.hpp"

Speed operator/ ( const Length & l, const Duration & d){
	Speed s{l.l / d.seconds};
	return s; 
}

Speed & operator= (const Speed &);

bool operator< (const Speed &) const;

bool operator> (const Speed &) const;

Speed operator+ ( const Speed & rhs ) const;

Speed & operator+= ( const Speed & rhs);

Speed operator- ( const Speed & rhs ) const;

//! Substracts a speed by a speed and return the resulting speed.
/*!
  \param rhs a speed
  \return the calculated speed.
*/
Speed & operator-= ( const Speed & rhs );

//! Multiplies a speed by a duration and return the resulating distance.
/*!
  \param rhs a Duration.
  \return the calculated distance.
*/
Length operator*(const Duration & rhs) const;

//! Divide a speed by a duration and return the resulting acceleration.
/*!
  \param rhs a Duration.
  \return the calculated distance.
*/
Acceleration operator/(const Duration & rhs) const;

//! Multiplie a speed by a double and return the resulting speed
/*!
  \param rhs a double.
  \return the calculated speed.
*/
Speed operator* ( const double & rhs ) const;

//! Multiplie a speed by a double and return the resulting speed
/*!
  \param rhs a double.
  \return the calculated speed.
*/
Speed & operator*= ( const double & rhs );

	//! Multiplie a speed by a double and return the resulting speed
/*!
  \param n a double.
  \param rhs a Speed.
  \return the calculated speed.
*/

friend Speed operator/ ( const Length & l, const Duration & d);

friend Speed operator* ( double n, const Speed & rhs );

//! Divide a speed by a speed and return the resulting double
/*!
  \param rhs a Speed.
  \return the calculated speed.
*/
double operator/ ( const Speed & rhs);
/// appends a speeds to an ostream and returns an ostream
friend std::ostream& operator<<(std::ostream & os, const Speed &rhs);
/// depend a speed from an istream and return the istream
friend std::istream& operator>>(std::istream & is, Speed & rhs);