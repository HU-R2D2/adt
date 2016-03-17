#include <iostream>
#include "gtest/gtest.h"



TEST (Box, Constructors)
{
	std::cout << "This is a test";

	ASSERT_EQ(1, 1); // this test will pass

	ASSERT_EQ(1, 2); // this test will fail


}