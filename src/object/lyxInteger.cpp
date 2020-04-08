#include "object/lyxInteger.hpp"
#include <stdio.h>

LyxInteger::LyxInteger(int x) {
    _value = x;
}

void LyxInteger::print() {
    printf("%d", _value);
}

LyxObject* LyxInteger::add(LyxObject* x) {
    return new LyxInteger(_value + ((LyxInteger*)x)->_value);
}

