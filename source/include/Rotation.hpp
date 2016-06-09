//! Roborescue
//! @file <Rotation.hpp>
//! @date Created: <7-4-16>
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

//! @brief      Rotation is a delta variant of an Attitude. Therefore it 
//!             represents some form of rotation around the x, y and z axes.
//!             These are called the pitch, yaw and roll.
//!             the pitch yaw and roll are the only attributes of Rotation
//!             and are Angle values.
//!             Therefore to create a Rotation, 3 Angles must be given.
//!
//!             For example:
//!             Totation a(1 * Angle::rad, 2 * Angle::rad, 3 * Angle::rad)
//!             This gives a Rotation with a 1rad pitch, a 2rad yaw and
//!             a 3rad roll.
#ifndef _ROTATION_HPP
#define _ROTATION_HPP

#include "../include/Length.hpp"
#include "../include/Angle.hpp"

namespace r2d2{
class Rotation{
    private:
        Angle x,y,z;
    public:
        //! @fn     Rotation::Rotation()
        //! @brief  Default constructor of a Rotation
        Rotation();
        
        //! @fn     Rotation::Rotation(Angle z, Angle y, Angle z)
        //! @brief  Constructor of a Rotation
        //! @param  pitch   The X Angle aka pitch of the Rotation
        //! @param  yaw	    The Y Angle aka yaw of the Rotation
        //! @param  roll    The Z Angle aka roll of the Rotation
        Rotation(Angle x, Angle y, Angle z);

        //! @fn     Angle Rotation::get_x()
        //! @brief  Gets the x Angle(pitch) of the Rotation and returns it
        //! @return	Angle   The x Angle aka pitch of the Rotation
        Angle get_pitch() const;
        
        //! @fn     Angle Rotation::get_y()
        //! @brief  Gets the y Angle(pitch) of the Rotation and returns it
        //! @return	Angle   The y Angle aka pitch of the Rotation
        Angle get_yaw() const;
        
        //! @fn     Angle Rotation::get_z()
        //! @brief  Gets the z Angle(pitch) of the Rotation and returns it
        //! @return	Angle   The z Angle aka pitch of the Rotation
        Angle get_roll() const;
        
        //! @fn     Rotation& Rotation::operator=
        //!         (const Rotation& rhs)
        //! @brief  Assignment operator of a Rotation
        //! @param  rhs     The Rotation that is being assigned to
        //!                 another Rotation
        //! @return	Rotation& Reference to the Rotation on which
        //!                         the assignment operator was called
        Rotation& operator=(const Rotation& rhs);
        
        //! @fn     Rotation Rotation::operator+(const
        //!         Rotation& rhs) const
        //! @brief  Add operator of two a Rotations
        //! @param  rhs         The Rotation that will be added
        //! @return	Rotation    The new Rotation that is created
        Rotation operator+(const Rotation& rhs) const;
        
        //! @fn     Rotation Rotation::operator-(const
        //!         Rotation& rhs) const
        //! @brief  Subtract operator of two a Rotations
        //! @param  rhs    The Rotation that will be subtracted
        //! @return	Rotation    The new Rotation that is created
        Rotation operator-(const Rotation& rhs) const;
        
        //! @fn     Rotation& Rotation::operator+=(const
        //!         Rotation& rhs)
        //! @brief  AddAssign operator of two Rotations
        //! @param  rhs     The Rotation that will be added
        //! @return	Attitude& Reference to the Rotation on which the
        //!                   AddAssign operator was called
        Rotation& operator+=(const Rotation& rhs);
        
        //! @fn     Rotation& Rotation::operator-=(const
        //!         Rotation& rhs)
        //! @brief  SubtractAssign operator of two Rotations
        //! @param  rhs     The Rotation that will be subtracted
        //! @return	Attitude& Reference to the Rotation on which the
        //!                   SubtractAssign operator was called
        Rotation& operator-=(const Rotation& rhs);
        
        //! @fn     std::ostream& Rotation::operator<<(std::ostream& lhs,
        //!                       const Attitude& rhs)
        //! @brief  Output operator of a Rotation
        //! @param  lhs    The ostream to which the Rotation will be added
        //! @param  rhs    The Rotation that will be added to the ostream
        //! @return	ostream& Reference to the tweaked lhs ostream
        friend std::ostream &operator<<(std::ostream& lhs,
                                        const Rotation& rhs);
};
}
#endif