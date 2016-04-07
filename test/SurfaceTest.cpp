#define DONT_COMPILE
#ifdef DONT_COMPILE
//! @file Surface.cpp
//! @date Created: 14-03-16
//! @version 1.0.0
//!
//! @author Matthijs Mud
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright � 2016, HU University of Applied Sciences Utrecht.
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

#include "../source/include/Surface.hpp"
#include "gtest/gtest.h"
#include <sstream>

TEST(Surface, Constructor) {
    Surface s{};
}

TEST(Surface, Plus) {
    const Surface square_meter = Length::METER * Length::METER;
    Surface surf1 = 32 * square_meter;
    Surface surf2 = 5 * square_meter;
    Surface surf3 = surf1 + surf2;

    EXPECT_DOUBLE_EQ(32, surf1 /
                         square_meter) << "Modified rhs, which is not allowed.";
    EXPECT_DOUBLE_EQ(5, surf2 /
                        square_meter) << "Modified lhs, which is not allowed.";
    EXPECT_DOUBLE_EQ(37, surf3 /
                         square_meter) << "Subtraction does not give the correct value.";

    const Surface *const p = &surf3;
    EXPECT_EQ(p,
              &(surf3 += surf2)) << "Pointer to a different object was returned.";
    EXPECT_DOUBLE_EQ(5, surf2 /
                        square_meter) << "Modified rhs, which is not allowed";
    EXPECT_DOUBLE_EQ(42,
                     surf3 / square_meter) << "Resulting value is incorrect";

}

TEST(Surface, Subtract) {
    const Surface square_meter = Length::METER * Length::METER;
    Surface surf1 = 32 * square_meter;
    Surface surf2 = 5 * square_meter;
    Surface surf3 = surf1 - surf2;

    EXPECT_DOUBLE_EQ(32, surf1 /
                         square_meter) << "Modified rhs, which is not allowed.";
    EXPECT_DOUBLE_EQ(5, surf2 /
                        square_meter) << "Modified lhs, which is not allowed.";
    EXPECT_DOUBLE_EQ(27, surf3 /
                         square_meter) << "Subtraction does not give the correct value.";

    const Surface *const p = &surf3;
    EXPECT_EQ(p,
              &(surf3 -= surf2)) << "Pointer to a different object was returned.";
    EXPECT_DOUBLE_EQ(5, surf2 /
                        square_meter) << "Modified rhs, which is not allowed";
    EXPECT_DOUBLE_EQ(22,
                     surf3 / square_meter) << "Resulting value is incorrect";
}

TEST(Surface, lengthMultiplication) {
    const Surface square_meter = Length::METER * Length::METER;
    Length l1_1 = 4 * Length::METER;
    Length l1_2 = 5 * Length::METER;
    Surface surf1 = l1_1 * l1_2;
    EXPECT_DOUBLE_EQ(20, surf1 / square_meter);

    Length l2_1 = -4 * Length::METER;
    Length l2_2 = -5 * Length::METER;
    Surface surf2 = l2_1 * l2_2;
    EXPECT_DOUBLE_EQ(20, surf2 / square_meter);

    Length l3_1 = -4 * Length::METER;
    Length l3_2 = 5 * Length::METER;
    Surface surf3 = l3_1 * l3_2;
    EXPECT_DOUBLE_EQ(-20, surf3 / square_meter);

    Length l4_1 = 4 * Length::METER;
    Length l4_2 = -5 * Length::METER;
    Surface surf4 = l4_1 * l4_2;
    EXPECT_DOUBLE_EQ(-20, surf4 / square_meter);
}

TEST(Surface, writeTo) {
    Surface surf = 4 * Length::METER * Length::METER;
    std::stringstream stream{};
    stream << surf;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("4m^2", output) << "";
}

TEST(Surface, readFrom) {
    const Surface square_meter = Length::METER * Length::METER;
    std::stringstream stream{};
    Surface surf;

    // Check whether the coordinate is read in correct form from the stream.
    stream << "15m^2";
    try { stream >> surf; } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    ASSERT_DOUBLE_EQ(15, surf / square_meter);

    // A list of strings which should NOT be parsed.
    // In comments is listed what is wrong with the string.
    auto failures = {
            "2m",    // Space between "coordinate" and opening brace is missing.
            "2m^",
            "2m^3",
            "2m%2",
            "2m²"
    };
    for (auto failure : failures) {
        try {
            std::stringstream stream{failure};
            stream >> surf;
            FAIL() << "Parsing \"" << failure <<
                   "\" to a surface should not be possible." << std::endl;
        } catch (SurfaceException &e) {
            // Behaves as expected.
            ASSERT_DOUBLE_EQ(15, surf /
                                 square_meter) << "Value was modified despite the promise";
        } catch (...) {
            FAIL() << "Wrong exception; was expecting [std::runtime_error]";
        }
    }

}

#endif //DONT_COMPILE