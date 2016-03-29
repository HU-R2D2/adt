#include "../source/include/Box.hpp"


/**
* CONSTRUCTORS 
*/

TEST (BoxConstructor, Coordinates) 
{
	// construct Box object with 2 Coordinates
}

TEST (BoxConstructor, CoordinateDistance) 
{
	// construct Box object with Coordinate and Distance

}

/**
* OPERATORS 
*/

TEST (BoxOperators, Equal) 
{

}

TEST (BoxOperators, Ostream) 
{

}

TEST (BoxOperators, Istream) 
{

}

/**
* METHODS 
*/

TEST (BoxMethods, ContainsCoordinate) 
{
	// test coordinate thats inside box

	// test coordinate thats outside box

}


TEST (BoxMethods, ContainsBox) 
{
	// test box thats inside box

	// test box thats outside box

	// test boxes that collide
	
}

TEST (BoxMethods, IntersectsBox) 
{
	// test box that is intersects

	// test box that doesn't intersects
}


TEST (BoxMethods, setBottomLeft) 
{
	// test if it sets the bottom left coordinate
}

TEST (BoxMethods, getBottomLeft) 
{
	// test if it returns the right bottom left coordinate
}



TEST (BoxMethods, setTopRight) 
{
	// test if it sets the top right coordinate

}

TEST (BoxMethods, getTopRight) 
{
	// test if it returns the right top right coordinate
}

TEST (BoxMethods, getUnionBox) 
{
	// test if method returns right result

}

TEST (BoxMethods, getIntersectionBox) 
{
	// test if 2 boxes that are intersecting returns the right box

	// test 2 boxes that aren't intersecting


}

TEST (BoxMethods, setAxisSize) 
{
	// test is axis size sets the right length
}

TEST (BoxMethods, getAxisSize) 
{
	// test if axis size returns the right length
}
