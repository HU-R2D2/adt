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
   EXPECT_EQ( m1.getSeconds(), 0 ) << "Default constructor, system time";

   double d = 10000;
   Moment m2 = test_clock.getMoment(d);
   
   EXPECT_EQ( m2.getSeconds(), d ) << "Given time value";
   d = -10000;
   try{
      Moment m3 = test_clock.getMoment(d);
      EXPECT_NE( m3.getSeconds(), d) << "Not negative";
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
   EXPECT_EQ( m1.getSeconds(), m2.getSeconds()) << "Object Assignment failed, operation failed";
   EXPECT_EQ( m1.getSeconds(), 1000) << "Object Assignment failed, wrong object modified";
   EXPECT_NE( &m1, &m2) << "Object Assignment failed, pointer test failed";
   m3 = test_clock.getMoment(666);
   m1 = m2 = m3;
   EXPECT_EQ(m1.getSeconds(), m2.getSeconds()) << "Object Chaining failed";
   EXPECT_EQ(m2.getSeconds(), m3.getSeconds()) << "Object Chaining failed";
}

TEST(Moment , AddAndSubtract)  {
   Moment m1 = test_clock.getMoment(5000);
   Moment m2 = test_clock.getMoment(10000);
   Moment m3 = test_clock.getMoment(5000);
   Moment m4 = test_clock.getMoment(30);
   Moment m5 = test_clock.getMoment(10);
   Duration d1 = m4 - m5;
   intptr_t ptrValue = (intptr_t)&m3;
   double test = m1.getSeconds();

   m3 = m3 = m1 - d1 - d1;
   intptr_t ptrValue2 = (intptr_t)&m3;

   ASSERT_EQ(test - 40/*4960*/, m3.getSeconds()) << "Duration subtracted from Moment failed";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object does not remain the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, d2.get_seconds()) << "Moment subtracted from Moment failed";
}
TEST(Moment , AddAndSubtract2)  {
   Moment m1 = test_clock.getMoment (1000);
   Duration d1 = test_clock.getMoment (1000) - test_clock.getMoment (500);
   intptr_t ptrValue = (intptr_t)&m1;
   double testTime = m1.getSeconds();
   m1 += d1;
   intptr_t ptrValue2 = (intptr_t)&m1;
   ASSERT_EQ(d1.get_seconds() + testTime, m1.getSeconds()) << "+= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned not the same object";
   testTime = m1.getSeconds();
   m1 -= d1;
   ptrValue = (intptr_t)&m1;
   ASSERT_EQ(testTime - d1.get_seconds(), m1.getSeconds()) << "-= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "-= returned not the same object";
}
TEST(Moment,  StreamOperators) {
   Moment m1 = test_clock.getMoment(0);
   Moment m2 = test_clock.getMoment(0);
   double testValue;
   stringstream ss;

   ss.str("500 1000");
   ss >> m1 >> m2;

   ASSERT_EQ(m1.getSeconds(), 500) << "First inputstream for Moment is incorrect";
   ASSERT_EQ(m2.getSeconds(), 1000) << "Second inputstream for Moment is incorrect";

   stringstream ss2;
   ss2 << m1 << " " << m2;

   double firstDouble, secondDouble;
   ss2 >> firstDouble >> secondDouble;

   ASSERT_EQ(m1.getSeconds(), firstDouble) << "First outputstream for Moment is incorrect";
   ASSERT_EQ(m2.getSeconds(), secondDouble) << "First outputstream for Moment is incorrect";
}

