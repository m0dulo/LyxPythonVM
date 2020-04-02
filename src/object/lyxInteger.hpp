#ifndef LYX_INTEGER_HPP_
#define LYX_INTEGER_HPP_

#include "object/lyxObject.hpp"

class LyxInteger : public LyxObject {
private:
    int _value;
public:
    LyxInteger(int x);
    int value() const {return _value;}
};

#endif // LYX_INTEGER_HPP_