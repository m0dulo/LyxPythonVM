#ifndef LYX_STRING_HPP_
#define LYX_STRING_HPP_

class LyxString {
private:
    char* _value;
    int _length;
public:
    LyxString(const char* x);
    LyxString(const char* x, const int length);

    char* value() const {return _value;}
    int length() const {return _length};
};
#endif // LYX_STRING_HPP_