//DateTime Tests
/*TEST(Enums, DateTime)   {
   ASSERT_EQ(1, (int)MONTH::JANUARY ) << "Month January does not equal 1";
}
TEST( Constructors, DateTime ) {
   const int year = 1900;
   const int mday = 1;
   const MONTH month = JANUARY;
   const int hour = 0;
   const int minute = 0;
   const int second = 0;
   int year2 = 1800 + 0 * 50;
   // ToDo check if test is completely useless or not
   for(int i = 1; i < 5; i++)   {
      year2 = 1800 + i * 50;
      DATETIME payday(year2, i * 2,  (MONTH)((int)MONTH::JANUARY + i), 2 + hour * i, minute + 2 * i, second + 3 * i);
      //proto_datetime testStruct(year2, i * 2, (MONTH)((int)MONTH::JANUARY + i), 0 + hour * i, minute + 2 * i, second + 3 * i);

      ASSERT_EQ(payday.getMonth(), MONTH::JANUARY + i) << "Month does not equal ctor month";
      ASSERT_EQ((int)payday.getYear(), year2 ) << "Year does not equal ctor year";
      ASSERT_EQ((int)payday.getMonthDay(), i * 2 ) << "Monthday does not equal ctor Monthday";
      ASSERT_EQ((int)payday.getHour(), 2 + hour * i ) << "Hour does not equal ctor Hour";
      ASSERT_EQ((int)payday.getMinute(), minute + 2 * i ) << "Minute does not equal ctor Minute";
      ASSERT_EQ((int)payday.getSecond(), second + 3 * i ) << "Second does not equal ctor Second";
   }
   // Check boundaries (such as month 13 and day 32)
   {
      int j, o;
      try{
         
         for(j = 0; j < 3; j++)   {   // Months
            for(o = 0; o < 5; o++)   { // Days
                  DATETIME(2100, o + 29, (MONTH)(j + 11), 66, 66, 66);
            }
         }
      }
      catch (...){
               cout << "Datetime has thrown an exception, month is" << (j + 11) << " and month day is " << o + 29 << endl;
      }
   }
   // Check non-leap year and february 29
   try{
      DATETIME(2015, 29, MONTH::FEBRUARY, 12, 12, 12);
   }catch(...) {
      cout << "Non leap year has thrown an exception" << endl;
   }
   // Check leap year and february 29
   DATETIME legit(2016, 29, MONTH::FEBRUARY, 12, 12, 12);
   ASSERT_EQ(legit.getMonth(), MONTH::FEBRUARY) << "Month in leap-year does not equal ctor month";
   ASSERT_EQ((int)legit.getYear(), 2016 ) << "Leap-year Year does not equal ctor year";
   ASSERT_EQ((int)legit.getMonthDay(), 29) << "Leap-year Monthday does not equal ctor Monthday";
}
void assertAllDateTimeData(DATETIME dt, DATETIME dt2)   {
   ASSERT_EQ( dt.getMonth(),   dt2.getMonth() )     << "Month does not equal ctor month";
   ASSERT_EQ( dt.getYear(),    dt2.getYear() )      << "Year does not equal ctor year";
   ASSERT_EQ( dt.getMonthDay(),dt2.getMonthDay() )  << "Monthday does not equal ctor Monthday";
   ASSERT_EQ( dt.getHour(),    dt2.getHour() )      << "Hour does not equal ctor Hour";
   ASSERT_EQ( dt.getMinute(),  dt2.getMinute() )    << "Minute does not equal ctor Minute";
   ASSERT_EQ( dt.getSecond(),  dt2.getSecond() )    << "Second does not equal ctor Second";
}
TEST(Assignment_Operator, DateTime) {
   DATETIME dt1(2016, 29, MONTH::FEBRUARY, 12, 12, 12);
   DATETIME dt2(2014, 16, MONTH::JANUARY, 5, 6, 7);
   intptr_t ptrdt1 = (intptr_t)&dt1;
   intptr_t ptrdt2 = (intptr_t)&dt2;
   dt1 = dt2;
   ASSERT_NE( &dt1, &dt2 )     << "Same Object, invalid operator (Objects should be different)";
   ASSERT_EQ( (intptr_t)&dt1, ptrdt1 )   << "dt1 Ptr has changed!";
   ASSERT_EQ( (intptr_t)&dt2, ptrdt2 )   << "dt2 Ptr has changed!";
   assertAllDateTimeData(dt1, dt2);
}
TEST( Addition_and_subtraction, DateTime)  {
   DATETIME dt1(2016, 29, MONTH::FEBRUARY, 12, 12, 12);
   Duration dt2(5000);
   //DATETIME - dt2;
}
/*void assertAllDateTimeData(DATETIME dt, uint16_t year, uint8_t mday, MONTH month, 
      uint8_t hour = 0, uint8_t minute = 0, uint8_t second = 0)   {
   ASSERT_EQ( dt.getMonth(),   month )     << "Month does not equal ctor month";
   ASSERT_EQ( dt.getYear(),    year )      << "Year does not equal ctor year";
   ASSERT_EQ( dt.getMonthDay(),Monthday )  << "Monthday does not equal ctor Monthday";
   ASSERT_EQ( dt.getHour(),    hour )      << "Hour does not equal ctor Hour";
   ASSERT_EQ( dt.getMinute(),  minute )      << "Minute does not equal ctor Minute";
   ASSERT_EQ( dt.getSecond(),  second )    << "Second does not equal ctor Second";
}*/

/*int main( int argc, char **argv ){	      

   std::cout << "testing Moment" << "\n";
   //DATETIME mydatetime(time(0));
   //DATETIME(DAY::TUESDAY, MONTH::JANUARY, 23, 2000, 5, 5, 5);
   testing::InitGoogleTest( &argc, argv );
   int result = RUN_ALL_TESTS();
   (void) result;
   while(true);
}*/