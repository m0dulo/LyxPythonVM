#include "runtime/interpreter.hpp"
#include "util/arrayList.hpp"
#include "object/lyxString.hpp"
#include "object/lyxInteger.hpp"
#include <string.h>

void Interpreter::run(CodeObject* codes) {
    int pc = 0;
    int code_length = codes->_bytebodes->length();

    _stack = new ArrayList<LyxObject*>(codes->_stack_size);
    _consts = codes->_consts;

    while (pc < code_length) {
        
    }
}