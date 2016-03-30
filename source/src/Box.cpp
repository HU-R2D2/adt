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

Coordinate Box::getBottomLeft()
{
	return bottomLeft;
}

Coordinate Box::getTopRight()
{
	return topRight;
}

Box Box::getUnionBox(Box box)
{
	Coordinate newBottomLeft;
	Coordinate newTopRight;

	if(bottomLeft.x < box.bottomLeft.x) 
		newBottomLeft.x = bottomLeft.x : newBottomLeft.x = box.bottomLeft.x;
	
	
	if(bottomLeft.y < box.bottomLeft.y) 
		newBottomLeft.y = bottomLeft.y : newBottomLeft.y = box.bottomLeft.y;

	if(bottomLeft.z < box.bottomLeft.z) 
		newBottomLeft.z = bottomLeft.z : newBottomLeft.z = box.bottomLeft.z;
	
	if(topRight.x > box.topRight.x) 
		newtopRight.x = topRight.x : newtopRight.x = box.topRight.x;

	if(topRight.y > box.topRight.y) 
		newtopRight.y = topRight.y : newtopRight.y = box.topRight.y;

	if(topRight.z > box.topRight.z) 
		newtopRight.z = topRight.z : newtopRight.z = box.topRight.z;

	return Box(newBottomLeft, newTopRight);
}

Box Box::getIntersectionBox(Box box)
{
	if(this->intersects(box))
	{
		// return intersection box
		if(this->contains(box.bottomLeft))
		{
			// intersectionBox bottomLeft
			return Box(box.getBottomLeft(), topRight);
		}
	}
	else
	{
		// no intersection box
		///return false;
		return Box(Coordinate(0.0,0.0,0.0),Coordinate(0.0,0.0,0.0));
	}
		
}

Distance Box::getAxisSize()
{
	// get axis size (calculate the distance of one edge)
	Distance dist;

	dist.setX(topRight.x - bottomLeft.x);
	dist.setY(topRight.y - bottomLeft.y);
	dist.setZ(topRight.z - bottomLeft.z);

	return dist;
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
