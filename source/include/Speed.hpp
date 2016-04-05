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
#include "ADT_Base.hpp"
class Acceleration;

class Speed : public ADT_Base<Speed>{


protected:
	
	//! Constructor for speed
	/*!
		\param val the value for speed in m\s
	*/
	Speed(double value);
	//double value;
public:
  friend ADT_Base<Speed>;
	//! Default constructor of a speed
	Speed();
  
  //! Multiplies a speed by a double
  /*!
    \param n a double.
    \param rhs a Speed.
    \return the calculated speed.
  */
  friend Speed operator* ( double n, const Speed & rhs );
  
	//! Appends a speed to an std::ostream and returns the ostream
  /*!
    \param os the std::ostream to append to
    \param rhs Object to append
    \return std::ostream
  */
	friend std::ostream& operator<<(std::ostream & os, const Speed &rhs);
	//! Reads a speed from an std::istream and returns the istream
  /*!
    \param os the std::istream to read it from;
    \param rhs Object to read
    \return std::istream
  */
	friend std::istream& operator>>(std::istream & is, Speed & rhs);

  //! Divides a Length by a duration.
    /*!
      \param l the length
      \param d the duration
      \return the calculated speed.
  */
	friend Speed operator/ ( const Length & l, const Duration & d);

  //! Multiplies a speed by a duration.
    /*!
      \param rhs a Duration.
      \return the calculated length in meters.
    */
  Length operator*(const Duration & rhs) const;

  //! Multiplies a speed by a duration.
    /*!
      \param lhs a Duration.
      \param rhs a Speed.
      \return the calculated length in meters.
    */
  friend Length operator*(const Duration & lhs, const Speed & rhs);

};

Speed operator/ ( const Length & l, const Duration & d);
#endif

