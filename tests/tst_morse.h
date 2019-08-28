#ifndef TST_MORSE_H
#define TST_MORSE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(morse, dummy)
{
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

#endif // TST_MORSE_H
