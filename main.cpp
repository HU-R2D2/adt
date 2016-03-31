#include "bmptk.h"
#include "gtest/gtest.h"
#include "string20.hpp"
#include "Datetime.hpp"
#include "Moment.hpp"
#include "Duration.hpp" // temp dummy object

#include <ctime> // For time test
#include <stdint.h>
#include <iostream>
using namespace std;
using namespace adt;

/**
   Moment Tests

*/
TEST( Constructors, Default ) {
   /* These tests could fail on SLOW PERFORMANCE computers, please take note! */
   Moment m1;
   time_t t = time(0);   // get time now
   EXPECT_EQ( m1.seconds, t ) << "Default constructor, system time";

   double d = 10000;
   time_t t2 = time(0);
   Moment m2(d);
   
   EXPECT_EQ( m2.seconds, d + t2 ) << "Given time value";
   d = -10000;
   Moment m3(d);
   time_t t3 = time(0);
   EXPECT_NE( m2.seconds, t3 + d) << "Not negative";
}
TEST( Assignment_Operator, Moment )  {
   Moment m1;
   Moment m2;
   m2.seconds = 1000;
   Moment m3;
   m1 = m2;
   EXPECT_EQ( m1.seconds, m2.seconds) << "Object Assignment failed";
   EXPECT_EQ( m1.seconds, 1000) << "Object Assignment failed";
   EXPECT_NE( &m1, &m2) << "Object Assignment failed";
   m3.seconds = 666;
   m1 = m2 = m3;
   EXPECT_EQ(m1.seconds, m2.seconds) << "Object Chaining failed";
   EXPECT_EQ(m2.seconds, m3.seconds) << "Object Chaining failed";
}

TEST( ADD_AND_SUBTRACT, Moment)  {
   Moment m1(5000);
   Moment m2(10000);
   Moment m3(5000);
   Duration d1(20);
   intptr_t ptrValue = (intptr_t)&m3;
   double test = m1.seconds;

   m3 = m3 = m1 - d1 - d1;
   intptr_t ptrValue2 = (intptr_t)&m3;

   ASSERT_EQ(test - 40/*4960*/, m3.seconds) << "Duration subtracted from Moment failed";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object does not remain the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, d2.seconds) << "Moment subtracted from Moment failed";
}
TEST( ADD_AND_SUBTRACT_SAME_OBJECT, Moment)  {
   Moment m1(1000);
   Duration d1(500);
   intptr_t ptrValue = (intptr_t)&m1;
   double testTime = m1.seconds;
   m1 += d1;
   intptr_t ptrValue2 = (intptr_t)&m1;
   ASSERT_EQ(d1.seconds + testTime, m1.seconds) << "+= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned not the same object";
   testTime = m1.seconds;
   m1 -= d1;
   ptrValue = (intptr_t)&m1;
   ASSERT_EQ(testTime - d1.seconds, m1.seconds) << "-= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "-= returned not the same object";
}
TEST( STREAM_OPERATORS, Streams ) {
   Moment m1(0);
   Moment m2(0);
   double testValue;
   stringstream ss;

   ss.str("500 1000");
   ss >> m1 >> m2;

   ASSERT_EQ(m1.seconds, 500) << "First inputstream for Moment is incorrect";
   ASSERT_EQ(m2.seconds, 1000) << "Second inputstream for Moment is incorrect";

   stringstream ss2;
   ss2 << m1 << " " << m2;

   double firstDouble, secondDouble;
   ss2 >> firstDouble >> secondDouble;

   ASSERT_EQ(m1.seconds, firstDouble) << "First outputstream for Moment is incorrect";
   ASSERT_EQ(m2.seconds, secondDouble) << "First outputstream for Moment is incorrect";
}
int main( int argc, char **argv ){	      

   std::cout << "testing Moment" << "\n";
   DATETIME mydatetime(time(0));
   testing::InitGoogleTest( &argc, argv );
   int result = RUN_ALL_TESTS();
   (void) result;
   while(true);
}