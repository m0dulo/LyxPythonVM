#include "runtime/interpreter.hpp"
#include "util/arrayList.hpp"
#include "object/lyxString.hpp"
#include "object/lyxInteger.hpp"
#include <string.h>
#include <stdio.h>

void Interpreter::run(CodeObject* codes) {
    int pc = 0;
    int code_length = codes->_bytebodes->length();

    _stack = new ArrayList<LyxObject*>(codes->_stack_size);
    _consts = codes->_consts;

    while (pc < code_length) {
        unsigned char op_code = (codes->_bytebodes->value())[pc++];
        bool has_argument = (op_code & 0xff) >= ByteCode::HAVE_ARGUMENT;

        int op_arg = -1;
        if (has_argument) {
            int byte1 = (codes->_bytebodes->value()[pc++] & 0xff);
            op_arg = ((codes->_bytebodes->value()[pc++] & 0xff) << 8) | byte1;
        }

        LyxObject* v, * w;
        switch (op_code) {
            case ByteCode::LOAD_CONST:
                _stack->add(_consts->get(op_arg));
                break;
            case ByteCode::PRINT_ITEM:
                v = _stack->pop();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;
            case ByteCode::BINARY_ADD:
                v = _stack->pop();
                w = _stack->pop();
                _stack->add(w->add(v));
                break;
            case ByteCode::RETURN_VALUE:
                _stack->pop();
                break;
            default:
                printf("ERROR: Unrecognized bye code %d\n", op_code);
        }
    }
}