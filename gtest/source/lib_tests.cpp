#include <gtest/gtest.h>

#include "lib.h"

TEST(LibTest, AddTests) {
  EXPECT_EQ(10, add(5,5));
  EXPECT_EQ(101, add(102,-1));
  EXPECT_EQ(0, add(0,0));
}
