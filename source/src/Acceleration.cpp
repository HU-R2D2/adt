// ++--++
// Roborescue
// @file <Acceleration.cpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
// @author <Stephan Vivie>
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
#include "../include/Acceleration.hpp"

#include <iostream>

Acceleration::Acceleration():ADT_Base<Acceleration>(0.0){}

Acceleration::Acceleration(double value):ADT_Base<Acceleration>(value){}

std::ostream & operator <<(std::ostream & lhs, const Acceleration & rhs) {
    lhs << "acceleration( " << rhs.value << " m/sec )";
    return lhs;
}


std::istream & operator >>(std::istream & lhs, Acceleration & rhs) {
// Make sure the data that is being decoded is an acceleration.
    std::string prefix;
    lhs >> std::ws >> prefix;
    if (prefix != "acceleration") {
        throw std::runtime_error{"Expecting prefix \"acceleration\", got something else."};
    }
    char temp;
    lhs >> std::ws >> temp;
    if (temp != '(') {
        throw std::runtime_error{"No opening brace encountered"};
    }

    // To guarantee the box remains unchanged when an error occurs,
    // a temporary storage is needed for the values.
    // If not, throw an exception or something along those lines.
    double acceleration;

    // The different values are separated by certain characters.
    // As they require multiple similar steps, this small lambda is defined.
    auto ReadComponent = [](std::istream & lhs, char expectedSeperator) {
        double value;
        char separator;
        lhs >> value >> separator;
        if(separator != expectedSeperator){
            std::cout << "sep: " << separator << std::endl;
            throw std::runtime_error{"Wrong or missing seperator."};
        }
        return value;
    };

    acceleration = ReadComponent(lhs, 'm');

    if (!lhs) {
        throw std::runtime_error{"Acceleration wasn't read in its entirety when end of stream was reached. "};
    }

    rhs.value = acceleration;

    return lhs;
}

Acceleration operator/ (const Speed & s, const Duration & d) {
    double durationValue = d / Duration::SECOND;
    double speedValue = s / (1 * Length::METER / Duration::SECOND);

    if (durationValue == 0.0 || speedValue == 0.0) {
        return Acceleration{0.0};
    }
    return Acceleration{ speedValue / durationValue };  
}