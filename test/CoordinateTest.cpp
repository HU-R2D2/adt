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
   Coordinate c2 = Coordinate::origin;
   c1 = c2;
   EXPECT_DOUBLE_EQ(0, c1.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
}

TEST(Coordinate, Addition) {
   Coordinate c1 = Coordinate::origin;
   Coordinate c2 = c1 + (Coordinate::origin - Coordinate::origin);
   EXPECT_DOUBLE_EQ(0, c1.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);

   Distance d{0,0,0};
   const Coordinate * const coordPointer = &c1;

   ASSERT_EQ(coordPointer, &(c1 -= d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(0, c1.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
}

TEST(Coordinate, Subtraction) {
   Coordinate c1 = Coordinate::origin;
   Coordinate c2 = Coordinate::origin;
   Distance d = c1 - c2;
   EXPECT_DOUBLE_EQ(0, d.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, d.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, d.getZ() / Length::METER);

   Coordinate c3 = c1 - d;
   EXPECT_DOUBLE_EQ(0, c3.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c3.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c3.getZ() / Length::METER);

   const Coordinate * const coordPointer = &c1;

   ASSERT_EQ(coordPointer, &(c1 -= d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(0, c1.getX() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
   EXPECT_DOUBLE_EQ(0, c1.getY() / Length::METER);
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
   stream >> coord;
   ASSERT_DOUBLE_EQ(15, coord.getX() / Length::METER);
   ASSERT_DOUBLE_EQ(7.5, coord.getY() / Length::METER);
   ASSERT_DOUBLE_EQ(3.75, coord.getZ() / Length::METER);
   ASSERT_EQ(originalPointer, &coord) << "A wrong reference is returned.";

   // A list of strings which should NOT be parsed.
   // In comments is listed what is wrong with the string.
   auto failures = {
         "coordinate(0,0,0)",    // Space between "coordinate" and opening brace is missing.
         "coordinate (0, 0, 0]", // Wrong closing brace.
         "coordinate [0, 0, 0)", // Wrong opening brace.
         "coordinate [0, 0, 0]", // Wrong opening and closing brace.
         "coord (0, 0, 0)"       // Incomplete indication of type; should be "coordinate".
   };
   for (auto failure : failures) {
      try {
         std::stringstream stream{failure};
         stream >> coord;
         FAIL() << "Parsing \"" << failure << "\" to a coordinate should not be possible." << std::endl;
      } catch (std::runtime_error & e) {
         // Behaves as expected.
         ASSERT_DOUBLE_EQ(15, coord.getX() / Length::METER) << "X value was modified despite the promise";
         ASSERT_DOUBLE_EQ(7.5, coord.getY() / Length::METER) << "Y value was modified despite the promise";
         ASSERT_DOUBLE_EQ(3.75, coord.getZ() / Length::METER) << "Z value was modified despite the promise";
         //std::cerr << e.what() << std::endl;
      } catch (...) {
         FAIL() << "Wrong exception; was expecting [std::runtime_error]";
      }
   }

}
#endif //ADT_COORDINATETEST_H
