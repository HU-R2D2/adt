#include "../include/Distance.hpp"

Distance::Distance(Length x, Length y, Length z) :
	x(x),
	y(y),
	z(z)
{}

Length Distance::get_x() {
	return x;
}

Length Distance::get_y() {
	return y;
}

Length Distance::get_z() {
	return z;
}

Length Distance::get_length() const {
	Length a;
	double tempx = x / Length::METER;
	double tempy = y / Length::METER;
	double tempz = z / Length::METER;
	a = sqrt((tempx * tempx) + (tempy * tempy) + (tempz * tempz)) * Length::METER;
	return a;
}

void Distance::set_x(Length x) {
	x = x;
}

void Distance::set_y(Length y) {
	y = y;
}

void Distance::set_z(Length z) {
	z = z;
}

Distance& Distance::operator= (const Distance& rhs){
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

Distance Distance::operator+ (const Distance& rhs) const {
	Distance temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	return temp;
}

Distance Distance::operator- (const Distance& rhs) const{
	Distance temp(*this);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	return temp;
}

Distance Distance::operator* (double number) const{
	Distance temp(*this);
	temp.x = temp.x * number;
	temp.y = temp.y * number;
	temp.z = temp.z * number;
	return temp;
}

Distance operator* (double number, const Distance& rhs) {
	Distance temp(rhs);
	temp.x = number * temp.x;
	temp.y = number * temp.y;
	temp.z = number * temp.z;
	return temp;
}
		
Distance Distance::operator/ (double number) const{
	Distance temp(*this);
	if(number == 0){
		return temp;
	}
	temp.x = temp.x / number;
	temp.y = temp.y / number;
	temp.z = temp.z / number;
	return temp;
}

Distance operator/ (double number, const Distance& rhs) {
	Distance temp(rhs);
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
	
Distance& Distance::operator+= (const Distance& rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}
	
Distance& Distance::operator-= (const Distance& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
		
bool Distance::operator> (const Distance& rhs) const {
	return get_length() > rhs.get_length();
}
		
bool Distance::operator< (const Distance& rhs) const {
	return get_length() < rhs.get_length();
}
		
std::ostream& operator<< (std::ostream& lhs, Distance& rhs) {
	lhs << "(" << rhs.get_x() << ", " << rhs.get_y() << ", " << rhs.get_z() << ")";
	return lhs;
}
		
Distance& operator>>(std::istream& input, Distance& rhs) {
	std::string prefix;
	input >> std::ws >> prefix;
	Length x,y,z;
	char temp;
	
	if(prefix == "Distance") {
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
		std::cerr << "No distance!";
	}
	return rhs;
}