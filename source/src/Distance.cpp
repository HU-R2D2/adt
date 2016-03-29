#include "../include/Distance.hpp"

/**********************************************************************************************//**
 * @fn		Distance::Distance(double x, double y, double z)
 *
 * @brief	Constructor of a Distance
 *
 * @param	x			The X coordinate of the distance
 * @param	y			The Y coordinate of the distance
 * @param	z			The Z coordinate of the distance
 **************************************************************************************************/

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
void Distance::setX(double x) {
	x = x;
}
void Distance::setY(double y) {
	y = y;
}
void Distance::setZ(double z) {
	z = z;
}


/**********************************************************************************************//**
 * @fn		Distance& Distance::operator= (const Distance& rhs)
 *
 * @brief	Assignment operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one is being assigned to another Distance
 * @return	Distance&	Reference to the Distance on which the assignment operator was called
 **************************************************************************************************/
Distance& Distance::operator= (const Distance& rhs){
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

/**********************************************************************************************//**
 * @fn		Distance Distance::operator+ (const Distance& rhs) const
 *
 * @brief	Add operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one is being added to another Distance
 * @return	Distance	The Distance on which the add operator was called
 **************************************************************************************************/
Distance Distance::operator+ (const Distance& rhs) const {
	Distance temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;
	return temp;
}

/**********************************************************************************************//**
 * @fn		Distance Distance::operator- (const Distance& rhs) const
 *
 * @brief	Substract operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one is being substracted from another Distance
 * @return	Distance	The Distance on which the substract operator was called
 **************************************************************************************************/
Distance Distance::operator- (const Distance& rhs) const{
	Distance temp(*this);
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	temp.z -= rhs.z;
	return temp;
}

/**********************************************************************************************//**
 * @fn		Distance Distance::operator* (double number) const
 *
 * @brief	Multiply operator of a Distance
 *
 * @param	number		The number by which the Distance is being multiplied
 * @return	Distance	The Distance on which the multiply operator was called
 **************************************************************************************************/
Distance Distance::operator* (double number) const{
	Distance temp(*this);
	temp.x = temp.x * number;
	temp.y = temp.y * number;
	temp.z = temp.z * number;
	return temp;
}

/**********************************************************************************************//**
 * @fn		Distance Distance::operator/ (double number) const
 *
 * @brief	Division operator of a Distance
 *
 * @param	number		The number by which the Distance is being divided
 * @return	Distance	The Distance on which the division operator was called
 **************************************************************************************************/		
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
	
/**********************************************************************************************//**
 * @fn		Distance& Distance::operator+= (const Distance& rhs)
 *
 * @brief	AddAssign operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one is being added to another Distance
 * @return	Distance&	Reference to the Distance on which the addAssignment operator was called
 **************************************************************************************************/	
Distance& Distance::operator+= (const Distance& rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

/**********************************************************************************************//**
 * @fn		Distance& Distance::operator-= (const Distance& rhs)
 *
 * @brief	SubstractAssign operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one is being substracted from another Distance
 * @return	Distance&	Reference to the Distance on which the substractAssignment operator was called
 **************************************************************************************************/		
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
//=============================================================================================

/**********************************************************************************************//**
 * @fn		std::ostream& Distance::operator<< (std::ostream& lhs, const Distance& rhs) const
 *
 * @brief	Output operator of a Distance
 *
 * @param	lhs			The left hand sight ostream, to this ostream the Distance will be added
 * @param	rhs			The right hand sight Distance, this one will be added to the lhs ostream
 * @return	ostream&	Reference to the tweaked lhs ostream
 **************************************************************************************************/		
std::ostream& operator<< (std::ostream& lhs, Distance& rhs) {
	lhs << "(" << rhs.getX() << "," << rhs.getY() << "," << rhs.getZ() << ")";
	return lhs;
}
		
/**********************************************************************************************//**
 * @fn		Distance& Distance::operator>>(std::istream& lhs, Distance& rhs)
 *
 * @brief	Input operator of a Distance
 *
 * @param	input			The istream, from this istream the Distance will be adapted
 * @param	rhs			The right hand sight Distance, this one will be adapted by the lhs istream
 * @return	Distance&	Reference to rhs Distance which is adapted by information from the lhs
 **************************************************************************************************/
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