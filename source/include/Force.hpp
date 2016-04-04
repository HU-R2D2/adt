/**
	*@author 	Job Verhaar
	*@date 		04-04-2016
	*@version 	0.1
**/
#ifndef _FORCE_HPP
#define _FORCE_HPP

#include "gtest/gtest.h"
#include "Weight.hpp"
#include "Acceleration.hpp"
#include <iostream>

class Force
{
private:
	//! Constructor for force
	/*!
		\param val the value for force in kg*m\s²
	*/
	Force(double val);
	double value;
public:
	Force();
	//! Assigns a Force to this Force. 
    /*!
      \param rhs a Force
      \return the assigned Force.
    */
	Force & operator= (const Force & rhs);

	
	//! Checks if a Force is smaller than another Force
	/*!
      \param rhs a Force
      \return the boolean that indicates if the Force is smaller than the Force
    */
	bool operator< (const Force & rhs) const;

	//! Checks if a Force is greater  than another Force
	/*!
      \param rhs a Force
      \return the boolean that indicates if the Force greater than the Force
    */
    bool operator> (const Force & rhs) const;

	//! Adds a Force to a Force.
    /*!
      \param rhs a Force
      \return the calculated Force.
    */
	Force operator+ ( const Force & rhs ) const;
	
	//! Adds a Force to a Force and assign it to this Force.
    /*!
      \param rhs a Force
      \return reference to updated Force.
    */
	Force & operator+= ( const Force & rhs);

	//! Substracts a Force by a Force.
    /*!
      \param rhs a Force.
      \return the calculated Force.
    */
	Force operator- ( const Force & rhs ) const;

	//! Substracts a Force by a Force and assign it to this Force.
    /*!
      \param rhs a Force.
      \return refence to updated Force.
    */
	Force & operator-= ( const Force & rhs );

	//! Multiplie a Force by a double
    /*!
      \param rhs a double.
      \return the calculated Force.
    */
	Force operator* ( const double & rhs ) const;

	//! Multiplies this Force by a double.
    /*!
      \param rhs a double.
      \return the reference to updated Force.
    */
	Force & operator*= ( const double & rhs );

   	//! Multiplies a Force by a double
    /*!
      \param n a double.
      \param rhs a Force.
      \return the calculated Force.
    */
    friend Force operator* ( double n, const Force & rhs );

    //! Divides a Force by a double.
    /*!
      \param rhs a double.
      \return the calculated Force.
    */
    Force operator/ ( const double & rhs ) const;

	//! Divides this Force by a double.
	/*!
	  \param rhs a double.
	  \return reference to updated Force.
	*/
	Force & operator/= ( const double & rhs );

  	//! Divide a Force by a Force
  	/*!
  	  \param rhs a Force.
  	  \return calculated result in double with no unit.
  	*/
  	static const Force NEWTON;
  	double operator/ ( const Force & rhs);
	//! Appends a Force to an std::ostream and returns the ostream
  	/*!
    	\param os the std::ostream to append to
    	\param rhs Object to append
    	\return std::ostream
  	*/
	friend std::ostream& operator<<(std::ostream & os, const Force &rhs);
	//! Reads a Force from an std::istream and returns the istream
  	/*!
   		\param os the std::istream to read it from;
    	\param rhs Object to read
    	\return std::istream
  	*/
	friend std::istream& operator>>(std::istream & is, Force & rhs);
	friend Acceleration operator/ (Speed & s, Duration &d);
  	//! Multiplies a Weight by a Accceleration.
    /*!
      \param w the Weight
      \param a the Accelation
      \return the calculated Force.
  	*/
	friend Force operator* ( const Weight & lhs, const Acceleration & rhs);
};
Force operator* ( const Weight & lhs, const Acceleration & rhs);

#endif