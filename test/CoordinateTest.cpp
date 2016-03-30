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


TEST(Coordinate, Construtor) {
   // TODO: Edit as the constructor should be private.
   Coordinate base (0.0, 0.0, 0.0);
   ASSERT_DOUBLE_EQ(0, base.getX());
   ASSERT_DOUBLE_EQ(0, base.getY());
   ASSERT_DOUBLE_EQ(0, base.getZ());

   Coordinate coord50 (50.0,50.0,50.0);
   ASSERT_DOUBLE_EQ(50, coord50.getX());
   ASSERT_DOUBLE_EQ(50, coord50.getY());
   ASSERT_DOUBLE_EQ(50, coord50.getZ());
}

TEST(Coordinate, Assignment) {
   auto value = Coordinate::origin;
   value = Coordinate::origin;
}

TEST(Coordinate, Addition) {
   auto value = Coordinate::origin;
   value + (Coordinate::origin - Coordinate::origin);
}

TEST(Coordinate, Subtraction) {

}

TEST(Coordinate, WriteTo) {
   std::stringstream stream{};
   stream << Coordinate::origin << std::endl;
   std::string output;
   std::getline(stream, output);
   EXPECT_EQ("coordinate (0m, 0m, 0m)", output);
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
      } catch (std::runtime_error) {
         // Behaves as expected.
         ASSERT_DOUBLE_EQ(15, coord.getX()) << "X value was modified despite the promise";
         ASSERT_DOUBLE_EQ(7.5, coord.getY()) << "Y value was modified despite the promise";
         ASSERT_DOUBLE_EQ(3.75, coord.getZ()) << "Z value was modified despite the promise";
         std::cerr << "" << std::endl;
      } catch (...) {
         FAIL() << "Wrong exception; was expecting [std::runtime_error]";
      }
   }

}
#endif //ADT_COORDINATETEST_H
