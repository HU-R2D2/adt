//! Roborescue
//! @file <Attitude.hpp>
//! @date Created: <6-4-16>
//! @version <0.5.0>
//!
//! @author <Casper Wolf & Remco Nijkamp>
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, 
//! with or without modification, are permitted provided that 
//! the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice, 
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice, 
//!   this list of conditions and the following disclaimer in the documentation 
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht nor 
//!   the names of its contributors may be used to endorse or promote products 
//!   derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
//! BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//! FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY
//! OF APPLIED SCIENCES UTRECHT BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//! SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//! OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//! WHETHER IN CONTRACT, STRICT LIABILITY,
//! OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
//! THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef ATTITUDE_HPP
#define ATTITUDE_HPP

#include "Delta_Attitude.hpp"
#include <iostream>

namespace r2d2{
class Attitude{
    private:
        //constexpr double M_PI = 3.14159265358979323846;
        //! using x = pitch, y = yaw, z = roll
        Angle x,y,z;

        //! positive value describing possible deviation
        //! from middle in either direction
        const double angle_amp {M_PI};

        //! set to 0 to have the values range from -pi to pi,
        //! or to pi to have them range from 0 to 2 * pi
        const double middle_angle {M_PI};

    public:
        //! @fn     Attitude::Attitude()
        //! @brief  Default constructor of an Attitude
        Attitude();
    
        //! @fn     Attitude::Attitude(Angle pitch, Angle yaw, Angle roll)
        //! @brief  Constructor of an Attitude
        //! @param  pitch   The X Angle aka pitch of the Attitude
        //! @param  yaw	    The Y Angle aka yaw of the Attitude
        //! @param  roll	The Z Angle aka roll of the Attitude
        Attitude(Angle pitch, Angle yaw, Angle roll);
        
        //! @fn     Angle Attitude::get_x()
        //! @brief  Gets the x Angle aka pitch of the Attitude and returns it
        //! @return	Angle	The x Angle aka pitch of the Attitude
        Angle get_pitch() const;
        
        //! @fn     Angle Attitude::get_y()
        //! @brief  Gets the y Angle aka pitch of the Attitude and returns it
        //! @return	Angle	The y Angle aka pitch of the Attitude
        Angle get_yaw() const;
        
        //! @fn     Angle Attitude::get_z()
        //! @brief  Gets the z Angle aka pitch of the Attitude and returns it
        //! @return	Angle	The z Angle aka pitch of the Attitude
        Angle get_roll() const;

        //! @fn     Attitude& Attitude::operator=(const Attitude& rhs)
        //! @brief  Assignment operator of an Attitude
        //! @param  rhs     The right hand sight Attitude, this one is 
        //!                 being assigned to another Attitude
        //! @return	Attitude& Reference to the Attitude on which the 
        //!                      assignment operator was called
        Attitude& operator=(const Attitude& rhs);
        
        //! @fn Delta_Attitude Attitude::operator+(const Attitude& rhs) const
        //! @brief  Add operator of an Attitude and another Attitude
        //! @param  rhs    The Attitude that will be added to an Attitude
        //! @return	Delta_Attitude    The Delta_Attitude that is created
        //!                           by the addition
        Delta_Attitude operator+(const Attitude& rhs) const;
        
        //! @fn Delta_Attitude Attitude::operator-(const Attitude& rhs) const
        //! @brief  Subtract operator of an Attitude and another Attitude
        //! @param  rhs    The Attitude that will be subtracted from an Attitude
        //! @return	Delta_Attitude    The Delta_Attitude that is created
        //!                           by the subtraction
        Delta_Attitude operator-(const Attitude& rhs) const;
        
        //! @fn Attitude Attitude::operator+(const Delta_Attitude& rhs) const
        //! @brief  Add operator of an Attitude and a Delta_Attitude
        //! @param  rhs    The Delta_Attitude that will be added to an Attitude
        //! @return	Attitude    The new Attitude that is created by the addition
        Attitude operator+(const Delta_Attitude& rhs) const;
        
        //! @fn Attitude Attitude::operator-(const Delta_Attitude& rhs) const
        //! @brief  Subtract operator of an Attitude and a Delta_Attitude
        //! @param  rhs     The Delta_Attitude that will be subtracted
        //!                 from an Attitude
        //! @return	Attitude The new Attitude that is created by the subtraction
        Attitude operator-(const Delta_Attitude& rhs) const;
        
        //! @fn    Attitude& Attitude::operator+=(const Delta_Attitude& rhs)
        //! @brief  AddAssign operator of an Attitude and a Delta_Attitude
        //! @param  rhs     The Delta_Attitude that will be added to the Attitude
        //! @return	Attitude& Reference to the Attitude on which the
        //!                   AddAssign operator was called
        Attitude& operator+=(const Delta_Attitude& rhs);

        //! @fn    Attitude& Attitude::operator-=(const Delta_Attitude& rhs)
        //! @brief  SubtractAssign operator of an Attitude and a Delta_Attitude
        //! @param  rhs       The Delta_Attitude that will be subtracted
        //!                   from the Attitude
        //! @return	Attitude& Reference to the Attitude on which the
        //!                   SubtractAssign operator was called
        Attitude& operator-=(const Delta_Attitude& rhs);

        //! @fn     std::ostream& Attitude::operator<<(std::ostream& lhs,
        //!                       const Attitude& rhs)
        //! @brief  Output operator of an Attitude
        //! @param  lhs     The ostream to which the Attitude will be added
        //! @param  rhs     The Attitude that will be added to the ostream
        //! @return	ostream& Reference to the tweaked lhs ostream
        friend std::ostream& operator<<(std::ostream& lhs ,const Attitude& rhs);
};
}
#endif