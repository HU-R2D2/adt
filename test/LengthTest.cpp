#include "gtest/gtest.h"
#include "../source/include/Length.hpp"
#include <iostream>

// constructors:
TEST(Length, DefaultConstructor) {
	Length a;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "length";
}

TEST(Length, doubleConstructor) {
	Length a(2);
	ASSERT_DOUBLE_EQ(a.getLength() , 2) << "length";
}
//==============================================================================================
// operatoren:
TEST(Length, AssignLength){   					//operator=
	Length a;
	a = Length(1);
	ASSERT_DOUBLE_EQ(a.getLength() , 1) << "empty l";
}

TEST(Length, AddLength) { 						//operator+
	// leeg + leeg
	Length a;
	Length b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a.getLength() , 0.0) << "empty+empty";
	
	// leeg + vol
	Length c(2);
	b = b + c;
	ASSERT_DOUBLE_EQ(b.getLength() , 2.0) << "empty+full";
	
	// vol + vol
	Length d(3);
	d = d + c;
 	ASSERT_DOUBLE_EQ(d.getLength() , 5.0) << "full+full";
}


TEST(Length, SubstractLength) { 				//operator-
	// leeg - leeg
	Length a;
	Length b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a.getLength() , 0.0) << "empty+empty";
	
	// leeg - vol
	Length c(2);
	b = b - c;
	ASSERT_DOUBLE_EQ(b.getLength() , 0.0) << "empty+full";
	
	// vol - leeg
	c = c - b;
	ASSERT_DOUBLE_EQ(c.getLength() , 2.0) << "empty+full";
	
	// vol - vol
	Length d(1);
	d = d - c;
 	ASSERT_DOUBLE_EQ(d.getLength() , 0.0) << "full+full neg";
	Length e(3);
	Length f(2);
	e = e - f;
 	ASSERT_DOUBLE_EQ(e.getLength() , 1.0) << "full+full";
}

TEST(Length, MultiplyDouble) { 						//operator* 1
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty*0 Length";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty Length";
		
	// vol * 0
	Length b(1);
	b = b * 0;
	ASSERT_DOUBLE_EQ(b.getLength() , 0) << "full*0 Length";
		
	// vol * getal1
	Length c(2);
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c.getLength() , 4) << "full*getal1 Length";
	
	// vol * getal2
	Length d(3);
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d.getLength() , 7.5) << "full * getal2 Length";

}

TEST(Length, MultiplyLength) { 						//operator* 2
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty*0 Length";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty Length";
		
	// vol * 0
	Length b(1);
	b = b * 0;
	ASSERT_DOUBLE_EQ(b.getLength() , 0) << "full*0 Length";
		
	// vol * getal1
	Length c(2);
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c.getLength() , 4) << "full*getal1 Length";
	
	// vol * getal2
	Length d(3);
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d.getLength() , 7.5) << "full * getal2 Length";

}

TEST(Length, SubstractDouble) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Length a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty / 0 Length";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty x";
	
	// vol / 0
	Length b(1);
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b.getLength() , 1) << "full / 0 Length";
	
	// vol / getal1
	Length c(1);
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c.getLength() , 0.5) << "full / getal1 Length";
	
	// vol / getal2
	Length d(1);
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d.getLength() , 0.4) << "full / getal2 Length ";
	
}

TEST(Length, AddAssignLength) {					//operator+=
	// leeg + leeg
	Length a;
	Length b;
	a += b;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty+empty";
	
	// leeg + vol
	Length c(2);
	b += c;
	ASSERT_DOUBLE_EQ(b.getLength() , 2) << "empty+full";
	
	// vol + vol
	Length d(3);
	d += c;
 	ASSERT_DOUBLE_EQ(d.getLength() , 5) << "full+full"; 
}

TEST(Length, SubtractAssignLength) { 			//operator-=
	// leeg - leeg
	Length a;
	Length b;
	a -= b;
	ASSERT_DOUBLE_EQ(a.getLength() , 0) << "empty-empty";
	
	// leeg - vol
	Length c(2);
	b -= c;
	ASSERT_DOUBLE_EQ(b.getLength() , 0) << "empty-full";
	
	// vol - leeg
	c -= b;
	ASSERT_DOUBLE_EQ(c.getLength() , 2) << "full-empty";
	
	// vol - vol
	Length d(1);
	d -= c;
 	ASSERT_DOUBLE_EQ(d.getLength() , 0) << "full-full neg";
	Length e(5);
	Length f(3);
	e -= f;
	ASSERT_DOUBLE_EQ(e.getLength() , 2) << "full-full";
}