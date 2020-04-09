#ifndef LYX_INTEGER_HPP_
#define LYX_INTEGER_HPP_

#include "object/lyxObject.hpp"

class LyxInteger : public LyxObject {
private:
    int _value;
public:
    LyxInteger(int x);
    int value() const {return _value;}

    virtual void print();
    virtual LyxObject* add(LyxObject* x);
    virtual LyxObject* greater(LyxObject* x);
    virtual LyxObject* less(LyxObject* x);
    virtual LyxObject* equal(LyxObject* x);
    virtual LyxObject* not_equal(LyxObject* x);
    virtual LyxObject* greater_equal(LyxObject* x);
    virtual LyxObject* less_equal(LyxObject* x);
};

#endif // LYX_INTEGER_HPP_