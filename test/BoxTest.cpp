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
	Coordinate bl = Coordinate::origin;
	Coordinate tr = Coordinate::origin + Distance(50.0*Length::METER, 50.0*Length::METER, 50.0*Length::METER);

	Box box (bl, tr);

	// get bottomLeft
	ASSERT_DOUBLE_EQ(bl.getX()/Length::METER, box.getBottomLeft().getX()/Length::METER);
	ASSERT_DOUBLE_EQ(bl.getY()/Length::METER, box.getBottomLeft().getY()/Length::METER);
	ASSERT_DOUBLE_EQ(bl.getZ()/Length::METER, box.getBottomLeft().getZ()/Length::METER);

	// get topRight
	ASSERT_DOUBLE_EQ(tr.getX()/Length::METER, box.getTopRight().getX()/Length::METER);
	ASSERT_DOUBLE_EQ(tr.getY()/Length::METER, box.getTopRight().getY()/Length::METER);
	ASSERT_DOUBLE_EQ(tr.getZ()/Length::METER, box.getTopRight().getZ()/Length::METER);

}

TEST (Box, CoordinateDistance) 
{
	// construct Box object with Coordinate and Distance
	Distance evenDistance (50.0*Length::METER,50.0*Length::METER,50.0*Length::METER);
	Coordinate origin = Coordinate::origin;

	
	Box rectangleBox (origin, evenDistance);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getX()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getY()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getZ()/Length::METER, 50);


	Distance unevenDistance (25.0*Length::METER,0.0*Length::METER,50.0*Length::METER);
	Box noRectangleBox (origin, unevenDistance); //cant happen -> exception or different behavior


}

/**
* OPERATORS 
*/

TEST (Box, Assign) 
{

	Box boxOne (Coordinate::origin, Coordinate::origin + Distance(25*Length::METER,25*Length::METER,25*Length::METER));
	Box boxTwo (Coordinate::origin + Distance{50*Length::METER,50*Length::METER,50*Length::METER}, Coordinate::origin + Distance{100*Length::METER,100*Length::METER,100*Length::METER});

	// assign boxTwo to boxOne
	boxOne = boxTwo;

	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getX()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getY()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getZ()/Length::METER, 50);

	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getX()/Length::METER, 100);
	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getY()/Length::METER, 100);
	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getZ()/Length::METER, 100);





}


TEST (Box, Ostream) 
{
	Coordinate bl = Coordinate::origin + Distance{};
	Coordinate tr = Coordinate::origin + Distance{50.0*Length::METER, 50.0*Length::METER, 50.0*Length::METER};

	Box box (bl, tr);

	std::stringstream stream{};
   	stream << box << std::endl;
   	std::string output;
   	std::getline(stream, output);
   	EXPECT_EQ("box (coordinate (0, 0, 0) coordinate (50, 50, 50))", output);

}


/**
* METHODS 
*/

TEST (Box, ContainsCoordinate) 
{
	Coordinate bl = Coordinate::origin + Distance{};
	Coordinate tr = Coordinate::origin + Distance{50.0*Length::METER, 50.0*Length::METER, 50.0*Length::METER};

	Box box (bl, tr);

	// test coordinate thats inside box
	Coordinate inside =Coordinate::origin + Distance{25.0*Length::METER,25.0*Length::METER,25.0*Length::METER};
	ASSERT_EQ(box.contains(inside), true);

	// test coordinate thats outside box
	Coordinate outside = Coordinate::origin + Distance{75.0*Length::METER,75.0*Length::METER,75.0*Length::METER};
	ASSERT_EQ(box.contains(outside), false);

	Box negativeBox(Coordinate::origin + Distance{-25*Length::METER,-25*Length::METER,-25*Length::METER},Coordinate::origin + Distance{-75*Length::METER,-75*Length::METER,-75*Length::METER});
	// test coordinate thats inside negative box
	Coordinate insideNegative = Coordinate::origin + Distance{-50*Length::METER,-50*Length::METER,-50*Length::METER};
	ASSERT_EQ(negativeBox.contains(insideNegative),true);

	// test coordinate thats outside negative box
	Coordinate outsideNegative = Coordinate::origin + Distance{-150*Length::METER,-150*Length::METER,-150*Length::METER};
	ASSERT_EQ(negativeBox.contains(outsideNegative),false);
	ASSERT_EQ(negativeBox.contains(outside),false);


}


