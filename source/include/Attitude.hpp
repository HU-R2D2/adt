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

        //! positive value describing possible deviation from middle in either direction
        const double angle_amp {M_PI};

        //! set to 0 to have the values range from -pi to pi, or to pi to have them range from 0 to 2 * pi
        const double middle_angle {M_PI};

    public:
        //!@brief 
        //!@param 
        Attitude(Angle pitch, Angle yaw, Angle roll);
        
        Angle get_x() const;
        Angle get_y() const;
        Angle get_z() const;

        //!@brief Assignment operator for an Attitude
        //!@param rhs Value to be copied into this Attitude
        Attitude& operator=(const Attitude &rhs);
        
        //!@brief
        //!@param
        Delta_Attitude operator+(const Attitude &rhs) const;
        
        //!@brief
        //!@param
        Delta_Attitude operator-(const Attitude &rhs) const;
        
        //!@brief
        //!@param
        Attitude operator+(const Delta_Attitude &rhs) const;
        
        //!@brief
        //!@param
        Attitude operator-(const Delta_Attitude &rhs) const;

        //!@brief Adds a Delta Attitude to this Attitude and returns this Attitude
        //!@param
        //!@return Attitude returns the changed Attitude
        Attitude& operator+=(const Delta_Attitude &rhs);

        //!@brief
        //!@param
        Attitude& operator-=(const Delta_Attitude &rhs);

        //!@brief
        //!@param
        friend std::ostream& operator<<(std::ostream& lhs ,const Attitude& rhs);
};
}
#endif