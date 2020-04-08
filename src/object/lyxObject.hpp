#ifndef LYX_OBJECT_HPP_
#define LYX_OBJECT_HPP_

class LyxObject {
public:
    virtual void print() {}
    virtual LyxObject* add(LyxObject* x) {}
};

#endif // LYX_OBJECT_HPP_