#ifndef _LYX_STRING_HPP
#define _LYX_STRING_HPP

#include "lyxObject.hpp"

class LyxString : public LyxObject {
private:
  char *_value;
  int _length;

public:
  LyxString(const char *x);
  LyxString(const char *x, const int length);

  const char *value() { return _value; }
  int length() { return _length; }
};

#endif