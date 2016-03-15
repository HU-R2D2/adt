
#include "Length.hpp"

/**********************************************************************************************//**
 * @fn	Length::Length(double l)
 *
 * @brief	Constructor of a Length
 *
 * @param	l			The X coordinate of the distance
 **************************************************************************************************/
Length(double l=0);


Length& operator= (const Length& rhs);
Length operator+ (const Length& rhs) const;
Length operator- (const Length& rhs) const;
Length operator* (double number) const;
Length operator/ (double number) const;
Length& operator+= (const Length& rhs);
Length& operator-= (const Length& rhs);
bool operator> (const Length& rhs) const;
bool operator< (const Length& rhs) const;
ostream& operator<< (ostream& os, const Length& rhs) const;
istream& operator>>( istream& is, Length& rhs)


///=================================================================

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
		
Distance Distance::operator/ (double rhs) const;		// bij delen door nul: gewoon niks doen!
		
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
		
bool Distance::operator> (const Distance& rhs) const;
		
bool Distance::operator< (const Distance& rhs) const;
		
ostream& Distance::operator<< (ostream& os, const Distance& rhs) const;
		
istream& Distance::operator>>( istream& is, Distance& rhs)

		