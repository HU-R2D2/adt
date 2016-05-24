//! Roborescue
//! @file <Delta_Attitude.hpp>
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

#ifndef _DELTA_ATTITUDE_HPP
#define _DELTA_ATTITUDE_HPP

#include "../include/Length.hpp"
#include "../include/Angle.hpp"

namespace r2d2{
class Delta_Attitude{
	private:
		Angle x,y,z;
	public:
        //! @fn     Delta_Attitude::Delta_Attitude()
        //! @brief  Default constructor of a Delta_Attitude
        Delta_Attitude();
        
        //! @fn     Delta_Attitude::Delta_Attitude(Angle z, Angle y, Angle z)
        //! @brief  Constructor of a Delta_Attitude
        //! @param  pitch   The X Angle aka pitch of the Delta_Attitude
        //! @param  yaw	    The Y Angle aka yaw of the Delta_Attitude
        //! @param  roll	The Z Angle aka roll of the Delta_Attitude
        Delta_Attitude(Angle x, Angle y, Angle z);
		
        //! @fn     Angle Delta_Attitude::get_x()
        //! @brief  Gets the x Angle(pitch) of the Delta_Attitude and returns it
        //! @return	Angle	The x Angle aka pitch of the Delta_Attitude
        Angle get_pitch() const;
        
        //! @fn     Angle Delta_Attitude::get_y()
        //! @brief  Gets the y Angle(pitch) of the Delta_Attitude and returns it
        //! @return	Angle	The y Angle aka pitch of the Delta_Attitude
        Angle get_yaw() const;
        
        //! @fn     Angle Delta_Attitude::get_z()
        //! @brief  Gets the z Angle(pitch) of the Delta_Attitude and returns it
        //! @return	Angle	The z Angle aka pitch of the Delta_Attitude
        Angle get_roll() const;
        
        //! @fn     Delta_Attitude& Delta_Attitude::operator=
        //!         (const Delta_Attitude& rhs)
        //! @brief  Assignment operator of a Delta_Attitude
        //! @param  rhs     The Delta_Attitude that is being assigned to
        //!                 another Delta_Attitude
        //! @return	Delta_Attitude& Reference to the Delta_Attitude on which
        //!                         the assignment operator was called
		Delta_Attitude& operator=(const Delta_Attitude& rhs);
        
        //! @fn     Delta_Attitude Delta_Attitude::operator+(const
        //!         Delta_Attitude& rhs) const
        //! @brief  Add operator of two a Delta_Attitudes
        //! @param  rhs    The Delta_Attitude that will be added
        //! @return	Delta_Attitude    The new Delta_Attitude that is created
        Delta_Attitude operator+(const Delta_Attitude& rhs) const;
        
        //! @fn     Delta_Attitude Delta_Attitude::operator-(const
        //!         Delta_Attitude& rhs) const
        //! @brief  Subtract operator of two a Delta_Attitudes
        //! @param  rhs    The Delta_Attitude that will be subtracted
        //! @return	Delta_Attitude    The new Delta_Attitude that is created
		Delta_Attitude operator-(const Delta_Attitude& rhs) const;
        
        //! @fn     Delta_Attitude& Delta_Attitude::operator+=(const
        //!         Delta_Attitude& rhs)
        //! @brief  AddAssign operator of two Delta_Attitudes
        //! @param  rhs     The Delta_Attitude that will be added
        //! @return	Attitude& Reference to the Delta_Attitude on which the
        //!                   AddAssign operator was called
		Delta_Attitude& operator+=(const Delta_Attitude& rhs);
        
        //! @fn     Delta_Attitude& Delta_Attitude::operator-=(const
        //!         Delta_Attitude& rhs)
        //! @brief  SubtractAssign operator of two Delta_Attitudes
        //! @param  rhs     The Delta_Attitude that will be subtracted
        //! @return	Attitude& Reference to the Delta_Attitude on which the
        //!                   SubtractAssign operator was called
		Delta_Attitude& operator-=(const Delta_Attitude& rhs);
        
        //Delta_Attitude operator*(const double& rhs);
        //double operator/(const double& rhs);
        //Delta_Attitude operator/(const double& rhs);
        
        //! @fn     std::ostream& Delta_Attitude::operator<<(std::ostream& lhs,
        //!                       const Attitude& rhs)
        //! @brief  Output operator of a Delta_Attitude
        //! @param  lhs    The ostream to which the Delta_Attitude will be added
        //! @param  rhs    The Delta_Attitude that will be added to the ostream
        //! @return	ostream& Reference to the tweaked lhs ostream
		friend std::ostream &operator<<(std::ostream& lhs,
        const Delta_Attitude& rhs);
};
}
#endif