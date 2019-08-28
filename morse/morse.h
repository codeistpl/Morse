#pragma once
#include "morse_global.h"
#include <string>

namespace morse {
std::string encode(const std::string &literal);
std::string decode(const std::string &code);
}; // namespace morse
