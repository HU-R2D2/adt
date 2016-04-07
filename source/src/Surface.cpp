//! @file Surface.cpp
//! @date Created: 04-04-16
//! @version 1.0.0
//!
//! @author Matthijs Mud
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//! THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
//! BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
//! GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//! HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//! LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
//! OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "../include/Surface.hpp"
#include "../include/Length.hpp"
#include <stdexcept>

Surface::Surface(const double &value)
        : value{value} {

}

Surface &Surface::operator=(const Surface &rhs) {
    value = rhs.value;
    return *this;
}

Surface &Surface::operator+=(const Surface &rhs) {
    value += rhs.value;
    return *this;
}

Surface Surface::operator+(const Surface &rhs) const {
    return Surface{value} += rhs;
}

Surface &Surface::operator-=(const Surface &rhs) {
    value -= rhs.value;
    return *this;
}

Surface Surface::operator-(const Surface &rhs) const {
    return Surface{value} -= rhs;
}

Surface operator*(const Length &lhs, const Length &rhs) {
    return Surface{(lhs / Length::METER) * (rhs / Length::METER)};
}

Surface &Surface::operator*=(const double &rhs) {
    value *= rhs;
    return *this;
}

Surface Surface::operator*(const double &rhs) const {
    return Surface{value} *= rhs;
}

Surface operator*(const double &lhs, const Surface &rhs) {
    return Surface{rhs.value} *= lhs;
}

Surface &Surface::operator/=(const double &rhs) {
    value /= rhs;
    return *this;
}

Surface Surface::operator/(const double &rhs) const {
    return Surface{value} /= rhs;
}

double Surface::operator/(const Surface &rhs) const {
    return value / rhs.value;
}

Length Surface::operator/(const Length &rhs) const {
    // Gets the value of the length by diving it,
    // so the surface can be divided;
    // as to supply the length of the other edge.
    return (value / (rhs / Length::METER)) * Length::METER;
}

std::ostream &operator<<(std::ostream &lhs, const Surface &rhs) {
    lhs << rhs.value << "m^2";
    return lhs;
}

std::istream &operator>>(std::istream &lhs, Surface &rhs) {
    Length value;
    char power, square;
    lhs >> std::ws >> value >> std::ws >> power >> square;
    if (power == '^' && square == '2') {
        rhs = value * Length::METER;
        return lhs;
    }
    throw SurfaceException{"Specified prefix is unknown."};
}

SurfaceException::SurfaceException(const char *message)
        : std::runtime_error{message} {

}
