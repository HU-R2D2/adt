/**
  *@author		Remco Nijkamp & Koen de Groot
  *@date 		15-03-16
  *@version 	0.1
  *@brief		Length is a .....
*/

#include <iostream> 
#include "Duration.hpp"
#include "gtest/gtest.h"

#ifndef  _LENGTH_HPP
#define _LENGTH_HPP
class Speed;
class Distance;

class Length{
	friend class Distance;	
	private:
		/**********************************************************************************************//**
		 * @fn		Length::Length(double l)
		 *
		 * @brief	Constructor of a Length
		 *
		 * @param	l			The coordinate of the distance
		 **************************************************************************************************/
		Length(double l);
	public:	
		Length(){l = 0;}
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	assignment operator of a Length
		 *
		 * @param	rhs 		the right hand side Length, this one is being assigned to another Length
		 **************************************************************************************************/
		Length& operator= (const Length& rhs);
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	Add operator of a Length
		 *
		 * @param	number		the number to add to the length
		 **************************************************************************************************/
		Length operator+ (const Length& rhs) const; 
		/**********************************************************************************************//**
		* @fn		Length::Length(const Length& rhs)
		*
		* @brief	substract operator of a Length
		*
		* @param	number 		the number to subtrackt from the length
		**************************************************************************************************/
		Length operator- (const Length& rhs) const;
		
		
		
		//=========================================================================================================================================================
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	multiply operator of a Length
		 *
		 * @param	number 		the number to multyply the length by
		 **************************************************************************************************/
		Length operator* (double number) const;
		/**********************************************************************************************//**
		 * @fn	Length::Length(const Length& rhs)
		 *
		 * @brief	division operator of a Length
		 *
		 * @param	number the number to devide the length by
		 **************************************************************************************************/
		Length operator/ (double number) const;
		//=========================================================================================================================================================
		
		
		double operator/ (const Length & rhs) const;
		// HELP?!?!?!?!
		//=========================================================================================================================================================
		/// multiply a Length by another Length and returns a Length
		friend Length operator* (double n, const Length& rhs);
		/// divides a Length by another Length and returns a Length
		friend Length operator/ (double n, const Length & rhs);


		friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs);
		/// adds a Length to a Length and returns this Length
		//=========================================================================================================================================================
		
		
		
		
		/**********************************************************************************************//**
		 * @fn	Length::Length(const Length& rhs)
		 *
		 * @brief	Add assign operator of a Length
		 *
		 * @param	number the number to add to the length
		 **************************************************************************************************/
		Length& operator+= (const Length& rhs);
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	subtract assign operator of a Length
		 *
		 * @param	number 		the number to subtract from the length
		 **************************************************************************************************/
		Length& operator-= (const Length& rhs);
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	greater then operator of a Length
		 *
		 * @param	rhs 		the right hand side to compare 
		 **************************************************************************************************/
		bool operator> (const Length& rhs) const;
		/**********************************************************************************************//**
		 * @fn		Length::Length(const Length& rhs)
		 *
		 * @brief	smaller then operator of a Length
		 *
		 * @param	rhs 		the right hand side to compare 
		 **************************************************************************************************/
		bool operator< (const Length& rhs) const;

		
		
		//================================================================================================================
		/// appends a Length to an ostream and returns an ostream
		friend std::ostream& operator<< (std:: ostream& os, const Length& rhs);
		/// adds an istream to a Length
		friend std::istream& operator>>(std::istream& is, Length& rhs);
		//================================================================================================================
		//FRIEND_TEST(Constructor, Default);
		
		FRIEND_TEST(Length, doubleConstructor);
		static const Length METER;
		static const Length CENTIMETER;
	private:
		double l;
};

#endif
