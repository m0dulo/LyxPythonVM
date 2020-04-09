#ifndef LYX_OBJECT_HPP_
#define LYX_OBJECT_HPP_

class LyxObject {
public:
    virtual void print() {}
    virtual LyxObject* add(LyxObject* x) {} 

    virtual LyxObject* greater(LyxObject* x) {}
    virtual LyxObject* less(LyxObject* x) {}
    virtual LyxObject* equal(LyxObject* x) {}
    virtual LyxObject* not_equal(LyxObject* x) {}
    virtual LyxObject* greater_equal(LyxObject* x) {}
    virtual LyxObject* less_equal(LyxObject* x) {}

};

#endif // LYX_OBJECT_HPP_