TEST (Box, ContainsBox) 
{
	Box box(Coordinate::origin + Distance(), Coordinate::origin + Distance(100*Length::METER,100*Length::METER,100*Length::METER));
	
	// test box thats inside box
	Box insideBigBox(Coordinate::origin + Distance(50*Length::METER,50*Length::METER,50*Length::METER), Coordinate::origin + Distance(75*Length::METER,75*Length::METER,75*Length::METER));
	ASSERT_EQ(box.contains(insideBigBox),true);

	// test box thats outside box
	Box outsideBigBox(Coordinate::origin + Distance(150*Length::METER,150*Length::METER,150*Length::METER), Coordinate::origin + Distance(200*Length::METER,200*Length::METER,200*Length::METER));
	ASSERT_EQ(box.contains(outsideBigBox), false);

	// test boxes that collide (shouldn't return true as it isn't fully inside the box)
	Box collidesWithBigBox(Coordinate::origin + Distance(50*Length::METER,50*Length::METER,50*Length::METER), Coordinate::origin + Distance(200*Length::METER,200*Length::METER,200*Length::METER));
	ASSERT_EQ(box.contains(collidesWithBigBox), false);

	
	Box negativeBox(Coordinate::origin + Distance(-50*Length::METER,-50*Length::METER,-50*Length::METER), Coordinate::origin + Distance(-100*Length::METER,-100*Length::METER,-100*Length::METER));
	
	// test negative box that is inside the box 
	Box negativeBoxInside(Coordinate::origin + Distance(-60*Length::METER,-60*Length::METER,-60*Length::METER), Coordinate::origin + Distance(-70*Length::METER,-70*Length::METER,-70*Length::METER));
	ASSERT_EQ(negativeBox.contains(negativeBoxInside), true);

	// test negative box that intersects but isnt fully inside the box
	Box negativeBoxIntersects(Coordinate::origin + Distance(-75*Length::METER,-75*Length::METER,-75*Length::METER), Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER));
	ASSERT_EQ(negativeBox.contains(negativeBoxIntersects), false);

	// test negative box that doesnt intersect at all
	Box negativeBoxOutside(Coordinate::origin + Distance(-175*Length::METER,-175*Length::METER,-175*Length::METER), Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER));
	ASSERT_EQ(negativeBox.contains(negativeBoxOutside), false);

	
}

TEST (Box, IntersectsBox) 
{
	Box box(Coordinate::origin + Distance(), Coordinate::origin + Distance(100*Length::METER,100*Length::METER,100*Length::METER));

	// test box that is inside
	Box insideBox(Coordinate::origin + Distance(25*Length::METER,25*Length::METER,25*Length::METER), Coordinate::origin + Distance(75*Length::METER,75*Length::METER,75*Length::METER));
	ASSERT_EQ(box.intersects(insideBox), true);

	// test box that intersects but isn't completely inside
	Box intersectBox(Coordinate::origin + Distance(50*Length::METER,50*Length::METER,50*Length::METER), Coordinate::origin + Distance(150*Length::METER,150*Length::METER,150*Length::METER));
	ASSERT_EQ(box.intersects(intersectBox), true);

	// test box that doesn't intersect at all
	Box outsideBox(Coordinate::origin + Distance(200*Length::METER,200*Length::METER,200*Length::METER), Coordinate::origin + Distance(500*Length::METER,500*Length::METER,500*Length::METER));
	ASSERT_EQ(box.intersects(outsideBox), false);

	
	Box negativeBox(Coordinate::origin + Distance(-50*Length::METER,-50*Length::METER,-50*Length::METER), Coordinate::origin + Distance(-100*Length::METER,-100*Length::METER,-100*Length::METER));
	
	// test negative box that is inside
	Box negativeBoxInside(Coordinate::origin + Distance(-60*Length::METER,-60*Length::METER,-60*Length::METER), Coordinate::origin + Distance(-70*Length::METER,-70*Length::METER,-70*Length::METER));
	ASSERT_EQ(negativeBox.intersects(negativeBoxInside), true);

	// test negative box that intersects
	Box negativeBoxIntersects(Coordinate::origin + Distance(-75*Length::METER,-75*Length::METER,-75*Length::METER), Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER));
	ASSERT_EQ(negativeBox.intersects(negativeBoxIntersects), true);

	// test negative box that doesn't intersect
	Box negativeBoxOutside(Coordinate::origin + Distance(-175*Length::METER,-175*Length::METER,-175*Length::METER), Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER));
	ASSERT_EQ(negativeBox.intersects(negativeBoxOutside), false);



}


TEST (Box, getBottomLeft) 
{
	// test if it returns the right bottom left coordinate
	Coordinate bl = Coordinate::origin;
	Coordinate tr = Coordinate::origin +Distance(50.0*Length::METER, 50.0*Length::METER, 50.0*Length::METER);
	Coordinate bl2 = Coordinate::origin + Distance(25*Length::METER,26*Length::METER,27*Length::METER);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getZ()/Length::METER, 0);

	Box box2(bl2, tr);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getX()/Length::METER, 25);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getY()/Length::METER, 26);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getZ()/Length::METER, 27);

	Box negative(Coordinate::origin + Distance(-10*Length::METER,-10*Length::METER,-10*Length::METER), Coordinate::origin + Distance(-50*Length::METER,-50*Length::METER,-50*Length::METER));
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getX()/Length::METER, -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getY()/Length::METER, -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getZ()/Length::METER, -10);
}



