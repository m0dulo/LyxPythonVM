#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include "code/bytecode.hpp"
#include "code/codeObject.hpp"

class Interpreter {
private:
    ArrayList<LyxObject*>* _stack;
    ArrayList<LyxObject*>* _consts;
public:
    Interpreter() = default;
    void run(CodeObject* codes);
};

#endif // INTERPRETER_HPP_