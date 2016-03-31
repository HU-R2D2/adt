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
   EXPECT_DOUBLE_EQ(0, c1.getX());
   EXPECT_DOUBLE_EQ(0, c1.getY());
   EXPECT_DOUBLE_EQ(0, c1.getY());
}

TEST(Coordinate, Addition) {
   Coordinate c1 = Coordinate::origin;
   Coordinate c2 = c1 + (Coordinate::origin - Coordinate::origin);
   EXPECT_DOUBLE_EQ(0, c1.getX());
   EXPECT_DOUBLE_EQ(0, c1.getY());
   EXPECT_DOUBLE_EQ(0, c1.getY());

   Distance d{0,0,0};
   const Coordinate * const coordPointer = &c1;

   ASSERT_EQ(coordPointer, &(c1 -= d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(0, c1.getX());
   EXPECT_DOUBLE_EQ(0, c1.getY());
   EXPECT_DOUBLE_EQ(0, c1.getY());
}

TEST(Coordinate, Subtraction) {
   Coordinate c1 = Coordinate::origin;
   Coordinate c2 = Coordinate::origin;
   Distance d = c1 - c2;
   EXPECT_DOUBLE_EQ(0, d.getX());
   EXPECT_DOUBLE_EQ(0, d.getY());
   EXPECT_DOUBLE_EQ(0, d.getZ());

   Coordinate c3 = c1 - d;
   EXPECT_DOUBLE_EQ(0, c3.getX());
   EXPECT_DOUBLE_EQ(0, c3.getY());
   EXPECT_DOUBLE_EQ(0, c3.getZ());

   const Coordinate * const coordPointer = &c1;

   ASSERT_EQ(coordPointer, &(c1 -= d)) << "Wrong reference returned.";
   EXPECT_DOUBLE_EQ(0, c1.getX());
   EXPECT_DOUBLE_EQ(0, c1.getY());
   EXPECT_DOUBLE_EQ(0, c1.getY());
}

TEST(Coordinate, WriteTo) {
   std::stringstream stream{};
   stream << Coordinate::origin << std::endl;
   std::string output;
   std::getline(stream, output);
   EXPECT_EQ("coordinate (0m, 0m, 0m)", output);
   EXPECT_EQ(&stream, &(stream << Coordinate::origin)) << "Wrong stream is returned.";
}

TEST(Coordinate, ReadFrom) {
   std::stringstream stream{};
   Coordinate coord = Coordinate::origin;
   const Coordinate * const originalPointer = &coord;

   stream << "coordinate (15m, 7.5m, 3.75m)";
   stream >> coord;
   ASSERT_DOUBLE_EQ(15, coord.getX());
   ASSERT_DOUBLE_EQ(7.5, coord.getY());
   ASSERT_DOUBLE_EQ(3.75, coord.getZ());
   ASSERT_EQ(originalPointer, &coord) << "A wrong reference is returned.";

   // A list of strings which should NOT be parsed.
   // In comments is listed what is wrong with the string.
   auto failures = {
         "coordinate(0m,0m,0m)",    // Space between "coordinate" and opening brace is missing.
         "coordinate (0, 0, 0)",    // Unit declarations are missing.
         "coordinate (0m, 0, 0)",   // Same as above, only for 1 value.
         "coordinate (0, 0m, 0)",   // Same as above.
         "coordinate (0, 0, 0m)",   // Same as above.
         "coordinate (0m, 0m, 0m]", // Wrong closing brace.
         "coordinate [0m, 0m, 0m)", // Wrong opening brace.
         "coordinate [0m, 0m, 0m]", // Wrong opening and closing brace.
         "coord (0m, 0m, 0m)"       // Incomplete indication of type; should be "coordinate".
   };
   for (auto failure : failures) {
      try {
         std::stringstream stream{failure};
         stream >> coord;
         FAIL() << "Parsing \"" << failure << "\" to a coordinate should not be possible." << std::endl;
      } catch (std::runtime_error & e) {
         // Behaves as expected.
         ASSERT_DOUBLE_EQ(15, coord.getX()) << "X value was modified despite the promise";
         ASSERT_DOUBLE_EQ(7.5, coord.getY()) << "Y value was modified despite the promise";
         ASSERT_DOUBLE_EQ(3.75, coord.getZ()) << "Z value was modified despite the promise";
         //std::cerr << e.what() << std::endl;
      } catch (...) {
         FAIL() << "Wrong exception; was expecting [std::runtime_error]";
      }
   }

}
#endif //ADT_COORDINATETEST_H