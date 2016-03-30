#include "bmptk.h"
#include "gtest/gtest.h"
#include "string20.hpp"
#include "Moment.hpp"
#include "Duration.hpp" // temp dummy object
#include <ctime> // For time test
#include <stdint.h>
#include <iostream>
using namespace std;
int len( const char * s ){
   return ( *s == '\0' ) ? 0 : 1 + len( s + 1 );
}

bool equal( const string20 & lhs, const char *rhs ){
   EXPECT_EQ( lhs.length(), len( rhs ) ) << "length";
   if( lhs.length() != len( rhs )) return false;
   for( int i = 0; i < lhs.length(); ++i ){
      EXPECT_EQ( lhs[ i ], rhs[ i ] ) << "content @ " << i ;
      if( lhs[ i ] != rhs[ i ] ) return false;
   }
   return true;
}
/*TEST( Constructors, Default ){
   string20 e;
   ASSERT_EQ( e.length(), 0 ) << "length";   
}

TEST( Constructors, Char ){      
   string20 c{ 'x' };
   ASSERT_EQ( c.length(), 1 ) << "length";   
   ASSERT_EQ( c[ 0 ], 'x' ) << "[0]";   
}

TEST( Assign, string ){      
   string20 s{};
   s = "";  
   ASSERT_TRUE( equal( s, "" )) << "empty";   
   s = "x";  
   ASSERT_TRUE( equal( s, "x" )) << "1char";   
   
   s = "01234567890123456789";
   ASSERT_TRUE( equal( s, "01234567890123456789" )) << "20char";  

   s = "012345678901234567890";
   ASSERT_TRUE( equal( s, "01234567890123456789" )) << "21char";  
   
   ASSERT_TRUE( equal( s = "abc", "abc" )) << "retval";     
   ASSERT_TRUE( equal( ( s = "abc" ) = "fgh", "fgh" )) << "retval assign";     
}*/
/**
   Moment Tests

*/
TEST( Constructors, Default ) {
   Moment m1;
   time_t t = time(0);   // get time now
   //double dt = t;
   EXPECT_EQ( m1.seconds, t ) << "Default constructor, system time";

   double d = 10000;
   Moment m2(d);
   EXPECT_EQ( m2.seconds, d ) << "Given time value";
   d = -10000;
   Moment m3(d);
   EXPECT_NE( m2.seconds, d ) << "Not negative";
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
   //Moment* test = &m3;
   m3 = m3 = m1 - d1 - d1;
   intptr_t ptrValue2 = (intptr_t)&m3;
   ASSERT_EQ(4960, m3.seconds) << "Duration subtracted from Moment failed";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object does not remain the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, m1.seconds) << "Moment subtracted from Moment failed";
   /*Duration d1(20);
   
   EXPECT_EQ( m3.seconds, m1.seconds - d1.seconds) << "Substracting and assigning substraction";
   //d1(bigger than moment);
   m3 = m1 - d1;
   EXPECT_EQ( m3.seconds, m1.seconds - d1.seconds) << "Substracting duration bigger than given moment";
   m3();
   uintptr_t objPtrValue = &m3;
   m3 = m1 - d1;*/
/*   uintptr_t objPtrValue = &m3;
   EXPECT_EQ(objPtrValue, &m3) << "Object remains the same object";*/

}
TEST( ADD_AND_SUBTRACT_SAME_OBJECT, Moment)  {
   Moment m1(1000);
   Duration d1(500);
   intptr_t ptrValue = (intptr_t)&m1;
   m1 += d1;
   intptr_t ptrValue2 = (intptr_t)&m1;
   ASSERT_EQ(1500, m1.seconds) << "+= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned not the same object";

   m1 -= d1;
   ptrValue = (intptr_t)&m1;
   ASSERT_EQ(1000, m1.seconds) << "-= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "-= returned not the same object";
}
TEST( STREAM_OPERATORS, Streams) {
   Moment m1(0);
   Moment m2(0);
   double testValue;
   stringstream ss;

   ss.str("500 1000");
   ss >> m1 >> m2;
   cout << m1 << ", " << m2 << endl;

   ASSERT_EQ(m1.seconds, 500) << "First inputstream for Moment is incorrect";
   ASSERT_EQ(m2.seconds, 1000) << "Second inputstream for Moment is incorrect";

   stringstream ss2;
   ss2 << m1 << " " << m2;
   cout << m1 << ", " << m2 << endl;
   cout << "stringstream here is" << ss2.str() << ", " << ss2.str() << endl;
   double firstDouble, secondDouble;
   ss2 >> firstDouble >> secondDouble;
   cout << "Double values after input" << firstDouble << "," << secondDouble << endl;

   ASSERT_EQ(m1.seconds, firstDouble) << "First outputstream for Moment is incorrect";
   ASSERT_EQ(m2.seconds, secondDouble) << "First outputstream for Moment is incorrect";
}
int main( int argc, char **argv ){	      

   string20bug = 0;  

   std::cout << "testing Moment" << "\n";

   testing::InitGoogleTest( &argc, argv );
   int result = RUN_ALL_TESTS();
   (void) result;
   /*
      Moment Tests
    */
   for(;;){
      bmptk::wait( 1 * bmptk::s );
   }
}