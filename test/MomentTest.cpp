#include "gtest/gtest.h"
#include "../source/include/Moment.hpp"
#include "../source/include/Duration.hpp"
#include <ctime> // For time test
#include <stdint.h>
#include <iostream>
using namespace std;
//using namespace adt;
Clock test_clock;
/**
   Moment Tests

*/
TEST(Moment,  Constructors) {
   Moment m1;
   EXPECT_EQ( m1.get_time(), 0 ) << "Default constructor, system time";

   double d = 10000;
   Moment m2 = test_clock.getMoment(d);
   
   EXPECT_EQ( m2.get_time(), d ) << "Given time value";
   d = -10000;
   try{
      Moment m3 = test_clock.getMoment(d);
      EXPECT_NE( m3.get_time(), d) << "Not negative";
   }catch(...) {
      //cout << "Error thrown and handled, throw working properly" << endl;
   }
}
TEST(Moment, AssignmentOperator)  {
   Moment m1;
   Moment m2;
   m1 = test_clock.getMoment(1000);
   m2 = test_clock.getMoment(1000);
   Moment m3;
   m1 = m2;
   EXPECT_EQ( m1.get_time(), m2.get_time()) << "Object Assignment failed, operation failed";
   EXPECT_EQ( m1.get_time(), 1000) << "Object Assignment failed, wrong object modified";
   EXPECT_NE( &m1, &m2) << "Object Assignment failed, pointer test failed";
   m3 = test_clock.getMoment(666);
   m1 = m2 = m3;
   EXPECT_EQ(m1.get_time(), m2.get_time()) << "Object Chaining failed";
   EXPECT_EQ(m2.get_time(), m3.get_time()) << "Object Chaining failed";
}

TEST(Moment , AddAndSubtract)  {
   Moment m1 = test_clock.getMoment(5000);
   Moment m2 = test_clock.getMoment(10000);
   Moment m3 = test_clock.getMoment(5000);
   Moment m4 = test_clock.getMoment(30);
   Moment m5 = test_clock.getMoment(10);
   Duration d1 = m4 - m5;
   intptr_t ptrValue = (intptr_t)&m3;
   double test = m1.get_time();

   m3 = m3 = m1 - d1 - d1;
   intptr_t ptrValue2 = (intptr_t)&m3;

   ASSERT_EQ(test - 40/*4960*/, m3.get_time()) << "Duration subtracted from Moment failed";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object does not remain the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, d2.get_seconds()) << "Moment subtracted from Moment failed";
}
TEST(Moment , AddAndSubtract2)  {
   Moment m1 = test_clock.getMoment (1000);
   Duration d1 = test_clock.getMoment (1000) - test_clock.getMoment (500);
   intptr_t ptrValue = (intptr_t)&m1;
   double testTime = m1.get_time();
   m1 += d1;
   intptr_t ptrValue2 = (intptr_t)&m1;
   ASSERT_EQ(d1.get_seconds() + testTime, m1.get_time()) << "+= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned not the same object";
   testTime = m1.get_time();
   m1 -= d1;
   ptrValue = (intptr_t)&m1;
   ASSERT_EQ(testTime - d1.get_seconds(), m1.get_time()) << "-= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "-= returned not the same object";
}
TEST(Moment,  StreamOperators) {
   Moment m1 = test_clock.getMoment(0);
   Moment m2 = test_clock.getMoment(0);
   stringstream ss;
   ss.str("500 1000");
   ss >> m1 >> m2;

   ASSERT_EQ(m1.get_time(), 500) << "First inputstream for Moment is incorrect";
   ASSERT_EQ(m2.get_time(), 1000) << "Second inputstream for Moment is incorrect";

   stringstream ss2;
   ss2 << m1 << " " << m2;

   double firstDouble, secondDouble;
   ss2 >> firstDouble >> secondDouble;
   
   ASSERT_EQ(m1.get_time(), firstDouble) << "First outputstream for Moment is incorrect";
   ASSERT_EQ(m2.get_time(), secondDouble) << "First outputstream for Moment is incorrect";
}
TEST(Moment, RelationalOperators)	{
	Moment m1 = test_clock.getMoment(500);
	Moment m2 = test_clock.getMoment(1000);
	ASSERT_EQ(m2 > m1, true) << "Greater than Comparison failed, should return true but did not";
	ASSERT_EQ(m1 > m2, false) << "Greater than Comparison failed, should return treu but did not";
	
	ASSERT_EQ(m1 < m2, true) << "Smaller than Comparison failed, should return true but did not";
	ASSERT_EQ(m2 < m1, false) << "Smaller than Comparison failed, should return false but did not";
}
TEST(Moment, ExceptionSafety)	{
	
	double d = -10000;
	try{
	  Moment m3 = test_clock.getMoment(d);
	  EXPECT_NE( m3.get_time(), d) << "Not negative";
	}catch(...) {
	  //cout << "Error thrown and handled, throw working properly" << endl;
	}
	Moment m1 = test_clock.getMoment(0);
	Moment m2 = test_clock.getMoment(0);
	stringstream ss;

	ss.str("test1 test2");
	try{
	   ss >> m1 >> m2;
	   ASSERT_EQ(m1.get_time(), 500) << "First inputstream for Moment is incorrect";
	   ASSERT_EQ(m2.get_time(), 1000) << "Second inputstream for Moment is incorrect";

	   stringstream ss2;
	   ss2 << m1 << " " << m2;

	   double firstDouble, secondDouble;
	   ss2 >> firstDouble >> secondDouble;

	   ASSERT_EQ(m1.get_time(), firstDouble) << "First outputstream for Moment is incorrect";
	   ASSERT_EQ(m2.get_time(), secondDouble) << "First outputstream for Moment is incorrect";
	}catch(...){
	   
	}
   
}