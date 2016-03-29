#include "bmptk.h"
#include "gtest/gtest.h"
#include "string20.hpp"
#include "Moment.hpp"
#include "Duration.hpp" // temp dummy object
#include <ctime> // For time test
#include <stdint.h>
#
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
   EXPECT_EQ( m1.seconds, m2.seconds) << "Object Assignment";
   EXPECT_EQ( m1.seconds, 1000) << "Object Assignment";
   EXPECT_NE( &m1, &m2) << "Object Assignment";
   m3.seconds = 666;
   m1 = m2 = m3;
   EXPECT_EQ(m1.seconds, m2.seconds) << "Object Chaining";
   EXPECT_EQ(m2.seconds, m3.seconds) << "Object Chaining";
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
   ASSERT_EQ(4960, m3.seconds) << "Duration subtracted from Moment";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object remains the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, m1.seconds) << "Moment subtracted from Moment";
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
   intptr_t ptrValue = &m1;
   m1 += d1;
   intptr_t ptrValue2 = &m1;
   ASSERT_EQ(1500, m1.duration) << "+= returns correct value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned same object";

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