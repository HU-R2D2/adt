#include "gtest/gtest.h"
#include "Length.hpp"

// constructors:
TEST(Constructor, Default) {
	Length a;
	ASSERT_EQ(a.l , 0) << "length";
}

TEST(Constructor, double) {
	Length a{2};
	ASSERT_EQ(a.l,1) << "length";
}
//==============================================================================================
// operatoren:
TEST( Assign, Length ){   				//operator=
	Length a;
	a = Distance{1,2,3};
	
	ASSERT_EQ(a.x,1) << "empty x";
	ASSERT_EQ(a.y,2) << "empty y";
	ASSERT_EQ(a.z,3) << "empty z";
	
	a = Distance{4,5,6};
	ASSERT_EQ(a.x,4) << "new x";
	ASSERT_EQ(a.y,5) << "new y";
	ASSERT_EQ(a.z,6) << "new z";  
}


TEST(Add, Distance) { 						//operator+
	// leeg + leeg
	Distance a;
	Distance b;
	a = a + b;
	ASSERT_EQ(a.x,0) << "empty+empty x";
	ASSERT_EQ(a.y,0) << "empty+empty y";
	ASSERT_EQ(a.z,0) << "empty+empty z";
	
	// leeg + vol
	Distance c{1,2,3};
	b = b + c;
	ASSERT_EQ(b.x,1) << "empty+full x";
	ASSERT_EQ(b.y,2) << "empty+full y";
	ASSERT_EQ(b.z,3) << "empty+full z";
	
	// vol + vol
	Distance d{1,2,3};
	Distance e{4,5,6};
	d = d + e;
 	ASSERT_EQ(d.x,5) << "full+full x";
	ASSERT_EQ(d.y,7) << "full+full y";
	ASSERT_EQ(d.z,9) << "full+full z";
}


TEST(Subtract, Distance) { 					//operator-
	// leeg - leeg
	Distance a;
	Distance b;
	a = a - b;
	ASSERT_EQ(a.x,0) << "empty-empty x";
	ASSERT_EQ(a.y,0) << "empty-empty y";
	ASSERT_EQ(a.z,0) << "empty-empty z";
	
	// leeg - vol
	Distance c{1,2,3};
	b = b - c;
	ASSERT_EQ(b.x,-1) << "empty-full x";
	ASSERT_EQ(b.y,-2) << "empty-full y";
	ASSERT_EQ(b.z,-3) << "empty-full z";
	
	// vol - leeg
	Distance d{1,2,3};
	Distance e;
	d = d - e;
	ASSERT_EQ(d.x,1) << "full-empty x";
	ASSERT_EQ(d.y,2) << "full-empty y";
	ASSERT_EQ(d.z,3) << "full-empty z";
	
	// vol - vol
	Distance f{4,5,6};
	Distance g{1,2,3};
	f = f - g;
 	ASSERT_EQ(f.x,3) << "full-full x";
	ASSERT_EQ(f.y,3) << "full-full y";
	ASSERT_EQ(f.z,3) << "full-full z";
}


TEST(Multiply, double) { 					//operator*
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Distance a;
	a = a * 0;
	ASSERT_EQ(a.x,0) << "empty*0 x";
	ASSERT_EQ(a.y,0) << "empty*0 y";
	ASSERT_EQ(a.z,0) << "empty*0 z";
	
	// leeg * getal1
	a = a * getal1
	ASSERT_EQ(a.x,0) << "empty x";
	ASSERT_EQ(a.y,0) << "empty y";
	ASSERT_EQ(a.z,0) << "empty z";
	
	// vol * 0
	Distance b{1,2,3}
	b = b * 0;
	ASSERT_EQ(b.x,0) << "full*0 x";
	ASSERT_EQ(b.y,0) << "full*0 y";
	ASSERT_EQ(b.z,0) << "full*0 z";
	
	// vol * getal1
	Distance c{1,2,3}
	c = c * getal1;
	ASSERT_EQ(c.x,2) << "full*getal1 x";
	ASSERT_EQ(c.y,4) << "full*getal1 y";
	ASSERT_EQ(c.z,6) << "full*getal1 z";
	
	// vol * getal2
	Distance d{1,2,3}
	d = d * getal2;
	ASSERT_EQ(d.x,2.5) << "full*getal2 x";
	ASSERT_EQ(d.y,5) << "full*getal2 y";
	ASSERT_EQ(d.z,7.5) << "full*getal2 z";
}


