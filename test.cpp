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
	a = Length{1};
	
	ASSERT_EQ(a.l,1) << "empty l";
}


TEST(Add, Length) { 						//operator+
	// leeg + leeg
	Length a;
	double b = 0;
	a = a + b;
	ASSERT_EQ(a.l,0) << "int empty + empty Length";
	
	// leeg + vol
	Length c{1};
	b = b + c;
	ASSERT_EQ(b.l,1) << "int empty + full Length";
	
	Length c{1};
	c = c + b;
	ASSERT_EQ(b.l,1) << "length empty + full int";
	
	// vol + vol
	length d{1};
	double e = 4;
	d = d + e;
 	ASSERT_EQ(d.l,5) << "length full + full double";
}


TEST(Subtract, Length) { 					//operator-
	// leeg - leeg
	Length a;
	double b = 0;
	a = a - b;
	ASSERT_EQ(a.l,0) << "length empty-empty double";
	
	// leeg - vol
	Length c{1};
	c = c - b;
	ASSERT_EQ(c.l,1) << "double empty-full Length";

	
	// vol - vol
	Length f{4};
	double g = 1;
	f = f - g;
 	ASSERT_EQ(f.l,3) << "Lnegth full-full double";
}


TEST(Multiply, double) { 					//operator*
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_EQ(a.l,0) << "empty*0 Length";
	
	// leeg * getal1
	a = a * getal1
	ASSERT_EQ(a.x,0) << "empty Length";
		
	// vol * 0
	Length b{1}
	b = b * 0;
	ASSERT_EQ(b.l,0) << "full*0 Length";
		
	// vol * getal1
	Length c{1}
	c = c * getal1;
	ASSERT_EQ(c.l,2) << "full*getal1 Length";
	
	// vol * getal2
	Length d{1}
	d = d * getal2;
	ASSERT_EQ(d.l,2.5) << "full * getal2 Length";

}


TEST(suptract, double) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Length a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(a.l,0) << "empty / 0 Length";
	
	// leeg / getal1
	a = a / getal1
	ASSERT_EQ(a.l,0) << "empty x";
	
	// vol / 0
	Length b{1,2,3}
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(b.l,0) << "full / 0 Length";
	
	// vol / getal1
	Length c{1}
	c = c / getal1;
	ASSERT_EQ(c.l,0.5) << "full / getal1 Length";
	
	// vol / getal2
	Distance d{1}
	d = d / getal2;
	ASSERT_EQ(d.l,0.4) << "full / getal2 Length ";
	
}


TEST(AddAssign, Length) {					//operator+=
	// leeg + leeg
	Length a;
	double b = 0;
	a += b;
	ASSERT_EQ(a.l,0) << "int empty + empty Length";
	
	// leeg + vol
	Length c{1};
	b += c;
	ASSERT_EQ(b.l,1) << "int empty + full Length";
	
	Length c{1};
	c += b;
	ASSERT_EQ(b.l,1) << "length empty + full int";
	
	// vol + vol
	length d{1};
	double e = 4;
	d += e;
 	ASSERT_EQ(d.l,5) << "length full + full double"; 
}


TEST(SubtractAssign, Length) { 			//operator-=
	// leeg - leeg
	Length a;
	double b = 0;
	a -= b;
	ASSERT_EQ(a.l,0) << "length empty-empty double";
	
	// leeg - vol
	Length c{1};
	c -= b;
	ASSERT_EQ(c.l,1) << "length empty-full double";

	
	// vol - vol
	Length f{4};
	double g = 1;
	f -= g;
 	ASSERT_EQ(f.l,3) << "length full-full double";
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

