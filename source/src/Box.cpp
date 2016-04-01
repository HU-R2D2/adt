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

const bool Box::contains(const Coordinate & coord) const
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

const bool Box::contains(const Box & box) const
{
	// Check if both coordinates of the box attribute are within current box bottomLeft and topRight
	if (this->contains(box.bottomLeft) && this->contains(box.topRight))
	{
		return true;
	} 
	return false;
}

const bool Box::intersects(const Box & box) const
{
	// Check if there is an intersection between two boxes
	// Uses AABB collision detection (Angle Aligned Bounding Box)
	if (topRight.x > box.bottomLeft.x && 
    bottomLeft.x < box.topRight.x &&
    topRight.y > box.bottomLeft.y &&
    bottomLeft.y < box.topRight.y &&
    topRight.z > box.bottomLeft.z &&
    bottomLeft.z < box.topRight.z)
	{
		return true;
	}

	return false;
}

Coordinate Box::get_bottom_left() const
{
	return bottomLeft;
}

Coordinate Box::get_top_right() const
{
	return topRight;
}

Box Box::get_union_box(const Box & box) const
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

Box Box::get_intersection_box(const Box & box) const
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

Distance Box::get_axis_size() const
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

std::istream & operator >>(std::istream & lhs, Box & rhs )
{
 	// Make sure the data that is being decoded is a Box.
   std::string prefix;
   lhs >> std::ws >> prefix;
   if (prefix != "boxes") {
      throw std::runtime_error{"Expecting prefix \"box\", got something else."};
   }
   char temp;
   lhs >> std::ws >> temp;
   if (temp != '(') {
      throw std::runtime_error{"No opening brace encountered"};
   }

   // To guarantee the box remains unchanged when an error occurs,
   // a temporary storage is needed for the values.
   // If not, throw an exception or something along those lines.
   Coordinate bottomLeft;
   Coordinate topRight;

   // The different values are separated by certain characters.
   // As they require multiple similar steps, this small lambda is defined.
   auto ReadComponent = [](std::istream & lhs, char expectedSeperator) {
      Coordinate value;
      char separator;
      lhs >> value >> separator;
      if(separator != expectedSeperator){
         throw std::runtime_error{"Wrong or missing seperator."};
      }
      return value;
   };

   bottomLeft = ReadComponent(lhs, ' ');
   topRight = ReadComponent(lhs, ' ');


   if (!lhs) {
      throw std::runtime_error{"Coordinate wasn't read in its entirety when end of stream was reached. "};
   }

   rhs.bottomLeft = bottomLeft;
   rhs.topRight = topRight;

   return lhs;
}
