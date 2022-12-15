#include "lyxString.hpp"
#include <string.h>

HiString::HiString(const char *x) {
  _length = strlen(x);
  _value = new char[_length];
  strcpy(_value, x);
}

HiString::HiString(const char *x, const int length) {
  _length = length;
  _value = new char[length];

  // do not use strcpy here, since '\0' is allowed.
  for (int i = 0; i < length; i++) {
    _value[i] = x[i];
  }
}