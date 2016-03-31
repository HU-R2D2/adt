#include "../include/Distance.hpp"

Distance::Distance(double x, double y, double z) :
	x(x),
	y(y),
	z(z)
{}

double Distance::getX() {
	return x;
}

double Distance::getY() {
	return y;
}

double Distance::getZ() {
	return z;
}

double Distance::getLength() const {
	return sqrt((x*x) + (y*y) + (z*z));
}

void Distance::setX(double x) {
	x = x;
}

void Distance::setY(double y) {
	y = y;
}

void Distance::setZ(double z) {
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
	double x,y,z;
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