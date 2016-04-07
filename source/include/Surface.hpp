//! @file Surface.hpp
//! @date Created: 14-03-16
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


#ifndef ADT_SURFACE_HPP
#define ADT_SURFACE_HPP

#include <iostream>
#include <stdexcept>
#include "Length.hpp"

// Forward declaration.
class Length;

class SurfaceException final : public std::runtime_error {
public:
    SurfaceException(const char *message);
};

//! @class Surface
//! @brief Representation for the size of outer side of an object.
//!
//!
class Surface final {
private:
    double value;

    //! @brief
    //!
    //! @param rhs .
    //! @return
    Surface(const double &value);

public:

    //! @brief Creates a surface of a meaningless size.
    //!
    //! Use this constructor to reserve space, which is later assigned.
    Surface() = default;

    //! @brief Copies the fields from the right hand side into this,
    //! and returns a reference to this.
    //!
    //! @param rhs Object from which to copy the values.
    //! @return Reference to the left hand side of the operator.
    Surface &operator=(const Surface &rhs);

    //! @brief Assigns the result of the addition of this and the other value,
    //! and returns a reference to the result.
    //!
    //! @param rhs Other surface to use in the addition.
    //! @return Reference to this, albeit incremented(?).
    Surface &operator+=(const Surface &rhs);

    //! @brief Gets the total surface defined by both surfaces.
    //!
    //! @param rhs Other surface to use in the addition.
    //! @return Total surface of both surfaces combined.
    Surface operator+(const Surface &rhs) const;

    //! @brief Assigns the result of the subtraction of this and the other value,
    //! and returns a reference to the result.
    //!
    //! @param rhs Other surface to use in the subtraction.
    //! @return Reference to this, albeit decremented(?).
    Surface &operator-=(const Surface &rhs);

    //! @brief Gets the surface which remains after subtracting the other surface from it.
    //!
    //! @param rhs Other surface to use in the subtraction.
    //! @return Remaining surface after the subtraction.
    Surface operator-(const Surface &rhs) const;

    //! @brief Multiplies this surface by the given amount,
    //! and returns a reference to its result.
    //!
    //! @param rhs Number of times to make this surface bigger (or smaller).
    //! @return Reference to this surface which should now be multiplied.
    Surface &operator*=(const double &rhs);

    //! @brief Creates a surface that is the specified amount of times bigger than this,
    //! and returns it.
    //!
    //! @param rhs Amount of times the surface should be bigger.
    //! @return The newly created surface.
    Surface operator*(const double &rhs) const;

    //! @brief Divides the current surface by the specified amount,
    //! and returns the result.
    //!
    //! @param rhs Amount to divide the surface by.
    //! @return Reference to this surface, albeit divided.
    Surface &operator/=(const double &rhs);

    //! @brief Gets a surface which is equal to this surface divided by the specified value.
    //!
    //! @param rhs Amount to divide the surface by.
    //! @return Surface divided by the given value.
    Surface operator/(const double &rhs) const;

    //! @brief Gets the amount of times this surface is bigger than
    //! the other surface.
    //!
    //! @param rhs Amount to divide the surface by.
    //! @return Amount of times this surface is bigger than the other surface.
    double operator/(const Surface &rhs) const;

    //! @brief Gets the (would be) length of the other edge of a rectangle w×h.
    //!
    //! @param rhs Length of one edge of the rectangle.
    //! @return The length of the other edge.
    Length operator/(const Length &rhs) const;

    //! @brief Defines a short hand for creating a square meter.
    static const Surface square_meter;

    //! @brief Creates a surface that is the specified amount of times bigger than this,
    //! and returns it.
    //!
    //! @param rhs Surface which should be an amount of times bigger.
    //! @return The newly created surface.
    friend Surface operator*(const double &lhs, const Surface &rhs);

    //! @brief Writes the specified surface to the std::ostream, returning that stream.
    //!
    //! The output is given in the format xm^2, where x is the value of square meters.
    //! @param lhs Stream to which to write the string representation of the coordinate.
    //! @param rhs Reference to the object to write to the outputstream.
    //! @return Reference to the stream passed in by lhs.
    //! @see operator>>(std::istream, Surface &)
    //! @see operator<<(std::ostream, const Surface &)
    friend std::ostream &operator<<(std::ostream &lhs, const Surface &rhs);

    //! @brief Reads a surface from the given input stream, returning said stream.
    //!
    //! The input should be given in the format "xm^2",
    //! where the x is the amount of square length.
    //! All of the suffixes supported by Length are also supported by this class.
    //!
    //! @param lhs Stream from which to read data
    //! @param rhs Reference to an uninitialized coordinate to overwrite.
    //! @return Reference to the stream passed in by lhs.
    //! @throw std::runtime_error Indicates a Coordinate could not be read from
    //! the given input stream due to it being in an incorrect format.
    //! The values in the supplied coordinate are not modified when an exception is thrown.
    //! @see operator<<(std::ostream &, Surface &)
    //! @see operator>>(std::istream &, Surface &)
    friend std::istream &operator>>(std::istream &lhs, Surface &rhs);

    // Allows for the use of the private constructor.
    friend Surface operator*(const Length &lhs, const Length &rhs);
};

//! @brief Gets a the surface defined by a rectangle defined the multiplied values.
//!
//! @param lhs Width of the rectangle.
//! @param rhs Height of the rectangle.
//! @return
Surface operator*(const Length &lhs, const Length &rhs);

#endif //ADT_SURFACE_HPP