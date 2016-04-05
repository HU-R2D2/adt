//!
//! @author		Remco Nijkamp
//! @date 		14-03-16
//! @version 	0.1
//! @brief		Translation is a 3-vector with an x, y and z value.
//! 			A Translation can be described as the difference between two Coordinates.

#ifndef  _TRANSLATION_HPP
#define _TRANSLATION_HPP
 
#include "Length.hpp"

#include <iostream>
#include <math.h>

class Coordinate;	// Forward declaration. Used to declare as friend.

class Translation final {
	friend class Coordinate;
	public:
		//! @fn 	Translation::Translation()
		//!
		//! @brief 	Default constructor of a Translation
		Translation(){}

		//! @fn		Translation::Translation(Length x, Length y, Length z)
		//! 
		//! @brief	Constructor of a Translation
		//!  
		//! @param	x			The X coordinate of the Translation
		//! @param	y			The Y coordinate of the Translation
		//! @param	z			The Z coordinate of the Translation
		Translation(Length x, Length y, Length z);
		
	public:
		
		 //! @fn		Length Translation::get_x()
		 //!
		 //! @brief	Gets the x Length value of the Translation and returns it
		 //!
		 //! @return	Length		The x Length of the Translation
		 
		Length get_x();
		
		 //! @fn		Length Translation::get_y()
		 //!
		 //! @brief	Gets the y Length value of the Translation and returns it
		 //!
		 //! @return	Length		The y Length of the Translation
		 
		Length get_y();
		
		 //! @fn		Length Translation::get_z()
		 //!
		 //! @brief	Gets the z Length value of the Translation and returns it
		 //!
		 //! @return	Length		The z Length of the Translation
		 
		Length get_z();
		
		 //! @fn		Length Translation::get_length()
		 //!
		 //! @brief	Gets the calculated Length of the Translation and returns it
		 //!
		 //! @return	Length		The absolute Length of the Translation
		 
		Length get_length() const;
		
		
		 //! @fn		void Translation::set_x(Length x)
		 //!
		 //! @brief	Sets the x Length value of the Translation to the given value
		 //!
		 //! @param	x			The x Length of the Translation
		 
		void set_x(Length x);
		
		 //! @fn		void Translation::set_y(Length y)
		 //!
		 //! @brief	Sets the y Length value of the Translation to the given value
		 //!
		 //! @param	y			The y Length of the Translation
		 
		void set_y(Length y);
		
		 //! @fn		void Translation::set_z(Length z)
		 //!
		 //! @brief	Sets the z Length value of the Translation to the given value
		 //!
		 //! @param	z			The z Length of the Translation
		 
		void set_z(Length z);
	
		
		 //! @fn		Translation& Translation::operator= (const Translation& rhs)
		 //!
		 //! @brief	Assignment operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one is being assigned to another Translation
		 //! @return	Translation&	Reference to the Translation on which the assignment operator was called
		 
		Translation& operator= (const Translation& rhs);
		
		 //! @fn		Translation Translation::operator+ (const Translation& rhs) const
		 //!
		 //! @brief	Add operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one is being added to another Translation
		 //! @return	Translation	The Translation on which the add operator was called
		 
		Translation operator+ (const Translation& rhs) const;
		
		 //! @fn		Translation Translation::operator- (const Translation& rhs) const
		 //!
		 //! @brief	Substract operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one is being substracted from another Translation
		 //! @return	Translation	The Translation on which the substract operator was called
		 
		Translation operator- (const Translation& rhs) const;
		
		 //! @fn		Translation Translation::operator//! (double number) const
		 //!
		 //! @brief	Multiply operator of a Translation
		 //!
		 //! @param	number		The number by which the Translation is being multiplied
		 //! @return	Translation	The Translation on which the multiply operator was called
		 
		Translation operator * (double number) const;
		
		
		
		friend Translation operator* (double number, const Translation& rhs);
		friend Translation operator/ (double number, const Translation& rhs);
		
		
		
		 //! @fn		Translation Translation::operator/ (double number) const
		 //!
		 //! @brief	Division operator of a Translation
		 //!
		 //! @param	number		The number by which the Translation is being divided
		 //! @return	Translation	The Translation on which the division operator was called
		 
		Translation operator/ (double number) const;
		
		 //! @fn		Translation& Translation::operator+= (const Translation& rhs)
		 //!
		 //! @brief	AddAssign operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one is being added to another Translation
		 //! @return	Translation&	Reference to the Translation on which the addAssignment operator was called
		 	
		Translation& operator+= (const Translation& rhs);
		
		 //! @fn		Translation& Translation::operator-= (const Translation& rhs)
		 //!
		 //! @brief	SubstractAssign operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one is being substracted from another Translation
		 //! @return	Translation&	Reference to the Translation on which the substractAssignment operator was called
		 	
		Translation& operator-= (const Translation& rhs);
		
		 //! @fn		bool Translation::operator> (const Translation& rhs) const
		 //!
		 //! @brief	GreaterThan operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one will be compared to another Translation
		 //! @return	bool		True if length is greater, False if not
		 
		bool operator> (const Translation& rhs) const;
		
		 //! @fn		bool Translation::operator< (const Translation& rhs) const
		 //!
		 //! @brief	LessThan operator of a Translation
		 //!
		 //! @param	rhs			The right hand sight Translation, this one will be compared to another Translation
		 //! @return	bool		True if length is smaller, False if not
		 
		bool operator< (const Translation& rhs) const;
		
	private:
		Length x,y,z;
};


 //! @fn		std::ostream& Translation::operator<< (std::ostream& lhs, const Translation& rhs) const
 //!
 //! @brief	Output operator of a Translation
 //!
 //! @param	lhs			The left hand sight ostream, to this ostream the Translation will be added
 //! @param	rhs			The right hand sight Translation, this one will be added to the lhs ostream
 //! @return	ostream&	Reference to the tweaked lhs ostream
 
std::ostream& operator<< (std::ostream& lhs, Translation& rhs);

 //! @fn		Translation& Translation::operator>>(std::istream& lhs, Translation& rhs)
 //!
 //! @brief	Input operator of a Translation
 //!
 //! @param	input		The istream, from this istream the Translation will be adapted
 //! @param	rhs			The right hand sight Translation, this one will be adapted by the lhs istream
 //! @return	Translation&	Reference to rhs Translation which is adapted by information from the lhs
 
Translation& operator>>(std::istream& input, Translation& rhs);

#endif
