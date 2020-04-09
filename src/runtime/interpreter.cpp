#include "runtime/interpreter.hpp"
#include "util/arrayList.hpp"
#include "object/lyxString.hpp"
#include "object/lyxInteger.hpp"
#include <string.h>
#include <stdio.h>
#include <stack>

#define PUSH(x) _stack->add((x))
#define POP()   _stack->pop() 

void Interpreter::run(CodeObject* codes) {
    int pc = 0;
    int code_length = codes->_bytebodes->length();

    _stack = new ArrayList<LyxObject*>(codes->_stack_size);
    _consts = codes->_consts;
    
    #ifdef DEBUG
    printf("length : %d \n", codes->_bytebodes->length());
    for (int i = 0; i < codes->_bytebodes->length(); ++i) {
        printf("%02x ", (unsigned char)(codes->_bytebodes->value()[i]));
    }
    printf("\n");
    #endif

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
                PUSH(_consts->get(op_arg));
                break;
            case ByteCode::PRINT_ITEM:
                v = POP();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;
            case ByteCode::BINARY_ADD:
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;
            case ByteCode::RETURN_VALUE:
                POP();
                break;
            case ByteCode::COMPARE_OP:
                w = POP();
                v = POP();
                switch(op_arg) {
                    case ByteCode::COMPARE::GRATER:
                        PUSH(v->greater(w));
                        break;
                    case ByteCode::COMPARE::LESS:
                        PUSH(v->less(w));
                        break;
                    case ByteCode::COMPARE::EQUAL:
                        PUSH(v->equal(w));
                        break;
                    case ByteCode::COMPARE::NOT_EQUAL:
                        PUSH(v->not_equal(w));
                        break;
                    case ByteCode::COMPARE::GRATER_EQUAL:
                        PUSH(v->greater_equal(w));
                        break;
                    case ByteCode::COMPARE::LESS_EQUAL:
                        PUSH(v->less_equal(w));
                        break;
                    default:
                        printf("ERROR: Unrecognized compare op %d\n", op_arg);
                }
                break;
            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if (((LyxInteger*)v)->value() == 0)
                    pc = op_arg;
                break;
            case ByteCode::JUMP_FORWARD:
                pc += op_arg;
                break;
            default:
                printf("ERROR: Unrecognized bye code %d\n", op_code);
        }
    }
}