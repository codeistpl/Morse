#include "morse.h"
#include <algorithm>
#include <cctype>
#include <map>

static std::map<char, std::string> map = {
    {'A', ".-"},     {'B', "-..."},   {'C', "-.-."},  {'D', "-.."},
    {'E', "."},      {'F', "..-."},   {'G', "--."},   {'H', "...."},
    {'I', ".."},     {'J', ".---"},   {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},     {'N', "-."},     {'O', "---"},   {'P', ".--."},
    {'Q', "--.-"},   {'R', ".-."},    {'S', "..."},   {'T', "-"},
    {'U', "..-"},    {'V', "...-"},   {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},   {'Z', "--.."},   {'1', ".----"}, {'2', "..---"},
    {'3', "...--"},  {'4', "....-"},  {'5', "....."}, {'6', "-...."},
    {'7', "--..."},  {'8', "---.."},  {'9', "----."}, {'0', "-----"},
    {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}};

char toChar(const std::string &code) {
  auto found = std::find_if(map.begin(), map.end(),
                            [&code](const std::pair<char, std::string> &pair) {
                              return pair.second == code;
                            });
  if (found != map.end()) {
    return found->first;
  } else {
    return 0x0;
  }
}

std::string morse::encode(const std::string &literal) {
  std::string code;
  bool begining = true;
  for (const char &c : literal) {
    if (!begining) {
      code.append(" ");
    } else {
      begining = false;
    }
    if (!isupper(c))
      code.append(map[static_cast<char>(toupper(c))]);
    else
      code.append(map[c]);
  }
  return code;
}

std::string morse::decode(const std::string &code) {
  std::string literal;
  std::size_t curr = 0, prev = 0;

  while (curr != std::string::npos) {
    curr = code.find(' ', prev);

    auto characterCode = code.substr(prev, curr - prev);
    auto character = toChar(characterCode);
    if (character != 0x0) {
      literal.push_back(character);
    }
    if (code.at(curr + 1) == ' ') {
      literal.append(" ");
      prev = curr + 2;
    } else {
      prev = curr + 1;
    }
  }
  return literal;
}
