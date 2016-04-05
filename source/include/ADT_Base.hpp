//!
//! @author		Job Verhaar
//! @date 		05-04-16
//! @version 	0.1
//! @brief		
//!

#ifndef _ADT_BASE_HPP
#define _ADT_BASE_HPP


class Speed;

template <class T> class ADT_Base
{
protected:
	double value;
	ADT_Base(double value):value{value}{}
public:
	ADT_Base():value{0.0}{}
	T& operator= (const T& rhs){
		value = rhs.value;
		return *static_cast<T*>(this);
	}
	
	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	Add operator of a T
	//!
	//! @param	number the number to add to the T
	T operator+ (const T& rhs) const{
		return T{value + rhs.value};
	} 

	//! @fn	T::T(const T& rhs)
	//!
	//! @brief	Add assign operator of a T
	//!
	//! @param	number the number to add to the T 

	T& operator+= (const T& rhs){
		value += rhs.value;
  		return *static_cast<T*>(this);
	}
	
	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	substract operator of a T
	//!
	//! @param	number the number to subtrackt from the T
	T operator- (const T& rhs) const{
		return T{value - rhs.value};
	}
	
	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	subtract assign operator of a T
	//!
	//! @param	number 		the number to subtract from the T
	T& operator-= ( const T& rhs){
		value -= rhs.value;
  		return *static_cast<T*>(this);
	}

	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	multiply operator of a T
	//!
	//! @param	number the number to multyply the T by
	T operator* (double number) const{
		return T{value * number};
	}

	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	multiply operator of a T
	//!
	//! @param	number the number to multyply the T by
	T operator*= (double number){
		value *= number;
		return *static_cast<T*>(this);
	}
	
	//! @fn 	T::T(const T& rhs)
	//!
	//! @brief	division operator of a T
	//!
	//! @param	number the number to devide the T by
	T operator/ (double number) const{
		if(number != 0){
    		return T{value / number};
  		}
  		return T{value};
	}

	//! @fn 	T::T(const T& rhs)
	//!
	//! @brief	division operator of a T
	//!
	//! @param	number the number to devide the T by
	T operator/= (double number){
		if(number != 0){
    		value /= number;
  		} 
  		return *static_cast<T*>(this);
	}
	
	//! @fn 	T::T(const T& rhs)
	//!
	//! @brief	division operator of a T
	//!
	//! @param	number the number to devide the T by
	double operator/ (const T & rhs) const{
		if(rhs.value != 0){
			return value / rhs.value;
		}
		return value;
	}

	//! Multiplies a speed by a double
    /*!
      \param n a double.
      \param rhs a Speed.
      \return the calculated speed.
    */

	
	
	
	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	greater then operator of a T
	//!
	//! @param	rhs 		the right hand side to compare 
	bool operator> (const T& rhs) const{
		return value > rhs.value;
	}

	//! @fn		T::T(const T& rhs)
	//!
	//! @brief	smaller then operator of a T
	//!
	//! @param	rhs 		the right hand side to compare 
	bool operator< (const T& rhs) const{
		return value < rhs.value;
	}
	
};

#endif