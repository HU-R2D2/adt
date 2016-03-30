#include "gtest/gtest.h"
#include "../source/include/Distance.hpp"
#include <iostream>

// constructors:
TEST(Distance, DefaultConstructor) {
	Distance a;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "z";
}


TEST(Distance, ConstructorDouble) {
	Distance a(1,2,3);
	ASSERT_DOUBLE_EQ(a.getX() , 1.0) << "x";
	ASSERT_DOUBLE_EQ(a.getY() , 2.0) << "y";
	ASSERT_DOUBLE_EQ(a.getZ() , 3.0) << "z";
}
//==============================================================================================
// operatoren:
TEST( Distance, AssignDistance ){   				//operator=
	Distance a;
	a = Distance(1,2,3);
	
	ASSERT_DOUBLE_EQ(a.getX() , 1.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 2.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 3.0) << "empty z";
	
	a = Distance(4,5,6);
	ASSERT_DOUBLE_EQ(a.getX() , 4.0) << "new x";
	ASSERT_DOUBLE_EQ(a.getY() , 5.0) << "new y";
	ASSERT_DOUBLE_EQ(a.getZ() , 6.0) << "new z";  
}

TEST(Distance, AddDistance) { 						//operator+
	// leeg + leeg
	Distance a;
	Distance b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty+empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty+empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty+empty z";
	
	// leeg + vol
	Distance c(1,2,3);
	b = b + c;
	ASSERT_DOUBLE_EQ(b.getX() , 1.0) << "empty+full x";
	ASSERT_DOUBLE_EQ(b.getY() , 2.0) << "empty+full y";
	ASSERT_DOUBLE_EQ(b.getZ() , 3.0) << "empty+full z";
	
	// vol + vol
	Distance d(1,2,3);
	Distance e(4,5,6);
	d = d + e;
 	ASSERT_DOUBLE_EQ(d.getX() , 5.0) << "full+full x";
	ASSERT_DOUBLE_EQ(d.getY() , 7.0) << "full+full y";
	ASSERT_DOUBLE_EQ(d.getZ() , 9.0) << "full+full z";
}

TEST(Distance, SubstractDistance) { 					//operator-
	// leeg - leeg
	Distance a;
	Distance b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty-empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty-empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty-empty z";
	
	// leeg - vol
	Distance c(1,2,3);
	b = b - c;
	ASSERT_DOUBLE_EQ(b.getX() , -1.0) << "empty-full x";
	ASSERT_DOUBLE_EQ(b.getY() , -2.0) << "empty-full y";
	ASSERT_DOUBLE_EQ(b.getZ() , -3.0) << "empty-full z";
	
	// vol - leeg
	Distance d(1,2,3);
	Distance e;
	d = d - e;
	ASSERT_DOUBLE_EQ(d.getX() , 1.0) << "full-empty x";
	ASSERT_DOUBLE_EQ(d.getY() , 2.0) << "full-empty y";
	ASSERT_DOUBLE_EQ(d.getZ() , 3.0) << "full-empty z";
	
	// vol - vol
	Distance f(4,5,6);
	Distance g(1,2,3);
	f = f - g;
 	ASSERT_DOUBLE_EQ(f.getX() , 3.0) << "full-full x";
	ASSERT_DOUBLE_EQ(f.getY() , 3.0) << "full-full y";
	ASSERT_DOUBLE_EQ(f.getZ() , 3.0) << "full-full z";
}

TEST(Distance, MultiplyDouble) { 					//operator*
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Distance a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty*0 x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty*0 y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty*0 z";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty z";
	
	// vol * 0
	Distance b(1,2,3);
	b = b * 0;
	ASSERT_DOUBLE_EQ(b.getX() , 0.0) << "full*0 x";
	ASSERT_DOUBLE_EQ(b.getY() , 0.0) << "full*0 y";
	ASSERT_DOUBLE_EQ(b.getZ() , 0.0) << "full*0 z";
	
	// vol * getal1
	Distance c(1,2,3);
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c.getX() , 2.0) << "full*getal1 x";
	ASSERT_DOUBLE_EQ(c.getY() , 4.0) << "full*getal1 y";
	ASSERT_DOUBLE_EQ(c.getZ() , 6.0) << "full*getal1 z";
	
	// vol * getal2
	Distance d(1,2,3);
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d.getX() , 2.5) << "full*getal2 x";
	ASSERT_DOUBLE_EQ(d.getY() , 5.0) << "full*getal2 y";
	ASSERT_DOUBLE_EQ(d.getZ() , 7.5) << "full*getal2 z";
}

