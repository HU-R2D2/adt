#include "gtest/gtest.h"
#include "../source/include/Duration.hpp"
#include <iostream>

// constructors:
TEST(Duration, DefaultConstructor) {
	Duration a;
	ASSERT_DOUBLE_EQ(a.get_seconds() , 0.0) << "seconds";
}

TEST(Duration, ConstructorDouble) {
	Duration a(2);
	ASSERT_DOUBLE_EQ(a.get_seconds() , 2.0) << "seconds";
}
//==============================================================================================
// operatoren:
TEST( Duration, AssignDuration ){   				//operator=
	Duration a;
	a = Duration(1);
	
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 1.0) << "empty seconds";
	
	a = Duration(4);
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 4.0) << "new seconds"; 
}

TEST(Duration, AddDuration) { 						//operator+
	// leeg + leeg
	Duration a;
	Duration b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty+empty seconds";
	
	// leeg + vol
	Duration c(1);
	b = b + c;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "empty+full seconds";
	
	// vol + vol
	Duration d(1);
	Duration e(4);
	d = d + e;
 	ASSERT_DOUBLE_EQ(d.get_seconds()  , 5.0) << "full+full seconds";
}

TEST(Duration, SubstractDuration) { 					//operator-
	// leeg - leeg
	Duration a;
	Duration b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty-empty seconds";
	
	// leeg - vol
	Duration c(1);
	b = b - c;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , -1.0) << "empty-full seconds";
	
	// vol - leeg
	Duration d(1);
	Duration e;
	d = d - e;
	ASSERT_DOUBLE_EQ(d.get_seconds()  , 1.0) << "full-empty seconds";
	
	// vol - vol
	Duration f(4);
	Duration g(1);
	f = f - g;
 	ASSERT_DOUBLE_EQ(f.get_seconds()  , 3.0) << "full-full seconds";
}

TEST(Duration, MultiplyDurationDouble) { 					//operator* (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Duration a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty*0 seconds";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty*getal1 seconds";
	
	// vol * 0
	Duration b(1);
	b = b * 0;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , 0.0) << "full*0 seconds";
	
	// vol * getal1
	Duration c(1);
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c.get_seconds()  , 2.0) << "full*getal1 seconds";
	
	// vol * getal2
	Duration d(1);
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d.get_seconds()  , 2.5) << "full*getal2 seconds";
}

TEST(Duration, MultiplyDoubleDuration) { 					//operator* (2)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// 0 * leeg
	Duration a;
	a = 0 * a;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "0*empty seconds";
	
	// getal1 * leeg
	a = getal1 * a;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "getal1*empty seconds";
	
	// 0 * vol
	Duration b(1);
	b = 0 * b;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , 0.0) << "0*full seconds";
	
	// getal1 * vol
	Duration c(1);
	c = getal1 * c;
	ASSERT_DOUBLE_EQ(c.get_seconds()  , 2.0) << "getal1*full seconds";
	
	// getal2 * vol
	Duration d(1);
	d = getal2 * d;
	ASSERT_DOUBLE_EQ(d.get_seconds()  , 2.5) << "getal2*full seconds";
}

TEST(Duration, DivideDurationDouble) { 					//operator/ (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Duration a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty/0 seconds";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty/getal1 seconds";
	
	// vol / 0
	Duration b(1);
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "full/0 seconds";
	
	// vol / getal1
	Duration c(1);
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c.get_seconds()  , 0.5) << "full/getal1 seconds";
	
	// vol / getal2
	Duration d(1);
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d.get_seconds()  , 0.4) << "full/getal2 seconds";
}



	/*	friend Speed operator/ (const Length & l, const Duration & d);
		friend Length operator*(const Duration & lhs, const Speed & rhs); */







TEST(Duration, AddAssignDuration) {					//operator+=
	//leeg + leeg
	Duration a;
	Duration b;
	a += b;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty+empty seconds";
	
	// leeg + vol
	Duration c(1);
	b += c;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "empty+full seconds";
	
	// vol + vol
	Duration d(1);
	Duration e(4);
	d += e;
 	ASSERT_DOUBLE_EQ(d.get_seconds()  , 5.0) << "full+full seconds"; 
}

TEST(Duration, SubstractAssignDuration) { 			//operator-=
	// leeg - leeg
	Duration a;
	Duration b;
	a -= b;
	ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty-empty seconds";
	
	// leeg - vol
	Duration c(1);
	b -= c;
	ASSERT_DOUBLE_EQ(b.get_seconds()  , -1.0) << "empty-full seconds";
	
	// vol - leeg
	Duration d(1);
	Duration e;
	d -= e;
	ASSERT_DOUBLE_EQ(d.get_seconds()  , 1.0) << "full-empty seconds";
	
	// vol - vol
	Duration f(4);
	Duration g(1);
	f -= g;
 	ASSERT_DOUBLE_EQ(f.get_seconds()  , 3.0) << "full-full seconds";
}

TEST(Duration, GreaterThan) { 				//operator>
	Duration a(2);
	Duration b(1);
	ASSERT_TRUE(a > b) << "greater than";
	ASSERT_FALSE(b > a) << "less than";
}

TEST(Duration, LessThan) { 					//operator<
	Duration a(1);
	Duration b(2);
	ASSERT_TRUE(a < b) << "less than";
	ASSERT_FALSE(b < a) << "greater than";
}

TEST(Duration, OutputStream) { 				//operator<<
	Duration a(1);
	std::stringstream stream{};
	stream << a << std::endl;
	std::string output;
	std::getline(stream, output);
	EXPECT_EQ("1s", output);
}

TEST(Duration, ReadFrom) {					//operator>>
	std::stringstream stream{};
	Duration d;
	const Duration * const originalPointer = &d;

	stream << "Duration 15s";
	stream >> d;
	ASSERT_DOUBLE_EQ(15, d.get_seconds());
	ASSERT_EQ(originalPointer, &d) << "A wrong reference is returned.";
}