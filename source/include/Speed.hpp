/**
  *@author Job Verhaar
  *@date 15-03-16
  *@version 0.1
*/
#ifndef  _SPEED_HPP
#define _SPEED_HPP

//#include "Length.hpp"
#include <iostream>
#include "Duration.hpp"
#include "Length.hpp"
class Acceleration;

class Speed {


private:
	/// constructor of a speed
	Speed();
	//! Constructor for speed
	/*!
		\param val the value for speed in m\s
	*/
	Speed(double val);
	double value;
public:
	//! Assign a speed to this speed. 
    /*!
      \param rhs a speed
      \return the assigned speed.
    */
	Speed & operator= (const Speed & rhs);
	//! Checks if a speed is smaller than another speed and returns the boolean
	/*!
      \param rhs a speed
      \return the boolean that indicates if the speed is smaller than the speed
    */
	bool operator< (const Speed & rhs) const;

	//! Checks if a speed is greater  than another speed and returns the boolean
	/*!
      \param rhs a speed
      \return the boolean that indicates if the speed greater than the speed
    */
    bool operator> (const Speed & rhs) const;

	//! Adds a speed to a speed and return the resulting speed.
    /*!
      \param rhs a speed
      \return the calculated speed.
    */
	Speed operator+ ( const Speed & rhs ) const;
	
	//! Adds a speed to a speed and return the resulting speed.
    /*!
      \param rhs a speed
      \return the calculated speed.
    */
	Speed & operator+= ( const Speed & rhs);

	//! Substracts a speed by a speed and return the resulting speed.
    /*!
      \param rhs a speed
      \return the calculated speed.
    */
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

	//! Multiplie a speed by a double and return the resulting speed
    /*!
      \param rhs a double.
      \return the calculated speed.
    */

    friend Length operator*(const Duration & lhs, const Speed & rhs);
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

    friend Speed operator* ( double n, const Speed & rhs );

    Speed operator/ ( const double & rhs ) const;

	Speed & operator/= ( const double & rhs );

    friend Speed operator/ ( double n, const Speed & rhs );



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

	friend Speed operator/ ( const Length & l, const Duration & d);

};

Speed operator/ ( const Length & l, const Duration & d);
#endif

