#include "../include/Box.hpp"


Box::Box(Coordinate bottomLeft, Coordinate topRight)
:
	bottomLeft(bottomLeft),
	topRight(topRight)
{

}

Box::Box(Coordinate origin, Distance dist)
:
	bottomLeft(origin),
	topRight(origin) // construct with origin element so it gets assigned.
{
	// calculate topRight coordinate with distance attribute
	topRight = Coordinate(topRight.x + dist.getX(),topRight.y + dist.getY(),topRight.z + dist.getZ());
	
}

bool Box::contains(Coordinate coord)
{
	// Check if coordinate  is within bottomLeft attribute and topRight attribute
	if (coord.x > bottomLeft.x &&
		coord.y > bottomLeft.y &&
		coord.z > bottomLeft.z)
	{
		if (coord.x < topRight.x &&
		coord.y < topRight.y &&
		coord.z < topRight.z)
		{
			return true;
		}
	}
			
	return false;
}

bool Box::contains(Box box)
{
	// Check if both coordinates of the box attribute are within current box bottomLeft and topRight
	if (this->contains(box.bottomLeft) && this->contains(box.topRight))
	{
		return true;
	} 
	return false;
}

bool Box::intersects(Box box)
{
	// Check if there is an intersection between two boxes
	if(this->contains(box.bottomLeft) || this->contains(box.topRight))
	{
		return true;
	}
	return false;
}

void Box::setBottomLeft(Coordinate coord)
{
	bottomLeft = coord;
}

Coordinate Box::getBottomLeft()
{
	return bottomLeft;
}

void Box::setTopRight(Coordinate coord)
{
	// box can only be rectangular
	topRight = coord;
}

Coordinate Box::getTopRight()
{
	return topRight;
}

Box Box::getUnionBox(Box box)
{
	//
	return Box(Coordinate(0.0,0.0,0.0),Coordinate(0.0,0.0,0.0));
}

Box Box::getIntersectionBox(Box box)
{
	//
	//return Box();
	return Box(Coordinate(0.0,0.0,0.0),Coordinate(0.0,0.0,0.0));
}

void Box::setAxisSize(Distance dist)
{
	// calculate top right coordinate based on bottomLeft + distance (same as constructor)
}

Distance Box::getAxisSize()
{
	// get axis size (calculate the distance of one edge)

	return Distance();
}

void Box::operator=(const Box & rhs)
{
	// Question: copy attributes of rhs to current instance or return new box with rhs properties??
	
	bottomLeft = rhs.bottomLeft;
	topRight = rhs.topRight;
}

std::ostream & operator <<(std::ostream & lhs, const Box & rhs) {
	lhs << "box (" << rhs.bottomLeft << " " << rhs.topRight << ")";
}
