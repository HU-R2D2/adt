// ++--++
// @file <filename>
// @date Created: <5-3-16>
// @version <0.0.0>
//
// @author <full name>
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
#include "../include/Translation.hpp"

Translation::Translation(Length x, Length y, Length z) :
	x(x),
	y(y),
	z(z)
{}

Length Translation::get_x() {
	return x;
}

Length Translation::get_y() {
	return y;
}

Length Translation::get_z() {
	return z;
}

Length Translation::get_length() const {
	Length a;
	double tempx = x / Length::METER;
	double tempy = y / Length::METER;
	double tempz = z / Length::METER;
	a = sqrt((tempx * tempx) + (tempy * tempy) + (tempz * tempz)) * Length::METER;
	return a;
}

void Translation::set_x(Length x) {
	x = x;
}

void Translation::set_y(Length y) {
	y = y;
}

void Translation::set_z(Length z) {
	z = z;
}

Translation& Translation::operator= (const Translation& rhs){
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

Translation Translation::operator+ (const Translation& rhs) const {
	Translation temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	return temp;
}

Translation Translation::operator- (const Translation& rhs) const{
	Translation temp(*this);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	return temp;
}

Translation Translation::operator* (double number) const{
	Translation temp(*this);
	temp.x = temp.x * number;
	temp.y = temp.y * number;
	temp.z = temp.z * number;
	return temp;
}

Translation operator* (double number, const Translation& rhs) {
	Translation temp(rhs);
	temp.x = number * temp.x;
	temp.y = number * temp.y;
	temp.z = number * temp.z;
	return temp;
}
		
Translation Translation::operator/ (double number) const{
	Translation temp(*this);
	if(number == 0){
		return temp;
	}
	temp.x = temp.x / number;
	temp.y = temp.y / number;
	temp.z = temp.z / number;
	return temp;
}

Translation operator/ (double number, const Translation& rhs) {
	Translation temp(rhs);
	double tx = temp.x / Length::METER;
	double ty = temp.y / Length::METER;
	double tz = temp.z / Length::METER;
	if((tx != 0) && (ty != 0) && (tz != 0)){
		temp.x = number * Length::METER / tx;
		temp.y = number * Length::METER / ty;
		temp.z = number * Length::METER / tz;
	}
	return temp;
}
	
Translation& Translation::operator+= (const Translation& rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}
	
Translation& Translation::operator-= (const Translation& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
		
bool Translation::operator> (const Translation& rhs) const {
	return get_length() > rhs.get_length();
}
		
bool Translation::operator< (const Translation& rhs) const {
	return get_length() < rhs.get_length();
}
		
std::ostream& operator<< (std::ostream& lhs, Translation& rhs) {
	lhs << "(" << rhs.get_x() << ", " << rhs.get_y() << ", " << rhs.get_z() << ")";
	return lhs;
}
		
Translation& operator>>(std::istream& input, Translation& rhs) {
	std::string prefix;
	input >> std::ws >> prefix;
	Length x,y,z;
	char temp;
	
	if(prefix == "Translation") {
		input >> temp;
		if (temp!='(') {
			std::cerr << "No opening brace encountered";
		}
		input >> x >> temp >> y >> temp >> z >> temp;
		rhs.set_x(x);
		rhs.set_y(y);
		rhs.set_z(z);
	}
	else {
		std::cerr << "No Translation!";
	}
	return rhs;
}