TEST (Box, getTopRight) 
{
	// test if it returns the right top right coordinate
	Coordinate bl = Coordinate::origin + Distance();
	Coordinate tr = Coordinate::origin + Distance(50.0*Length::METER, 50.0*Length::METER, 50.0*Length::METER);
	Coordinate tr2 = Coordinate::origin + Distance(25*Length::METER,25*Length::METER,25*Length::METER);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getTopRight().getX()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().getY()/Length::METER, 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().getZ()/Length::METER, 50);

	Box box2(bl, tr2);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getX()/Length::METER, 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getY()/Length::METER, 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getZ()/Length::METER, 25);

	Box negative(Coordinate::origin + Distance(-10*Length::METER,-10*Length::METER,-10*Length::METER), Coordinate::origin + Distance(-50*Length::METER,-50*Length::METER,-50*Length::METER));
	ASSERT_DOUBLE_EQ(negative.getTopRight().getX()/Length::METER, -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().getY()/Length::METER, -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().getZ()/Length::METER, -50);

}


TEST (Box, getUnionBox) 
{
	// test if method returns right result

	Box box (Coordinate::origin + Distance(), Coordinate::origin + Distance(100*Length::METER,100*Length::METER,100*Length::METER));

	Box biggerBox(Coordinate::origin + Distance(25*Length::METER,25*Length::METER,25*Length::METER), Coordinate::origin + Distance(120*Length::METER,120*Length::METER,120*Length::METER));
	Box unionBox(Coordinate::origin + Distance(), Coordinate::origin + Distance());
	unionBox = box.getUnionBox(biggerBox);

	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getZ()/Length::METER, 0);

	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getX()/Length::METER, 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getY()/Length::METER, 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getZ()/Length::METER, 120);


	// test if method returns the right result when using negative boxes

	Box negativeBox(Coordinate::origin + Distance(-75*Length::METER,-75*Length::METER,-75*Length::METER), Coordinate::origin + Distance(-25*Length::METER,-25*Length::METER,-25*Length::METER));

	Box negativeBox2(Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER), Coordinate::origin + Distance(-75*Length::METER,-75*Length::METER,-75*Length::METER));

	unionBox = negativeBox.getUnionBox(negativeBox2);

	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getX()/Length::METER, -125);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getY()/Length::METER, -125);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getZ()/Length::METER, -125);

	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getX()/Length::METER, -25);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getY()/Length::METER, -25);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getZ()/Length::METER, -25);




}

TEST (Box, getIntersectionBox) 
{
	// test if 2 boxes that are intersecting returns the right box
	Box box (Coordinate::origin + Distance(), Coordinate::origin + Distance(100*Length::METER,100*Length::METER,100*Length::METER));

	Box collidingBox (Coordinate::origin + Distance(75*Length::METER,75*Length::METER,75*Length::METER), Coordinate::origin + Distance(125*Length::METER,125*Length::METER,125*Length::METER));

	Box collidedBox(Coordinate::origin + Distance(), Coordinate::origin + Distance());
	collidedBox = box.getIntersectionBox(collidingBox);

	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getX()/Length::METER, 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getY()/Length::METER, 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getZ()/Length::METER, 75);

	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getX()/Length::METER, 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getY()/Length::METER, 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getZ()/Length::METER, 100);


	// test 2 boxes that aren't intersecting
	Box notCollidingBox (Coordinate::origin + Distance(125*Length::METER,125*Length::METER,125*Length::METER), Coordinate::origin + Distance(150*Length::METER,150*Length::METER,150*Length::METER));

	Box notCollidedBox(Coordinate::origin + Distance(), Coordinate::origin + Distance());
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getZ()/Length::METER, 0);

	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getZ()/Length::METER, 0);


	// test 2 negative boxes that are intersecting
	Box negativeBox(Coordinate::origin + Distance(-75*Length::METER,-75*Length::METER,-75*Length::METER), Coordinate::origin + Distance(-25*Length::METER,-25*Length::METER,-25*Length::METER));

	Box negativeBoxIntersecting(Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER), Coordinate::origin + Distance(-50*Length::METER,-50*Length::METER,-50*Length::METER));

	collidedBox = negativeBox.getIntersectionBox(negativeBoxIntersecting);

	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getX()/Length::METER, -75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getY()/Length::METER, -75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getZ()/Length::METER, -75);

	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getX()/Length::METER, -50);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getY()/Length::METER, -50);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getZ()/Length::METER, -50);

	// test 2 negative boxes that aren't intersecting
	Box negativeBoxNotIntersecting(Coordinate::origin + Distance(-80*Length::METER,-80*Length::METER,-80*Length::METER), Coordinate::origin + Distance(-125*Length::METER,-125*Length::METER,-125*Length::METER));

	notCollidedBox = negativeBox.getIntersectionBox(negativeBoxNotIntersecting);

	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getZ()/Length::METER, 0);

	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getX()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getY()/Length::METER, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getZ()/Length::METER, 0);

} 