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
   Coordinate base (0.0,0.0,0.0);
   ASSERT_DOUBLE_EQ(base.getX(), 0.0);
   ASSERT_DOUBLE_EQ(base.getY(), 0.0);
   ASSERT_DOUBLE_EQ(base.getZ(), 0.0);

   Coordinate coord50 (50.0,50.0,50.0);
   ASSERT_DOUBLE_EQ(coord50.getX(), 50.0);
   ASSERT_DOUBLE_EQ(coord50.getY(), 50.0);
   ASSERT_DOUBLE_EQ(coord50.getZ(), 50.0);
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
   auto coord = Coordinate::origin;
   stream << "coordinate (40.43m, 83m, 2.98m)";
   stream >> coord;
}
#endif //ADT_COORDINATETEST_H
