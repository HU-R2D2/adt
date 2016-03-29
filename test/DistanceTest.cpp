#include "gtest/gtest.h"
#include "../source/include/Distance.hpp"

// constructors:
TEST(Distance, DefaultConstructor) {
	Distance a;
	ASSERT_DOUBLE_EQ(a.x , 0.0) << "x";
	ASSERT_DOUBLE_EQ(a.y , 0.0) << "y";
	ASSERT_DOUBLE_EQ(a.z , 0.0) << "z";
}

TEST(Distance, ConstructorDouble) {
	Distance a{1,2,3};
	ASSERT_DOUBLE_EQ(a.x,1.0) << "x";
	ASSERT_DOUBLE_EQ(a.y,2.0) << "y";
	ASSERT_DOUBLE_EQ(a.z,3.0) << "z";
}
//==============================================================================================
// operatoren:
TEST( Distance, AssignDistance ){   				//operator=
	Distance a;
	a = Distance{1,2,3};
	
	ASSERT_DOUBLE_EQ(a.x,1.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.y,2.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.z,3.0) << "empty z";
	
	a = Distance{4,5,6};
	ASSERT_DOUBLE_EQ(a.x,4.0) << "new x";
	ASSERT_DOUBLE_EQ(a.y,5.0) << "new y";
	ASSERT_DOUBLE_EQ(a.z,6.0) << "new z";  
}

TEST(Distance, AddDistance) { 						//operator+
	// leeg + leeg
	Distance a;
	Distance b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty+empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty+empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty+empty z";
	
	// leeg + vol
	Distance c{1,2,3};
	b = b + c;
	ASSERT_DOUBLE_EQ(b.x,1.0) << "empty+full x";
	ASSERT_DOUBLE_EQ(b.y,2.0) << "empty+full y";
	ASSERT_DOUBLE_EQ(b.z,3.0) << "empty+full z";
	
	// vol + vol
	Distance d{1,2,3};
	Distance e{4,5,6};
	d = d + e;
 	ASSERT_DOUBLE_EQ(d.x,5.0) << "full+full x";
	ASSERT_DOUBLE_EQ(d.y,7.0) << "full+full y";
	ASSERT_DOUBLE_EQ(d.z,9.0) << "full+full z";
}

TEST(Distance, SubstractDistance) { 					//operator-
	// leeg - leeg
	Distance a;
	Distance b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty-empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty-empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty-empty z";
	
	// leeg - vol
	Distance c{1,2,3};
	b = b - c;
	ASSERT_DOUBLE_EQ(b.x,-1.0) << "empty-full x";
	ASSERT_DOUBLE_EQ(b.y,-2.0) << "empty-full y";
	ASSERT_DOUBLE_EQ(b.z,-3.0) << "empty-full z";
	
	// vol - leeg
	Distance d{1,2,3};
	Distance e;
	d = d - e;
	ASSERT_DOUBLE_EQ(d.x,1.0) << "full-empty x";
	ASSERT_DOUBLE_EQ(d.y,2.0) << "full-empty y";
	ASSERT_DOUBLE_EQ(d.z,3.0) << "full-empty z";
	
	// vol - vol
	Distance f{4,5,6};
	Distance g{1,2,3};
	f = f - g;
 	ASSERT_DOUBLE_EQ(f.x,3.0) << "full-full x";
	ASSERT_DOUBLE_EQ(f.y,3.0) << "full-full y";
	ASSERT_DOUBLE_EQ(f.z,3.0) << "full-full z";
}

TEST(Distance, MultiplyDouble) { 					//operator*
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Distance a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty*0 x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty*0 y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty*0 z";
	
	// leeg * getal1
	a = a * getal1
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty z";
	
	// vol * 0
	Distance b{1,2,3}
	b = b * 0;
	ASSERT_DOUBLE_EQ(b.x,0.0) << "full*0 x";
	ASSERT_DOUBLE_EQ(b.y,0.0) << "full*0 y";
	ASSERT_DOUBLE_EQ(b.z,0.0) << "full*0 z";
	
	// vol * getal1
	Distance c{1,2,3}
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c.x,2.0) << "full*getal1 x";
	ASSERT_DOUBLE_EQ(c.y,4.0) << "full*getal1 y";
	ASSERT_DOUBLE_EQ(c.z,6.0) << "full*getal1 z";
	
	// vol * getal2
	Distance d{1,2,3}
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d.x,2.5) << "full*getal2 x";
	ASSERT_DOUBLE_EQ(d.y,5.0) << "full*getal2 y";
	ASSERT_DOUBLE_EQ(d.z,7.5) << "full*getal2 z";
}

