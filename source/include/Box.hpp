#ifndef _BOX_HPP
#define _BOX_HPP

#include "Coordinate.hpp" // Fake mock-class until naming off Coordinate class is fixed
#include "Distance.hpp"
#include <iostream>
#include "gtest/gtest.h"

/**
	ToDo 
	Review
	
*	@author 		Stephan Vivie
*	@date			15-03-2016
*	@version		0.1
	@brief	A 3D rectangular box in space, which is aligned to the 3 axises.
	
*/

class Box {
	friend class Distance;
public:
	//! @brief Constructs a box with 2 coordinates, bottom left and top right of the 3D ractangle
    //!
    //! @param bottomLeft
    //! @param topRight 
	Box (Coordinate bottomLeft, Coordinate topRight);

	//! @brief Constructs a box with one coordinate and a distance, bottom left coordinate and the distance of the axises.
    //!
    //! @param origin bottom left coordinate of the rectangle
    //! @param dist the size of one edge (axis) 
	Box (Coordinate origin, Distance dist);

	

public:
	//! @brief Checks whether box contains coordinate
    //!
    //! @param coord The coordinate to check
    //! @return boolean State if parameter is inside of this object 
	bool contains (Coordinate coord);

	//! @brief Check whether box contains another box
    //!
    //! @param box 
    //! @return boolean State if parameter is inside of this object	
	bool contains (Box box);

	//! @brief Check whether box intersects with another box, returns boolean
    //!
    //! @param 
    //! @return 	
	bool intersects (Box box);

	//! @brief return bottom left coordinate
    //!
    //! @return bottomLeft coordinate
	Coordinate getBottomLeft();

	//! @brief return the top right coordinate
    //!
    //! @return topright coordinate
	Coordinate getTopRight();

	//! @brief Returns box that contains both boxes
    //!
    //! @param box the box to create an union box with
    //! @return Box the union box
	Box getUnionBox(Box box);

	//! @brief Returns box that contains the shared space (intersection area) between two boxes
    //!
    //! @param 
    //! @return 
	Box getIntersectionBox(Box box);

	//! @brief Returns the size of the axis
    //!
    //! @param 
    //! @return 
	Distance getAxisSize();


	//! @brief assignment operator for a box
    //!
    //! @param box the box to assign
    //! @return the object
	Box operator= ( const Box & );

	//! @brief appends a box to an std::ostream and returns the ostream
    //!
    //! @param os the std::ostream to append to
    //! @param rhs Object to append
    //! @return std::ostream
	friend std::ostream & operator<< (std::ostream & os, const Box & rhs);

private:
	
	Coordinate bottomLeft;
	Coordinate topRight;


};

#endif	// _BOX_HPP

