//! \file morse.h is a main interface header for morse parsing library

#pragma once
#include <string>

namespace morse {
/*!
 * \brief encode
 * \param literal is a latin letters only text that will be encoded into mors
 * code
 *
 * \return mors code
 *
 * \details Morse-coded text consist only of '.', '-' and
 * ' ' (space) characters single space character is used to separate characters
 * in a word, two space characters are used to separate words there is no
 * difference between upper- and lower-case letters characters that don't exist
 * in Morse alphabet are skipped
 */
std::string encode(const std::string &literal);

/*!
 * \brief decode
 * \param code
 * \return decoded uppercase text.
 */
std::string decode(const std::string &code);
}; // namespace morse
