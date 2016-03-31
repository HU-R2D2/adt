#include "gtest/gtest.h"
#include "../source/include/Length.hpp"
#include <iostream>

// constructors:
TEST(Constructor, Default) {
	Length a;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "length";
}

TEST(Length, doubleConstructor) {
	Length a(2);
	ASSERT_DOUBLE_EQ(a/Length::METER , 2) << "length";
}
//==============================================================================================
// operatoren:
TEST(Length, AssignLength){   					//operator=
	Length a;
	a = 2 * Length::METER;
	ASSERT_DOUBLE_EQ(a/Length::METER , 2) << "empty l";
}

TEST(Length, AddLength) { 						//operator+
	// leeg + leeg
	Length a = 0 * Length::METER;
	Length b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0.0) << "empty+empty";
	
	// leeg + vol
	Length c = 2 * Length::METER;
	b = b + c;
	ASSERT_DOUBLE_EQ(b/Length::METER , 2.0) << "empty+full";
	
	// vol + vol
	Length d = 3 * Length::METER;
	d = d + c;
 	ASSERT_DOUBLE_EQ(d/Length::METER , 5.0) << "full+full";
}


TEST(Length, SubstractLength) { 				//operator-
	// leeg - leeg
	Length a{};
	Length b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0.0) << "empty-empty";
	
	// leeg - vol
	Length c = 2 * Length::METER;
	b = b - c;
	ASSERT_DOUBLE_EQ(b/Length::METER , -2.0) << "empty-full";
	
	// vol - leeg
	c = c - a;
	ASSERT_DOUBLE_EQ(c/Length::METER , 2.0) << "full-empty";
	
	// vol - vol
	Length d = 1 * Length::METER;
	d = d - c;
 	ASSERT_DOUBLE_EQ(d/Length::METER , -1.0) << "full-full neg";
	Length e= 3 * Length::METER;
	Length f= 2 * Length::METER;
	e = e - f;
 	ASSERT_DOUBLE_EQ(e/Length::METER , 1.0) << "full-full";
}

TEST(Length, MultiplyDouble) { 						//operator* 1
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty*0 Length";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty Length";
		
	// vol * 0
	Length b =1 * Length::METER;
	b = b * 0;
	ASSERT_DOUBLE_EQ(b/Length::METER , 0) << "full*0 Length";
		
	// vol * getal1
	Length c =2 * Length::METER;
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c/Length::METER , 4) << "full*getal1 Length";
	
	// vol * getal2
	Length d =3  * Length::METER;
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d/Length::METER , 7.5) << "full * getal2 Length";

}

/*TEST(Length, MultiplyLength) { 						//operator* 2
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Length a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty*0 Length";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty Length";
		
	// vol * 0
	Length b(1);
	b = b * 0;
	ASSERT_DOUBLE_EQ(b/Length::METER , 0) << "full*0 Length";
		
	// vol * getal1
	Length c(2);
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c/Length::METER , 4) << "full*getal1 Length";
	
	// vol * getal2
	Length d(3);
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d/Length::METER , 7.5) << "full * getal2 Length";
DIT is all bij vorige test gedaan
}*/

TEST(Length, DivideDouble) { 					//operator/
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Length a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty / 0 Length";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty x";
	
	// vol / 0
	Length b = 1 * Length::METER;
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b/Length::METER , 1) << "full / 0 Length";
	
	// vol / getal1
	Length c = 1 * Length::METER;
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c/Length::METER , 0.5) << "full / getal1 Length";
	
	// vol / getal2
	Length d =1 * Length::METER;
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d/Length::METER , 0.4) << "full / getal2 Length ";
	
}

TEST(Length, AddAssignLength) {					//operator+=
	// leeg + leeg
	Length a;
	Length b;
	a += b;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty+empty";
	
	// leeg + vol
	Length c = 2  * Length::METER;
	b += c;
	ASSERT_DOUBLE_EQ(b/Length::METER , 2) << "empty+full";
	
	// vol + vol
	Length d = 3 * Length::METER;
	d += c;
 	ASSERT_DOUBLE_EQ(d/Length::METER , 5) << "full+full"; 
}

TEST(Length, SubtractAssignLength) { 			//operator-=
	// leeg - leeg
	Length a;
	Length b;
	a -= b;
	ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty-empty";
	
	// leeg - vol
	Length c = 2  * Length::METER;
	b -= c;
	ASSERT_DOUBLE_EQ(b/Length::METER , -2) << "empty-full";
	
	// vol - leeg
	c -= a;
	ASSERT_DOUBLE_EQ(c/Length::METER , 2) << "full-empty";
	
	// vol - vol
	Length d = 1 * Length::METER;
	d -= c;
 	ASSERT_DOUBLE_EQ(d/Length::METER , -1) << "full-full neg";
	Length e = 5 * Length::METER;
	Length f = 3 * Length::METER;
	e -= f;
	ASSERT_DOUBLE_EQ(e/Length::METER , 2) << "full-full";
}	

