#include "../include/Distance.hpp"

Distance::Distance(Length x, Length y, Length z) :
	x(x),
	y(y),
	z(z)
{}

Length Distance::getX() {
	return x;
}

Length Distance::getY() {
	return y;
}

Length Distance::getZ() {
	return z;
}

Length Distance::getLength() const {
	Length a;
	a = sqrt((x*x) + (y*y) + (z*z)) * Length::METER;
	return a;
}

void Distance::setX(Length x) {
	x = x;
}

void Distance::setY(Length y) {
	y = y;
}

void Distance::setZ(Length z) {
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
	return getLength() > rhs.getLength();
}
		
bool Distance::operator< (const Distance& rhs) const {
	return getLength() < rhs.getLength();
}
		
std::ostream& operator<< (std::ostream& lhs, Distance& rhs) {
	lhs << "(" << rhs.getX() << "," << rhs.getY() << "," << rhs.getZ() << ")";
	return lhs;
}
		
Distance& operator>>(std::istream& input, Distance& rhs) {		// WAT WIL JE HIER TERUGKRIJGEN?? een Distance lijkt me?
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
		rhs.setX(x);
		rhs.setY(y);
		rhs.setZ(z);
	}
	else {
		std::cerr << "No distance!";
	}
	return rhs;
}