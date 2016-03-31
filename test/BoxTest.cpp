/* #include "../source/include/Box.hpp"
#include <iostream>

/**
*	@author 		Stephan Vivie
*	@date			29-03-2016
*/


/**
* CONSTRUCTORS 
*/
/*
TEST (Box, Coordinates) 
{
	// construct Box object with 2 Coordinates
	Coordinate bl = Coordinate::origin;
	Coordinate tr = Coordinate::origin + Distance(50.0, 50.0, 50.0);

	Box box (bl, tr);

	// get bottomLeft
	ASSERT_DOUBLE_EQ(bl.getX(), box.getBottomLeft().getX());
	ASSERT_DOUBLE_EQ(bl.getY(), box.getBottomLeft().getY());
	ASSERT_DOUBLE_EQ(bl.getZ(), box.getBottomLeft().getZ());

	// get topRight
	ASSERT_DOUBLE_EQ(tr.getX(), box.getTopRight().getX());
	ASSERT_DOUBLE_EQ(tr.getY(), box.getTopRight().getY());
	ASSERT_DOUBLE_EQ(tr.getZ(), box.getTopRight().getZ());

}

TEST (Box, CoordinateDistance) 
{
	// construct Box object with Coordinate and Distance
	Distance evenDistance (50.0,50.0,50.0);
	Coordinate origin = Coordinate::origin;

	
	Box rectangleBox (origin, evenDistance);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getX(), 50);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getY(), 50);
	ASSERT_DOUBLE_EQ(rectangleBox.getTopRight().getZ(), 50);


	Distance unevenDistance (25.0,0.0,50.0);
	Box noRectangleBox (origin, unevenDistance); //cant happen -> exception or different behavior


}

/**
* OPERATORS 
*/
/*
TEST (Box, Assign) 
{

	Box boxOne (Coordinate::origin, Coordinate::origin + Distance(25,25,25));
	Box boxTwo (Coordinate::origin + Distance{50,50,50}, Coordinate::origin + Distance{100,100,100});

	// assign boxTwo to boxOne
	boxOne = boxTwo;

	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getX(), 50);
	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getY(), 50);
	ASSERT_DOUBLE_EQ(boxOne.getBottomLeft().getZ(), 50);

	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getX(), 100);
	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getY(), 100);
	ASSERT_DOUBLE_EQ(boxOne.getTopRight().getZ(), 100);





}

TEST (Box, Ostream) 
{
	Coordinate bl = Coordinate::origin + Distance{0.0, 0.0, 0.0};
	Coordinate tr = Coordinate::origin + Distance{50.0, 50.0, 50.0};

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
/*
TEST (Box, ContainsCoordinate) 
{
	Coordinate bl = Coordinate::origin + Distance{0.0, 0.0, 0.0};
	Coordinate tr = Coordinate::origin + Distance{50.0, 50.0, 50.0};

	Box box (bl, tr);

	// test coordinate thats inside box
	Coordinate inside =Coordinate::origin + Distance{25.0,25.0,25.0};
	ASSERT_EQ(box.contains(inside), true);

	// test coordinate thats outside box
	Coordinate outside = Coordinate::origin + Distance{75.0,75.0,75.0};
	ASSERT_EQ(box.contains(outside), false);

	Box negativeBox(Coordinate::origin + Distance{-25,-25,-25},Coordinate::origin + Distance{-75,-75,-75});
	// test coordinate thats inside negative box
	Coordinate insideNegative = Coordinate::origin + Distance{-50,-50,-50};
	ASSERT_EQ(negativeBox.contains(insideNegative),true);

	// test coordinate thats outside negative box
	Coordinate outsideNegative = Coordinate::origin + Distance{-150,-150,-150};
	ASSERT_EQ(negativeBox.contains(outsideNegative),false);
	ASSERT_EQ(negativeBox.contains(outside),false);


}


TEST (Box, ContainsBox) 
{
	Box box(Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(100,100,100));
	
	// test box thats inside box
	Box insideBigBox(Coordinate::origin + Distance(50,50,50), Coordinate::origin + Distance(75,75,75));
	ASSERT_EQ(box.contains(insideBigBox),true);

	// test box thats outside box
	Box outsideBigBox(Coordinate::origin + Distance(150,150,150), Coordinate::origin + Distance(200,200,200));
	ASSERT_EQ(box.contains(outsideBigBox), false);

	// test boxes that collide (shouldn't return true as it isn't fully inside the box)
	Box collidesWithBigBox(Coordinate::origin + Distance(50,50,50), Coordinate::origin + Distance(200,200,200));
	ASSERT_EQ(box.contains(collidesWithBigBox), false);

	
	Box negativeBox(Coordinate::origin + Distance(-50,-50,-50), Coordinate::origin + Distance(-100,-100,-100));
	
	// test negative box that is inside the box 
	Box negativeBoxInside(Coordinate::origin + Distance(-60,-60,-60), Coordinate::origin + Distance(-70,-70,-70));
	ASSERT_EQ(negativeBox.contains(negativeBoxInside), true);

	// test negative box that intersects but isnt fully inside the box
	Box negativeBoxIntersects(Coordinate::origin + Distance(-75,-75,-75), Coordinate::origin + Distance(-125,-125,-125));
	ASSERT_EQ(negativeBox.contains(negativeBoxIntersects), false);

	// test negative box that doesnt intersect at all
	Box negativeBoxOutside(Coordinate::origin + Distance(-175,-175,-175), Coordinate::origin + Distance(-125,-125,-125));
	ASSERT_EQ(negativeBox.contains(negativeBoxOutside), false);

	
}

TEST (Box, IntersectsBox) 
{
	Box box(Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(100,100,100));

	// test box that is inside
	Box insideBox(Coordinate::origin + Distance(25,25,25), Coordinate::origin + Distance(75,75,75));
	ASSERT_EQ(box.intersects(insideBox), true);

	// test box that intersects but isn't completely inside
	Box intersectBox(Coordinate::origin + Distance(50,50,50), Coordinate::origin + Distance(150,150,150));
	ASSERT_EQ(box.intersects(intersectBox), true);

	// test box that doesn't intersect at all
	Box outsideBox(Coordinate::origin + Distance(200,200,200), Coordinate::origin + Distance(500,500,500));
	ASSERT_EQ(box.intersects(outsideBox), false);

	
	Box negativeBox(Coordinate::origin + Distance(-50,-50,-50), Coordinate::origin + Distance(-100,-100,-100));
	
	// test negative box that is inside
	Box negativeBoxInside(Coordinate::origin + Distance(-60,-60,-60), Coordinate::origin + Distance(-70,-70,-70));
	ASSERT_EQ(negativeBox.intersects(negativeBoxInside), true);

	// test negative box that intersects
	Box negativeBoxIntersects(Coordinate::origin + Distance(-75,-75,-75), Coordinate::origin + Distance(-125,-125,-125));
	ASSERT_EQ(negativeBox.intersects(negativeBoxIntersects), true);

	// test negative box that doesn't intersect
	Box negativeBoxOutside(Coordinate::origin + Distance(-175,-175,-175), Coordinate::origin + Distance(-125,-125,-125));
	ASSERT_EQ(negativeBox.intersects(negativeBoxOutside), false);



}


TEST (Box, getBottomLeft) 
{
	// test if it returns the right bottom left coordinate
	Coordinate bl = Coordinate::origin;
	Coordinate tr = Coordinate::origin +Distance(50.0, 50.0, 50.0);
	Coordinate bl2 = Coordinate::origin + Distance(25,26,27);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getX(), 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getY(), 0);
	ASSERT_DOUBLE_EQ(box.getBottomLeft().getZ(), 0);

	Box box2(bl2, tr);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getX(), 25);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getY(), 26);
	ASSERT_DOUBLE_EQ(box2.getBottomLeft().getZ(), 27);

	Box negative(Coordinate::origin + Distance(-10,-10,-10), Coordinate::origin + Distance(-50,-50,-50));
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getX(), -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getY(), -10);
	ASSERT_DOUBLE_EQ(negative.getBottomLeft().getZ(), -10);
}



TEST (Box, getTopRight) 
{
	// test if it returns the right top right coordinate
	Coordinate bl = Coordinate::origin + Distance(0.0, 0.0, 0.0);
	Coordinate tr = Coordinate::origin + Distance(50.0, 50.0, 50.0);
	Coordinate tr2 = Coordinate::origin + Distance(25,25,25);

	Box box (bl, tr);
	ASSERT_DOUBLE_EQ(box.getTopRight().getX(), 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().getY(), 50);
	ASSERT_DOUBLE_EQ(box.getTopRight().getZ(), 50);

	Box box2(bl, tr2);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getX(), 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getY(), 25);
	ASSERT_DOUBLE_EQ(box2.getTopRight().getZ(), 25);

	Box negative(Coordinate::origin + Distance(-10,-10,-10), Coordinate::origin + Distance(-50,-50,-50));
	ASSERT_DOUBLE_EQ(negative.getTopRight().getX(), -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().getY(), -50);
	ASSERT_DOUBLE_EQ(negative.getTopRight().getZ(), -50);

}

TEST (Box, getUnionBox) 
{
	// test if method returns right result

	Box box (Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(100,100,100));

	Box biggerBox(Coordinate::origin + Distance(25,25,25), Coordinate::origin + Distance(120,120,120));
	Box unionBox(Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(0,0,0));
	unionBox = box.getUnionBox(biggerBox);

	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getX(), 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getY(), 0);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getZ(), 0);

	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getX(), 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getY(), 120);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getZ(), 120);


	// test if method returns the right result when using negative boxes

	Box negativeBox(Coordinate::origin + Distance(-75,-75,-75), Coordinate::origin + Distance(-25,-25,-25));

	Box negativeBox2(Coordinate::origin + Distance(-125,-125,-125), Coordinate::origin + Distance(-75,-75,-75));

	unionBox = negativeBox.getUnionBox(negativeBox2);

	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getX(), -125);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getY(), -125);
	ASSERT_DOUBLE_EQ(unionBox.getBottomLeft().getZ(), -125);

	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getX(), -25);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getY(), -25);
	ASSERT_DOUBLE_EQ(unionBox.getTopRight().getZ(), -25);




}

TEST (Box, getIntersectionBox) 
{
	// test if 2 boxes that are intersecting returns the right box
	Box box (Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(100,100,100));

	Box collidingBox (Coordinate::origin + Distance(75,75,75), Coordinate::origin + Distance(125,125,125));

	Box collidedBox(Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(0,0,0));
	collidedBox = box.getIntersectionBox(collidingBox);

	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getX(), 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getY(), 75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getZ(), 75);

	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getX(), 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getY(), 100);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getZ(), 100);


	// test 2 boxes that aren't intersecting
	Box notCollidingBox (Coordinate::origin + Distance(125,125,125), Coordinate::origin + Distance(150,150,150));

	Box notCollidedBox(Coordinate::origin + Distance(0,0,0), Coordinate::origin + Distance(0,0,0));
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getX(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getY(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getZ(), 0);

	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getX(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getY(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getZ(), 0);


	// test 2 negative boxes that are intersecting
	Box negativeBox(Coordinate::origin + Distance(-75,-75,-75), Coordinate::origin + Distance(-25,-25,-25));

	Box negativeBoxIntersecting(Coordinate::origin + Distance(-125,-125,-125), Coordinate::origin + Distance(-50,-50,-50));

	collidedBox = negativeBox.getIntersectionBox(negativeBoxIntersecting);

	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getX(), -75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getY(), -75);
	ASSERT_DOUBLE_EQ(collidedBox.getBottomLeft().getZ(), -75);

	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getX(), -50);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getY(), -50);
	ASSERT_DOUBLE_EQ(collidedBox.getTopRight().getZ(), -50);

	// test 2 negative boxes that aren't intersecting
	Box negativeBoxNotIntersecting(Coordinate::origin + Distance(-80,-80,-80), Coordinate::origin + Distance(-125,-125,-125));

	notCollidedBox = negativeBox.getIntersectionBox(negativeBoxNotIntersecting);

	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getX(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getY(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getBottomLeft().getZ(), 0);

	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getX(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getY(), 0);
	ASSERT_DOUBLE_EQ(notCollidedBox.getTopRight().getZ(), 0);

}