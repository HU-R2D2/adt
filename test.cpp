#include "gtest/gtest.h"
#include "Length.hpp"

// constructors:

TEST(Constructor, Default) {
	Length a;
	ASSERT_EQ(a.length, 0) << "length";
}

TEST(Constructor, double) {
	Length a{2};
	ASSERT_EQ(a.length,1) << "length";
}

//==============================================================================================
// operatoren:

TEST( Assign, Length ){   				//operator=
	Length a;
	a = Length{1};
	
	ASSERT_EQ(a.length,1) << "empty length";
	
	a = Length{4};
	ASSERT_EQ(a.length,4) << "new length"; 
}


TEST(Add, Length) { 						//operator+
	// leeg + leeg
	Length a;
	Length b;
	a = a + b;
	ASSERT_EQ(a.length,0) << "empty+empty length";
	
	// leeg + vol
	Length c{1};
	b = b + c;
	ASSERT_EQ(b.length,1) << "empty+full length";
	
	// vol + vol
	Length d{1};
	Length e{4};
	d = d + e;
 	ASSERT_EQ(d.length,5) << "full+full length";
}


TEST(Subtract, Length) { 					//operator-
	// leeg - leeg
	Length a;
	Length b;
	a = a - b;
	ASSERT_EQ(a.length,0) << "empty-empty length";
	
	// leeg - vol
	Distance c{1};
	b = b - c;
	ASSERT_EQ(b.length,-1) << "empty-full length";
	
	// vol - leeg
	Length d{1};
	Length e;
	d = d - e;
	ASSERT_EQ(d.length,1) << "full-empty length";
	
	// vol - vol
	Length f{4};
	Length g{1};
	f = f - g;
 	ASSERT_EQ(f.length,3) << "full-full length";
}


TEST(Multiply, double) { 					//operator*
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_EQ(a.length,0) << "empty*0 length";
	
	// leeg * getal1
	a = a * getal1
	ASSERT_EQ(a.length,0) << "empty length";
	
	// vol * 0
	Length b{1}
	b = b * 0;
	ASSERT_EQ(b.length,0) << "full*0 length";
	
	// vol * getal1
	Length c{1}
	c = c * getal1;
	ASSERT_EQ(c.length,2) << "full*getal1 length";
	
	// vol * getal2
	Length d{1}
	d = d * getal2;
	ASSERT_EQ(d.length,2.5) << "full*getal2 length";
}


TEST(Length, double) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Length a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(a.length,0) << "empty/0 length";
	
	// leeg / getal1
	a = a / getal1
	ASSERT_EQ(a.length,0) << "empty length";
	
	// vol / 0
	Distance b{1,2,3}
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_EQ(b.length,0) << "full/0 length";
	
	// vol / getal1
	Distance c{1,2,3}
	c = c / getal1;
	ASSERT_EQ(c.length,0.5) << "full/getal1 length";
	
	// vol / getal2
	Distance d{1,2,3}
	d = d / getal2;
	ASSERT_EQ(d.length,0.4) << "full/getal2 length";
}


TEST(AddAssign, Length) {					//operator+=
	//leeg + leeg
	Length a;
	Length b;
	a += b;
	ASSERT_EQ(a.length,0) << "empty+empty length";
	
	
	// leeg + vol
	Length c{1};
	b += c;
	ASSERT_EQ(b.length,1) << "empty+full length";
	
	// vol + vol
	Length d{1};
	Length e{4};
	d += e;
 	ASSERT_EQ(d.length,5) << "full+full length";
}


TEST(SubtractAssign, Length) { 			//operator-=
	// leeg - leeg
	Length a;
	Length b;
	a -= b;
	ASSERT_EQ(a.length,0) << "empty-empty length";
	
	// leeg - vol
	Length c{1};
	b -= c;
	ASSERT_EQ(b.length,-1) << "empty-full length";
	
	// vol - leeg
	Length d{1};
	Length e;
	d -= e;
	ASSERT_EQ(d.length,1) << "full-empty length";
	
	// vol - vol
	Length f{4};
	Length g{1};
	f -= g;
 	ASSERT_EQ(f.length,3) << "full-full length";
}
				
		
bool Length::operator> (const Length& rhs) const;
		
bool Length::operator< (const Length& rhs) const;
		
ostream& Length::operator<< (ostream& os, const Length& rhs) const;
		
istream& Length::operator>>( istream& is, Length& rhs)


//===============================================================================================
int main( int argc, char **argv ){	      

   string20bug = 10;  
   
   std::cout << "testing string20bug = " << string20bug << "\n";

   testing::InitGoogleTest( &argc, argv );
   int result = RUN_ALL_TESTS();
   (void) result;
}

