#include "../include/Box.hpp"

Box::Box(Coordinate lhs, Coordinate rhs)
{
	if(lhs.x < rhs.x){
		bottomLeft.x = lhs.x;
		topRight.x = rhs.x;
	}
	else{
		bottomLeft.x = rhs.x;
		topRight.x = lhs.x;
	}
	if(lhs.y < rhs.y){
		bottomLeft.y = lhs.y;
		topRight.y = rhs.y;
	}
	else{
		bottomLeft.y = rhs.y;
		topRight.y = lhs.y;
	}
	if(lhs.z < rhs.z){
		bottomLeft.z = lhs.z;
		topRight.z = rhs.z;
	}
	else{
		bottomLeft.z = rhs.z;
		topRight.z = lhs.z;
	}
}

Box::Box(Coordinate origin, Distance dist):
	Box(origin, origin + dist)
{
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

	if (coord.x < bottomLeft.x &&
		coord.y < bottomLeft.y &&
		coord.z < bottomLeft.z
		)
	{
		if(coord.x > topRight.x &&
			coord.y > topRight.y &&
			coord.z > topRight.z)
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

Coordinate Box::get_bottom_left()
{
	return bottomLeft;
}

Coordinate Box::get_top_right()
{
	return topRight;
}

Box Box::get_union_box(Box box)
{
	Coordinate newBottomLeft;
	Coordinate newTopRight;

	(bottomLeft.x < box.bottomLeft.x) ?
		newBottomLeft.x = bottomLeft.x : newBottomLeft.x = box.bottomLeft.x;
	
	
	(bottomLeft.y < box.bottomLeft.y) ?
		newBottomLeft.y = bottomLeft.y : newBottomLeft.y = box.bottomLeft.y;

	(bottomLeft.z < box.bottomLeft.z) ? 
		newBottomLeft.z = bottomLeft.z : newBottomLeft.z = box.bottomLeft.z;
	
	(topRight.x > box.topRight.x) ?
		newTopRight.x = topRight.x : newTopRight.x = box.topRight.x;

	(topRight.y > box.topRight.y) ?
		newTopRight.y = topRight.y : newTopRight.y = box.topRight.y;

	(topRight.z > box.topRight.z) ?
		newTopRight.z = topRight.z : newTopRight.z = box.topRight.z;

	return Box(newBottomLeft, newTopRight);
}

Box Box::get_intersection_box(Box box)
{
	if(this->intersects(box))
	{
		// return intersection box
		if(this->contains(box.bottomLeft))
		{
			// intersectionBox bottomLeft
			return Box(box.get_bottom_left(), topRight);
		}
		else
		{
			return Box(bottomLeft, box.get_top_right());
		}
	}
	else
	{
		// no intersection box
		return Box(Coordinate(), Coordinate());
	}
		
}

Distance Box::get_axis_size()
{
	Distance dist;

	dist.set_x(topRight.x - bottomLeft.x);
	dist.set_y(topRight.y - bottomLeft.y);
	dist.set_z(topRight.z - bottomLeft.z);

	return dist;
}

Box & Box::operator=(const Box & rhs)
{	
	bottomLeft = rhs.bottomLeft;
	topRight = rhs.topRight;

	return *this;
}

std::ostream & operator <<(std::ostream & lhs, const Box & rhs) {
	lhs << "box (" << rhs.bottomLeft << " " << rhs.topRight << ")";
}
