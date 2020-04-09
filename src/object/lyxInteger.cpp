#include "object/lyxInteger.hpp"
#include "runtime/universe.hpp"
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
        return Universe::LyxTrue;
    else
        return Universe::LyxFalse;
}

LyxObject* LyxInteger::less(LyxObject* x) {
    if (_value < ((LyxInteger*)x)->_value)
        return Universe::LyxTrue;
    else
        return Universe::LyxFalse;
}

LyxObject* LyxInteger::equal(LyxObject* x) {
    if (_value == ((LyxInteger*)x)->_value)
        return Universe::LyxTrue;
    else 
        return Universe::LyxFalse;
}

LyxObject* LyxInteger::not_equal(LyxObject* x) {
    if (_value != ((LyxInteger*)x)->_value)
        return Universe::LyxTrue;
    else 
        return Universe::LyxFalse;
}

LyxObject* LyxInteger::greater_equal(LyxObject* x) {
    if (_value >= ((LyxInteger*)x)->_value)
        return Universe::LyxTrue;
    else 
        return Universe::LyxFalse;
}

LyxObject* LyxInteger::less_equal(LyxObject* x) {
    if (_value <= ((LyxInteger*)x)->_value)
        return Universe::LyxTrue;
    else 
        return Universe::LyxFalse;
}

