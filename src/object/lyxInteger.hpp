#ifndef _LYX_INTEGER_HPP
#define _LYX_INTEGER_HPP

#include "lyxObject.hpp"

class LyxInteger : public LyxObject {
private:
  int _value;

public:
  LyxInteger(int x);
  int value() { return _value; }
};

#endif