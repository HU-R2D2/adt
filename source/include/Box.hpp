#ifndef _BOX_HPP
#define _BOX_HPP

#include "Coordinate.hpp"
#include "Translation.hpp"

#include <iostream>
	
//!	@author 		Stephan Vivie
//! @date			15-03-2016
//!	@version		0.1
//!	@brief	        A 3D rectangular box in space, which is aligned to the 3 axises.
	

class Box final {
	friend class Translation;

public:
    Box();
	//! @brief Constructs a box with 2 coordinates, bottom left and top right of the 3D ractangle
    //!
    //! @param bottomLeft
    //! @param topRight 
	Box (Coordinate bottomLeft, Coordinate topRight);

	//! @brief Constructs a box with one coordinate and a Translation, bottom left coordinate and the Translation of the axises.
    //!
    //! @param origin bottom left coordinate of the rectangle
    //! @param dist the size of one edge (axis) 
	Box (Coordinate origin, Translation dist);

	

public:
	//! @brief Checks whether box contains coordinate
    //!
    //! @param coord The coordinate to check
    //! @return boolean State if parameter is inside of this object 
	const bool contains (const Coordinate & coord) const;

	//! @brief Check whether box contains another box
    //!
    //! @param box 
    //! @return boolean State if parameter is inside of this object	
	const bool contains (const Box & box) const;

	//! @brief Check whether box intersects with another box, returns boolean
    //!
    //! @param 
    //! @return 	
	const bool intersects (const Box & box) const;

	//! @brief return bottom left coordinate
    //!
    //! @return bottomLeft coordinate
	Coordinate get_bottom_left() const;

	//! @brief return the top right coordinate
    //!
    //! @return topright coordinate
	Coordinate get_top_right() const;

	//! @brief Returns the smallest possible box that contains both boxes
    //!
    //! @param box the box to create an union box with
    //! @return Box the union box
	Box get_union_box(const Box & box) const;

	//! @brief Returns box that contains the shared space (intersection area) between two boxes
    //! @note If there is no intersection between the boxes, a empty box will be returned
    //!
    //! @param box the box to create an shared space with
    //! @return Box The box that contains the shared space. When there is no overlapse in the two boxes a box with (0.0,0.0,0.0) is returned.
	Box get_intersection_box(const Box & box) const;

	//! @brief Returns the size of the axis
    //!
    //! @return Translation of the axis
	Translation get_axis_size() const;


	//! @brief assignment operator for a box
    //!
    //! @param box the box to assign
    //! @return the object
	Box & operator= ( const Box & );

	//! @brief appends a box to an std::ostream and returns the ostream
    //!
    //! @param os the std::ostream to append to
    //! @param rhs Object to append
    //! @return std::ostream
	friend std::ostream & operator<< (std::ostream & os, const Box & rhs);


    //! @brief read a box from std::istream and return the istream
    //!
    //! @param lhs the istream to read from
    //! @param rhs the coordinate to write the values to
    //! @return std::istream the istream
    friend std::istream &operator>>(std::istream &lhs, Box & rhs);

private:
	
	Coordinate bottomLeft;
	Coordinate topRight;

    

};

#endif	// _BOX_HPP

