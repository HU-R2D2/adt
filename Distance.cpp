
#include "Distance.hpp"

/**********************************************************************************************//**
 * @fn	Distance::Distance(double x, double y, double z)
 *
 * @brief	Constructor of a Distance
 *
 * @param	x			The X coordinate of the distance
 * @param	y			The Y coordinate of the distance
 * @param	z			The Z coordinate of the distance
 **************************************************************************************************/

Distance::Distance(double x=0, double y=0, double z=0) :
	x = x,
	y = y,
	z = z
{}


Distance& Distance::operator= (const Distance& rhs){
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}


Distance Distance::operator+ (const Distance& rhs) const{
	Distance temp{*this};
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	return temp;
}

Distance Distance::operator- ( const Distance& rhs ) const{
	Distance temp{*this};
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	return temp;
}

Distance Distance::operator* (double number) const{
	Distance temp{*this};
	temp.x = temp.x * number;
	temp.y = temp.y * number;
	temp.z = temp.z * number;
	return temp;
}
		
Distance Distance::operator/ (double number) const{
	Distance temp{*this};
	if(number == 0){
		return temp
	}
	temp.x = temp.x / number;
	temp.y = temp.y / number;
	temp.z = temp.z / number;
	return temp;
}
		
Distance& Distance::operator+= (const Distance& rhs){
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
		
Distance& Distance::operator-= (const Distance& rhs){
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

//=============================================================================================
		
bool Distance::operator> (const Distance& rhs) const{
	// hier met de echte lengte van dat ding!:
	
	
	
	// direction is:  (uitgaande van 2 coordinaten)
	// wortel van ((x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2 )
	
}
		
bool Distance::operator< (const Distance& rhs) const{
	// hier met de echte lengte!
}
		
std::ostream& Distance::operator<< (std::ostream& lhs, const Distance& rhs) const{
	lhs << "(" << rhs.x << "," << rhs.y << "," << rhs.z << ")";
	return lhs;
}
		
Distance& Distance::operator>>(std::istream& lhs, Distance& rhs){		// WAT WIL JE HIER TERUGKRIJGEN?? een Distance lijkt me?
	std::string prefix;
	lhs >> std::ws >> prefix;
	double x,y,z;
	
	if (prefix == "Distance") {
		char temp
		input >> temp
		if (temp!='(') {
			std::cerr << "No opening brace encountered";
		}
		input >> x >> temp >> y >> temp >> z >> temp;
		rhs.x = x;
		rhs.y = y;
		rhs.z = z;
	}
	else {
		std::cerr << "No distance!"
	}
	return rhs
}