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

/**********************************************************************************************//**
 * @fn		double Distance::getX()
 *
 * @brief	Gets the x value of the Distance
 *
 * @return	double		The x coordinate of the distance
 **************************************************************************************************/
double Distance::getX() {
	return x;
}

/**********************************************************************************************//**
 * @fn		double Distance::getY()
 *
 * @brief	Gets the y value of the Distance
 *
 * @return	double		The y coordinate of the distance
 **************************************************************************************************/
double Distance::getY() {
	return y;
}

/**********************************************************************************************//**
 * @fn		double Distance::getZ()
 *
 * @brief	Gets the z value of the Distance
 *
 * @return	double		The z coordinate of the distance
 **************************************************************************************************/
double Distance::getZ() {
	return z;
}

/**********************************************************************************************//**
 * @fn		double Distance::getLength()
 *
 * @brief	Gets the calculated Length of the Distance
 *
 * @return	double		The Length of the distance
 **************************************************************************************************/
double Distance::getLength() const {
	return sqrt((x*x) + (y*y) + (z*z));
}

/**********************************************************************************************//**
 * @fn		void Distance::setX(double x)
 *
 * @brief	Sets the x value of the Distance
 *
 * @param	x			The x coordinate of the distance
 **************************************************************************************************/
void Distance::setX(double x) {
	x = x;
}

/**********************************************************************************************//**
 * @fn		void Distance::setY(double y)
 *
 * @brief	Sets the y value of the Distance
 *
 * @param	y			The y coordinate of the distance
 **************************************************************************************************/
void Distance::setY(double y) {
	y = y;
}

/**********************************************************************************************//**
 * @fn		void Distance::setZ(double z)
 *
 * @brief	Sets the z value of the Distance
 *
 * @param	z			The z coordinate of the distance
 **************************************************************************************************/
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
Distance& Distance::operator-= (const Distance& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

/**********************************************************************************************//**
 * @fn		bool Distance::operator> (const Distance& rhs) const
 *
 * @brief	GreaterThan operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one will be compared to another Distance
 * @return	bool		True if length is greater, False if not
 **************************************************************************************************/		
bool Distance::operator> (const Distance& rhs) const {
	return getLength() > rhs.getLength();
}
	
/**********************************************************************************************//**
 * @fn		bool Distance::operator< (const Distance& rhs) const
 *
 * @brief	LessThan operator of a Distance
 *
 * @param	rhs			The right hand sight Distance, this one will be compared to another Distance
 * @return	bool		True if length is smaller, False if not
 **************************************************************************************************/	
bool Distance::operator< (const Distance& rhs) const {
	return getLength() < rhs.getLength();
}

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