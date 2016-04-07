// ++--++
// Roborescue
// @file <Weight.hpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
// @author <Job Verhaar>
//
// @section LICENSE
// License: newBSD
//
// Copyright © 2016, HU University of Applied Sciences Utrecht.
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
// ++--++
//!
//! @author		Job Verhaar
//! @date 		04-04-16
//! @version 	0.1
//! @brief		Weight is a .....
//!

#ifndef _WEIGHT_HPP
#define _WEIGHT_HPP

#include "ADT_Base.hpp"

#include <iostream> 

class Weight : public ADT_Base<Weight>{
protected:
    //! @fn     Weight::Weight(double l)
    //!
    //! @brief  Constructor of a Weight
    //!
    //! @param	value the weight in KG
    Weight(double value);

public:
    friend ADT_Base<Weight>;
    //! @fn 	Weight::Weight()
    //!
    //! @brief 	Defaut constructor of Weight
    Weight();

    //! @fn     std::ostream operator<<(std::ostream& os, const Weight& rhs)
    //!
    //! @brief Appends a Weight to an std::ostream and returns the ostream
    //!
    //! @param os the std::ostream to append to
    //! @param rhs Object to append
    //! @return std::ostream
    friend std::ostream& operator<< (std:: ostream& os, const Weight& rhs);

    //! @fn    std::istream operator>>(std::istream& is, Weight& rhs)
    //!
    //! @brief Reads a Weight from an std::istream and returns the istream
    //!
    //! @param os the std::istream to read it from;
    //! @param rhs Object to read
    //! @return std::istream
    friend std::istream& operator>>(std::istream& is, Weight& rhs);

    //! @fn		Weight operator*(double n, const Weight & rhs)
    //!
    //! @brief	multiply a Weight bu a double and returns a Weight
    //!
    //! @param  n a double
    //! @param  rhs the Weight that is multiplied
    //! @return The calcukated Weight
    friend Weight operator* (double n, const Weight& rhs);

    static const Weight KILOGRAM;
    static const Weight GRAM;
};
#endif