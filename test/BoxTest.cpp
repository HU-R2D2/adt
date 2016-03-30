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

TEST (Box, Assign) 
{

	Box boxOne (Coordinate(0,0,0), Coordinate(25,25,25));
	Box boxTwo (Coordinate(50,50,50), Coordinate(100,100,100));

	// assign boxTwo to boxOne
	boxOne = boxTwo;

	ASSERT_DOUBLE_EQ(boxOne.bottomLeft.x, 50);
	ASSERT_DOUBLE_EQ(boxOne.bottomLeft.y, 50);
	ASSERT_DOUBLE_EQ(boxOne.bottomLeft.z, 50);

	ASSERT_DOUBLE_EQ(boxOne.topRight.x, 100);
	ASSERT_DOUBLE_EQ(boxOne.topRight.y, 100);
	ASSERT_DOUBLE_EQ(boxOne.topRight.z, 100);





}

TEST (Box, Ostream) 
{
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

	Box negativeBox(Coordinate(-25,-25,-25),Coordinate(-75,-75,-75));
	// test coordinate thats inside negative box
	Coordinate insideNegative(-50,-50,-50);
	ASSERT_EQ(negativeBox.contains(insideNegative),true);

	// test coordinate thats outside negative box
	Coordinate outsideNegative(-150,-150,-150);
	ASSERT_EQ(negativeBox.contains(outsideNegative),false);
	ASSERT_EQ(negativeBox.contains(outside),false);


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

	
	Box negativeBox(Coordinate(-50,-50,-50), Coordinate(-100,-100,-100));
	
	// test negative box that is inside the box 
	Box negativeBoxInside(Coordinate(-60,-60,-60), Coordinate(-70,-70,-70));
	ASSERT_EQ(negativeBox.contains(negativeBoxInside), true);

	// test negative box that intersects but isnt fully inside the box
	Box negativeBoxIntersects(Coordinate(-75,-75,-75), Coordinate(-125,-125,-125));
	ASSERT_EQ(negativeBox.contains(negativeBoxIntersects), false);

	// test negative box that doesnt intersect at all
	Box negativeBoxOutside(Coordinate(-175,-175,-175), Coordinate(-125,-125,-125));
	ASSERT_EQ(negativeBox.contains(negativeBoxOutside), false);

	
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

	
	Box negativeBox(Coordinate(-50,-50,-50), Coordinate(-100,-100,-100));
	
	// test negative box that is inside
	Box negativeBoxInside(Coordinate(-60,-60,-60), Coordinate(-70,-70,-70));
	ASSERT_EQ(negativeBox.intersects(negativeBoxInside), true);

	// test negative box that intersects
	Box negativeBoxIntersects(Coordinate(-75,-75,-75), Coordinate(-125,-125,-125));
	ASSERT_EQ(negativeBox.intersects(negativeBoxIntersects), true);

	// test negative box that doesn't intersect
	Box negativeBoxOutside(Coordinate(-175,-175,-175), Coordinate(-125,-125,-125));
	ASSERT_EQ(negativeBox.intersects(negativeBoxOutside), false);



}


TEST (Box, getBottomLeft) 
{
	// test if it returns the right bottom left coordinate
	Coordinate bl(0.0, 0.0, 0.0);
	Coordinate tr(50.0, 50.0, 50.0);
	Coordinate bl2(25,26,27);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().x, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().y, 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().z, 0);

	Box box2(bl2, tr);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().x, 25);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().y, 26);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().z, 27);

	Box negative(Coordinate(-10,-10,-10), Coordinate(-50,-50,-50));
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().x, -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().y, -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().z, -10);
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

	Box negative(Coordinate(-10,-10,-10), Coordinate(-50,-50,-50));
	ASSERT_DOUBLE_EQ(negative.getTopRight().x, -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().y, -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().z, -50);

}

TEST (Box, getUnionBox) 
{
	// test if method returns right result

	Box box (Coordinate(0,0,0), Coordinate(100,100,100));

	Box biggerBox(Coordinate(25,25,25), Coordinate(120,120,120));
	Box unionBox(Coordinate(0,0,0), Coordinate(0,0,0));
	unionBox = box.getUnionBox(biggerBox);

	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().x, 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().y, 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().z, 0);

	ASSERT_DOUBLE_EQ(unionBox.getTopRight().x, 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().y, 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().z, 120);


	// test if method returns the right result when using negative boxes

	Box negativeBox(Coordinate(-25,-25,-25), Coordinate(-75,-75,-75));

	Box negativeBox2(Coordinate(-75,-75,-75), Coordinate(-125,-125,-125));

	unionBox = negativeBox.getUnionBox(negativeBox2);

	//ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().x, -25);
	//ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().y, -25);
	//ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().z, -25);

	//ASSERT_DOUBLE_EQ(unionBox.getTopRight().x, -125);
	//ASSERT_DOUBLE_EQ(unionBox.getTopRight().y, -125);
	//ASSERT_DOUBLE_EQ(unionBox.getTopRight().z, -125);




}

TEST (Box, getIntersectionBox) 
{
	// test if 2 boxes that are intersecting returns the right box
	Box box (Coordinate(0,0,0), Coordinate(100,100,100));

	Box collidingBox (Coordinate(75,75,75), Coordinate(125,125,125));

	Box collidedBox(Coordinate(0,0,0), Coordinate(0,0,0));
	collidedBox = box.getIntersectionBox(collidingBox);

	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().x, 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().y, 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().z, 75);

	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().x, 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().y, 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().z, 100);


	// test 2 boxes that aren't intersecting
	Box notCollidingBox (Coordinate(125,125,125), Coordinate(150,150,150));

	Box notCollidedBox(Coordinate(0,0,0), Coordinate(0,0,0));
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().x, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().y, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().z, 0);

	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().x, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().y, 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().z, 0);


	// test 2 negative boxes that are intersecting
	Box negativeBox(Coordinate(-25,-25,-25), Coordinate(-75,-75,-75));

	Box negativeBoxIntersecting(Coordinate(-50,-50,-50), Coordinate(-125,-125,-125));

	collidedBox = negativeBox.getUnionBox(negativeBoxIntersecting);

	//ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().x, -50);
	//ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().y, -50);
	//ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().z, -50);

	//ASSERT_DOUBLE_EQ(collidedBox.getTopRight().x, -75);
	//ASSERT_DOUBLE_EQ(collidedBox.getTopRight().y, -75);
	//ASSERT_DOUBLE_EQ(collidedBox.getTopRight().z, -75);

	// test 2 negative boxes that aren't intersecting
	Box negativeBoxNotIntersecting(Coordinate(-80,-80,-80), Coordinate(-125,-125,-125));

	notCollidedBox = negativeBox.getUnionBox(negativeBoxNotIntersecting);

	//ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().x, 0);
	//ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().y, 0);
	//ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().z, 0);

	//ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().x, 0);
	//ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().y, 0);
	//ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().z, 0);

}
