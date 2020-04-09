#include "runtime/universe.hpp"
#include "object/lyxInteger.hpp"
#include "object/lyxObject.hpp"

LyxInteger* Universe::LyxTrue = nullptr;
LyxInteger* Universe::LyxFalse = nullptr;

LyxObject* Universe::LyxNone = nullptr;

void Universe::genesis() {
    LyxTrue = new LyxInteger(1);
    LyxFalse = new LyxInteger(0);

    LyxNone = new LyxObject();
}

void Universe::destory() {
}