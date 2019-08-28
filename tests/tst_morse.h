#ifndef TST_MORSE_H
#define TST_MORSE_H

#include "../morse/morse.h"
#include <algorithm>
#include <cctype>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(morse, empty_string) {
  auto code = morse::encode("");
  EXPECT_TRUE(code.empty());
}

TEST(morse, single_char) {
  auto aCode = morse::encode("a");
  auto ACode = morse::encode("A");
  EXPECT_EQ(aCode, ".-");
  EXPECT_EQ(ACode, ".-");

  EXPECT_STREQ("A", morse::decode(aCode).c_str());
  EXPECT_STREQ("A", morse::decode(ACode).c_str());
}

TEST(morse, sos) {
  auto code = morse::encode("sos");
  EXPECT_STREQ("... --- ...", code.c_str());
  auto literal = morse::decode(code);
  EXPECT_STREQ("SOS", literal.c_str());
}

TEST(morse, double_word) {
  auto code = morse::encode("som sos");
  EXPECT_STREQ("... --- --  ... --- ...", code.c_str());
  auto literal = morse::decode(code);
  EXPECT_STREQ("SOM SOS", literal.c_str());
}

TEST(morse, lorem_ipsum) {
  std::string lorem =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin nibh "
      "augue, suscipit a, scelerisque sed, lacinia in, mi. Cras vel lorem. "
      "Etiam pellentesque aliquet tellus. Phasellus pharetra nulla ac diam. "
      "Quisque semper justo at risus. Donec venenatis, turpis vel hendrerit "
      "interdum, dui ligula ultricies purus, sed posuere libero dui id orci. "
      "Nam congue, pede vitae dapibus aliquet, elit magna vulputate arcu, vel "
      "tempus metus leo non est. Etiam sit amet lectus quis est congue mollis. "
      "Phasellus congue lacus eget neque. Phasellus ornare, ante vitae "
      "consectetuer consequat, purus sapien ultricies dolor, et mollis pede "
      "metus eget nisi. Praesent sodales velit quis augue. Cras suscipit, urna "
      "at aliquam rhoncus, urna quam viverra nisi, in interdum massa nibh nec "
      "erat.";

  auto code = morse::encode(lorem);
  auto decodedLorem = morse::decode(code);
  EXPECT_EQ(lorem.size(), decodedLorem.size());

  EXPECT_TRUE(
      std::equal(lorem.begin(), lorem.end(), decodedLorem.begin(),
                 [](char a, char b) { return toupper(a) == toupper(b); }));
}
#endif // TST_MORSE_H
