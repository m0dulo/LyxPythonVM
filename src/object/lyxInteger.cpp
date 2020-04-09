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

LyxObject* LyxInteger::greater(LyxObject* x) {
    if (_value > ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else
        return new LyxInteger(0);
}

LyxObject* LyxInteger::less(LyxObject* x) {
    if (_value < ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else
        return new LyxInteger(0);
}

LyxObject* LyxInteger::equal(LyxObject* x) {
    if (_value == ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else 
        return new LyxInteger(0);
}

LyxObject* LyxInteger::not_equal(LyxObject* x) {
    if (_value != ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else 
        return new LyxInteger(0);
}

LyxObject* LyxInteger::greater_equal(LyxObject* x) {
    if (_value >= ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else 
        return new LyxInteger(0);
}

LyxObject* LyxInteger::less_equal(LyxObject* x) {
    if (_value <= ((LyxInteger*)x)->_value)
        return new LyxInteger(1);
    else 
        return new LyxInteger(0);
}

