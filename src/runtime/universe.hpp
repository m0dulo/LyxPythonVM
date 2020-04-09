#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

class LyxInteger;
class LyxObject;

class Universe {
public:
    static LyxInteger* LyxTrue;
    static LyxInteger* LyxFalse;

    static LyxObject* LyxNone;

    static void genesis();
    static void destory();
};

#endif // UNIVERSE_HPP_