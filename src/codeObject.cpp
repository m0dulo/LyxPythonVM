#include "codeObject.hpp"

CodeObject::CodeObject(int argcount, int nlocals, int stacksize, int flag, LyxString *bytecodes,
        ArrayList<LyxObject*>* consts, ArrayList<LyxObject*>* names,
        ArrayList<LyxObject*>* varnames,
        ArrayList<LyxObject*>* freevars, ArrayList<LyxObject*>* cellvars,
        LyxString* file_name, LyxString* co_name, int lineno, LyxString* notable):
            _argcount(argcount),
            _nlocals(nlocals),
            _stack_size(stacksize),
            _flag(flag),
            _bytebodes(bytecodes),
            _consts(consts),
            _var_names(varnames),
            _free_vars(freevars),
            _cell_vars(cellvars),
            _co_name(co_name),
            _file_name(file_name),
            _lineno(lineno),
            _notable(notable) {
}         