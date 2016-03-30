#include "Length.hpp"

/**********************************************************************************************//**
 * @fn	Length::Length(double l)
 *
 * @brief	Constructor of a Length
 *
 * @param	l	The coordinate of the distance
 **************************************************************************************************/
 
Length::Length(double l = 0):
	l = l;
{}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	assain operator of a Length
 *
 * @param	rhs the right hand side that is being assaind to the length
 **************************************************************************************************/

Length& Length::operator= (const Length& rhs){
	l = rhs.l;
	return *this;
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	Add operator of a Length
 *
 * @param	number the number to add to the length
 **************************************************************************************************/

Length Length::operator+ (double number) const{
  Length temp {*this};
  temp.l = temp.l + number;
  return temp
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	subtrackt operator of a Length
 *
 * @param	number the number to subtrackt from the length
 **************************************************************************************************/

Length Length::operator- (double number) const{
  Length temp {*this};
  temp.l = temp.l - number;
  return temp;	
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	multyply operator of a Length
 *
 * @param	number the number to multyply the length by
 **************************************************************************************************/

Length Length::operator* (double number) const{
  Length temp {*this};
  temp.l = number * temp.l;
  return temp;	
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	devision operator of a Length
 *
 * @param	number the number to devide the length by
 **************************************************************************************************/


Length Length::operator/ (double number) const{
	Length temp {*this};
  temp.l = temp.l / number;
  return temp; 
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	Add operator of a Length
 *
 * @param	number the number to add to the length
 **************************************************************************************************/

Length& Length::operator+= (double number){
  Length temp {*this};
  temp.l += number;
  return temp;
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	subtrackt operator of a Length
 *
 * @param	number the number to subtrackt from the length
 **************************************************************************************************/

Length& Length::operator-= (double number){
	Length temp {*this};
  temp.l -= number;
  return temp;
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	greater then operator of a Length
 *
 * @param	rhs the right hand side to compare 
 **************************************************************************************************/

bool Length::operator> (const Length& rhs) const{
	Length temp {*this}
  if(temp.l > rhs.l){
    return true;
   }else{
    return false;
   }
}

/**********************************************************************************************//**
 * @fn	Length::Length(const Length& rhs)
 *
 * @brief	smaller then operator of a Length
 *
 * @param	rhs the right hand side to compare 
 **************************************************************************************************/

bool Length::operator< (const Length& rhs) const{
  Length temp {*this}
  if(temp.l < rhs.l){
    return true;
   }else{
    return false;
   }	
}

ostream& Length::operator<< (ostream& os, const Length& rhs) const{
	   lhs << rhs.l
}

istream& Length::operator>>( istream& is, Length& rhs){  //?
	
}		