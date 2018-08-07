/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <string>
#include <sstream>
#include "crypto/random.h"
#include "base/strings/string_util.h"

namespace brave_sync {

namespace tools {

std::string GenerateObjectId() {
  //16 random 8-bit unsigned numbers
  const size_t length = 16;
  uint8_t bytes[length];
  crypto::RandBytes(bytes, sizeof(bytes));
  std::stringstream ss;
  for (size_t i = 0; i < length; ++i) {
    const uint8_t &byte = bytes[i];
    ss << std::dec << (int)byte;
    if (i != length - 1) {
      ss << ", ";
    }
  }
  LOG(ERROR) << "TAGAB GenerateObjectId ss.str()="<<ss.str();
  return ss.str();
}

std::string replaceUnsupportedCharacters(const std::string &in) {
  std::string result;
  base::ReplaceChars(in, "\\", "\\\\", &result);
  base::ReplaceChars(result, "\"", "\\\"", &result);

  return result;
}

} // namespace tools

} // namespace brave_sync