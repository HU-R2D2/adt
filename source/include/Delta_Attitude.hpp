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
        Delta_Attitude();
        Delta_Attitude(Angle x, Angle y, Angle z);
		
        Angle get_x() const;
        Angle get_y() const;
        Angle get_z() const;
        
		Delta_Attitude& operator=( const Delta_Attitude& rhs );
        Delta_Attitude operator+( const Delta_Attitude& rhs );
		Delta_Attitude operator-( const Delta_Attitude& rhs );
		Delta_Attitude& operator+=( const Delta_Attitude& rhs );
		Delta_Attitude& operator-=( const Delta_Attitude& rhs );
        
        //Delta_Attitude operator*(const double& rhs);
        //double operator/(const double& rhs);
        //Delta_Attitude operator/(const double& rhs);
		friend std::ostream &operator<<(std::ostream& lhs, const Delta_Attitude& rhs);
};
}
#endif