////
//  ???????  ??????? ???????  ??????? ??????? ???????????????? ??????????   ???????????
//  ?????????????????????????????????????????????????????????????????????   ???????????
//  ???????????   ??????????????   ?????????????????  ???????????     ???   ?????????
//  ???????????   ??????????????   ?????????????????  ???????????     ???   ?????????
//  ???  ????????????????????????????????  ????????????????????????????????????????????
//  ???  ??? ??????? ???????  ??????? ???  ??????????????????? ??????? ??????? ????????
//
//
// @file Speed.hpp
// @date Created: 15-03-16
// @version 0.1
//
// @author Job Verhaar
//
// @section LICENSE
// License: newBSD
//
// Copyright � 2016, HU University of Applied Sciences Utrecht.
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

#ifndef  _SPEED_HPP
#define _SPEED_HPP

//#include "Length.hpp"
#include <iostream>
#include "Duration.hpp"
#include "Length.hpp"
class Acceleration;

class Speed final {
private:
   Speed();
   //! Constructor for speed
   //!
   //! \param val the value for speed in m\s
   Speed(double val);
   double value;

public:
   //! Default constructor of a speed
   //! Assigns a speed to this speed.
   //!
   //! \param rhs a speed
   //! \return the assigned speed.
   Speed & operator= (const Speed & rhs);

   //! Adds a speed to a speed.
   //!
   //! \param rhs a speed
   //! \return the calculated speed.
   Speed operator+ ( const Speed & rhs ) const;

   //! Checks if a speed is smaller than another speed
   //!
   //! \param rhs a speed
   //! \return the boolean that indicates if the speed is smaller than the speed.
   bool operator< (const Speed & rhs) const;

   //! Checks if a speed is greater  than another speed
   //!
   //! \param rhs a speed
   //! \return the boolean that indicates if the speed greater than the speed
   bool operator> (const Speed & rhs) const;

   //! Adds a speed to a speed and assign it to this speed.
   //!
   //! \param rhs a speed
   //!   \return reference to updated speed.
   Speed & operator+= ( const Speed & rhs);

   //! Substracts a speed by a speed.
   //!
   //! \param rhs a speed.
   //! \return the calculated speed.
   Speed operator- ( const Speed & rhs ) const;

   //! Substracts a speed by a speed and assign it to this speed.
   //!
   //! \param rhs a speed.
   //! \return refence to updated speed.
   Speed & operator-= ( const Speed & rhs );

   //! Multiplies a speed by a duration.
   //!
   //! \param rhs a Duration.
   //! \return the calculated length in meters.
   Length operator*(const Duration & rhs) const;

   //! Multiplies a speed by a duration.
   //!
   //! \param lhs a Duration.
   //! \param rhs a Speed.
   //! \return the calculated length in meters.
   friend Length operator*(const Duration & lhs, const Speed & rhs);

   //! Multiplie a speed by a double
   //!
   //! \param rhs a double.
   //! \return the calculated speed.
   Speed operator* ( const double & rhs ) const;

   //! Multiplies this speed by a double.
   //!
   //! \param rhs a double.
   //! \return the reference to updated speed.
   Speed & operator*= ( const double & rhs );

   //! Multiplies a speed by a double
   //!
   //! \param n a double.
   //! \param rhs a Speed.
   //! \return the calculated speed.
   friend Speed operator* ( double n, const Speed & rhs );

   //! Divides a speed by a double.
   //!
   //!  \param rhs a double.
   //!  \return the calculated speed.
   Speed operator/ ( const double & rhs ) const;

   //! Divides this speed by a double.
   //!
   //! \param rhs a double.
   //! \return reference to updated speed.
   Speed & operator/= ( const double & rhs );

   //! Divide a speed by a speed
   //!
   //! \param rhs a Speed.
   //! \return calculated result in double with no unit.
   double operator/ ( const Speed & rhs) const;

   //! Appends a speed to an std::ostream and returns the ostream
   //!
   //! \param os the std::ostream to append to
   //! \param rhs Object to append
   //! \return std::ostream
   friend std::ostream& operator<<(std::ostream & os, const Speed &rhs);

   //! Reads a speed from an std::istream and returns the istream
   //!
   //! \param os the std::istream to read it from;
   //! \param rhs Object to read
   //! \return std::istream
   friend std::istream& operator>>(std::istream & is, Speed & rhs);

   //! Divides a Length by a duration.
   //!
   //! \param l the length
   //! \param d the duration
   //! \return the calculated speed.
   friend Speed operator/ ( const Length & l, const Duration & d);
};

Speed operator/ ( const Length & l, const Duration & d);
#endif