TEST(Distance, DivideDouble) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Distance a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty/0 x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty/0 y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty/0 z";
	
	// leeg / getal1
	a = a / getal1
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty z";
	
	// vol / 0
	Distance b{1,2,3}
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b.x,0.0) << "full/0 x";
	ASSERT_DOUBLE_EQ(b.y,0.0) << "full/0 y";
	ASSERT_DOUBLE_EQ(b.z,0.0) << "full/0 z";
	
	// vol / getal1
	Distance c{1,2,3}
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c.x,0.5) << "full/getal1 x";
	ASSERT_DOUBLE_EQ(c.y,1.0) << "full/getal1 y";
	ASSERT_DOUBLE_EQ(c.z,1.5) << "full/getal1 z";
	
	// vol / getal2
	Distance d{1,2,3}
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d.x,0.4) << "full/getal2 x";
	ASSERT_DOUBLE_EQ(d.y,0.8) << "full/getal2 y";
	ASSERT_DOUBLE_EQ(d.z,1.2) << "full/getal2 z";
}

TEST(Distance, AddAssignDistance) {					//operator+=
	//leeg + leeg
	Distance a;
	Distance b;
	a += b;
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty+empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty+empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty+empty z";
	
	
	// leeg + vol
	Distance c{1,2,3};
	b += c;
	ASSERT_DOUBLE_EQ(b.x,1.0) << "empty+full x";
	ASSERT_DOUBLE_EQ(b.y,2.0) << "empty+full y";
	ASSERT_DOUBLE_EQ(b.z,3.0) << "empty+full z";
	
	// vol + vol
	Distance d{1,2,3};
	Distance e{4,5,6};
	d += e;
 	ASSERT_DOUBLE_EQ(d.x,5.0) << "full+full x";
	ASSERT_DOUBLE_EQ(d.y,7.0) << "full+full y";
	ASSERT_DOUBLE_EQ(d.z,9.0) << "full+full z"; 
}

TEST(Distance, SubstractAssignDistance) { 			//operator-=
	// leeg - leeg
	Distance a;
	Distance b;
	a -= b;
	ASSERT_DOUBLE_EQ(a.x,0.0) << "empty-empty x";
	ASSERT_DOUBLE_EQ(a.y,0.0) << "empty-empty y";
	ASSERT_DOUBLE_EQ(a.z,0.0) << "empty-empty z";
	
	// leeg - vol
	Distance c{1,2,3};
	b -= c;
	ASSERT_DOUBLE_EQ(b.x,-1.0) << "empty-full x";
	ASSERT_DOUBLE_EQ(b.y,-2.0) << "empty-full y";
	ASSERT_DOUBLE_EQ(b.z,-3.0) << "empty-full z";
	
	// vol - leeg
	Distance d{1,2,3};
	Distance e;
	d -= e;
	ASSERT_DOUBLE_EQ(d.x,1.0) << "full-empty x";
	ASSERT_DOUBLE_EQ(d.y,2.0) << "full-empty y";
	ASSERT_DOUBLE_EQ(d.z,3.0) << "full-empty z";
	
	// vol - vol
	Distance f{4,5,6};
	Distance g{1,2,3};
	f -= g;
 	ASSERT_DOUBLE_EQ(f.x,3.0) << "full-full x";
	ASSERT_DOUBLE_EQ(f.y,3.0) << "full-full y";
	ASSERT_DOUBLE_EQ(f.z,3.0) << "full-full z";
}
//==============================================================================================================		
/*		
bool Distance::operator> (const Distance& rhs) const;
		
bool Distance::operator< (const Distance& rhs) const;
*/
TEST(Distance, OutputStream) { 			//operator<<				// ZOIETS??????????????
	std::string s;
	Distance a{1,2,3};
	std::string t = s << a;
	ASSERT_EQ(t,"(1,2,3)") << "distance";
}
		
TEST(Distance, InputStream) { 			//operator>>				// ZOIETS??????????????
	Distance a;
	std::ifstream input("test.txt");
	a >> input;
	ASSERT_DOUBLE_EQ(a.x,1.0) << "x";
	ASSERT_DOUBLE_EQ(a.y,2.0) << "y";
	ASSERT_DOUBLE_EQ(a.z,3.0) << "z";
}
/*
//===============================================================================================
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}*/