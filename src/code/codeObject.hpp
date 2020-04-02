#ifndef CODE_OBJECT_HPP_
#define CODE_OBJECT_HPP_

#include "object/lyxObject.hpp"

class LyxString;

template <typename T>
class ArrayList;

class CodeObject : public LyxObject {
public:
    int _argcount;
    int _nlocals;
    int _stack_size;
    int _flag;

    LyxString* _bytebodes;
    ArrayList<LyxObject*>* _names;
    ArrayList<LyxObject*>* _consts;
    ArrayList<LyxObject*>* _var_names;

    ArrayList<LyxObject*>* _free_vars;
    ArrayList<LyxObject*>* _cell_vars;

    LyxString* _co_name;
    LyxString* _file_name;

    int _lineno;
    LyxString* _notable;

    CodeObject(int argcount, int nlocals, int stacksize, int flag, LyxString *bytecodes,
        ArrayList<LyxObject*>* consts, ArrayList<LyxObject*>* names,
        ArrayList<LyxObject*>* varnames,
        ArrayList<LyxObject*>* freevars, ArrayList<LyxObject*>* cellvars,
        LyxString* file_name, LyxString* co_name, int lineno, LyxString* notable);
};

#endif // CODE_OBJECT_HPP_