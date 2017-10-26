// File: convert.h
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class BadConversion : public std::runtime_error {
public:
  BadConversion(const std::string& s)
    : std::runtime_error(s)
    { }
};

inline float convertToDouble(const std::string& s,
                              bool failIfLeftoverChars = true)
{
  std::istringstream i(s);
  float x;
  char c;
  if (!(i >> x) || (failIfLeftoverChars && i.get(c)))
    throw BadConversion("convertToFloat(\"" + s + "\")");
  return x;
}
