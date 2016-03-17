#include <limits.h>
#include "gtest/gtest.h"

class SampleTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};


TEST(Sample,Sample)
{
	EXPECT_EQ(1,1);
}

TEST(Sample,SampleFail)
{
	EXPECT_EQ(1,0);
}