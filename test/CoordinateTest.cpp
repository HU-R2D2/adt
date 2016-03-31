//
// Created by Matthijs on 29-3-2016.
//

#ifndef ADT_COORDINATETEST_H
#define ADT_COORDINATETEST_H

#include <limits.h>
#include "gtest/gtest.h"
#include "../source/include/Coordinate.hpp"
#include "../source/include/Distance.hpp"
#include <string>
#include <sstream>


TEST(Coordinate, Assignment) {
   Coordinate c1 = Coordinate::origin;
   Coordinate c2 = Coordinate::origin + Distance{1 * Length::METER, 2 * Length::METER, 3 * Length::METER};
   c1 = c2;
   EXPECT_DOUBLE_EQ(1, c1.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(2, c1.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(3, c1.get_z() / Length::METER);

   Coordinate c3 = Coordinate::origin + Distance{-1 * Length::METER, -2 * Length::METER, -3 * Length::METER};
   c1 = c3;
   EXPECT_DOUBLE_EQ(-1, c1.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(-2, c1.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(-3, c1.get_z() / Length::METER);
}

TEST(Coordinate, Addition) {
   Coordinate c1 = Coordinate::origin + Distance{2 * Length::METER, 4 * Length::METER, 8 * Length::METER};
   EXPECT_DOUBLE_EQ(2, c1.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(4, c1.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(8, c1.get_z() / Length::METER);

   Coordinate c2 = Coordinate::origin + Distance{-2 * Length::METER, -4 * Length::METER, -8 * Length::METER};
   EXPECT_DOUBLE_EQ(-2, c2.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(-4, c2.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(-8, c2.get_z() / Length::METER);

   Coordinate c3 = c2 + Distance{4 * Length::METER, 6 * Length::METER, 0 * Length::METER};
   EXPECT_DOUBLE_EQ(2, c3.get_x()/Length::METER);
   EXPECT_DOUBLE_EQ(2, c3.get_y()/Length::METER);
   EXPECT_DOUBLE_EQ(-8, c3.get_z()/Length::METER);
   Distance d{3 * Length::METER, -7 * Length::METER, 13 * Length::METER};

   const Coordinate * const coordPointer = &c3;

   ASSERT_EQ(coordPointer, &(c3 += d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(5, c3.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(-5, c3.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(5, c3.get_z() / Length::METER);
}

TEST(Coordinate, Subtraction) {
   Coordinate c1 = Coordinate::origin - Distance{2 * Length::METER, 4 * Length::METER, 8 * Length::METER};
   EXPECT_DOUBLE_EQ(-2, c1.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(-4, c1.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(-8, c1.get_z() / Length::METER);

   Coordinate c2 = Coordinate::origin - Distance{-2 * Length::METER, -4 * Length::METER, -8 * Length::METER};
   EXPECT_DOUBLE_EQ(2, c2.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(4, c2.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(8, c2.get_z() / Length::METER);

   Coordinate c3 = c2 - Distance{4 * Length::METER, 6 * Length::METER, 0 * Length::METER};
   EXPECT_DOUBLE_EQ(-2, c3.get_x()/Length::METER);
   EXPECT_DOUBLE_EQ(-2, c3.get_y()/Length::METER);
   EXPECT_DOUBLE_EQ(8, c3.get_z()/Length::METER);
   Distance d{3 * Length::METER, -7 * Length::METER, 13 * Length::METER};

   const Coordinate * const coordPointer = &c3;

   ASSERT_EQ(coordPointer, &(c3 -= d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(-5, c3.get_x() / Length::METER);
   EXPECT_DOUBLE_EQ(5, c3.get_y() / Length::METER);
   EXPECT_DOUBLE_EQ(-5, c3.get_z() / Length::METER);
}

TEST(Coordinate, WriteTo) {
   std::stringstream stream{};
   stream << Coordinate::origin << std::endl;
   std::string output;
   std::getline(stream, output);
   EXPECT_EQ("coordinate (0, 0, 0)", output);
   EXPECT_EQ(&stream, &(stream << Coordinate::origin)) << "Wrong stream is returned.";
}

TEST(Coordinate, ReadFrom) {
   std::stringstream stream{};
   Coordinate coord = Coordinate::origin;
   const Coordinate * const originalPointer = &coord;

   stream << "coordinate (15, 7.5, 3.75)";
   try { stream >> coord;}catch(std::exception & e){ std::cerr << e.what() << std::endl; }
   ASSERT_DOUBLE_EQ(15, coord.get_x() / Length::METER);
   ASSERT_DOUBLE_EQ(7.5, coord.get_y() / Length::METER);
   ASSERT_DOUBLE_EQ(3.75, coord.get_z() / Length::METER);
   ASSERT_EQ(originalPointer, &coord) << "A wrong reference is returned.";

   // A list of strings which should NOT be parsed.
   // In comments is listed what is wrong with the string.
   auto failures = {
         "coordinate(0,0,0)",    // Space between "coordinate" and opening brace is missing.
         "coordinate (0, 0, 0]", // Wrong closing brace.
         "coordinate [0, 0, 0)", // Wrong opening brace.
         "coordinate [0, 0, 0]", // Wrong opening and closing brace.
         "coordinate (0; 0, 0)", // Wrong separator.
         "coordinate (0, 0 0)",  // Missing separator.
         "coord (0, 0, 0)"       // Incomplete indication of type; should be "coordinate".
   };
   for (auto failure : failures) {
      try {
         std::stringstream stream{failure};
         stream >> coord;
         FAIL() << "Parsing \"" << failure << "\" to a coordinate should not be possible." << std::endl;
      } catch (std::runtime_error & e) {
         // Behaves as expected.
         ASSERT_DOUBLE_EQ(15, coord.get_x() / Length::METER) << "X value was modified despite the promise";
         ASSERT_DOUBLE_EQ(7.5, coord.get_y() / Length::METER) << "Y value was modified despite the promise";
         ASSERT_DOUBLE_EQ(3.75, coord.get_z() / Length::METER) << "Z value was modified despite the promise";
         //std::cerr << e.what() << std::endl;
      } catch (...) {
         FAIL() << "Wrong exception; was expecting [std::runtime_error]";
      }
   }

}
#endif //ADT_COORDINATETEST_H