TEST(Distract, double) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Distance a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(a.x,0) << "empty/0 x";
	ASSERT_EQ(a.y,0) << "empty/0 y";
	ASSERT_EQ(a.z,0) << "empty/0 z";
	
	// leeg / getal1
	a = a / getal1
	ASSERT_EQ(a.x,0) << "empty x";
	ASSERT_EQ(a.y,0) << "empty y";
	ASSERT_EQ(a.z,0) << "empty z";
	
	// vol / 0
	Distance b{1,2,3}
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(b.x,0) << "full/0 x";
	ASSERT_EQ(b.y,0) << "full/0 y";
	ASSERT_EQ(b.z,0) << "full/0 z";
	
	// vol / getal1
	Distance c{1,2,3}
	c = c / getal1;
	ASSERT_EQ(c.x,0.5) << "full/getal1 x";
	ASSERT_EQ(c.y,1) << "full/getal1 y";
	ASSERT_EQ(c.z,1.5) << "full/getal1 z";
	
	// vol / getal2
	Distance d{1,2,3}
	d = d / getal2;
	ASSERT_EQ(d.x,0.4) << "full/getal2 x";
	ASSERT_EQ(d.y,0.8) << "full/getal2 y";
	ASSERT_EQ(d.z,1.2) << "full/getal2 z";
}


TEST(AddAssign, Distance) {					//operator+=
	//leeg + leeg
	Distance a;
	Distance b;
	a += b;
	ASSERT_EQ(a.x,0) << "empty+empty x";
	ASSERT_EQ(a.y,0) << "empty+empty y";
	ASSERT_EQ(a.z,0) << "empty+empty z";
	
	
	// leeg + vol
	Distance c{1,2,3};
	b += c;
	ASSERT_EQ(b.x,1) << "empty+full x";
	ASSERT_EQ(b.y,2) << "empty+full y";
	ASSERT_EQ(b.z,3) << "empty+full z";
	
	// vol + vol
	Distance d{1,2,3};
	Distance e{4,5,6};
	d += e;
 	ASSERT_EQ(d.x,5) << "full+full x";
	ASSERT_EQ(d.y,7) << "full+full y";
	ASSERT_EQ(d.z,9) << "full+full z"; 
}


TEST(SubtractAssign, Distance) { 			//operator-=
	// leeg - leeg
	Distance a;
	Distance b;
	a -= b;
	ASSERT_EQ(a.x,0) << "empty-empty x";
	ASSERT_EQ(a.y,0) << "empty-empty y";
	ASSERT_EQ(a.z,0) << "empty-empty z";
	
	// leeg - vol
	Distance c{1,2,3};
	b -= c;
	ASSERT_EQ(b.x,-1) << "empty-full x";
	ASSERT_EQ(b.y,-2) << "empty-full y";
	ASSERT_EQ(b.z,-3) << "empty-full z";
	
	// vol - leeg
	Distance d{1,2,3};
	Distance e;
	d -= e;
	ASSERT_EQ(d.x,1) << "full-empty x";
	ASSERT_EQ(d.y,2) << "full-empty y";
	ASSERT_EQ(d.z,3) << "full-empty z";
	
	// vol - vol
	Distance f{4,5,6};
	Distance g{1,2,3};
	f -= g;
 	ASSERT_EQ(f.x,3) << "full-full x";
	ASSERT_EQ(f.y,3) << "full-full y";
	ASSERT_EQ(f.z,3) << "full-full z";
}
		

TEST(Equal, char) {
    string20 a{};
    string20 b{};
    ASSERT_EQ(a,b) << "empty";

    string20 c{'a'};
    string20 d{'a'};
    ASSERT_EQ(c,d) << "1char";
}
		
		
bool Distance::operator> (const Distance& rhs) const;
		
bool Distance::operator< (const Distance& rhs) const;
		
ostream& Distance::operator<< (ostream& os, const Distance& rhs) const;
		
istream& Distance::operator>>( istream& is, Distance& rhs)

//===============================================================================================


//===============================================================================================
TEST(Equal, char) {
    string20 a{};
    string20 b{};
    ASSERT_EQ(a,b) << "empty";

    string20 c{'a'};
    string20 d{'a'};
    ASSERT_EQ(c,d) << "1char";
}

//===============================================================================================
int main( int argc, char **argv ){	      

   string20bug = 10;  
   
   std::cout << "testing string20bug = " << string20bug << "\n";

   testing::InitGoogleTest( &argc, argv );
   int result = RUN_ALL_TESTS();
   (void) result;
}