TEST(Distance, DivideDouble) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Distance a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty/0 x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty/0 y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty/0 z";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty z";
	
	// vol / 0
	Distance b(1,2,3);
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b.getX() , 1.0) << "full/0 x";
	ASSERT_DOUBLE_EQ(b.getY() , 2.0) << "full/0 y";
	ASSERT_DOUBLE_EQ(b.getZ() , 3.0) << "full/0 z";
	
	// vol / getal1
	Distance c(1,2,3);
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c.getX() , 0.5) << "full/getal1 x";
	ASSERT_DOUBLE_EQ(c.getY() , 1.0) << "full/getal1 y";
	ASSERT_DOUBLE_EQ(c.getZ() , 1.5) << "full/getal1 z";
	
	// vol / getal2
	Distance d(1,2,3);
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d.getX() , 0.4) << "full/getal2 x";
	ASSERT_DOUBLE_EQ(d.getY() , 0.8) << "full/getal2 y";
	ASSERT_DOUBLE_EQ(d.getZ() , 1.2) << "full/getal2 z";
}

TEST(Distance, AddAssignDistance) {					//operator+=
	//leeg + leeg
	Distance a;
	Distance b;
	a += b;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty+empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty+empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty+empty z";
	
	// leeg + vol
	Distance c(1,2,3);
	b += c;
	ASSERT_DOUBLE_EQ(b.getX() , 1.0) << "empty+full x";
	ASSERT_DOUBLE_EQ(b.getY() , 2.0) << "empty+full y";
	ASSERT_DOUBLE_EQ(b.getZ() , 3.0) << "empty+full z";
	
	// vol + vol
	Distance d(1,2,3);
	Distance e(4,5,6);
	d += e;
 	ASSERT_DOUBLE_EQ(d.getX() , 5.0) << "full+full x";
	ASSERT_DOUBLE_EQ(d.getY() , 7.0) << "full+full y";
	ASSERT_DOUBLE_EQ(d.getZ() , 9.0) << "full+full z"; 
}

TEST(Distance, SubstractAssignDistance) { 			//operator-=
	// leeg - leeg
	Distance a;
	Distance b;
	a -= b;
	ASSERT_DOUBLE_EQ(a.getX() , 0.0) << "empty-empty x";
	ASSERT_DOUBLE_EQ(a.getY() , 0.0) << "empty-empty y";
	ASSERT_DOUBLE_EQ(a.getZ() , 0.0) << "empty-empty z";
	
	// leeg - vol
	Distance c(1,2,3);
	b -= c;
	ASSERT_DOUBLE_EQ(b.getX() , -1.0) << "empty-full x";
	ASSERT_DOUBLE_EQ(b.getY() , -2.0) << "empty-full y";
	ASSERT_DOUBLE_EQ(b.getZ() , -3.0) << "empty-full z";
	
	// vol - leeg
	Distance d(1,2,3);
	Distance e;
	d -= e;
	ASSERT_DOUBLE_EQ(d.getX() , 1.0) << "full-empty x";
	ASSERT_DOUBLE_EQ(d.getY() , 2.0) << "full-empty y";
	ASSERT_DOUBLE_EQ(d.getZ() , 3.0) << "full-empty z";
	
	// vol - vol
	Distance f(4,5,6);
	Distance g(1,2,3);
	f -= g;
 	ASSERT_DOUBLE_EQ(f.getX() , 3.0) << "full-full x";
	ASSERT_DOUBLE_EQ(f.getY() , 3.0) << "full-full y";
	ASSERT_DOUBLE_EQ(f.getZ() , 3.0) << "full-full z";
}

TEST(Distance, GreaterThan) { 				//operator>
	Distance a(2,2,2);
	Distance b(1,1,1);
	ASSERT_TRUE(a > b) << "greater than";
	ASSERT_FALSE(b > a) << "less than";
}

TEST(Distance, LessThan) { 					//operator<
	Distance a(1,1,1);
	Distance b(2,2,2);
	ASSERT_TRUE(a < b) << "less than";
	ASSERT_FALSE(b < a) << "greater than";
}

TEST(Distance, OutputStream) { 				//operator<<
	Distance a(1,2,3);
	std::stringstream stream{};
	stream << a << std::endl;
	std::string output;
	std::getline(stream, output);
	EXPECT_EQ("(1,2,3)", output);
}
		
//TEST(Distance, InputStream) { 			//operator>>				// ZOIETS??????????????
//	Distance a;
//	std::ifstream input("test.txt");
//	input.open();
//	a >> input;
//	input.close();
//	ASSERT_DOUBLE_EQ(a.getX() , 1.0) << "x";
//	ASSERT_DOUBLE_EQ(a.getY() , 2.0) << "y";
//	ASSERT_DOUBLE_EQ(a.getZ() , 3.0) << "z";
//}