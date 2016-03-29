#include "../source/include/Box.hpp"
#include <iostream>

/**
*	@author 		Stephan Vivie
*	@date			29-03-2016
*/


/**
* CONSTRUCTORS 
*/

TEST (Box, Coordinates) 
{
	// construct Box object with 2 Coordinates
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);

	Box box (bl, tr);

	// get bottomLeft
	ASSERT_DOUBLE_EQ(bl.x, box.bottomLeft.x);
	ASSERT_DOUBLE_EQ(bl.y, box.bottomLeft.y);
	ASSERT_DOUBLE_EQ(bl.z, box.bottomLeft.z);

	// get topRight
	ASSERT_DOUBLE_EQ(tr.x, box.topRight.x);
	ASSERT_DOUBLE_EQ(tr.y, box.topRight.y);
	ASSERT_DOUBLE_EQ(tr.z, box.topRight.z);

}

TEST (Box, CoordinateDistance) 
{
	// construct Box object with Coordinate and Distance
	Distance evenDistance (50.0,50.0,50.0);
	Coordinate origin(0.0 ,0.0 ,0.0);

	
	Box rectangleBox (origin, evenDistance);
	ASSERT_DOUBLE_EQ(rectangleBox.topRight.x, 50);
	ASSERT_DOUBLE_EQ(rectangleBox.topRight.y, 50);
	ASSERT_DOUBLE_EQ(rectangleBox.topRight.z, 50);


	Distance unevenDistance (25.0,0.0,50.0);
	Box noRectangleBox (origin, unevenDistance); //cant happen -> exception or different behavior


}

/**
* OPERATORS 
*/

TEST (Box, Equal) 
{
	Box boxOne (Coordinate(), Coordinate());

	Box boxTwo (Coordinate(), Coordinate());


}

TEST (Box, Ostream) 
{
	// moet nog invulling krijgen (hoe print je een box?)

	// box( coord: x,y,z  coord: x,y,z )
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);

	Box box (bl, tr);

	std::stringstream stream{};
   	stream << box << std::endl;
   	std::string output;
   	std::getline(stream, output);
   	EXPECT_EQ("box (coordinate (0m, 0m, 0m) coordinate (50m, 50m, 50m))", output);

}


/**
* METHODS 
*/

TEST (Box, ContainsCoordinate) 
{
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);

	Box box (bl, tr);

	// test coordinate thats inside box
	Coordinate inside (25.0,25.0,25.0);
	ASSERT_EQ(box.contains(inside), true);

	// test coordinate thats outside box
	Coordinate outside (75.0,75.0,75.0);
	ASSERT_EQ(box.contains(outside), false);
}


TEST (Box, ContainsBox) 
{
	Box box(Coordinate(0,0,0), Coordinate(100,100,100));
	
	// test box thats inside box
	Box insideBigBox(Coordinate(50,50,50), Coordinate(75,75,75));
	ASSERT_EQ(box.contains(insideBigBox),true);

	// test box thats outside box
	Box outsideBigBox(Coordinate(150,150,150), Coordinate(200,200,200));
	ASSERT_EQ(box.contains(outsideBigBox), false);

	// test boxes that collide (shouldn't return true as it isn't fully inside the box)
	Box collidesWithBigBox(Coordinate(50,50,50), Coordinate(200,200,200));
	ASSERT_EQ(box.contains(collidesWithBigBox), false);

	


	
}

TEST (Box, IntersectsBox) 
{
	Box box(Coordinate(0,0,0), Coordinate(100,100,100));

	// test box that is inside
	Box insideBox(Coordinate(25,25,25), Coordinate(75,75,75));
	ASSERT_EQ(box.intersects(insideBox), true);

	// test box that intersects but isn't completely inside
	Box intersectBox(Coordinate(50,50,50), Coordinate(150,150,150));
	ASSERT_EQ(box.intersects(intersectBox), true);

	// test box that doesn't intersect at all
	Box outsideBox(Coordinate(200,200,200), Coordinate(500,500,500));
	ASSERT_EQ(box.intersects(outsideBox), false);
}


TEST (Box, setBottomLeft) 
{
	// test if it sets the bottom left coordinate
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);
	Coordinate newBottomLeft(25,25,25);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.bottomLeft.x, 0);
	ASSERT_DOUBLE_EQ(box.bottomLeft.y, 0);
	ASSERT_DOUBLE_EQ(box.bottomLeft.z, 0);

	box.setBottomLeft(newBottomLeft);

	ASSERT_DOUBLE_EQ(box.bottomLeft.x, 25);
	ASSERT_DOUBLE_EQ(box.bottomLeft.y, 25);
	ASSERT_DOUBLE_EQ(box.bottomLeft.z, 25);

}

TEST (Box, getBottomLeft) 
{
	// test if it returns the right bottom left coordinate
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);
	Coordinate bl2(25,25,25);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().x, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().y, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().z, 0);

	Box box2(bl2, tr);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().x, 25);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().y, 25);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().z, 25);
}



TEST (Box, setTopRight) 
{
	// test if it sets the top right coordinate
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);
	Coordinate newTopRight(25,25,25);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.topRight.x, 50);
	ASSERT_DOUBLE_EQ(box.topRight.y, 50);
	ASSERT_DOUBLE_EQ(box.topRight.z, 50);

	box.setTopRight(newTopRight);

	ASSERT_DOUBLE_EQ(box.topRight.x, 25);
	ASSERT_DOUBLE_EQ(box.topRight.y, 25);
	ASSERT_DOUBLE_EQ(box.topRight.z, 25);
}

TEST (Box, getTopRight) 
{
	// test if it returns the right top right coordinate
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);
	Coordinate tr2(25,25,25);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getTopRight().x, 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().y, 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().z, 50);

	Box box2(bl, tr2);
	ASSERT_DOUBLE_EQ(box2.getTopRight().x, 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().y, 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().z, 25);
}

TEST (Box, getUnionBox) 
{
	// test if method returns right result

}

TEST (Box, getIntersectionBox) 
{
	// test if 2 boxes that are intersecting returns the right box

	// test 2 boxes that aren't intersecting


}

TEST (Box, setAxisSize) 
{
	// test is axis size sets the right length
}

TEST (Box, getAxisSize) 
{
	// test if axis size returns the right length
}
