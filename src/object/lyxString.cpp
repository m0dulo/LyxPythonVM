#include "object/lyxString.hpp"
#include <string.h>

LyxString::LyxString(const char* x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
}

LyxString::LyxString(const char *x, const int length) {
    _length = length;
    _value = new char[_length];

    for (int i = 0; i < length; ++i) {
        _value[i] = x[i];
    }
}